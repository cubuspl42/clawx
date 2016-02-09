#define DLL_NAME "DDRAW"

#include <windows.h>
#include <ddraw.h>
#include "../proxy/proxy.h"

#pragma pack(1)

HINSTANCE hLThis = 0;
HINSTANCE hL = 0;
FARPROC p[22] = { 0 };

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		log(DLL_NAME, "DLL_PROCESS_ATTACH");

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
		log(DLL_NAME, "DLL_PROCESS_DETACH");
		FreeLibrary(hL);
	}
	else if (reason == DLL_THREAD_ATTACH) {
		// log(DLL_NAME, "DLL_THREAD_ATTACH");
	}
	else if (reason == DLL_THREAD_DETACH) {
		// log(DLL_NAME, "DLL_THREAD_DETACH");
	}
	else {
		log(DLL_NAME " ??? ", reason);
	}

	return 1;
}

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

	IDirectDraw *dd;
	HRESULT result = _DirectDrawCreate(lpGUID, &dd, pUnkOuter);

	IDirectDraw *ddp = (IDirectDraw *)DirectDrawProxyCreate(dd);
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

