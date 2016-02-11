#define DLL_NAME "PROXY"

#include "proxy.h"
#include "dump.h"

#include "json.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

//#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using json = nlohmann::json;

const unsigned MAGIC = 0x1a1b1c00;

bool DISABLE_PROXY = false;

HWND hWnd;
sf::RenderWindow *window;

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
	static IDirectDrawPalette* unwrap(IDirectDrawPalette *ddp) {
		if (!ddp) return nullptr;
		DirectDrawPaletteProxy *ddpp = (DirectDrawPaletteProxy*)ddp;
		if (ddpp->magic != MAGIC) {
			log("!~~~~~~~ magic != MAGIC ~~~~~~~!");
		}
		return ddpp->ddp;
	}

	static IDirectDrawPalette* wrap(IDirectDrawPalette *ddp) {
		if (!ddp) return nullptr;
		DirectDrawPaletteProxy *ddpp = (DirectDrawPaletteProxy*)ddp;
		if (ddpp->magic == MAGIC) {
			log("!~~~~~~~ magic == MAGIC ~~~~~~~!");
		}
		return new DirectDrawPaletteProxy(ddp);
	}

	int magic = MAGIC;
	IDirectDrawPalette *ddp;

	DirectDrawPaletteProxy(IDirectDrawPalette *ddp) {
		this->ddp = ddp;
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
	STDMETHOD(GetEntries)(THIS_ DWORD a, DWORD b, DWORD c, LPPALETTEENTRY d) {
		DDRAW_PALETTE_PROXY(GetEntries);

		if (DISABLE_PROXY) {
			return ddp->GetEntries(a, b, c, d);
		}
		else {
			return S_OK;
		}
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, DWORD, LPPALETTEENTRY) {
		DDRAW_PALETTE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetEntries)(THIS_ DWORD a, DWORD b, DWORD c, LPPALETTEENTRY d) {
		DDRAW_PALETTE_PROXY(SetEntries);

		if (DISABLE_PROXY) {
			return ddp->SetEntries(a, b, c, d);
		}
		else {
			return S_OK;
		}
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

std::vector<UCHAR> buffer(1920 * 1080 * 32);
std::vector<unsigned> pal(256);

class DirectDrawSurfaceProxy : public IDirectDrawSurface3
{
	static IDirectDrawSurface3* unwrap(IDirectDrawSurface3 *dds3) {
		if (!dds3) return nullptr;
		DirectDrawSurfaceProxy *dds3p = (DirectDrawSurfaceProxy*)dds3;
		if (dds3p->magic != MAGIC) {
			log("!~~~~~~~ magic != MAGIC ~~~~~~~!");
		}
		return dds3p->dds3();
	}

	static IDirectDrawSurface3* wrap(IDirectDrawSurface3 *dds3) {
		if (!dds3) return nullptr;
		DirectDrawSurfaceProxy *dds3p = (DirectDrawSurfaceProxy*)dds3;
		if (dds3p->magic == MAGIC) {
			log("!~~~~~~~ magic == MAGIC ~~~~~~~!");
		}
		return new DirectDrawSurfaceProxy(dds3, nullptr);
	}
public:
	int magic = MAGIC;
	IDirectDrawSurface *_dds1 = nullptr;
	IDirectDrawSurface3 *_dds3 = nullptr;
	DDSURFACEDESC ddsd;
	DDSURFACEDESC gddsd;

	int width = -1;
	int height = -1;
	std::vector<UCHAR> surface_mem;
	std::vector<unsigned> texture_data;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Texture texture2;
	sf::Sprite sprite2;

	sf::RectangleShape shape;

	IDirectDrawSurface3 *dds3() {
		if (!_dds3) {
			log("_dds3 = NULL");
		}
		return _dds3;
	}

	DirectDrawSurfaceProxy(IDirectDrawSurface *dds1, LPDDSURFACEDESC ddsd) {
		this->_dds1 = dds1;
		set_ddsd(ddsd);
	}

	DirectDrawSurfaceProxy(IDirectDrawSurface3 *dds3, LPDDSURFACEDESC ddsd) {
		this->_dds3 = dds3;
		set_ddsd(ddsd);
	}

	void set_ddsd(LPDDSURFACEDESC ddsd) {
		if (ddsd) {
			this->ddsd = *ddsd;
			if (ddsd->dwBackBufferCount) {
				width = config["backbuffer_w"];
				height = config["backbuffer_h"];
			}
			else {
				width = ddsd->dwWidth;
				height = ddsd->dwHeight;
			}

				texture.create(width, height);
			
				texture2.loadFromFile("FRAME001.png");
				sprite2.setTexture(texture2);



#if 0

			bool status = texture.create(width, height);
			//texture.loadFromFile("FRAME001.png");

			if (ddsd->dwBackBufferCount == 0 && ddsd->dwWidth < 320) {
				texture_data.resize(width * height);

				for (int i = 0; i < width * height; ++i) {
					texture_data[i] = 0x88888888;
				}

				texture.update((const sf::Uint8*)texture_data.data());

				sprite.setTexture(texture);
			}



			//log("texture.create", width, height, status);

			surface_mem.resize(width * height);
#endif
		}
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_SURFACE_PROXY(QueryInterface);
		log("this = ", this);

		HRESULT result = S_OK;

		if (DISABLE_PROXY) {
			result = _dds1->QueryInterface(riid, (void**)&_dds3);

		}

		log("dds3 =", _dds3);

		log_out(this);

		*ppvObj = this;

		return result;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_SURFACE_PROXY(AddRef);
		return dds3()->AddRef();
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_SURFACE_PROXY(Release);

		if (DISABLE_PROXY) {
			return dds3()->Release();
		}
		else {
			return S_OK;
		}
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
	STDMETHOD(Blt)(THIS_ LPRECT a, LPDIRECTDRAWSURFACE3 b, LPRECT c, DWORD d, LPDDBLTFX e) {
		DDRAW_SURFACE_PROXY(Blt);

		log("this =", this);
		log("bdds3 =", c);

		if (DISABLE_PROXY) {
			bool Blt_enable = config["Blt_enable"];

			if (Blt_enable) {
				auto result = dds3()->Blt(a, unwrap(b), c, d, e);

				log_hresult(result);

				return result;
			}
			else {
				return S_OK;
			}
		}
		else {
			if (!a) return S_OK;

#if 0
			shape.setPosition(a->left, a->top);
			shape.setSize(sf::Vector2f(a->right - a->left, a->bottom - a->top));
			shape.setOutlineColor(sf::Color::Red);
			shape.setFillColor(sf::Color::Transparent);
			shape.setOutlineThickness(1);

			log("window->draw(shape)");

			window->draw(shape);
#endif

			return S_OK;


			sprite.setPosition(a->left, a->top);
			sprite2.setPosition(a->left, a->top);

			if (width > gddsd.lPitch) return S_OK;
			if (ddsd.dwBackBufferCount) return S_OK;

	
			window->draw(sprite);
			//window->draw(sprite2);

			return S_OK;
		}
	}
	STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD) {
		DDRAW_SURFACE_PROXY(BltBatch);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(BltFast)(THIS_ DWORD a, DWORD b, LPDIRECTDRAWSURFACE3 c, LPRECT d, DWORD e) {
		DDRAW_SURFACE_PROXY(BltFast);

		log("this = ", this);
		log("bdds3 = ", c);

		if (DISABLE_PROXY) {
			bool BltFast_enable = config["BltFast_enable"];

			if (BltFast_enable) {
				auto result = dds3()->BltFast(a, b, unwrap(c), d, e);

				log_hresult(result);

				return result;
			}
			else {
				return S_OK;
			}
		}
		else {
			//if (!a) return S_OK;

#if 0
			shape.setPosition(a, b);
			shape.setSize(sf::Vector2f(d->right - d->left, d->bottom - d->top));
			shape.setOutlineColor(sf::Color::Red);
			shape.setOutlineThickness(1);

			window->draw(shape);
#endif
			DirectDrawSurfaceProxy *ddsd = (DirectDrawSurfaceProxy *)c;
			auto &sprite = ddsd->sprite;

			sprite.setPosition(a, b);
			//sprite2.setPosition(a, b);


			//if (c->dwBackBufferCount) return S_OK;

			window->draw(sprite);
			//window->draw(sprite2);

			return S_OK;
		}
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

		log("this = ", this);
		log("fdds3 = ", a);

		if (DISABLE_PROXY) {
			auto result = dds3()->Flip(unwrap(a), b);

			log_hresult(result);

			return result;
		}
		else {
			window->display();
			window->clear(sf::Color::Blue);

			return S_OK;
		}
	}
	STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS a, LPDIRECTDRAWSURFACE3 FAR *b) {
		DDRAW_SURFACE_PROXY(GetAttachedSurface);
		log("this = ", this);

		if (DISABLE_PROXY) {
			LPDIRECTDRAWSURFACE3 adds3;
			auto result = dds3()->GetAttachedSurface(a, &adds3);

			if (adds3) {
				log_out(adds3);
			}
			else {
				log_out("NULL");
			}

			log("adds3 = ", adds3);

			auto p = (DirectDrawSurfaceProxy*)wrap(adds3);
			*b = p;

			log_out(*b);

			return result;
		}
		else {
			IDirectDrawSurface3 *dds = nullptr;
			auto p = new DirectDrawSurfaceProxy(dds, &ddsd);
			*b = p;

			log_out(p);

			return S_OK;
		}
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

		if (DISABLE_PROXY) {
			return dds3()->GetDC(a);
		}
		else {
			*a = (HDC)1;
			return S_OK;
		}
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
		log("this = ", this);
		auto result = dds3()->GetPixelFormat(a);
		return result;
	}
	STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_SURFACE_PROXY(GetSurfaceDesc);
		log("this = ", this);

		DDSURFACEDESC ddsd00 = ddsd;
		ddsd00.dwWidth = ddsd00.dwHeight = 0;

		std::string s = ddsd.dwWidth ?
			"GetSurfaceDesc_" + std::to_string(h(&ddsd00)) :
			"GetSurfaceDesc_" + std::to_string(h(&ddsd));

		if (DISABLE_PROXY) {
			auto result = dds3()->GetSurfaceDesc(a);
			Dump(s, a);

			if (ddsd.dwWidth > 512 && ddsd.dwWidth < 640) {
				int x = 0;
			}

			log_ddsd(&ddsd);
			log_ddsd(a);

			if (ddsd.dwBackBufferCount) {
				int w = config["GetSurfaceDesc_backbuffer_w"];
				int h = config["GetSurfaceDesc_backbuffer_h"];

				a->dwWidth = w;
				a->dwHeight = h;
			}

			return result;
		}
		else {
			Load(s, a);
			if (ddsd.dwWidth) {
				a->dwWidth = ddsd.dwWidth;
				a->dwHeight = ddsd.dwHeight;
			}

			gddsd = *a;
			
			log_ddsd(&ddsd);
			log_ddsd(a);

			return S_OK;
		}
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) {
		DDRAW_SURFACE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(IsLost)(THIS) {
		DDRAW_SURFACE_PROXY(IsLost);

		if (DISABLE_PROXY) {
			return dds3()->IsLost();
		}
		else {
			return 0;
		}
	}
	STDMETHOD(Lock)(THIS_ LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d) {
		DDRAW_SURFACE_PROXY(Lock);
		log("this = ", this);
		log(ddsd.dwWidth, ddsd.dwHeight);

		if (DISABLE_PROXY) {
			auto result = dds3()->Lock(a, b, c, d);


			if (b->lpSurface) {
				log("lpSurface:", b->lpSurface);
			}
			else {
				log("lpSurface: NULL");
			}

			DDSURFACEDESC x = ddsd;
			x.dwWidth = x.dwHeight = 0;
			x.lpSurface = 0;
			//log("h(&y)", h(&x));
			//log("h(&x)", h(&x));

			Dump("Lock_" + std::to_string(h(&x)), b);

			return result;
		}
		else {
			DDSURFACEDESC x = ddsd;
			x.dwWidth = x.dwHeight = 0;
			x.lpSurface = 0;
			//log("h(&y)", h(&x));

			Load("Lock_" + std::to_string(h(&x)), b);
			b->dwWidth = width;
			b->dwHeight = height;

			buffer.clear();
			buffer.resize(gddsd.lPitch * height, 0xAB);
			texture_data.resize(width * height, 0xAB);

			b->lpSurface = buffer.data();
			
			return S_OK;
		}
	}
	STDMETHOD(ReleaseDC)(THIS_ HDC a) {
		DDRAW_SURFACE_PROXY(ReleaseDC);

		if (DISABLE_PROXY) {
			return dds3()->ReleaseDC(a);
		}
		else {
			return S_OK;
		}
	}
	STDMETHOD(Restore)(THIS) {
		DDRAW_SURFACE_PROXY(Restore);
		return dds3()->Restore();
	}
	STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER) {
		DDRAW_SURFACE_PROXY(SetClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetColorKey)(THIS_ DWORD a, LPDDCOLORKEY b) {
		DDRAW_SURFACE_PROXY(SetColorKey);
		if (DISABLE_PROXY) {
			return dds3()->SetColorKey(a, b);
		}
		else {
			return S_OK;
		}
	}
	STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG) {
		DDRAW_SURFACE_PROXY(SetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE a) {
		DDRAW_SURFACE_PROXY(SetPalette);
		log("this = ", this);

		if (DISABLE_PROXY) {
			auto result = dds3()->SetPalette(DirectDrawPaletteProxy::unwrap(a));

			log_hresult(result);

			return result;
		}
		else {
			return S_OK;
		}
	}
	STDMETHOD(Unlock)(THIS_ LPVOID a) {
		DDRAW_SURFACE_PROXY(Unlock);
		log("this = ", this);

		if (DISABLE_PROXY) {
			auto result = dds3()->Unlock(a);
			return result;
		}
		else {
			//return S_OK;

			if (ddsd.dwBackBufferCount == 0) {
				UCHAR *dst = (UCHAR *)texture_data.data();
				UCHAR *src = (UCHAR *)buffer.data();

				if (width > gddsd.lPitch) return S_OK;

				for (int i = 0; i < height; ++i) {
					for (int j = 0; j < width; ++j) {
						unsigned *px = &texture_data[i * width + j];
						UCHAR k = buffer[i * gddsd.lPitch + j];

						UCHAR *b = (UCHAR *)px;
						b[0] = b[1] = b[2] = k;
						b[3] = k ? 0xFF : 0;
					};
				}
				
				texture.update((const sf::Uint8*)texture_data.data());
				sprite.setTexture(texture);

				auto im = texture.copyToImage();

				auto filename = "b/" + std::to_string(h(&gddsd)) + ".png";
				im.saveToFile(filename);

				//stbi_write_png(filename.c_str(), width, height, 4, texture_data.data(), width);
			}
			return S_OK;
		}
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

#define DDRAW_PROXY(method) log("DirectDrawProxy", #method);

struct DirectDrawProxy : public IDirectDraw2
{
	IDirectDraw *dd = nullptr;
	IDirectDraw2 *dd2 = nullptr;

	DirectDrawProxy(IDirectDraw *dd) {
		window->create(hWnd);
		window->setVerticalSyncEnabled(true);
		window->clear(sf::Color::Red);
		window->display();
		this->dd = dd;
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_PROXY(QueryInterface);

		log("this =", this);

		HRESULT result = S_OK;

		if (DISABLE_PROXY) {
			result = dd->QueryInterface(riid, (void**)(&dd2));
		}

		log_out(this);

		*ppvObj = this;

		return result;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_PROXY(AddRef);
		return dd2->AddRef();
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_PROXY(Release);
		return S_OK; // Leak?
		return dd2->Release();
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
	STDMETHOD(CreatePalette)(THIS_ DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR* c, IUnknown FAR *d) {
		DDRAW_PROXY(CreatePalette);

		LPDIRECTDRAWPALETTE ddp = nullptr;

		if (DISABLE_PROXY) {
			auto result = dd2->CreatePalette(a, b, &ddp, d);
			auto ddpp = new DirectDrawPaletteProxy(ddp);
			*c = ddpp;
			return result;
		}
		else {
			auto ddpp = new DirectDrawPaletteProxy(ddp);
			*c = ddpp;
			return S_OK;
		}
		
		return S_OK;
	}
	STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC a, LPDIRECTDRAWSURFACE FAR *b, IUnknown FAR *c) {
		DDRAW_PROXY(CreateSurface);

		log_in(a, b, c);
		log_in("w:", a->dwWidth, "h:", a->dwHeight, "bbc:", a->dwBackBufferCount);

		log_ddsd(a);

		IDirectDrawSurface *dds = nullptr;

		if (DISABLE_PROXY) {
			HRESULT result = dd2->CreateSurface(a, &dds, c);

			log("dds1 =", dds);

			DirectDrawSurfaceProxy *ddsp = new DirectDrawSurfaceProxy(dds, a);
			*b = (IDirectDrawSurface*)ddsp;

			log_out(ddsp);

			log_hresult(result);

			return result;
		}
		else {
			DirectDrawSurfaceProxy *ddsp = new DirectDrawSurfaceProxy(dds, a);

			*b = (IDirectDrawSurface*)ddsp;

			return S_OK;
		}
	}
	STDMETHOD(DuplicateSurface)(THIS_ LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR *b) {
		DDRAW_PROXY(DuplicateSurface);
		return PROXY_UNIMPLEMENTED();
	}

	LPDDENUMMODESCALLBACK _EnumDisplayModesCallback = nullptr;

	static HRESULT FAR PASCAL EnumDisplayModesCallback(LPDDSURFACEDESC a, LPVOID b) {
		DDRAW_PROXY(EnumDisplayModesCallback);

		static int i = 0;
		if (i == 0) {
			Dump("EnumDisplayModes_0", a);
			++i;
		}

		log_ddsd(a);

		DirectDrawProxy *self = (DirectDrawProxy *)b;
		auto result = self->_EnumDisplayModesCallback(a, nullptr);

		log_hresult(result);

		return result;
	}

	STDMETHOD(EnumDisplayModes)(THIS_ DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMMODESCALLBACK d) {
		DDRAW_PROXY(EnumDisplayModes);

		log_in(a, b, c, d);

		if (DISABLE_PROXY) {
			_EnumDisplayModesCallback = d;
			auto result = dd2->EnumDisplayModes(a, b, this, EnumDisplayModesCallback);
			log_hresult(result);
			return result;
		}
		else {
			DDSURFACEDESC ddsd;
			Load("EnumDisplayModes_0", &ddsd);
			d(&ddsd, c);
			return S_OK;
		}
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
		if (DISABLE_PROXY) {
			log_in(a, b);

			auto result = dd2->GetCaps(a, b);

			if (a)
				log_caps(a);
			if (b)
				log_caps(b);

			log_hresult(result);

			return result;
		}
		else {
			Load("GetCaps_a", a);
			Load("GetCaps_b", a);
		}
	}
	STDMETHOD(GetDisplayMode)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_PROXY(GetDisplayMode);

		log_in(a);

		if (DISABLE_PROXY) {
			auto result = dd2->GetDisplayMode(a);

			int w = config["GetDisplayMode_w"];
			int h = config["GetDisplayMode_h"];

			log_out(w, h);

			a->dwWidth = w;
			a->dwHeight = h;

			log_hresult(result);
			return result;
		}
		else {
			Load("EnumDisplayModes_0", a);
			return S_OK;
		}
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
		if (DISABLE_PROXY) {
			return dd2->RestoreDisplayMode();
		}
		else {
			return S_OK;
		}
	}
	STDMETHOD(SetCooperativeLevel)(THIS_ HWND hWnd, DWORD flags) {
		DDRAW_PROXY(SetCooperativeLevel);

		auto fdef = make_fdef({
			FLAG(DDSCL_FULLSCREEN),
			FLAG(DDSCL_ALLOWREBOOT),
			FLAG(DDSCL_NOWINDOWCHANGES),
			FLAG(DDSCL_NORMAL)
		});

		log("hWnd =", hWnd);
		log_flags("flags", fdef, flags);

		if (DISABLE_PROXY) {
			std::vector<std::string> SetCooperativeLevel_flags = config["SetCooperativeLevel_flags"];

			// flags = set_flags(fdef, SetCooperativeLevel_flags);

			auto result = dd2->SetCooperativeLevel(hWnd, flags);

			log_hresult(result);

			return result;
		}
		else {
			return S_OK;
		}
	}
	STDMETHOD(SetDisplayMode)(THIS_ DWORD w, DWORD h, DWORD c, DWORD d, DWORD e) {
		DDRAW_PROXY(SetDisplayMode);
		log(">", w, h, c, d);

		w = config["SetDisplayMode_w"];
		h = config["SetDisplayMode_h"];

		if (DISABLE_PROXY) {
			auto result = dd2->SetDisplayMode(w, h, c, d, e);
			log_hresult(result);
			return result;
		}
		else {
			return S_OK;
		}
	}
	STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD a, HANDLE b) {
		DDRAW_PROXY(WaitForVerticalBlank);

		if (DISABLE_PROXY) {
			return dd2->WaitForVerticalBlank(a, b);
		}
		else {
			return S_OK;
		}
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
	IDirectDraw *dd = nullptr;

	if (DISABLE_PROXY) {
		_DirectDrawCreate(lpGUID, &dd, pUnkOuter);
	}

	auto ddp = new DirectDrawProxy(dd);

	*lplpDD = (IDirectDraw *)ddp;

	return S_OK;
}

std::ofstream log_file;
json _config;

int proxy_init() {
	log_file.open("log.txt");
	//log_file.rdbuf()->pubsetbuf(0, 0);

	std::ifstream cfg_file;
	cfg_file.open("config.json");
	_config << cfg_file;

	DISABLE_PROXY = _config["disable_proxy"];

	for (auto &c : pal) {
		unsigned char *px = (unsigned char *)&c;
		px[0] = rand();
			px[1] = rand();
			px[2] = rand();
		px[0] = 255;
	}

	return 0;
}

int _ = proxy_init();

PROXY_EXPORTS void SetHwnd(HWND _hWnd) {
	hWnd = _hWnd;
	window = new sf::RenderWindow();
}

PROXY_EXPORTS void *ProxyLog() {
	return &log_file;
}

PROXY_EXPORTS void *Config() {
	return &_config;
}
