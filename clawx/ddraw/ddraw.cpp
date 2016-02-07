#define DLL_NAME "DDRAW"
#define PROXY_LOG

#include <windows.h>
#include <ddraw.h>
#include "../proxy.h"

#pragma pack(1)

HINSTANCE hLThis = 0;
HINSTANCE hL = 0;
FARPROC p[22] = { 0 };

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{

	//proxy_log("DllMain", reason);

	if (reason == DLL_PROCESS_ATTACH)
	{
		MessageBox(0, DLL_NAME, DLL_NAME, 0);

		proxy_log("DllMain", "DLL_PROCESS_ATTACH");

		hLThis = hInst;
		hL = LoadLibrary("C:\\Windows\\System32\\DDRAW.DLL");

		proxy_log("DllMain", "Loaded", DLL_NAME);

		if (!hL) return false;

		p[0] = GetProcAddress(hL, "AcquireDDThreadLock");
		p[1] = GetProcAddress(hL, "CompleteCreateSysmemSurface");
		p[2] = GetProcAddress(hL, "D3DParseUnknownCommand");
		p[3] = GetProcAddress(hL, "DDGetAttachedSurfaceLcl");
		p[4] = GetProcAddress(hL, "DDInternalLock");
		p[5] = GetProcAddress(hL, "DDInternalUnlock");
		p[6] = GetProcAddress(hL, "DSoundHelp");
		p[7] = GetProcAddress(hL, "DirectDrawCreate");
		p[8] = GetProcAddress(hL, "DirectDrawCreateClipper");
		p[9] = GetProcAddress(hL, "DirectDrawCreateEx");
		p[10] = GetProcAddress(hL, "DirectDrawEnumerateA");
		p[11] = GetProcAddress(hL, "DirectDrawEnumerateExA");
		p[12] = GetProcAddress(hL, "DirectDrawEnumerateExW");
		p[13] = GetProcAddress(hL, "DirectDrawEnumerateW");
		p[14] = GetProcAddress(hL, "DllCanUnloadNow");
		p[15] = GetProcAddress(hL, "DllGetClassObject");
		p[16] = GetProcAddress(hL, "GetDDSurfaceLocal");
		p[17] = GetProcAddress(hL, "GetOLEThunkData");
		p[18] = GetProcAddress(hL, "GetSurfaceFromDC");
		p[19] = GetProcAddress(hL, "RegisterSpecialCase");
		p[20] = GetProcAddress(hL, "ReleaseDDThreadLock");
		p[21] = GetProcAddress(hL, "SetAppCompatData");

	}
	if (reason == DLL_PROCESS_DETACH)
	{
		proxy_log("DllMain", "DLL_PROCESS_DETACH");
		FreeLibrary(hL);
	}
	else if (reason == DLL_THREAD_ATTACH) {
		proxy_log("DllMain", "DLL_THREAD_ATTACH");
		++thread_number;
		thread_index = thread_number;
	}
	else if (reason == DLL_THREAD_DETACH) {
		proxy_log("DllMain", "DLL_THREAD_DETACH");
	}
	else {
		proxy_log("DllMain", reason);
	}

	return 1;
}

const unsigned MAGIC = 0x1a1b1c00;

#define DDRAW_PALETTE_PROXY(method) proxy_log("IDirectDrawPalettePrx", #method);

class IDirectDrawPalettePrx : public IDirectDrawPalette
{
public:
	int magic = MAGIC;
	IDirectDrawPalette *ddp;

	IDirectDrawPalettePrx(IDirectDrawPalette *ddp) {
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

#define DDRAW_SURFACE3_PROXY(method) proxy_log("IDirectDrawSurface3Prx", #method);

class IDirectDrawSurface3Prx : public IDirectDrawSurface3
{
	static IDirectDrawSurface3* unwrap(IDirectDrawSurface3 *dds3) {
		if (!dds3) return nullptr;
		IDirectDrawSurface3Prx *dds3p = (IDirectDrawSurface3Prx*)dds3;
		if (dds3p->magic != MAGIC) {
			proxy_log("!~~~~~~~ magic != MAGIC ~~~~~~~!");
		}
		return dds3p->dds3;
	}

	static IDirectDrawSurface3* wrap(IDirectDrawSurface3 *dds3) {
		if (!dds3) return nullptr;
		IDirectDrawSurface3Prx *dds3p = (IDirectDrawSurface3Prx*)dds3;
		if (dds3p->magic == MAGIC) {
			proxy_log("!~~~~~~~ magic == MAGIC ~~~~~~~!");
		}
		return new IDirectDrawSurface3Prx(dds3);
	}
public:
	int magic = MAGIC;
	IDirectDrawSurface3 *dds3 = nullptr;

	IDirectDrawSurface3Prx(IDirectDrawSurface3 *dds) {
		this->dds3 = dds;
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_SURFACE3_PROXY(QueryInterface);
		proxy_log("this = ", this);

		proxy_log(riid.Data1);

		*((IDirectDrawSurface3**)ppvObj) = this;

		return S_OK;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_SURFACE3_PROXY(AddRef);
		return dds3->AddRef();
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_SURFACE3_PROXY(Release);
		return dds3->Release();
	}
	/*** IDirectDrawSurface methods ***/
	STDMETHOD(AddAttachedSurface)(THIS_ LPDIRECTDRAWSURFACE3) {
		DDRAW_SURFACE3_PROXY(AddAttachedSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(AddOverlayDirtyRect)(THIS_ LPRECT) {
		DDRAW_SURFACE3_PROXY(AddOverlayDirtyRect);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Blt)(THIS_ LPRECT a, LPDIRECTDRAWSURFACE3 b, LPRECT c, DWORD d, LPDDBLTFX e) {
		DDRAW_SURFACE3_PROXY(Blt);
		proxy_log("this =", this);
		proxy_log("bdds3 =", c);
		STACK_PUSH(Blt);
		auto result = dds3->Blt(a, unwrap(b), c, d, e);
		STACK_POP(Blt);
		return result;
	}
	STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD) {
		DDRAW_SURFACE3_PROXY(BltBatch);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(BltFast)(THIS_ DWORD a, DWORD b, LPDIRECTDRAWSURFACE3 c, LPRECT d, DWORD e) {
		DDRAW_SURFACE3_PROXY(BltFast);
		proxy_log("this = ", this);
		proxy_log("bdds3 = ", c);
		STACK_PUSH(BltFast);
		IDirectDrawSurface3Prx *ddsp = (IDirectDrawSurface3Prx*)c;
		auto result = dds3->BltFast(a, b, unwrap(c), d, e);
		STACK_POP(BltFast);
		return result;
	}

	STDMETHOD(DeleteAttachedSurface)(THIS_ DWORD, LPDIRECTDRAWSURFACE3) {
		DDRAW_SURFACE3_PROXY(DeleteAttachedSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumAttachedSurfaces)(THIS_ LPVOID, LPDDENUMSURFACESCALLBACK) {
		DDRAW_SURFACE3_PROXY(EnumAttachedSurfaces);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumOverlayZOrders)(THIS_ DWORD, LPVOID, LPDDENUMSURFACESCALLBACK) {
		DDRAW_SURFACE3_PROXY(EnumOverlayZOrders);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE3 a, DWORD b) {
		DDRAW_SURFACE3_PROXY(Flip);
		STACK_PUSH(Flip);
		proxy_log("this = ", this);
		proxy_log("fdds3 = ", a);
		IDirectDrawSurface3Prx *ddsp = (IDirectDrawSurface3Prx*)a;
		auto result = dds3->Flip(unwrap(a), b);
		STACK_POP(Flip);
		return result;
	}
	STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS a, LPDIRECTDRAWSURFACE3 FAR *b) {
#if 0
		DDRAW_SURFACE3_PROXY(GetAttachedSurface);
		LPDIRECTDRAWSURFACE3 adds3;
		auto result = dds3->GetAttachedSurface(a, &adds3);
		proxy_log("adds3 =", adds3);
		*b = adds3;
		return result;
#else
		proxy_log("this = ", this);
		STACK_PUSH(GetAttachedSurface);
		LPDIRECTDRAWSURFACE3 adds3;
		auto result = dds3->GetAttachedSurface(a, &adds3);
		*b = wrap(adds3);
		STACK_POP(GetAttachedSurface);
		return result;
#endif
	}
	STDMETHOD(GetBltStatus)(THIS_ DWORD) {
		DDRAW_SURFACE3_PROXY(GetBltStatus);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetCaps)(THIS_ LPDDSCAPS) {
		DDRAW_SURFACE3_PROXY(GetCaps);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetClipper)(THIS_ LPDIRECTDRAWCLIPPER FAR*) {
		DDRAW_SURFACE3_PROXY(GetClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetColorKey)(THIS_ DWORD, LPDDCOLORKEY) {
		DDRAW_SURFACE3_PROXY(GetColorKey);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetDC)(THIS_ HDC FAR *a) {
		DDRAW_SURFACE3_PROXY(GetDC);
		return dds3->GetDC(a);
	}
	STDMETHOD(GetFlipStatus)(THIS_ DWORD) {
		DDRAW_SURFACE3_PROXY(GetFlipStatus);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetOverlayPosition)(THIS_ LPLONG, LPLONG) {
		DDRAW_SURFACE3_PROXY(GetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetPalette)(THIS_ LPDIRECTDRAWPALETTE FAR*) {
		DDRAW_SURFACE3_PROXY(GetPalette);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetPixelFormat)(THIS_ LPDDPIXELFORMAT a) {
		DDRAW_SURFACE3_PROXY(GetPixelFormat);
		STACK_PUSH(GetPixelFormat);
		proxy_log("this = ", this);
		auto result = dds3->GetPixelFormat(a);
		STACK_POP(GetPixelFormat);
		return result;
	}
	STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_SURFACE3_PROXY(GetSurfaceDesc);
		proxy_log("this = ", this);
		STACK_PUSH(GetSurfaceDesc);
		auto result = dds3->GetSurfaceDesc(a);
		STACK_POP(GetSurfaceDesc);
		return result;
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) {
		DDRAW_SURFACE3_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(IsLost)(THIS) {
		DDRAW_SURFACE3_PROXY(IsLost);
		return dds3->IsLost();
	}
	STDMETHOD(Lock)(THIS_ LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d) {
		DDRAW_SURFACE3_PROXY(Lock);
		proxy_log("this = ", this);
		STACK_PUSH(Lock);
		auto result = dds3->Lock(a, b, c, d);
		STACK_POP(Lock);
		return result;
	}
	STDMETHOD(ReleaseDC)(THIS_ HDC a) {
		DDRAW_SURFACE3_PROXY(ReleaseDC);
		return dds3->ReleaseDC(a);
	}
	STDMETHOD(Restore)(THIS) {
		DDRAW_SURFACE3_PROXY(Restore);
		return dds3->Restore();
	}
	STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER) {
		DDRAW_SURFACE3_PROXY(SetClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetColorKey)(THIS_ DWORD a, LPDDCOLORKEY b) {
		DDRAW_SURFACE3_PROXY(SetColorKey);
		return dds3->SetColorKey(a, b);
	}
	STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG) {
		DDRAW_SURFACE3_PROXY(SetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE a) {
		DDRAW_SURFACE3_PROXY(SetPalette);
		proxy_log("this = ", this);
		STACK_PUSH(SetPalette);
		IDirectDrawPalettePrx *ddpp = (IDirectDrawPalettePrx*)a;
		auto result = dds3->SetPalette(ddpp->magic == MAGIC ? ddpp->ddp : a);
		STACK_POP(SetPalette);
		return result;
	}
	STDMETHOD(Unlock)(THIS_ LPVOID a) {
		DDRAW_SURFACE3_PROXY(Unlock);
		proxy_log("this = ", this);
		STACK_PUSH(Unlock);
		auto result = dds3->Unlock(a);
		STACK_POP(Unlock);
		return result;
	}
	STDMETHOD(UpdateOverlay)(THIS_ LPRECT, LPDIRECTDRAWSURFACE3, LPRECT, DWORD, LPDDOVERLAYFX) {
		DDRAW_SURFACE3_PROXY(UpdateOverlay);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(UpdateOverlayDisplay)(THIS_ DWORD) {
		DDRAW_SURFACE3_PROXY(UpdateOverlayDisplay);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(UpdateOverlayZOrder)(THIS_ DWORD, LPDIRECTDRAWSURFACE3) {
		DDRAW_SURFACE3_PROXY(UpdateOverlayZOrder);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetDDInterface)(THIS_ LPVOID FAR *) {
		DDRAW_SURFACE3_PROXY(GetDDInterface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(PageLock)(THIS_ DWORD) {
		DDRAW_SURFACE3_PROXY(PageLock);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(PageUnlock)(THIS_ DWORD) {
		DDRAW_SURFACE3_PROXY(PageUnlock);
		return PROXY_UNIMPLEMENTED();
	}
	/*** Added in the V3 interface ***/
	STDMETHOD(SetSurfaceDesc)(THIS_ LPDDSURFACEDESC a, DWORD b) {
		DDRAW_SURFACE3_PROXY(SetSurfaceDesc);
		return PROXY_UNIMPLEMENTED();
	}
};

#define DDRAW_SURFACE_PROXY(method) proxy_log("IDirectDrawSurfacePrx", #method);

struct IDirectDrawSurfacePrx : public IDirectDrawSurface
{
	int magic = MAGIC;
	IDirectDrawSurface *dds1;

	IDirectDrawSurfacePrx(IDirectDrawSurface *dds) {
		this->dds1 = dds;
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(QueryInterface);

		proxy_log("this =", this);
		proxy_log("this->dds1 =", dds1);

		proxy_log(std::hex, riid.Data1);

		IDirectDrawSurface3 *dds3 = nullptr;
		auto result = dds1->QueryInterface(riid, (void**)&dds3);

		proxy_log("dds3 =", dds3);

		IDirectDrawSurface3Prx *dds3p = new IDirectDrawSurface3Prx(dds3);

		proxy_log("dds3p =", dds3p);

		*((IDirectDrawSurface3**)ppvObj) = dds3p;
		return result;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(AddRef);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(Release);
		return dds1->Release();
	}
	/*** IDirectDrawSurface methods ***/
	STDMETHOD(AddAttachedSurface)(THIS_ LPDIRECTDRAWSURFACE) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(AddAttachedSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(AddOverlayDirtyRect)(THIS_ LPRECT) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(AddOverlayDirtyRect);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Blt)(THIS_ LPRECT, LPDIRECTDRAWSURFACE, LPRECT, DWORD, LPDDBLTFX) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(Blt);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(BltBatch);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(BltFast)(THIS_ DWORD, DWORD, LPDIRECTDRAWSURFACE, LPRECT, DWORD) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(BltFast);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(DeleteAttachedSurface)(THIS_ DWORD, LPDIRECTDRAWSURFACE) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(DeleteAttachedSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumAttachedSurfaces)(THIS_ LPVOID, LPDDENUMSURFACESCALLBACK) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(EnumAttachedSurfaces);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumOverlayZOrders)(THIS_ DWORD, LPVOID, LPDDENUMSURFACESCALLBACK) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(EnumOverlayZOrders);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE a, DWORD b) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(Flip);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS, LPDIRECTDRAWSURFACE FAR *) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(GetAttachedSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetBltStatus)(THIS_ DWORD) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(GetBltStatus);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetCaps)(THIS_ LPDDSCAPS) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(GetCaps);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetClipper)(THIS_ LPDIRECTDRAWCLIPPER FAR*) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(GetClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetColorKey)(THIS_ DWORD, LPDDCOLORKEY) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(GetColorKey);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetDC)(THIS_ HDC FAR *) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(GetDC);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetFlipStatus)(THIS_ DWORD) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(GetFlipStatus);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetOverlayPosition)(THIS_ LPLONG, LPLONG) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(GetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetPalette)(THIS_ LPDIRECTDRAWPALETTE FAR*) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(GetPalette);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetPixelFormat)(THIS_ LPDDPIXELFORMAT) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(GetPixelFormat);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(GetSurfaceDesc);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(IsLost)(THIS) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(IsLost);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Lock)(THIS_ LPRECT, LPDDSURFACEDESC, DWORD, HANDLE) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(Lock);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(ReleaseDC)(THIS_ HDC) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(ReleaseDC);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Restore)(THIS) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(Restore);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(SetClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetColorKey)(THIS_ DWORD, LPDDCOLORKEY) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(SetColorKey);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(SetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE a) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(SetPalette);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Unlock)(THIS_ LPVOID) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(Unlock);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(UpdateOverlay)(THIS_ LPRECT, LPDIRECTDRAWSURFACE, LPRECT, DWORD, LPDDOVERLAYFX) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(UpdateOverlay);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(UpdateOverlayDisplay)(THIS_ DWORD) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(UpdateOverlayDisplay);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(UpdateOverlayZOrder)(THIS_ DWORD, LPDIRECTDRAWSURFACE) {
		/* ~~~~~~~~ IDirectDrawSurface ~~~~~~~~ */
		DDRAW_SURFACE_PROXY(UpdateOverlayZOrder);
		return PROXY_UNIMPLEMENTED();
	}
};

#define DDRAW2_PROXY(method) proxy_log("IDirectDraw2Prx", #method);

IDirectDraw2 *dd2;

class IDirectDraw2Prx : public IDirectDraw2
{
public:
	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW2_PROXY(QueryInterface);

		proxy_log("this =", this);
		proxy_log(std::hex, riid.Data1, riid.Data2, riid.Data3);

		return dd2->QueryInterface(riid, ppvObj);
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW2_PROXY(AddRef);
		return dd2->AddRef();
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW2_PROXY(Release);
		return dd2->Release();
	}
	/*** IDirectDraw methods ***/
	STDMETHOD(Compact)(THIS) {
		DDRAW2_PROXY(Compact);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(CreateClipper)(THIS_ DWORD a, LPDIRECTDRAWCLIPPER FAR* b, IUnknown FAR *c) {
		DDRAW2_PROXY(CreateClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(CreatePalette)(THIS_ DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR* c, IUnknown FAR *d) {
		DDRAW2_PROXY(CreatePalette);
		return dd2->CreatePalette(a, b, c, d);
		// --------------------------
		LPDIRECTDRAWPALETTE ddp;
		auto result = dd2->CreatePalette(a, b, &ddp, d);
		*c = new IDirectDrawPalettePrx(ddp);
		return result;
	}
	STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC a, LPDIRECTDRAWSURFACE FAR *b, IUnknown FAR *c) {
		DDRAW2_PROXY(CreateSurface);

		IDirectDrawSurface *dds = nullptr;
		auto result = dd2->CreateSurface(a, &dds, c);
		IDirectDrawSurfacePrx *ddsp = new IDirectDrawSurfacePrx(dds);

		proxy_log("dds =", dds);
		proxy_log("ddsp =", ddsp);

		proxy_log(std::dec, "w:", a->dwWidth, "h:", a->dwHeight, "bbc:", a->dwBackBufferCount);

		*b = (IDirectDrawSurface*)ddsp;
		return result;
	}
	STDMETHOD(DuplicateSurface)(THIS_ LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR *b) {
		DDRAW2_PROXY(DuplicateSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumDisplayModes)(THIS_ DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMMODESCALLBACK d) {
		DDRAW2_PROXY(EnumDisplayModes);
		return dd2->EnumDisplayModes(a, b, c, d);
	}
	STDMETHOD(EnumSurfaces)(THIS_ DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMSURFACESCALLBACK) {
		DDRAW2_PROXY(EnumSurfaces);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(FlipToGDISurface)(THIS) {
		DDRAW2_PROXY(FlipToGDISurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetCaps)(THIS_ LPDDCAPS a, LPDDCAPS b) {
		DDRAW2_PROXY(GetCaps);
		return dd2->GetCaps(a, b);
	}
	STDMETHOD(GetDisplayMode)(THIS_ LPDDSURFACEDESC a) {
		DDRAW2_PROXY(GetDisplayMode);
		return dd2->GetDisplayMode(a);
	}
	STDMETHOD(GetFourCCCodes)(THIS_  LPDWORD, LPDWORD) {
		DDRAW2_PROXY(GetFourCCCodes);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetGDISurface)(THIS_ LPDIRECTDRAWSURFACE FAR *) {
		DDRAW2_PROXY(GetGDISurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetMonitorFrequency)(THIS_ LPDWORD) {
		DDRAW2_PROXY(GetMonitorFrequency);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetScanLine)(THIS_ LPDWORD) {
		DDRAW2_PROXY(GetScanLine);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetVerticalBlankStatus)(THIS_ LPBOOL) {
		DDRAW2_PROXY(GetVerticalBlankStatus);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Initialize)(THIS_ GUID FAR *) {
		DDRAW2_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(RestoreDisplayMode)(THIS) {
		DDRAW2_PROXY(RestoreDisplayMode);
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

	STDMETHOD(SetCooperativeLevel)(THIS_ HWND a, DWORD b) {
		DDRAW2_PROXY(SetCooperativeLevel);
		return dd2->SetCooperativeLevel(a, b);
	}
	STDMETHOD(SetDisplayMode)(THIS_ DWORD a, DWORD b, DWORD c, DWORD d, DWORD e) {
		DDRAW2_PROXY(SetDisplayMode);
		return dd2->SetDisplayMode(a, b, c, d, e);
	}
	STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD a, HANDLE b) {
		DDRAW2_PROXY(WaitForVerticalBlank);
		return dd2->WaitForVerticalBlank(a, b);
	}
	/*** Added in the v2 interface ***/
	STDMETHOD(GetAvailableVidMem)(THIS_ LPDDSCAPS, LPDWORD, LPDWORD) {
		DDRAW2_PROXY(GetAvailableVidMem);
		return PROXY_UNIMPLEMENTED();
	};
};

#define DDRAW_PROXY(method) proxy_log("IDirectDrawPrx", #method);

IDirectDraw *dd = nullptr;

struct IDirectDrawPrx : IDirectDraw
{
	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_PROXY(QueryInterface);

		proxy_log("this =", this);
		proxy_log(std::hex, riid.Data1, riid.Data2, riid.Data3);

		auto result = dd->QueryInterface(riid, (void**)(&dd2));
		*((IDirectDraw2**)ppvObj) = new IDirectDraw2Prx();
		return result;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_PROXY(AddRef);
		return dd->AddRef();
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_PROXY(Release);
		return dd->Release();
	}
	/*** IDirectDraw methods ***/
	STDMETHOD(Compact)(THIS) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(Compact);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(CreateClipper)(THIS_ DWORD a, LPDIRECTDRAWCLIPPER FAR* b, IUnknown FAR *c) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(CreateClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(CreatePalette)(THIS_ DWORD, LPPALETTEENTRY a, LPDIRECTDRAWPALETTE FAR* b, IUnknown FAR *c) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(CreatePalette);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC a, LPDIRECTDRAWSURFACE FAR *b, IUnknown FAR *c) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(CreateSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(DuplicateSurface)(THIS_ LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR *b) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(DuplicateSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumDisplayModes)(THIS_ DWORD, LPDDSURFACEDESC a, LPVOID b, LPDDENUMMODESCALLBACK c) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(EnumDisplayModes);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumSurfaces)(THIS_ DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMSURFACESCALLBACK) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(EnumSurfaces);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(FlipToGDISurface)(THIS) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(FlipToGDISurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetCaps)(THIS_ LPDDCAPS a, LPDDCAPS b) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(GetCaps);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetDisplayMode)(THIS_ LPDDSURFACEDESC a) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(GetDisplayMode);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetFourCCCodes)(THIS_  LPDWORD, LPDWORD) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(GetFourCCCodes);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetGDISurface)(THIS_ LPDIRECTDRAWSURFACE FAR *) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(GetGDISurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetMonitorFrequency)(THIS_ LPDWORD) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(GetMonitorFrequency);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetScanLine)(THIS_ LPDWORD) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(GetScanLine);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetVerticalBlankStatus)(THIS_ LPBOOL) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(GetVerticalBlankStatus);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Initialize)(THIS_ GUID FAR *) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(RestoreDisplayMode)(THIS) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(RestoreDisplayMode);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetCooperativeLevel)(THIS_ HWND, DWORD) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(SetCooperativeLevel);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetDisplayMode)(THIS_ DWORD, DWORD, DWORD) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(SetDisplayMode);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD, HANDLE) {
		/* ~~~~~~~~ IDirectDraw ~~~~~~~~ */
		DDRAW_PROXY(WaitForVerticalBlank);
		return PROXY_UNIMPLEMENTED();
	}
};

#if 1

HRESULT result;

// DirectDrawCreate
extern "C" HRESULT WINAPI __E__7__(
	GUID         *lpGUID,
	LPDIRECTDRAW *lplpDD,
	IUnknown     *pUnkOuter
) {
	PROXY(DirectDrawCreate)

	typedef HRESULT(WINAPI *F)(
		GUID         *lpGUID,
		LPDIRECTDRAW *lplpDD,
		IUnknown     *pUnkOuter
	);
	F f = (F)p[7];

	// HRESULT result = f(lpGUID, lplpDD, pUnkOuter);
	HRESULT result = f(lpGUID, &dd, pUnkOuter);

	IDirectDraw *ddp = new IDirectDrawPrx();
	*lplpDD = ddp;

	return result;
}

#else

// DirectDrawCreate
extern "C" __declspec(naked) HRESULT __stdcall __E__7__(
	_In_  GUID FAR         *lpGUID,
	_Out_ LPDIRECTDRAW FAR *lplpDD,
	_In_  IUnknown FAR     *pUnkOuter
	)
{

	PROXY(DirectDrawCreate)
		__asm
	{
		jmp p[7 * 4];
	}
}

#endif

// AcquireDDThreadLock
extern "C" __declspec(naked) void __stdcall __E__0__()
{
	PROXY(AcquireDDThreadLock)
		__asm
	{
		jmp p[0 * 4];
	}
}

// CompleteCreateSysmemSurface
extern "C" __declspec(naked) void __stdcall __E__1__()
{
	PROXY(CompleteCreateSysmemSurface)
		__asm
	{
		jmp p[1 * 4];
	}
}

// D3DParseUnknownCommand
extern "C" __declspec(naked) void __stdcall __E__2__()
{
	PROXY(D3DParseUnknownCommand)
		__asm
	{
		jmp p[2 * 4];
	}
}

// DDGetAttachedSurfaceLcl
extern "C" __declspec(naked) void __stdcall __E__3__()
{
	PROXY(DDGetAttachedSurfaceLcl)
		__asm
	{
		jmp p[3 * 4];
	}
}

// DDInternalLock
extern "C" __declspec(naked) void __stdcall __E__4__()
{
	PROXY(DDInternalLock)
		__asm
	{
		jmp p[4 * 4];
	}
}

// DDInternalUnlock
extern "C" __declspec(naked) void __stdcall __E__5__()
{
	PROXY(DDInternalUnlock)
		__asm
	{
		jmp p[5 * 4];
	}
}

// DSoundHelp
extern "C" __declspec(naked) void __stdcall __E__6__()
{
	PROXY(DSoundHelp)
		__asm
	{
		jmp p[6 * 4];
	}
}

// DirectDrawCreateClipper
extern "C" __declspec(naked) void __stdcall __E__8__()
{
	PROXY(DirectDrawCreateClipper)
		__asm
	{
		jmp p[8 * 4];
	}
}

// DirectDrawCreateEx
extern "C" __declspec(naked) void __stdcall __E__9__()
{
	PROXY(DirectDrawCreateEx)
		__asm
	{
		jmp p[9 * 4];
	}
}

// DirectDrawEnumerateA
extern "C" __declspec(naked) void __stdcall __E__10__()
{
	PROXY(DirectDrawEnumerateA)
		__asm
	{
		jmp p[10 * 4];
	}
}

// DirectDrawEnumerateExA
extern "C" __declspec(naked) void __stdcall __E__11__()
{
	PROXY(DirectDrawEnumerateExA)
		__asm
	{
		jmp p[11 * 4];
	}
}

// DirectDrawEnumerateExW
extern "C" __declspec(naked) void __stdcall __E__12__()
{
	PROXY(DirectDrawEnumerateExW)
		__asm
	{
		jmp p[12 * 4];
	}
}

// DirectDrawEnumerateW
extern "C" __declspec(naked) void __stdcall __E__13__()
{
	PROXY(DirectDrawEnumerateW)
		__asm
	{
		jmp p[13 * 4];
	}
}

// DllCanUnloadNow
extern "C" __declspec(naked) void __stdcall __E__14__()
{
	PROXY(DllCanUnloadNow)
		__asm
	{
		jmp p[14 * 4];
	}
}

// DllGetClassObject
extern "C" __declspec(naked) void __stdcall __E__15__()
{
	PROXY(DllGetClassObject)
		__asm
	{
		jmp p[15 * 4];
	}
}

// GetDDSurfaceLocal
extern "C" __declspec(naked) void __stdcall __E__16__()
{
	PROXY(GetDDSurfaceLocal)
		__asm
	{
		jmp p[16 * 4];
	}
}

// GetOLEThunkData
extern "C" __declspec(naked) void __stdcall __E__17__()
{
	PROXY(GetOLEThunkData)
		__asm
	{
		jmp p[17 * 4];
	}
}

// GetSurfaceFromDC
extern "C" __declspec(naked) void __stdcall __E__18__()
{
	PROXY(GetSurfaceFromDC)
		__asm
	{
		jmp p[18 * 4];
	}
}

// RegisterSpecialCase
extern "C" __declspec(naked) void __stdcall __E__19__()
{
	PROXY(RegisterSpecialCase)
		__asm
	{
		jmp p[19 * 4];
	}
}

// ReleaseDDThreadLock
extern "C" __declspec(naked) void __stdcall __E__20__()
{
	PROXY(ReleaseDDThreadLock)
		__asm
	{
		jmp p[20 * 4];
	}
}

// SetAppCompatData
extern "C" __declspec(naked) void __stdcall __E__21__()
{
	PROXY(SetAppCompatData)
		__asm
	{
		jmp p[21 * 4];
	}
}

