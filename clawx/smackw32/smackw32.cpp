#define DLL_NAME "SMACKW32"
#include "../proxy.h"
#include <windows.h>

#pragma pack(1)

HINSTANCE hLThis = 0;
HINSTANCE hL = 0;
FARPROC p[39] = {0};

BOOL WINAPI DllMain(HINSTANCE hInst,DWORD reason,LPVOID)
	{
	if (reason == DLL_PROCESS_ATTACH)
		{
		MessageBox(0, DLL_NAME, DLL_NAME, 0);


		hLThis = hInst;
		hL = LoadLibrary("_smackw32.dll");
		if (!hL) return false;


		p[0] = GetProcAddress(hL,"_SetDirectSoundHWND@4");
		p[1] = GetProcAddress(hL,"_SmackBufferBlit@32");
		p[2] = GetProcAddress(hL,"_SmackBufferClear@8");
		p[3] = GetProcAddress(hL,"_SmackBufferClose@4");
		p[4] = GetProcAddress(hL,"_SmackBufferCopyPalette@12");
		p[5] = GetProcAddress(hL,"_SmackBufferFocused@4");
		p[6] = GetProcAddress(hL,"_SmackBufferFromScreen@16");
		p[7] = GetProcAddress(hL,"_SmackBufferNewPalette@12");
		p[8] = GetProcAddress(hL,"_SmackBufferOpen@24");
		p[9] = GetProcAddress(hL,"_SmackBufferSetPalette@4");
		p[10] = GetProcAddress(hL,"_SmackBufferString@8");
		p[11] = GetProcAddress(hL,"_SmackBufferToBuffer@32");
		p[12] = GetProcAddress(hL,"_SmackBufferToBufferTrans@36");
		p[13] = GetProcAddress(hL,"_SmackClose@4");
		p[14] = GetProcAddress(hL,"_SmackColorRemap@16");
		p[15] = GetProcAddress(hL,"_SmackColorTrans@8");
		p[16] = GetProcAddress(hL,"_SmackDoFrame@4");
		p[17] = GetProcAddress(hL,"_SmackFrameRate@4");
		p[18] = GetProcAddress(hL,"_SmackGetTrackData@12");
		p[19] = GetProcAddress(hL,"_SmackGoto@8");
		p[20] = GetProcAddress(hL,"_SmackNextFrame@4");
		p[21] = GetProcAddress(hL,"_SmackOpen@12");
		p[22] = GetProcAddress(hL,"_SmackSetSystemRes@4");
		p[23] = GetProcAddress(hL,"_SmackSimulate@4");
		p[24] = GetProcAddress(hL,"_SmackSoundCheck@0");
		p[25] = GetProcAddress(hL,"_SmackSoundInTrack@8");
		p[26] = GetProcAddress(hL,"_SmackSoundOnOff@8");
		p[27] = GetProcAddress(hL,"_SmackSoundUseDW@12");
		p[28] = GetProcAddress(hL,"_SmackSoundUseDirectSound@4");
		p[29] = GetProcAddress(hL,"_SmackSoundUseMSS@4");
		p[30] = GetProcAddress(hL,"_SmackSoundUseWin@0");
		p[31] = GetProcAddress(hL,"_SmackSummary@8");
		p[32] = GetProcAddress(hL,"_SmackToBuffer@28");
		p[33] = GetProcAddress(hL,"_SmackToBufferRect@8");
		p[34] = GetProcAddress(hL,"_SmackToScreen@24");
		p[35] = GetProcAddress(hL,"_SmackVolumePan@16");
		p[36] = GetProcAddress(hL,"_SmackWait@4");
		p[37] = GetProcAddress(hL,"_TimerFunc@20");
		p[38] = GetProcAddress(hL,"_donemarker@20");


		}
	if (reason == DLL_PROCESS_DETACH)
		{
		FreeLibrary(hL);
		}

	return 1;
	}

// _SetDirectSoundHWND@4
extern "C" __declspec(naked) void __stdcall __E__0__()
	{
	PROXY(_SetDirectSoundHWND@4)
	__asm
		{
		jmp p[0*4];
		}
	}

// _SmackBufferBlit@32
extern "C" __declspec(naked) void __stdcall __E__1__()
	{
	PROXY(_SmackBufferBlit@32)
	__asm
		{
		jmp p[1*4];
		}
	}

// _SmackBufferClear@8
extern "C" __declspec(naked) void __stdcall __E__2__()
	{
	PROXY(_SmackBufferClear@8)
	__asm
		{
		jmp p[2*4];
		}
	}

// _SmackBufferClose@4
extern "C" __declspec(naked) void __stdcall __E__3__()
	{
	PROXY(_SmackBufferClose@4)
	__asm
		{
		jmp p[3*4];
		}
	}

// _SmackBufferCopyPalette@12
extern "C" __declspec(naked) void __stdcall __E__4__()
	{
	PROXY(_SmackBufferCopyPalette@12)
	__asm
		{
		jmp p[4*4];
		}
	}

// _SmackBufferFocused@4
extern "C" __declspec(naked) void __stdcall __E__5__()
	{
	PROXY(_SmackBufferFocused@4)
	__asm
		{
		jmp p[5*4];
		}
	}

// _SmackBufferFromScreen@16
extern "C" __declspec(naked) void __stdcall __E__6__()
	{
	PROXY(_SmackBufferFromScreen@16)
	__asm
		{
		jmp p[6*4];
		}
	}

// _SmackBufferNewPalette@12
extern "C" __declspec(naked) void __stdcall __E__7__()
	{
	PROXY(_SmackBufferNewPalette@12)
	__asm
		{
		jmp p[7*4];
		}
	}

// _SmackBufferOpen@24
extern "C" __declspec(naked) void __stdcall __E__8__()
	{
	PROXY(_SmackBufferOpen@24)
	__asm
		{
		jmp p[8*4];
		}
	}

// _SmackBufferSetPalette@4
extern "C" __declspec(naked) void __stdcall __E__9__()
	{
	PROXY(_SmackBufferSetPalette@4)
	__asm
		{
		jmp p[9*4];
		}
	}

// _SmackBufferString@8
extern "C" __declspec(naked) void __stdcall __E__10__()
	{
	PROXY(_SmackBufferString@8)
	__asm
		{
		jmp p[10*4];
		}
	}

// _SmackBufferToBuffer@32
extern "C" __declspec(naked) void __stdcall __E__11__()
	{
	PROXY(_SmackBufferToBuffer@32)
	__asm
		{
		jmp p[11*4];
		}
	}

// _SmackBufferToBufferTrans@36
extern "C" __declspec(naked) void __stdcall __E__12__()
	{
	PROXY(_SmackBufferToBufferTrans@36)
	__asm
		{
		jmp p[12*4];
		}
	}

// _SmackClose@4
extern "C" __declspec(naked) void __stdcall __E__13__()
	{
	PROXY(_SmackClose@4)
	__asm
		{
		jmp p[13*4];
		}
	}

// _SmackColorRemap@16
extern "C" __declspec(naked) void __stdcall __E__14__()
	{
	PROXY(_SmackColorRemap@16)
	__asm
		{
		jmp p[14*4];
		}
	}

// _SmackColorTrans@8
extern "C" __declspec(naked) void __stdcall __E__15__()
	{
	PROXY(_SmackColorTrans@8)
	__asm
		{
		jmp p[15*4];
		}
	}

// _SmackDoFrame@4
extern "C" __declspec(naked) void __stdcall __E__16__()
	{
	PROXY(_SmackDoFrame@4)
	__asm
		{
		jmp p[16*4];
		}
	}

// _SmackFrameRate@4
extern "C" __declspec(naked) void __stdcall __E__17__()
	{
	PROXY(_SmackFrameRate@4)
	__asm
		{
		jmp p[17*4];
		}
	}

// _SmackGetTrackData@12
extern "C" __declspec(naked) void __stdcall __E__18__()
	{
	PROXY(_SmackGetTrackData@12)
	__asm
		{
		jmp p[18*4];
		}
	}

// _SmackGoto@8
extern "C" __declspec(naked) void __stdcall __E__19__()
	{
	PROXY(_SmackGoto@8)
	__asm
		{
		jmp p[19*4];
		}
	}

// _SmackNextFrame@4
extern "C" __declspec(naked) void __stdcall __E__20__()
	{
	PROXY(_SmackNextFrame@4)
	__asm
		{
		jmp p[20*4];
		}
	}

// _SmackOpen@12
extern "C" __declspec(naked) void __stdcall __E__21__()
	{
	PROXY(_SmackOpen@12)
	__asm
		{
		jmp p[21*4];
		}
	}

// _SmackSetSystemRes@4
extern "C" __declspec(naked) void __stdcall __E__22__()
	{
	PROXY(_SmackSetSystemRes@4)
	__asm
		{
		jmp p[22*4];
		}
	}

// _SmackSimulate@4
extern "C" __declspec(naked) void __stdcall __E__23__()
	{
	PROXY(_SmackSimulate@4)
	__asm
		{
		jmp p[23*4];
		}
	}

// _SmackSoundCheck@0
extern "C" __declspec(naked) void __stdcall __E__24__()
	{
	PROXY(_SmackSoundCheck@0)
	__asm
		{
		jmp p[24*4];
		}
	}

// _SmackSoundInTrack@8
extern "C" __declspec(naked) void __stdcall __E__25__()
	{
	PROXY(_SmackSoundInTrack@8)
	__asm
		{
		jmp p[25*4];
		}
	}

// _SmackSoundOnOff@8
extern "C" __declspec(naked) void __stdcall __E__26__()
	{
	PROXY(_SmackSoundOnOff@8)
	__asm
		{
		jmp p[26*4];
		}
	}

// _SmackSoundUseDW@12
extern "C" __declspec(naked) void __stdcall __E__27__()
	{
	PROXY(_SmackSoundUseDW@12)
	__asm
		{
		jmp p[27*4];
		}
	}

// _SmackSoundUseDirectSound@4
extern "C" __declspec(naked) void __stdcall __E__28__()
	{
	PROXY(_SmackSoundUseDirectSound@4)
	__asm
		{
		jmp p[28*4];
		}
	}

// _SmackSoundUseMSS@4
extern "C" __declspec(naked) void __stdcall __E__29__()
	{
	PROXY(_SmackSoundUseMSS@4)
	__asm
		{
		jmp p[29*4];
		}
	}

// _SmackSoundUseWin@0
extern "C" __declspec(naked) void __stdcall __E__30__()
	{
	PROXY(_SmackSoundUseWin@0)
	__asm
		{
		jmp p[30*4];
		}
	}

// _SmackSummary@8
extern "C" __declspec(naked) void __stdcall __E__31__()
	{
	PROXY(_SmackSummary@8)
	__asm
		{
		jmp p[31*4];
		}
	}

// _SmackToBuffer@28
extern "C" __declspec(naked) void __stdcall __E__32__()
	{
	PROXY(_SmackToBuffer@28)
	__asm
		{
		jmp p[32*4];
		}
	}

// _SmackToBufferRect@8
extern "C" __declspec(naked) void __stdcall __E__33__()
	{
	PROXY(_SmackToBufferRect@8)
	__asm
		{
		jmp p[33*4];
		}
	}

// _SmackToScreen@24
extern "C" __declspec(naked) void __stdcall __E__34__()
	{
	PROXY(_SmackToScreen@24)
	__asm
		{
		jmp p[34*4];
		}
	}

// _SmackVolumePan@16
extern "C" __declspec(naked) void __stdcall __E__35__()
	{
	PROXY(_SmackVolumePan@16)
	__asm
		{
		jmp p[35*4];
		}
	}

// _SmackWait@4
extern "C" __declspec(naked) void __stdcall __E__36__()
	{
	PROXY(_SmackWait@4)
	__asm
		{
		jmp p[36*4];
		}
	}

// _TimerFunc@20
extern "C" __declspec(naked) void __stdcall __E__37__()
	{
	PROXY(_TimerFunc@20)
	__asm
		{
		jmp p[37*4];
		}
	}

// _donemarker@20
extern "C" __declspec(naked) void __stdcall __E__38__()
	{
	PROXY(_donemarker@20)
	__asm
		{
		jmp p[38*4];
		}
	}

