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
	if (reason == DLL_PROCESS_ATTACH)
	{
		MessageBox(0, "", "", 0);

		proxy_log(DLL_NAME, "DLL_PROCESS_ATTACH");

		hLThis = hInst;
		hL = LoadLibrary("C:\\Windows\\System32\\DDRAW.DLL");

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
	else if (reason == DLL_PROCESS_DETACH)
	{
		proxy_log(DLL_NAME, "DLL_PROCESS_DETACH");
		FreeLibrary(hL);
	}
	else if (reason == DLL_THREAD_ATTACH) {
		// proxy_log(DLL_NAME, "DLL_THREAD_ATTACH");
		++thread_number;
		thread_index = thread_number;
	}
	else if (reason == DLL_THREAD_DETACH) {
		// proxy_log(DLL_NAME, "DLL_THREAD_DETACH");
	}
	else {
		proxy_log(DLL_NAME " ??? ", reason);
	}

	return 1;
}

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

class DirectDrawSurfaceProxy : public IDirectDrawSurface3
{
	static IDirectDrawSurface3* unwrap(IDirectDrawSurface3 *dds3) {
		if (!dds3) return nullptr;
		DirectDrawSurfaceProxy *dds3p = (DirectDrawSurfaceProxy*)dds3;
		if (dds3p->magic != MAGIC) {
			proxy_log("!~~~~~~~ magic != MAGIC ~~~~~~~!");
		}
		return dds3p->dds3;
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
	IDirectDrawSurface *dds1 = nullptr;
	IDirectDrawSurface3 *dds3 = nullptr;

	DirectDrawSurfaceProxy(IDirectDrawSurface *dds1) {
		this->dds1 = dds1;
	}

	DirectDrawSurfaceProxy(IDirectDrawSurface3 *dds3) {
		this->dds3 = dds3;
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_SURFACE_PROXY(QueryInterface);
		proxy_log("this = ", this);

		// proxy_log(riid.Data1);

		auto result = dds1->QueryInterface(riid, (void**)&dds3);

		*ppvObj = this;

		return S_OK;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_SURFACE_PROXY(AddRef);
		return dds3->AddRef();
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_SURFACE_PROXY(Release);
		return dds3->Release();
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
		STACK_PUSH(Blt);
		auto result = dds3->Blt(a, unwrap(b), c, d, e);
		STACK_POP(Blt);
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
		STACK_PUSH(BltFast);
		DirectDrawSurfaceProxy *ddsp = (DirectDrawSurfaceProxy*)c;
		auto result = dds3->BltFast(a, b, unwrap(c), d, e);
		STACK_POP(BltFast);
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
		STACK_PUSH(Flip);
		proxy_log("this = ", this);
		proxy_log("fdds3 = ", a);
		DirectDrawSurfaceProxy *ddsp = (DirectDrawSurfaceProxy*)a;
		auto result = dds3->Flip(unwrap(a), b);
		STACK_POP(Flip);
		return result;
	}
	STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS a, LPDIRECTDRAWSURFACE3 FAR *b) {
		DDRAW_SURFACE_PROXY(GetAttachedSurface);
		proxy_log("this = ", this);
		STACK_PUSH(GetAttachedSurface);
		LPDIRECTDRAWSURFACE3 adds3;
		auto result = dds3->GetAttachedSurface(a, &adds3);
		*b = wrap(adds3);
		STACK_POP(GetAttachedSurface);
		return result;
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
		return dds3->GetDC(a);
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
		STACK_PUSH(GetPixelFormat);
		proxy_log("this = ", this);
		auto result = dds3->GetPixelFormat(a);
		STACK_POP(GetPixelFormat);
		return result;
	}
	STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_SURFACE_PROXY(GetSurfaceDesc);
		proxy_log("this = ", this);
		STACK_PUSH(GetSurfaceDesc);
		auto result = dds3->GetSurfaceDesc(a);
		STACK_POP(GetSurfaceDesc);
		return result;
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) {
		DDRAW_SURFACE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(IsLost)(THIS) {
		DDRAW_SURFACE_PROXY(IsLost);
		return dds3->IsLost();
	}
	STDMETHOD(Lock)(THIS_ LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d) {
		DDRAW_SURFACE_PROXY(Lock);
		proxy_log("this = ", this);
		STACK_PUSH(Lock);
		auto result = dds3->Lock(a, b, c, d);
		STACK_POP(Lock);
		return result;
	}
	STDMETHOD(ReleaseDC)(THIS_ HDC a) {
		DDRAW_SURFACE_PROXY(ReleaseDC);
		return dds3->ReleaseDC(a);
	}
	STDMETHOD(Restore)(THIS) {
		DDRAW_SURFACE_PROXY(Restore);
		return dds3->Restore();
	}
	STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER) {
		DDRAW_SURFACE_PROXY(SetClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetColorKey)(THIS_ DWORD a, LPDDCOLORKEY b) {
		DDRAW_SURFACE_PROXY(SetColorKey);
		return dds3->SetColorKey(a, b);
	}
	STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG) {
		DDRAW_SURFACE_PROXY(SetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE a) {
		DDRAW_SURFACE_PROXY(SetPalette);
		proxy_log("this = ", this);
		STACK_PUSH(SetPalette);
		DirectDrawPaletteProxy *ddpp = (DirectDrawPaletteProxy*)a;
		auto result = dds3->SetPalette(DirectDrawPaletteProxy::unwrap(a));
		STACK_POP(SetPalette);
		return result;
	}
	STDMETHOD(Unlock)(THIS_ LPVOID a) {
		DDRAW_SURFACE_PROXY(Unlock);
		proxy_log("this = ", this);
		STACK_PUSH(Unlock);
		auto result = dds3->Unlock(a);
		STACK_POP(Unlock);
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

IDirectDraw *dd = nullptr;
IDirectDraw2 *dd2 = nullptr;

class DirectDrawProxy : public IDirectDraw2
{
public:
	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_PROXY(QueryInterface);

		proxy_log("this =", this);
		proxy_log(std::hex, riid.Data1, riid.Data2, riid.Data3);

		auto result = dd->QueryInterface(riid, (void**)(&dd2));

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

		IDirectDrawSurface *dds = nullptr;
		auto result = dd2->CreateSurface(a, &dds, c);

		DirectDrawSurfaceProxy *ddsp = new DirectDrawSurfaceProxy(dds);

		proxy_log("dds =", dds);
		proxy_log("ddsp =", ddsp);

		proxy_log(std::dec, "w:", a->dwWidth, "h:", a->dwHeight, "bbc:", a->dwBackBufferCount);

		*b = (IDirectDrawSurface*)ddsp;
		return result;
	}
	STDMETHOD(DuplicateSurface)(THIS_ LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR *b) {
		DDRAW_PROXY(DuplicateSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumDisplayModes)(THIS_ DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMMODESCALLBACK d) {
		DDRAW_PROXY(EnumDisplayModes);
		return dd2->EnumDisplayModes(a, b, c, d);
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
		return dd2->GetCaps(a, b);
	}
	STDMETHOD(GetDisplayMode)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_PROXY(GetDisplayMode);
		return dd2->GetDisplayMode(a);
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

	STDMETHOD(SetCooperativeLevel)(THIS_ HWND a, DWORD b) {
		DDRAW_PROXY(SetCooperativeLevel);
		return dd2->SetCooperativeLevel(a, b);
	}
	STDMETHOD(SetDisplayMode)(THIS_ DWORD a, DWORD b, DWORD c, DWORD d, DWORD e) {
		DDRAW_PROXY(SetDisplayMode);
		return dd2->SetDisplayMode(a, b, c, d, e);
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

	F _DirectDrawCreate = (F)p[7];

	HRESULT result = _DirectDrawCreate(lpGUID, &dd, pUnkOuter);

	IDirectDraw *ddp = (IDirectDraw *)new DirectDrawProxy();
	*lplpDD = ddp;

	return result;
}

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

