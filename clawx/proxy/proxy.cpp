#define DLL_NAME "PROXY"

#include "log.h"
#include "proxy.h"
#include "dump.h"
#include "utils.h"

#include "Config.h"
#include "Renderer.h"

#include "json.hpp"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <SFML/Window.hpp>

#include <fstream>
#include <unordered_map>

using json = nlohmann::json;

const unsigned MAGIC = 0x1a1b1c00;

bool DISABLE_PROXY = false;

const bool debug = config("debug");

sf::Window *window;

Renderer *r = nullptr;

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

#define PROXY_UNIMPLEMENTED() (log_call("UNIMPLEMENTED", "!", this), 0)

#define DDRAW_PALETTE_PROXY(method) log_call("DirectDrawpaletteProxy", #method, this)

class DirectDrawProxy;
class DirectDrawSurfaceProxy;

DirectDrawSurfaceProxy *front_buffer;
DirectDrawSurfaceProxy *back_buffer;

void render_to_screen(DirectDrawSurfaceProxy *ddsp);

struct DirectDrawPaletteProxy : public IDirectDrawPalette
{
	static const unsigned PALETTE_SIZE = Palette::PALETTE_SIZE;

	Renderer *renderer = nullptr;

	Palette palette;

	std::vector<PALETTEENTRY> entries;

	DirectDrawPaletteProxy(Renderer *renderer) {

		this->renderer = renderer;

		entries.resize(PALETTE_SIZE);
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

		assert(dwBase == 0 && dwNumEntries == PALETTE_SIZE);

		for (int i = 0; i < PALETTE_SIZE; ++i) {
			lpEntries[i] = entries[i];
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

		assert(dwStartingEntry == 0 && dwCount == PALETTE_SIZE);

		for (int i = 0; i < PALETTE_SIZE; ++i) {
			entries[i] = lpEntries[i];
		}

		palette.Update(lpEntries);

		render_to_screen(front_buffer);

		return S_OK;
	}
};

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

inline int pow2roundup(int x)
{
	if (x < 0)
		return 0;
	--x;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return x + 1;
}

void log_surface_call(const char *method, DirectDrawSurfaceProxy* ddsp);

HWND get_hwnd(DirectDrawProxy *ddp);

#define DDRAW_SURFACE_PROXY(method) log_surface_call(#method, this)

class DirectDrawSurfaceProxy : public IDirectDrawSurface3
{
public:
	enum Kind {
		NORMAL_SURFACE,
		FRONT_BUFFER,
		BACK_BUFFER
	};

	int magic = MAGIC;

	ULONG ref_count = 0;

	DirectDrawProxy *ddp = nullptr;
	size_t d_h = 0;

	Kind kind;
	int width = 0;
	int height = 0;

	DirectDrawPaletteProxy *ddpp = nullptr;

	Renderer::Surface surface;

	HDC hdcMem = 0; // TODO: cleanup
	HBITMAP memBm = 0;

	DirectDrawSurfaceProxy(DirectDrawProxy *ddp, Kind kind, size_t d_h, int width, int height) {
		this->ddp = ddp;
		this->d_h = d_h;

		this->kind = kind;
		this->width = width;
		this->height = height;

		this->surface = r->CreateSurface(width, height, kind == FRONT_BUFFER);

		AddRef();
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_SURFACE_PROXY(QueryInterface);
		*ppvObj = this;
		AddRef();
		return S_OK;
	}

	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_SURFACE_PROXY(AddRef);
		return ++ref_count;
	}

	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_SURFACE_PROXY(Release);

		if (--ref_count == 0) {
			delete this;
		}

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

	void Dump() {
		r->DownloadSurfaceBuffer(&surface);
		log(img_dump(width, height, surface.texture_buffer.data()));
	}

	STDMETHOD(Blt)(
		LPRECT               lpDestRect,
		LPDIRECTDRAWSURFACE3 lpDDSrcSurface,
		LPRECT               lpSrcRect,
		DWORD                dwFlags,
		LPDDBLTFX            lpDDBltFx
		) {
		DDRAW_SURFACE_PROXY(Blt);

		DirectDrawSurfaceProxy *ddsp = (DirectDrawSurfaceProxy *)lpDDSrcSurface;


		if (debug) {
			bool disable_log = config("disable_log");

			if (!disable_log && lpSrcRect && lpDestRect) {
				log(json_dump({
					{ "src.L", lpSrcRect->left },
					{ "src.R", lpSrcRect->right },
					{ "src.T", lpSrcRect->top },
					{ "src.B", lpSrcRect->bottom },
					{ "dst.L", lpDestRect->left },
					{ "dst.R", lpDestRect->right },
					{ "dst.T", lpDestRect->top },
					{ "dst.B", lpDestRect->bottom },
					{ "flags", dwFlags }
				}));
			}
		}


		if (lpDestRect && lpSrcRect) {
			int x = lpDestRect->left - lpSrcRect->left;
			int y = lpDestRect->top - lpSrcRect->top;
			int sx = 1;
			int sy = 1;

			if (dwFlags & DDBLT_DDFX) {
				assert(lpDestRect);
				if (lpDDBltFx->dwDDFX & DDBLTFX_MIRRORLEFTRIGHT) {
					x = lpDestRect->right + lpSrcRect->left;
					sx = -1;
				}
				if (lpDDBltFx->dwDDFX & DDBLTFX_MIRRORUPDOWN) {
					y = lpDestRect->bottom + lpSrcRect->top;
					sy = -1;
				}
			}

			r->Render(x, y, sx, sy, 0, &surface, &ddsp->surface);

			if (debug) {
				if (config("blt_dump_ddsp")) {
					ddsp->Dump();
				}
				if (config("blt_dump_this")) {
					this->Dump();
				}
			}
		}
		else if (dwFlags & DDBLT_COLORFILL) {
			if (!lpDestRect || (lpDestRect->left == 0)) {
				assert(!lpDDSrcSurface);
				DWORD fillColor = lpDDBltFx->dwFillColor;
				r->Clear(&surface, fillColor);
			}
		}

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

		if (debug) {
			bool disable_log = config("disable_log");

			if (!disable_log && lpSrcRect) {
				log(json_dump({
					{ "src.L", lpSrcRect->left },
					{ "src.R", lpSrcRect->right },
					{ "src.T", lpSrcRect->top },
					{ "src.B", lpSrcRect->bottom },
					{ "flags", dwFlags }
				}));
			}
		}


		DirectDrawSurfaceProxy *ddsp = (DirectDrawSurfaceProxy *)lpDDSrcSurface;

		int x = dwX - lpSrcRect->left;
		int y = dwY - lpSrcRect->top;

		r->Render(x, y, 1, 1, 0, &surface, &ddsp->surface);

		if (debug) {
			if (config("blt_dump_ddsp")) {
				ddsp->Dump();
			}
			if (config("blt_dump_this")) {
				this->Dump();
			}
		}

		return S_OK;


		//return BltGeneric(x, y, lpDDSrcSurface);
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

	void RenderToScreen() {
		r->RenderToScreen(&surface);
	}

	STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE3 a, DWORD b) {
		DDRAW_SURFACE_PROXY(Flip);

		assert(kind == FRONT_BUFFER);

		if (debug) {

			static int i = 0;
			++i;
			if (i % 5 == 0)
				GetConfig()->Reload();

		}

		r->Render(0, 0, 1, 1, -1, &surface, &back_buffer->surface);

		RenderToScreen();

		if (debug) {
			if (config("flip_dump"))
				Dump();
		}


		window->setVerticalSyncEnabled(true);
		window->display();

		//r->Clear(&surface, 0, 0, 0);

		if (debug) {
			int flip_sleep = config("flip_sleep");
			Sleep(flip_sleep);
		}

		window->setVerticalSyncEnabled(false);

		return S_OK;
	}
	STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS a, LPDIRECTDRAWSURFACE3 FAR *out_dds) {
		DDRAW_SURFACE_PROXY(GetAttachedSurface);

		auto ddsp = new DirectDrawSurfaceProxy(ddp, BACK_BUFFER, d_h, width, height);
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
// TODO: Support GDI drawing
#if 0
		if (!hdcMem) {
			assert(!memBm);
			HDC hdcScreen = ::GetDC(0);
			hdcMem = CreateCompatibleDC(hdcScreen);
			memBm = CreateCompatibleBitmap(hdcScreen, width, height);
			SelectObject(hdcMem, memBm);
		}

		*a = hdcMem;
#endif
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

		std::string s = "GetSurfaceDesc_" + std::to_string(d_h);

		Load(s, a);

		a->dwWidth = width;
		a->dwHeight = height;
		a->lPitch = width;

		return S_OK;
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) {
		DDRAW_SURFACE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(IsLost)(THIS) {
		//DDRAW_SURFACE_PROXY(IsLost);
		return 0;
	}

	STDMETHOD(Lock)(THIS_ LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d) {
		DDRAW_SURFACE_PROXY(Lock);

		r->DownloadSurfaceBuffer(&surface);

		Load("Lock_" + std::to_string(d_h), b);
		b->dwWidth = width;
		b->dwHeight = height;
		b->lPitch = width;

		b->lpSurface = surface.texture_buffer.data();

		return S_OK;
	}

	STDMETHOD(ReleaseDC)(THIS_ HDC hdc) {
		DDRAW_SURFACE_PROXY(ReleaseDC);

// TODO: Support GDI drawing
#if 0
		assert(hdc == hdcMem);

		BITMAPINFO bmInfo = { 0 };
		bmInfo.bmiHeader.biSize = sizeof(bmInfo.bmiHeader);

		GetDIBits(hdcMem, memBm, 0, 0, nullptr, &bmInfo, DIB_PAL_COLORS);

		int error = GetDIBits(hdcMem, memBm, 0, height, surface.texture_buffer.data(), &bmInfo, DIB_PAL_COLORS);
		assert(error != 0);
#endif
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

		assert(b->dwColorSpaceHighValue == 0 && b->dwColorSpaceLowValue == 0);

		return S_OK;
	}

	STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG) {
		DDRAW_SURFACE_PROXY(SetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}

	STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE a) {
		DDRAW_SURFACE_PROXY(SetPalette);

		ddpp = (DirectDrawPaletteProxy *)a;

		r->SetPalette(&ddpp->palette);

		return S_OK;
	}

	STDMETHOD(Unlock)(THIS_ LPVOID a) {
		DDRAW_SURFACE_PROXY(Unlock);

		r->UploadSurfaceBuffer(&surface);

		if (kind == FRONT_BUFFER) {
			r->RenderToScreen(&surface);
			window->display();
		}

		if (debug && config("unlock_dump_this"))
			this->Dump();

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

void render_to_screen(DirectDrawSurfaceProxy *ddsp) {
	ddsp->RenderToScreen();
	window->display();
}

void log_surface_call(const char *method, DirectDrawSurfaceProxy* ddsp) {
	if (!debug) return;

	bool disable_log = config("disable_log");

	if (disable_log) {
		return;
	}

	log_call("DirectDrawSurfaceProxy", method, ddsp);

	std::string t = "surface";

	if (ddsp->kind == DirectDrawSurfaceProxy::FRONT_BUFFER) {
		t = "frontbuffer";
	}
	else if (ddsp->kind == DirectDrawSurfaceProxy::BACK_BUFFER) {
		t = "backbuffer";
	}

	log(tag("span", { { "class", t } }, t) + '\n');
}

std::string read_file(std::string filename) {
	std::ifstream f(filename.c_str());
	std::stringstream ss;
	ss << f.rdbuf();
	return ss.str();
}

#define DDRAW_PROXY(method) log_call("DirectDrawProxy", #method, this);

struct DirectDrawProxy : public IDirectDraw2
{
	Renderer renderer;
	HWND hwnd = 0;

	DirectDrawSurfaceProxy *GetFrontBuffer() {
		return front_buffer;
	}

	DirectDrawSurfaceProxy *GetBackBuffer()
	{
		return back_buffer;
	}

	DirectDrawProxy(HWND hwnd, int window_width, int window_height)
		: renderer(hwnd, window_width, window_height), hwnd(hwnd)
	{
		r = &renderer;
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

	STDMETHOD(CreatePalette)(
		DWORD                   dwFlags,
		LPPALETTEENTRY          lpDDColorArray,
		LPDIRECTDRAWPALETTE FAR *lplpDDPalette,
		IUnknown FAR            *pUnkOuter
		) {
		DDRAW_PROXY(CreatePalette);

		auto ddpp = new DirectDrawPaletteProxy(&renderer);
		*lplpDDPalette = ddpp;

		ddpp->SetEntries(dwFlags, 0, DirectDrawPaletteProxy::PALETTE_SIZE, lpDDColorArray);

		return S_OK;
	}

	STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC ddsd, LPDIRECTDRAWSURFACE FAR *out_dds, IUnknown FAR *c) {
		DDRAW_PROXY(CreateSurface);

		DirectDrawSurfaceProxy::Kind kind = DirectDrawSurfaceProxy::NORMAL_SURFACE;

		int width = ddsd->dwWidth;
		int height = ddsd->dwHeight;

		if (ddsd->dwBackBufferCount) {
			kind = DirectDrawSurfaceProxy::FRONT_BUFFER;
			width = config("backbuffer_w");
			height = config("backbuffer_h");
		}

		size_t d_h = kind == DirectDrawSurfaceProxy::FRONT_BUFFER ? h(ddsd) : ddsd00_h(ddsd);

		DirectDrawSurfaceProxy *ddsp = new DirectDrawSurfaceProxy(this, kind, d_h, width, height);

		if (kind == DirectDrawSurfaceProxy::FRONT_BUFFER) {
			front_buffer = ddsp;
		}

		log(ptr(ddsp));

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

HWND get_hwnd(DirectDrawProxy *ddp) {
	return ddp->hwnd;
}

const char *html_head = R"HTML(
<head>
<link rel="stylesheet" type="text/css" href="style.css">
</head>
)HTML";

class Proxy : public IProxy {
	std::ofstream _log;

	DirectDrawProxy *ddp = nullptr;

public:

	Proxy() {
		if (debug) {
			std::string log_filename = config("log_filename");
			_log.open(log_filename.c_str());
		}

		_log << html_head;

		window = new sf::Window;
	}

	~Proxy() {}

	HWND CreateWindowExA(
		CreateWindowExA_type _CreateWindowExA,
		DWORD     dwExStyle,
		LPCTSTR   lpClassName,
		LPCTSTR   lpWindowName,
		DWORD     dwStyle,
		int       x,
		int       y,
		int       nWidth,
		int       nHeight,
		HWND      hWndParent,
		HMENU     hMenu,
		HINSTANCE hInstance,
		LPVOID    lpParam
		) {
		if (config("windowed")) {
			dwStyle = 0;
			nWidth = config("window_width");
			nHeight = config("window_height");
		}
		else {
			nWidth = config("fullscreen_width");
			nHeight = config("fullscreen_height");
		}

		HWND hWnd = _CreateWindowExA(
			dwExStyle,
			lpClassName,
			lpWindowName,
			dwStyle,
			x,
			y,
			nWidth,
			nHeight,
			hWndParent,
			hMenu,
			hInstance,
			lpParam
			);

		window->create(hWnd);

		bool vsync = config("vsync");

		window->setVerticalSyncEnabled(vsync);

		ddp = new DirectDrawProxy(hWnd, nWidth, nHeight);

		return hWnd;
	}

	HRESULT DirectDrawProxyCreate(
		DirectDrawCreatePtr _DirectDrawCreate,
		GUID *lpGUID,
		LPDIRECTDRAW *lplpDD,
		IUnknown     *pUnkOuter
		) {
		assert(ddp);

		*lplpDD = (IDirectDraw *)ddp;

		return S_OK;
	}

	void Log(std::string s) {
		if (!debug) return;

		bool disable_log = config("disable_log");

		if (disable_log) {
			return;
		}

		_log << s;
		_log.flush();
	}
};

PROXY_EXPORTS IProxy *GetProxy() {
	static Proxy *proxy = nullptr;
	if (!proxy) {
		proxy = new Proxy();
	}
	return proxy;
}
