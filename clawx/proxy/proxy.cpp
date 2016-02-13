#define DLL_NAME "PROXY"

#include "proxy.h"
#include "dump.h"

#include "json.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

//#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <unordered_map>

using json = nlohmann::json;

const unsigned MAGIC = 0x1a1b1c00;

bool DISABLE_PROXY = false;

HWND hWnd;
sf::RenderWindow *window;

sf::RenderTexture *tempbuffer;

template<typename T>
size_t h(const T* ptr) {
	const char *c = (const char *)ptr;
	int n = sizeof(T);
	std::size_t seed = 0;
	for (int i = 0; i < n; ++i) {
		char j = c[i];
		seed ^= j + 0x9e3779b9 + (seed << 6) + (seed >> 2);
	}
	return seed;
}

void load_config();

size_t h_ddsd00(DDSURFACEDESC *ddsd) {
	DDSURFACEDESC ddsd00 = *ddsd;
	ddsd00.dwWidth = ddsd00.dwHeight = 0;
	return h(&ddsd00);
}

auto make_fdef(std::vector<std::pair<unsigned, std::string>> fdef) {
	return fdef;
}

unsigned set_flags(std::vector<std::pair<unsigned, std::string>> fdef, std::vector<std::string> flags) {
	unsigned f = 0;
	for (auto fi : flags) {
		for (auto &p : fdef) {
			if (fi == p.second) {
				f |= p.first;
			}
		}
	}
	return f;
}

#define DDRAW_PALETTE_PROXY(method) log("DirectDrawPaletteProxy", #method);

struct DirectDrawPaletteProxy : public IDirectDrawPalette
{
	std::vector<PALETTEENTRY> entries;
	std::unordered_map<unsigned, int> reverse_map;

	DirectDrawPaletteProxy() {}

	sf::Color mapIndex(int i) {
		auto &e = entries[i];
		return sf::Color(e.peRed, e.peGreen, e.peBlue, 0xFF);
	}

	int mapColor(sf::Color c) {
		c.a = 0xFF;
		return reverse_map[c.toInteger()];
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_PALETTE_PROXY(QueryInterface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_PALETTE_PROXY(AddRef);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_PALETTE_PROXY(Release);
		return PROXY_UNIMPLEMENTED();
	}
	/*** IDirectDrawPalette methods ***/
	STDMETHOD(GetCaps)(THIS_ LPDWORD) {
		DDRAW_PALETTE_PROXY(GetCaps);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetEntries)(
		DWORD          dwFlags,
		DWORD          dwBase,
		DWORD          dwNumEntries,
		LPPALETTEENTRY lpEntries
	) {
		DDRAW_PALETTE_PROXY(GetEntries);

		struct P {
			PALETTEENTRY e[256];
		};

		if (entries.empty()) {
			entries.resize(256);
			P *p = (P*)entries.data();
			Load("GetEntries_0", p);
		}

		entries.resize(dwBase + dwNumEntries);

		for (int i = dwBase; i < dwNumEntries; ++i) {
			*lpEntries = entries[i];
			++lpEntries;
		}

		return S_OK;
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, DWORD, LPPALETTEENTRY) {
		DDRAW_PALETTE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetEntries)(
		DWORD          dwFlags,
		DWORD          dwStartingEntry,
		DWORD          dwCount,
		LPPALETTEENTRY lpEntries
	) {
		DDRAW_PALETTE_PROXY(SetEntries);

		entries.resize(dwStartingEntry + dwCount);

		for (int i = dwStartingEntry; i < dwCount; ++i) {
			entries[i] = *lpEntries;
			++lpEntries;
		}

		reverse_map.reserve(entries.size());

		int i = 0;
		for (auto &e : entries) {
			sf::Color c(e.peRed, e.peGreen, e.peBlue, 0xFF);
			reverse_map[c.toInteger()] = i;
			++i;
		}

		return S_OK;
	}
};

#define DDRAW_SURFACE_PROXY(method) log("DirectDrawSurfaceProxy", #method);

#define _DDSCL_NORMAL 0

void log_ddsd(LPDDSURFACEDESC ddsd) {
	log_flags("ddsd->dwFlags", {
		FLAG(DDSD_ALL),
		FLAG(DDSD_ALPHABITDEPTH),
		FLAG(DDSD_BACKBUFFERCOUNT),
		FLAG(DDSD_CAPS),
		FLAG(DDSD_CKDESTBLT),
		FLAG(DDSD_CKDESTOVERLAY),
		FLAG(DDSD_CKSRCBLT),
		FLAG(DDSD_CKSRCOVERLAY),
		FLAG(DDSD_HEIGHT),
		FLAG(DDSD_LINEARSIZE),
		FLAG(DDSD_LPSURFACE),
		FLAG(DDSD_MIPMAPCOUNT),
		FLAG(DDSD_PITCH),
		FLAG(DDSD_PIXELFORMAT),
		FLAG(DDSD_REFRESHRATE),
		FLAG(DDSD_TEXTURESTAGE),
		FLAG(DDSD_WIDTH),
		FLAG(DDSD_ZBUFFERBITDEPTH),
	}, ddsd->dwFlags);
	log(ddsd->dwWidth, ddsd->dwHeight);
	log(ddsd->lPitch, ddsd->ddpfPixelFormat.dwRGBBitCount);
}

void log_fx(LPDDBLTFX bltfx) {
	log_flags("bltfx->dwDDFX", {
		FLAG(DDBLTFX_ARITHSTRETCHY),
		FLAG(DDBLTFX_MIRRORLEFTRIGHT),
		FLAG(DDBLTFX_MIRRORUPDOWN),
		FLAG(DDBLTFX_NOTEARING),
		FLAG(DDBLTFX_ROTATE180),
		FLAG(DDBLTFX_ROTATE270),
		FLAG(DDBLTFX_ROTATE90),
		FLAG(DDBLTFX_ZBUFFERBASEDEST),
		FLAG(DDBLTFX_ZBUFFERRANGE)
	}, bltfx->dwDDFX);
}

int fileExists(TCHAR * file)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE handle = FindFirstFile(file, &FindFileData);
	int found = handle != INVALID_HANDLE_VALUE;
	if (found)
	{
		//FindClose(&handle); this will crash
		FindClose(handle);
	}
	return found;
}

size_t ddsd00_h(LPDDSURFACEDESC ddsd) {
	DDSURFACEDESC ddsd00 = *ddsd;
	ddsd00.dwWidth = ddsd00.dwHeight = 0;
	ddsd00.lpSurface = nullptr;
	return h(&ddsd00);
}

class DirectDrawProxy;
class DirectDrawSurfaceProxy;

DirectDrawSurfaceProxy *front_buffer;
DirectDrawSurfaceProxy *back_buffer;

std::vector<char> buffer(1920 * 1080 * 4);

class DirectDrawSurfaceProxy : public IDirectDrawSurface3
{
public:
	enum Kind {
		NORMAL_SURFACE,
		FRONT_BUFFER,
		BACK_BUFFER
	};

	int magic = MAGIC;

	DirectDrawProxy *ddp = nullptr;
	Kind kind;
	size_t d_h = 0;
	int width = 0;
	int height = 0;
	int pitch = 0;

	std::unique_ptr<sf::RenderTexture> render_texture;
	sf::Texture texture;
	std::vector<UCHAR> indexed_buffer;

	DirectDrawPaletteProxy *ddpp = nullptr;

	DirectDrawSurfaceProxy(DirectDrawProxy *ddp, Kind kind, size_t d_h, int width, int height, int pitch) {
		this->ddp = ddp;
		this->kind = kind;
		this->d_h = d_h;
		this->width = width;
		this->height = height;
		this->pitch = pitch;

		if (kind != NORMAL_SURFACE) {
			render_texture = std::make_unique<sf::RenderTexture>();
			render_texture->create(width, height);
		}

		texture.create(width, height);
		indexed_buffer.resize(640 * 480 * 4); // ...
	}

	const sf::Texture &getTexture() {
		if (render_texture) {
			return render_texture->getTexture();
		}
		else {
			return texture;
		}
	}

	sf::Sprite getSprite() {
		return sf::Sprite(getTexture());
	}

	void display() {
		sf::Sprite sprite = getSprite();
		window->draw(sprite);
		window->display();
		//window->clear();
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_SURFACE_PROXY(QueryInterface);

		*ppvObj = this;

		return S_OK;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_SURFACE_PROXY(AddRef);
		return S_OK;
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_SURFACE_PROXY(Release);
		return S_OK;
	}
	/*** IDirectDrawSurface methods ***/
	STDMETHOD(AddAttachedSurface)(THIS_ LPDIRECTDRAWSURFACE3) {
		DDRAW_SURFACE_PROXY(AddAttachedSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(AddOverlayDirtyRect)(THIS_ LPRECT) {
		DDRAW_SURFACE_PROXY(AddOverlayDirtyRect);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Blt)(
		 LPRECT               lpDestRect,
		 LPDIRECTDRAWSURFACE3 lpDDSrcSurface,
		 LPRECT               lpSrcRect,
		 DWORD                dwFlags,
		 LPDDBLTFX            lpDDBltFx
	) {
		DDRAW_SURFACE_PROXY(Blt);

		if (!lpDDSrcSurface) {
			return S_OK;
		}

		if (kind == NORMAL_SURFACE) {
			return S_OK;
		}

		int x = 0;
		int y = 0;

		if (lpDestRect) {
			x = lpDestRect->left;
			y = lpDestRect->top;
		}

		if (lpSrcRect) {
			//x -= lpSrcRect->left;
			//y -= lpSrcRect->top;
		}

		DirectDrawSurfaceProxy *ddsd = (DirectDrawSurfaceProxy *)lpDDSrcSurface;
		
		sf::Sprite sprite = ddsd->getSprite();
		sprite.setPosition(x, y);
		render_texture->draw(sprite);

		dump("_blt");

		return S_OK;
	}

	STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD) {
		DDRAW_SURFACE_PROXY(BltBatch);
		return PROXY_UNIMPLEMENTED();
	}

	STDMETHOD(BltFast)(THIS_
		DWORD                dwX,
		DWORD                dwY,
		LPDIRECTDRAWSURFACE3 lpDDSrcSurface,
		LPRECT               lpSrcRect,
		DWORD                dwFlags
	) {
		DDRAW_SURFACE_PROXY(BltFast);

		if (kind == NORMAL_SURFACE) {
			return S_OK;
		}

		int x = dwX;
		int y = dwY;

		if (lpSrcRect) {
			//x -= lpSrcRect->left;
			//y -= lpSrcRect->top;
		}

		DirectDrawSurfaceProxy *ddsd = (DirectDrawSurfaceProxy *)lpDDSrcSurface;

		sf::Sprite sprite = ddsd->getSprite();
		sprite.setPosition(x, y);
		render_texture->draw(sprite);

		dump("_bltfast");

		return S_OK;
	}

	STDMETHOD(DeleteAttachedSurface)(THIS_ DWORD, LPDIRECTDRAWSURFACE3) {
		DDRAW_SURFACE_PROXY(DeleteAttachedSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumAttachedSurfaces)(THIS_ LPVOID, LPDDENUMSURFACESCALLBACK) {
		DDRAW_SURFACE_PROXY(EnumAttachedSurfaces);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumOverlayZOrders)(THIS_ DWORD, LPVOID, LPDDENUMSURFACESCALLBACK) {
		DDRAW_SURFACE_PROXY(EnumOverlayZOrders);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE3 a, DWORD b) {
		DDRAW_SURFACE_PROXY(Flip);

		static int i = 0;
		++i;
		if(i % 5 == 0)
			load_config();

		std::swap(front_buffer->render_texture, back_buffer->render_texture);

		front_buffer->display();
		back_buffer->render_texture->clear(sf::Color::Transparent);

		return S_OK;
	}
	STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS a, LPDIRECTDRAWSURFACE3 FAR *out_dds) {
		DDRAW_SURFACE_PROXY(GetAttachedSurface);

		auto ddsp = new DirectDrawSurfaceProxy(ddp, BACK_BUFFER, d_h, width, height, width);
		*out_dds = ddsp;

		back_buffer = ddsp;
			
		return S_OK;
	}
	STDMETHOD(GetBltStatus)(THIS_ DWORD) {
		DDRAW_SURFACE_PROXY(GetBltStatus);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetCaps)(THIS_ LPDDSCAPS) {
		DDRAW_SURFACE_PROXY(GetCaps);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetClipper)(THIS_ LPDIRECTDRAWCLIPPER FAR*) {
		DDRAW_SURFACE_PROXY(GetClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetColorKey)(THIS_ DWORD, LPDDCOLORKEY) {
		DDRAW_SURFACE_PROXY(GetColorKey);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetDC)(THIS_ HDC FAR *a) {
		DDRAW_SURFACE_PROXY(GetDC);

		*a = (HDC)1;

		return S_OK;
	}
	STDMETHOD(GetFlipStatus)(THIS_ DWORD) {
		DDRAW_SURFACE_PROXY(GetFlipStatus);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetOverlayPosition)(THIS_ LPLONG, LPLONG) {
		DDRAW_SURFACE_PROXY(GetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetPalette)(THIS_ LPDIRECTDRAWPALETTE FAR*) {
		DDRAW_SURFACE_PROXY(GetPalette);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetPixelFormat)(THIS_ LPDDPIXELFORMAT a) {
		DDRAW_SURFACE_PROXY(GetPixelFormat);
		return S_OK;
	}
	STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_SURFACE_PROXY(GetSurfaceDesc);
		log("this = ", this);

		std::string s = "GetSurfaceDesc_" + std::to_string(d_h);

		Load(s, a);

		a->dwWidth = width;
		a->dwHeight = height;

		pitch = a->lPitch;

		if (pitch < width) {
			pitch = 640;
		}

		return S_OK;
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) {
		DDRAW_SURFACE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(IsLost)(THIS) {
		DDRAW_SURFACE_PROXY(IsLost);
		return 0;
	}
	STDMETHOD(Lock)(THIS_ LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d) {
		DDRAW_SURFACE_PROXY(Lock);

		Load("Lock_" + std::to_string(d_h), b);
		b->dwWidth = width;
		b->dwHeight = height;

		if (render_texture)
			render_texture->display();

		if (config["lock_textures"].get<bool>()) {
			sf::Image image = getTexture().copyToImage();
			indexed_buffer = image2indexed(image, ddpp, pitch);
		}
		
		b->lpSurface = indexed_buffer.data();

		dump("_lock");

		return S_OK;
	}
	STDMETHOD(ReleaseDC)(THIS_ HDC a) {
		DDRAW_SURFACE_PROXY(ReleaseDC);
		return S_OK;
	}
	STDMETHOD(Restore)(THIS) {
		DDRAW_SURFACE_PROXY(Restore);
		return S_OK;
	}
	STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER) {
		DDRAW_SURFACE_PROXY(SetClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetColorKey)(THIS_ DWORD a, LPDDCOLORKEY b) {
		DDRAW_SURFACE_PROXY(SetColorKey);
		return S_OK;
	}
	STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG) {
		DDRAW_SURFACE_PROXY(SetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE a) {
		DDRAW_SURFACE_PROXY(SetPalette);
		
		ddpp = (DirectDrawPaletteProxy *)a;

		return S_OK;
	}

	static sf::Image indexed2image(const UCHAR *indexed_buffer, DirectDrawPaletteProxy *ddpp, int width, int height, int pitch) {
		sf::Image image;
		image.create(width, height);

		if (!ddpp && front_buffer && front_buffer->ddpp) {
			ddpp = front_buffer->ddpp;
		}
		else {
			return image;
		}


		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				UCHAR k = indexed_buffer[i * pitch + j];
				sf::Color c = ddpp->mapIndex(k);
				image.setPixel(j, i, c);
			};
		}

		return image;
	}

	static std::vector<UCHAR> image2indexed(const sf::Image &image, DirectDrawPaletteProxy *ddpp, int pitch) {
		int width = image.getSize().x;
		int height = image.getSize().y;
		std::vector<UCHAR> indexed_buffer(pitch * height);

		if (!ddpp && front_buffer && front_buffer->ddpp) {
			ddpp = front_buffer->ddpp;
		}
		else {
			return indexed_buffer;
		}

		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				sf::Color c = image.getPixel(j, i);
				UCHAR k = ddpp->mapColor(c);
				indexed_buffer[i * pitch + j] = k;
			};
		}
		return indexed_buffer;
	}

	void dump(std::string p) {
#if 0
		if (indexed_buffer.size() && fileExists("dump")) {
			static int i = 0;
			int p = width;
			if (pitch > 0 && pitch < 1024) p = pitch;

			auto rgbab = indexed2rgba((UCHAR*)indexed_buffer.data(), width, height, p);

			char t[64];

			const char *tp = "sf";
			if (kind == FRONT_BUFFER) tp = "fb";
			if (kind == BACK_BUFFER) tp = "bb";

			sprintf_s(t, "d/%05d_%p_%s_%s.png", i++, this, tp, unlock ? "unlock": "lock");

			stbi_write_bmp(t, width, height, 4, rgbab.data());
		}
#else
		if (fileExists("dump")) {
			static int i = 0;

			char t[64];

			const char *tp = "sf";
			if (kind == FRONT_BUFFER) tp = "fb";
			if (kind == BACK_BUFFER) tp = "bb";

			sprintf_s(t, "d/%05d_%p_%s_%s.bmp", i++, this, tp, p.c_str());

			sf::Image image = getTexture().copyToImage();
			image.saveToFile(t);

			//stbi_write_bmp(t, width, height, 4, pixels);
		}
#endif
	}

	STDMETHOD(Unlock)(THIS_ LPVOID a) {
		DDRAW_SURFACE_PROXY(Unlock);

		sf::Image image = indexed2image(indexed_buffer.data(), ddpp, width, height, pitch);
		texture.update(image);

		if (kind != NORMAL_SURFACE) {
			sf::Sprite sprite(texture);
			render_texture->draw(sprite);

			if (kind == FRONT_BUFFER) {
				display();
			}
		}


		dump("_unlock");
			
		return S_OK;
	}

	STDMETHOD(UpdateOverlay)(THIS_ LPRECT, LPDIRECTDRAWSURFACE3, LPRECT, DWORD, LPDDOVERLAYFX) {
		DDRAW_SURFACE_PROXY(UpdateOverlay);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(UpdateOverlayDisplay)(THIS_ DWORD) {
		DDRAW_SURFACE_PROXY(UpdateOverlayDisplay);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(UpdateOverlayZOrder)(THIS_ DWORD, LPDIRECTDRAWSURFACE3) {
		DDRAW_SURFACE_PROXY(UpdateOverlayZOrder);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetDDInterface)(THIS_ LPVOID FAR *) {
		DDRAW_SURFACE_PROXY(GetDDInterface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(PageLock)(THIS_ DWORD) {
		DDRAW_SURFACE_PROXY(PageLock);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(PageUnlock)(THIS_ DWORD) {
		DDRAW_SURFACE_PROXY(PageUnlock);
		return PROXY_UNIMPLEMENTED();
	}
	/*** Added in the V3 interface ***/
	STDMETHOD(SetSurfaceDesc)(THIS_ LPDDSURFACEDESC a, DWORD b) {
		DDRAW_SURFACE_PROXY(SetSurfaceDesc);
		return PROXY_UNIMPLEMENTED();
	}
};

void log_caps(LPDDCAPS ddcaps) {
	 log_flags("ddcaps->dwCaps", {
		FLAG(DDCAPS_3D),
		FLAG(DDCAPS_ALIGNBOUNDARYDEST),
		FLAG(DDCAPS_ALIGNBOUNDARYSRC),
		FLAG(DDCAPS_ALIGNSIZEDEST),
		FLAG(DDCAPS_ALIGNSIZESRC),
		FLAG(DDCAPS_ALIGNSTRIDE),
		FLAG(DDCAPS_ALPHA),
		FLAG(DDCAPS_BANKSWITCHED),
		FLAG(DDCAPS_BLT),
		FLAG(DDCAPS_BLTCOLORFILL),
		FLAG(DDCAPS_BLTDEPTHFILL),
		FLAG(DDCAPS_BLTFOURCC),
		FLAG(DDCAPS_BLTQUEUE),
		FLAG(DDCAPS_BLTSTRETCH),
		FLAG(DDCAPS_CANBLTSYSMEM),
		FLAG(DDCAPS_CANCLIP),
		FLAG(DDCAPS_CANCLIPSTRETCHED),
		FLAG(DDCAPS_COLORKEY),
		FLAG(DDCAPS_COLORKEYHWASSIST),
		FLAG(DDCAPS_GDI),
		FLAG(DDCAPS_NOHARDWARE),
		FLAG(DDCAPS_OVERLAY),
		FLAG(DDCAPS_OVERLAYCANTCLIP),
		FLAG(DDCAPS_OVERLAYFOURCC),
		FLAG(DDCAPS_OVERLAYSTRETCH),
		FLAG(DDCAPS_PALETTE),
		FLAG(DDCAPS_PALETTEVSYNC),
		FLAG(DDCAPS_READSCANLINE),
		FLAG(DDCAPS_VBI),
		FLAG(DDCAPS_ZBLTS),
		FLAG(DDCAPS_ZOVERLAYS),
	}, ddcaps->dwCaps);

	log_flags("ddcaps->dwCaps2", {
		FLAG(DDCAPS2_AUTOFLIPOVERLAY),
		FLAG(DDCAPS2_CANBOBHARDWARE),
		FLAG(DDCAPS2_CANBOBINTERLEAVED),
		FLAG(DDCAPS2_CANBOBNONINTERLEAVED),
		FLAG(DDCAPS2_CANCALIBRATEGAMMA),
		FLAG(DDCAPS2_CANDROPZ16BIT),
		FLAG(DDCAPS2_CANFLIPODDEVEN),
		FLAG(DDCAPS2_CANMANAGETEXTURE),
		FLAG(DDCAPS2_CANRENDERWINDOWED),
		FLAG(DDCAPS2_CERTIFIED),
		FLAG(DDCAPS2_COLORCONTROLPRIMARY),
		FLAG(DDCAPS2_COLORCONTROLOVERLAY),
		FLAG(DDCAPS2_COPYFOURCC),
		FLAG(DDCAPS2_FLIPINTERVAL),
		FLAG(DDCAPS2_FLIPNOVSYNC),
		FLAG(DDCAPS2_NO2DDURING3DSCENE),
		FLAG(DDCAPS2_NONLOCALVIDMEM),
		FLAG(DDCAPS2_NONLOCALVIDMEMCAPS),
		FLAG(DDCAPS2_NOPAGELOCKREQUIRED),
		FLAG(DDCAPS2_PRIMARYGAMMA),
		FLAG(DDCAPS2_STEREO),
		FLAG(DDCAPS2_TEXMANINNONLOCALVIDMEM),
		FLAG(DDCAPS2_VIDEOPORT),
		FLAG(DDCAPS2_WIDESURFACES),
	}, ddcaps->dwCaps2);
}

void log_ddscaps(LPDDSCAPS ddscaps) {
	log_flags("ddscaps->dwCaps", {
		//FLAG(DDSCAPS_3D),
		FLAG(DDSCAPS_3DDEVICE),
		FLAG(DDSCAPS_ALLOCONLOAD),
		FLAG(DDSCAPS_ALPHA),
		FLAG(DDSCAPS_BACKBUFFER),
		FLAG(DDSCAPS_COMPLEX),
		FLAG(DDSCAPS_FLIP),
		FLAG(DDSCAPS_FRONTBUFFER),
		FLAG(DDSCAPS_HWCODEC),
		FLAG(DDSCAPS_LIVEVIDEO),
		FLAG(DDSCAPS_LOCALVIDMEM),
		FLAG(DDSCAPS_MIPMAP),
		FLAG(DDSCAPS_MODEX),
		FLAG(DDSCAPS_NONLOCALVIDMEM),
		FLAG(DDSCAPS_OFFSCREENPLAIN),
		FLAG(DDSCAPS_OPTIMIZED),
		FLAG(DDSCAPS_OVERLAY),
		FLAG(DDSCAPS_OWNDC),
		FLAG(DDSCAPS_PALETTE),
		FLAG(DDSCAPS_PRIMARYSURFACE),
		FLAG(DDSCAPS_STANDARDVGAMODE),
		FLAG(DDSCAPS_SYSTEMMEMORY),
		FLAG(DDSCAPS_TEXTURE),
		FLAG(DDSCAPS_VIDEOMEMORY),
		FLAG(DDSCAPS_VIDEOPORT),
		FLAG(DDSCAPS_VISIBLE),
		FLAG(DDSCAPS_WRITEONLY),
		FLAG(DDSCAPS_ZBUFFER),
	}, ddscaps->dwCaps);
}

#define DDRAW_PROXY(method) log("DirectDrawProxy", #method);

struct DirectDrawProxy : public IDirectDraw2
{
	DirectDrawSurfaceProxy *GetFrontBuffer() {
		return front_buffer;
	}

	DirectDrawSurfaceProxy *GetBackBuffer() {
		return back_buffer;
	}

	DirectDrawProxy() {
		window->setVerticalSyncEnabled(config["vsync"].get<bool>());
		window->create(hWnd);
		window->clear(sf::Color::Red);
		window->display();
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_PROXY(QueryInterface);

		*ppvObj = this;

		return S_OK;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_PROXY(AddRef);
		return S_OK;
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_PROXY(Release);
		return S_OK;
	}
	/*** IDirectDraw methods ***/
	STDMETHOD(Compact)(THIS) {
		DDRAW_PROXY(Compact);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(CreateClipper)(THIS_ DWORD a, LPDIRECTDRAWCLIPPER FAR* b, IUnknown FAR *c) {
		DDRAW_PROXY(CreateClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(CreatePalette)(THIS_ DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR* out_ddp, IUnknown FAR *d) {
		DDRAW_PROXY(CreatePalette);

		auto ddpp = new DirectDrawPaletteProxy();
		*out_ddp = ddpp;
		
		return S_OK;
	}
	STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC ddsd, LPDIRECTDRAWSURFACE FAR *out_dds, IUnknown FAR *c) {
		DDRAW_PROXY(CreateSurface);

		DirectDrawSurfaceProxy::Kind kind = DirectDrawSurfaceProxy::NORMAL_SURFACE;

		int width = ddsd->dwWidth;
		int height = ddsd->dwHeight;

		if (ddsd->dwBackBufferCount) {
			kind = DirectDrawSurfaceProxy::FRONT_BUFFER;
			width = config["backbuffer_w"];
			height = config["backbuffer_h"];
		}

		size_t d_h = kind == DirectDrawSurfaceProxy::FRONT_BUFFER ? h(ddsd) : ddsd00_h(ddsd);

		DirectDrawSurfaceProxy *ddsp = new DirectDrawSurfaceProxy(this, kind, d_h, width, height, width);

		if (kind == DirectDrawSurfaceProxy::FRONT_BUFFER) {
			front_buffer = ddsp;
		}

		*out_dds = (IDirectDrawSurface*)ddsp;

		return S_OK;
	}
	STDMETHOD(DuplicateSurface)(THIS_ LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR *b) {
		DDRAW_PROXY(DuplicateSurface);
		return PROXY_UNIMPLEMENTED();
	}

	STDMETHOD(EnumDisplayModes)(THIS_ DWORD a, LPDDSURFACEDESC b, LPVOID user_ptr, LPDDENUMMODESCALLBACK callback) {
		DDRAW_PROXY(EnumDisplayModes);

		DDSURFACEDESC ddsd;

		Load("EnumDisplayModes_0", &ddsd);
		callback(&ddsd, user_ptr);

		Load("EnumDisplayModes_1", &ddsd);
		callback(&ddsd, user_ptr);

		Load("EnumDisplayModes_2", &ddsd);
		callback(&ddsd, user_ptr);

		return S_OK;
	}
	STDMETHOD(EnumSurfaces)(THIS_ DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMSURFACESCALLBACK) {
		DDRAW_PROXY(EnumSurfaces);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(FlipToGDISurface)(THIS) {
		DDRAW_PROXY(FlipToGDISurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetCaps)(THIS_ LPDDCAPS a, LPDDCAPS b) {
		DDRAW_PROXY(GetCaps);

		Load("GetCaps_a", a);
		Load("GetCaps_b", a);

		return S_OK;
	}
	STDMETHOD(GetDisplayMode)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_PROXY(GetDisplayMode);

		Load("EnumDisplayModes_0", a);

		return S_OK;
	}
	STDMETHOD(GetFourCCCodes)(THIS_  LPDWORD, LPDWORD) {
		DDRAW_PROXY(GetFourCCCodes);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetGDISurface)(THIS_ LPDIRECTDRAWSURFACE FAR *) {
		DDRAW_PROXY(GetGDISurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetMonitorFrequency)(THIS_ LPDWORD) {
		DDRAW_PROXY(GetMonitorFrequency);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetScanLine)(THIS_ LPDWORD) {
		DDRAW_PROXY(GetScanLine);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetVerticalBlankStatus)(THIS_ LPBOOL) {
		DDRAW_PROXY(GetVerticalBlankStatus);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Initialize)(THIS_ GUID FAR *) {
		DDRAW_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(RestoreDisplayMode)(THIS) {
		DDRAW_PROXY(RestoreDisplayMode);
		return S_OK;
	}
	STDMETHOD(SetCooperativeLevel)(THIS_ HWND hWnd, DWORD flags) {
		DDRAW_PROXY(SetCooperativeLevel);
		return S_OK;
	}
	STDMETHOD(SetDisplayMode)(THIS_ DWORD w, DWORD h, DWORD c, DWORD d, DWORD e) {
		DDRAW_PROXY(SetDisplayMode);
		return S_OK;
	}
	STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD a, HANDLE b) {
		DDRAW_PROXY(WaitForVerticalBlank);
		return S_OK;
	}
	/*** Added in the v2 interface ***/
	STDMETHOD(GetAvailableVidMem)(THIS_ LPDDSCAPS, LPDWORD, LPDWORD) {
		DDRAW_PROXY(GetAvailableVidMem);
		return PROXY_UNIMPLEMENTED();
	};
};

PROXY_EXPORTS HRESULT DirectDrawProxyCreate(
	DirectDrawCreatePtr _DirectDrawCreate,
	GUID *lpGUID,
	LPDIRECTDRAW *lplpDD,
	IUnknown     *pUnkOuter
) {
	auto ddp = new DirectDrawProxy();

	*lplpDD = (IDirectDraw *)ddp;

	return S_OK;
}

std::ofstream log_file;
json _config;

void load_config() {
	std::ifstream cfg_file;
	cfg_file.open("config.json");
	_config << cfg_file;
	cfg_file.close();
}

int proxy_init() {
	log_file.open("log.txt");

	load_config();

	return 0;
}

int _ = proxy_init();

PROXY_EXPORTS void SetHwnd(HWND _hWnd) {
	hWnd = _hWnd;
	window = new sf::RenderWindow();
	tempbuffer = new sf::RenderTexture();
	tempbuffer->create(config["backbuffer_w"], config["backbuffer_h"]);
}

PROXY_EXPORTS void *ProxyLog() {
	return &log_file;
}

PROXY_EXPORTS void *Config() {
	return &_config;
}
