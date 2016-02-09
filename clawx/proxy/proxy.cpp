#define DLL_NAME "PROXY"

#include "proxy.h"
#include "dump.h"

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

const unsigned MAGIC = 0x1a1b1c00;

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

		return S_OK;
		return ddp->GetEntries(a, b, c, d);
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, DWORD, LPPALETTEENTRY) {
		DDRAW_PALETTE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetEntries)(THIS_ DWORD a, DWORD b, DWORD c, LPPALETTEENTRY d) {
		DDRAW_PALETTE_PROXY(SetEntries);
		return S_OK;
		return ddp->SetEntries(a, b, c, d);
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
	log(ddsd->ddpfPixelFormat.dwFourCC, ddsd->dwRefreshRate);
}

std::vector<char> buffer(1920 * 1080 * 32);

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
		return new DirectDrawSurfaceProxy(dds3);
	}
public:
	int magic = MAGIC;
	IDirectDrawSurface *_dds1 = nullptr;
	IDirectDrawSurface3 *_dds3 = nullptr;
	std::string t;
	DDSURFACEDESC ddsd;

	IDirectDrawSurface3 *dds3() {
		if (!_dds3) {
			log("_dds3 = NULL");
		}
		return _dds3;
	}

	// DirectDrawSurfaceProxy() {}

	DirectDrawSurfaceProxy(IDirectDrawSurface *dds1, LPDDSURFACEDESC ddsd) {
		t = current_time();
		this->_dds1 = dds1;
		this->ddsd = *ddsd;
	}

	DirectDrawSurfaceProxy(IDirectDrawSurface3 *dds3) {
		t = current_time();
		this->_dds3 = dds3;
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_SURFACE_PROXY(QueryInterface);
		log("this = ", this);







		// auto result = _dds1->QueryInterface(riid, (void**)&_dds3);

		log("dds3 =", _dds3);

		log("<", this);

		*ppvObj = this;

		return S_OK;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_SURFACE_PROXY(AddRef);
		return dds3()->AddRef();
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_SURFACE_PROXY(Release);
		return S_OK;
		//return dds3()->Release();
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

		return S_OK;

		auto result = dds3()->Blt(a, unwrap(b), c, d, e);
		return result;
	}
	STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD) {
		DDRAW_SURFACE_PROXY(BltBatch);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(BltFast)(THIS_ DWORD a, DWORD b, LPDIRECTDRAWSURFACE3 c, LPRECT d, DWORD e) {
		DDRAW_SURFACE_PROXY(BltFast);
		log("this = ", this);
		log("bdds3 = ", c);

		return S_OK;

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
		log("this = ", this);
		log("fdds3 = ", a);

		return S_OK;

		DirectDrawSurfaceProxy *ddsp = (DirectDrawSurfaceProxy*)a;
		auto result = dds3()->Flip(unwrap(a), b);
		return result;
	}
	STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS a, LPDIRECTDRAWSURFACE3 FAR *b) {
		DDRAW_SURFACE_PROXY(GetAttachedSurface);
		log("this = ", this);

		{
			auto p = new DirectDrawSurfaceProxy(nullptr);
			p->ddsd = ddsd;
			*b = p;
			log("<", p);
			return S_OK;
		}


		LPDIRECTDRAWSURFACE3 adds3;
		auto result = dds3()->GetAttachedSurface(a, &adds3);
		if (adds3) {
			log("<", adds3);
		}
		else {
			log("< NULL");
		}
		log("adds3 = ", adds3);
#if _DDSCL_NORMAL
		auto p = new DirectDrawSurfaceProxy();
		//p->_dds1 = (IDirectDrawSurface*)0xAA00AA00;
		//p->_dds3 = (IDirectDrawSurface3*)0xAA00AA00;
		*b = p;
#else
		auto p = (DirectDrawSurfaceProxy*)wrap(adds3);
		*b = p;
#endif
		log("<", *b);
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

		*a = (HDC)1;
		return S_OK;

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
		log("this = ", this);
		auto result = dds3()->GetPixelFormat(a);
		return result;
	}
	STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_SURFACE_PROXY(GetSurfaceDesc);
		log("this = ", this);

#if 0
		auto result = dds3()->GetSurfaceDesc(a);
		log("h(ddsd)", h(&ddsd));
		log_ddsd(&ddsd);
		log("h(a)", h(a));
		log_ddsd(a);
		log("<", a->lpSurface);
		return result;
#endif
		bool dump = false;

		if (ddsd.dwWidth) {
			DDSURFACEDESC ddsd00 = ddsd;
			ddsd00.dwWidth = ddsd00.dwHeight = 0;
			std::string s = "GetSurfaceDesc_" + std::to_string(h(&ddsd00));

			if (dump) {
				auto result = dds3()->GetSurfaceDesc(a);
				Dump(s, a);
			}
			else {
				Load(s, a);
				a->dwWidth = ddsd.dwWidth;
				a->dwHeight = ddsd.dwHeight;
			}
		}
		else {
			std::string s = "GetSurfaceDesc_" + std::to_string(h(&ddsd));

			if (dump) {
				auto result = dds3()->GetSurfaceDesc(a);
				Dump(s, a);
			}
			else {
				Load(s, a);
			}
		}

		log_ddsd(&ddsd);
		log_ddsd(a);

		return S_OK;
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) {
		DDRAW_SURFACE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(IsLost)(THIS) {
		DDRAW_SURFACE_PROXY(IsLost);
		return 0;
		return dds3()->IsLost();
	}
	STDMETHOD(Lock)(THIS_ LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d) {
		DDRAW_SURFACE_PROXY(Lock);
		log("this = ", this);
		log(ddsd.dwWidth, ddsd.dwHeight);
		*b = ddsd;
		b->lpSurface = buffer.data();
		return S_OK;

		auto result = dds3()->Lock(a, b, c, d);
		if (b->lpSurface) {
			log("Lock:", b->lpSurface);
		}
		else {
			log("Lock: NULL");
		}
		return result;
	}
	STDMETHOD(ReleaseDC)(THIS_ HDC a) {
		DDRAW_SURFACE_PROXY(ReleaseDC);
		return S_OK;
		//return dds3()->ReleaseDC(a);
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
		return S_OK;
		return dds3()->SetColorKey(a, b);
	}
	STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG) {
		DDRAW_SURFACE_PROXY(SetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE a) {
		DDRAW_SURFACE_PROXY(SetPalette);
		log("this = ", this);

		return S_OK;

		DirectDrawPaletteProxy *ddpp = (DirectDrawPaletteProxy*)a;
		auto result = dds3()->SetPalette(DirectDrawPaletteProxy::unwrap(a));
		return result;
	}
	STDMETHOD(Unlock)(THIS_ LPVOID a) {
		DDRAW_SURFACE_PROXY(Unlock);
		log("this = ", this);
		return S_OK;
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

#define DDRAW_PROXY(method) log("DirectDrawProxy", #method);

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

		log("this =", this);

		// auto result = dd->QueryInterface(riid, (void**)(&dd2));

		log("<", this);

		*ppvObj = this;

		return S_OK;
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
		//auto result = dd2->CreatePalette(a, b, &ddp, d);
		*c = new DirectDrawPaletteProxy(ddp);
		return S_OK;
	}
	STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC a, LPDIRECTDRAWSURFACE FAR *b, IUnknown FAR *c) {
		DDRAW_PROXY(CreateSurface);
		log(">", a, b, c);
		log("> w:", a->dwWidth, "h:", a->dwHeight, "bbc:", a->dwBackBufferCount);
		log_ddsd(a);


#if _DDSCL_NORMAL
		DDSURFACEDESC &ddsd = *a;
		if (ddsd.ddsCaps.dwCaps & DDSCAPS_PRIMARYSURFACE) {
			ddsd.dwFlags = DDSD_CAPS;
			ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
		}
#endif

		IDirectDrawSurface *dds = nullptr;
		HRESULT result = S_OK;
		// result = dd2->CreateSurface(a, &dds, c);

		DirectDrawSurfaceProxy *ddsp = new DirectDrawSurfaceProxy(dds, a);
		*b = (IDirectDrawSurface*)ddsp;

		log("dds1 =", dds);
		if (result) {
			log("*", (void*)result);
		}
		else {
			log("* S_OK");
		}
		log("<", ddsp);

		return result;
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

		DirectDrawProxy *self = (DirectDrawProxy *)b;
		log_ddsd(a);
		auto result = self->_EnumDisplayModesCallback(a, nullptr);
		return result;
	}

	STDMETHOD(EnumDisplayModes)(THIS_ DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMMODESCALLBACK d) {
		DDRAW_PROXY(EnumDisplayModes);
		log(">", a, b, c, d);

		DDSURFACEDESC ddsd;
		Load("EnumDisplayModes_0", &ddsd);
		d(&ddsd, nullptr);

		return S_OK;

		_EnumDisplayModesCallback = d;
		auto result = dd2->EnumDisplayModes(a, b, this, EnumDisplayModesCallback);
		log("*", result);
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
		log(">", a, b);
		HRESULT result = S_OK;
		//auto result = dd2->GetCaps(a, b);

		Load("GetCaps_a", a);
		Load("GetCaps_b", a);

		return result;

		if (a) log_flags("a->dwCaps", {
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
		}, a->dwCaps);
		if (a) log_flags("a->dwCaps2", {
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
		}, a->dwCaps2);
		if (b) log_flags("b->dwCaps", {
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
		}, b->dwCaps);
		if (b) log_flags("b->dwCaps2", {
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
		}, b->dwCaps2);

		log("*", result);
		return result;
	}
	STDMETHOD(GetDisplayMode)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_PROXY(GetDisplayMode);
		log(">", a);

#if 1
		//a->dwFlags = DDSD_WIDTH | DDSD_HEIGHT;
		//a->dwWidth = 640, a->dwHeight = 480;
		Load("EnumDisplayModes_0", a);

		return S_OK;
#endif

		auto result = dd2->GetDisplayMode(a);
		log_ddsd(a);
		log("*", result);
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

		return S_OK;

		log("hWnd =", hWnd);
		log_flags("flags", { 
			FLAG(DDSCL_FULLSCREEN),
			FLAG(DDSCL_ALLOWREBOOT),
			FLAG(DDSCL_NOWINDOWCHANGES),
			FLAG(DDSCL_NORMAL)	
		}, flags);

#if _DDSCL_NORMAL
		flags = DDSCL_NORMAL;
#endif

		// return S_OK;

		auto result = dd2->SetCooperativeLevel(hWnd, flags);
		log("*", result);
		return result;
	}
	STDMETHOD(SetDisplayMode)(THIS_ DWORD w, DWORD h, DWORD c, DWORD d, DWORD e) {
		DDRAW_PROXY(SetDisplayMode);
		log(">", w, h, c, d);
		w = 1920, h = 1080;

		return S_OK;

		auto result = dd2->SetDisplayMode(w, h, c, d, e);
		log("*", result);
		return result;
	}
	STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD a, HANDLE b) {
		DDRAW_PROXY(WaitForVerticalBlank);
		return S_OK;
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

std::ofstream log_file;

int proxy_init() {
	log_file.open("log.txt");
	log_file.rdbuf()->pubsetbuf(0, 0);
	return 0;
}

int _ = proxy_init();

PROXY_EXPORTS void *ProxyLog() {
	return &log_file;
}
