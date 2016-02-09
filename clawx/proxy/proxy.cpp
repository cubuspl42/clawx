#define DLL_NAME "PROXY"

#include "proxy.h"

const unsigned MAGIC = 0x1a1b1c00;

#define DDRAW_PALETTE_PROXY(method) proxy_log("DirectDrawPaletteProxy", #method);

struct DirectDrawPaletteProxy : public IDirectDrawPalette
{
	static IDirectDrawPalette* unwrap(IDirectDrawPalette *ddp) {
		if (!ddp) return nullptr;
		DirectDrawPaletteProxy *ddpp = (DirectDrawPaletteProxy*)ddp;
		if (ddpp->magic != MAGIC) {
			proxy_log("!~~~~~~~ magic != MAGIC ~~~~~~~!");
		}
		return ddpp->ddp;
	}

	static IDirectDrawPalette* wrap(IDirectDrawPalette *ddp) {
		if (!ddp) return nullptr;
		DirectDrawPaletteProxy *ddpp = (DirectDrawPaletteProxy*)ddp;
		if (ddpp->magic == MAGIC) {
			proxy_log("!~~~~~~~ magic == MAGIC ~~~~~~~!");
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
		return ddp->GetEntries(a, b, c, d);
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, DWORD, LPPALETTEENTRY) {
		DDRAW_PALETTE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetEntries)(THIS_ DWORD a, DWORD b, DWORD c, LPPALETTEENTRY d) {
		DDRAW_PALETTE_PROXY(SetEntries);
		return ddp->SetEntries(a, b, c, d);
	}
};

#define DDRAW_SURFACE_PROXY(method) proxy_log("DirectDrawSurfaceProxy", #method);

#define _DDSCL_NORMAL 0

class DirectDrawSurfaceProxy : public IDirectDrawSurface3
{
	static IDirectDrawSurface3* unwrap(IDirectDrawSurface3 *dds3) {
		if (!dds3) return nullptr;
		DirectDrawSurfaceProxy *dds3p = (DirectDrawSurfaceProxy*)dds3;
		if (dds3p->magic != MAGIC) {
			proxy_log("!~~~~~~~ magic != MAGIC ~~~~~~~!");
		}
		return dds3p->dds3();
	}

	static IDirectDrawSurface3* wrap(IDirectDrawSurface3 *dds3) {
		if (!dds3) return nullptr;
		DirectDrawSurfaceProxy *dds3p = (DirectDrawSurfaceProxy*)dds3;
		if (dds3p->magic == MAGIC) {
			proxy_log("!~~~~~~~ magic == MAGIC ~~~~~~~!");
		}
		return new DirectDrawSurfaceProxy(dds3);
	}
public:
	int magic = MAGIC;
	IDirectDrawSurface *_dds1 = nullptr;
	IDirectDrawSurface3 *_dds3 = nullptr;

	IDirectDrawSurface3 *dds3() {
		if (!_dds3) {
			proxy_log("_dds3 = NULL");
		}
		return _dds3;
	}

	DirectDrawSurfaceProxy() {}

	DirectDrawSurfaceProxy(IDirectDrawSurface *dds1) {
		this->_dds1 = dds1;
	}

	DirectDrawSurfaceProxy(IDirectDrawSurface3 *dds3) {
		this->_dds3 = dds3;
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_SURFACE_PROXY(QueryInterface);
		proxy_log("this = ", this);

		auto result = _dds1->QueryInterface(riid, (void**)&_dds3);

		proxy_log("dds3 =", _dds3);

		proxy_log("<", this);

		*ppvObj = this;

		return S_OK;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_SURFACE_PROXY(AddRef);
		return dds3()->AddRef();
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_SURFACE_PROXY(Release);
		return dds3()->Release();
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
		proxy_log("this =", this);
		proxy_log("bdds3 =", c);
		auto result = dds3()->Blt(a, unwrap(b), c, d, e);
		return result;
	}
	STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD) {
		DDRAW_SURFACE_PROXY(BltBatch);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(BltFast)(THIS_ DWORD a, DWORD b, LPDIRECTDRAWSURFACE3 c, LPRECT d, DWORD e) {
		DDRAW_SURFACE_PROXY(BltFast);
		proxy_log("this = ", this);
		proxy_log("bdds3 = ", c);
		DirectDrawSurfaceProxy *ddsp = (DirectDrawSurfaceProxy*)c;
		auto result = dds3()->BltFast(a, b, unwrap(c), d, e);
		return result;
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
		proxy_log("this = ", this);
		proxy_log("fdds3 = ", a);
		DirectDrawSurfaceProxy *ddsp = (DirectDrawSurfaceProxy*)a;
		auto result = dds3()->Flip(unwrap(a), b);
		return result;
	}
	STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS a, LPDIRECTDRAWSURFACE3 FAR *b) {
		DDRAW_SURFACE_PROXY(GetAttachedSurface);
		proxy_log("this = ", this);
		LPDIRECTDRAWSURFACE3 adds3;
		auto result = dds3()->GetAttachedSurface(a, &adds3);
		if (adds3) {
			proxy_log("<", adds3);
		}
		else {
			proxy_log("< NULL");
		}
		proxy_log("adds3 = ", adds3);
#if _DDSCL_NORMAL
		auto p = new DirectDrawSurfaceProxy();
		//p->_dds1 = (IDirectDrawSurface*)0xAA00AA00;
		//p->_dds3 = (IDirectDrawSurface3*)0xAA00AA00;
		*b = p;
#else
		auto p = (DirectDrawSurfaceProxy*)wrap(adds3);
		*b = p;
#endif
		proxy_log("<", *b);
		return result;
#if _DDSCL_NORMAL
		return S_OK;
#else
		return result;
#endif
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
		return dds3()->GetDC(a);
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
		proxy_log("this = ", this);
		auto result = dds3()->GetPixelFormat(a);
		return result;
	}
	STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_SURFACE_PROXY(GetSurfaceDesc);
		proxy_log("this = ", this);
		auto result = dds3()->GetSurfaceDesc(a);
		proxy_log("<", a->lpSurface);
		return result;
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) {
		DDRAW_SURFACE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(IsLost)(THIS) {
		DDRAW_SURFACE_PROXY(IsLost);
		return dds3()->IsLost();
	}
	STDMETHOD(Lock)(THIS_ LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d) {
		DDRAW_SURFACE_PROXY(Lock);
		proxy_log("this = ", this);
		auto result = dds3()->Lock(a, b, c, d);
		if (b->lpSurface) {
			proxy_log("Lock:", b->lpSurface);
		}
		else {
			proxy_log("Lock: NULL");
		}
		return result;
	}
	STDMETHOD(ReleaseDC)(THIS_ HDC a) {
		DDRAW_SURFACE_PROXY(ReleaseDC);
		return dds3()->ReleaseDC(a);
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
		return dds3()->SetColorKey(a, b);
	}
	STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG) {
		DDRAW_SURFACE_PROXY(SetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE a) {
		DDRAW_SURFACE_PROXY(SetPalette);
		proxy_log("this = ", this);
		DirectDrawPaletteProxy *ddpp = (DirectDrawPaletteProxy*)a;
		auto result = dds3()->SetPalette(DirectDrawPaletteProxy::unwrap(a));
		return result;
	}
	STDMETHOD(Unlock)(THIS_ LPVOID a) {
		DDRAW_SURFACE_PROXY(Unlock);
		proxy_log("this = ", this);
		auto result = dds3()->Unlock(a);
		return result;
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

#define DDRAW_PROXY(method) proxy_log("DirectDrawProxy", #method);

struct DirectDrawProxy : public IDirectDraw2
{
	IDirectDraw *dd = nullptr;
	IDirectDraw2 *dd2 = nullptr;

	DirectDrawProxy(IDirectDraw *dd) {
		this->dd = dd;
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_PROXY(QueryInterface);

		proxy_log("this =", this);

		auto result = dd->QueryInterface(riid, (void**)(&dd2));

		proxy_log("<", this);

		*ppvObj = this;

		return result;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_PROXY(AddRef);
		return dd2->AddRef();
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_PROXY(Release);
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
		LPDIRECTDRAWPALETTE ddp;
		auto result = dd2->CreatePalette(a, b, &ddp, d);
		*c = new DirectDrawPaletteProxy(ddp);
		return result;
	}
	STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC a, LPDIRECTDRAWSURFACE FAR *b, IUnknown FAR *c) {
		DDRAW_PROXY(CreateSurface);
		proxy_log(">", a, b, c);
		proxy_log("> w:", a->dwWidth, "h:", a->dwHeight, "bbc:", a->dwBackBufferCount);

#if _DDSCL_NORMAL
		DDSURFACEDESC &ddsd = *a;
		if (ddsd.ddsCaps.dwCaps & DDSCAPS_PRIMARYSURFACE) {
			ddsd.dwFlags = DDSD_CAPS;
			ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
		}
#endif

		IDirectDrawSurface *dds = nullptr;
		auto result = dd2->CreateSurface(a, &dds, c);

		DirectDrawSurfaceProxy *ddsp = new DirectDrawSurfaceProxy(dds);
		*b = (IDirectDrawSurface*)ddsp;

		proxy_log("dds1 =", dds);
		if (result) {
			proxy_log("*", (void*)result);
		}
		else {
			proxy_log("* S_OK");
		}
		proxy_log("<", ddsp);

		return result;
	}
	STDMETHOD(DuplicateSurface)(THIS_ LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR *b) {
		DDRAW_PROXY(DuplicateSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumDisplayModes)(THIS_ DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMMODESCALLBACK d) {
		DDRAW_PROXY(EnumDisplayModes);
		proxy_log(">", a, b, c, d);
		auto result = dd2->EnumDisplayModes(a, b, c, d);
		proxy_log("*", result);
		return result;
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
		proxy_log(">", a, b);
		auto result = dd2->GetCaps(a, b);
		proxy_log("*", result);
		return result;
	}
	STDMETHOD(GetDisplayMode)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_PROXY(GetDisplayMode);
		proxy_log(">", a);
		auto result = dd2->GetDisplayMode(a);
		proxy_log("*", result);
		return result;
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
		return dd2->RestoreDisplayMode();
	}

	/*
	* Exclusive mode owner will be responsible for the entire primary surface.
	* GDI can be ignored. used with DD
	*/
#define DDSCL_FULLSCREEN                        0x00000001l

	/*
	* allow CTRL_ALT_DEL to work while in fullscreen exclusive mode
	*/
#define DDSCL_ALLOWREBOOT                       0x00000002l

	/*
	* prevents DDRAW from modifying the application window.
	* prevents DDRAW from minimize/restore the application window on activation.
	*/
#define DDSCL_NOWINDOWCHANGES                   0x00000004l

	/*
	* app wants to work as a regular Windows application
	*/
#define DDSCL_NORMAL                            0x00000008l

	STDMETHOD(SetCooperativeLevel)(THIS_ HWND hWnd, DWORD flags) {
		DDRAW_PROXY(SetCooperativeLevel);
		proxy_log(hWnd, flags);
#if _DDSCL_NORMAL
		flags = DDSCL_NORMAL;
#endif
		auto result = dd2->SetCooperativeLevel(hWnd, flags);
		proxy_log("*", result);
		return result;
	}
	STDMETHOD(SetDisplayMode)(THIS_ DWORD w, DWORD h, DWORD c, DWORD d, DWORD e) {
		DDRAW_PROXY(SetDisplayMode);
		proxy_log(">", w, h, c, d);
		w = 1920, h = 1080;
		auto result = dd2->SetDisplayMode(w, h, c, d, e);
		proxy_log("*", result);
		return result;
	}
	STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD a, HANDLE b) {
		DDRAW_PROXY(WaitForVerticalBlank);
		return dd2->WaitForVerticalBlank(a, b);
	}
	/*** Added in the v2 interface ***/
	STDMETHOD(GetAvailableVidMem)(THIS_ LPDDSCAPS, LPDWORD, LPDWORD) {
		DDRAW_PROXY(GetAvailableVidMem);
		return PROXY_UNIMPLEMENTED();
	};
};

PROXY_EXPORTS IDirectDraw *DirectDrawProxyCreate(IDirectDraw *dd) {
	return (IDirectDraw *)new DirectDrawProxy(dd);
}

std::ofstream proxy_log_file;

int proxy_init() {
	proxy_log_file.open("proxy_log.txt");
	proxy_log_file.rdbuf()->pubsetbuf(0, 0);
	return 0;
}

int _ = proxy_init();

PROXY_EXPORTS void *ProxyLog() {
	return &proxy_log_file;
}
