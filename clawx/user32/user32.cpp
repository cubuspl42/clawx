#define DLL_NAME "USER32"

#include "../proxy/proxy.h"
#include <windows.h>

#pragma pack(1)

HINSTANCE hLThis = 0;
HINSTANCE hL = 0;
FARPROC p[1025] = { 0 };

#define PROXY(a)

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		log(DLL_NAME, "DLL_PROCESS_ATTACH");

		hLThis = hInst;
		hL = LoadLibrary("C:\\Windows\\System32\\USER32.DLL");

		if (!hL) return false;

		p[0] = GetProcAddress(hL, "ActivateKeyboardLayout");
		p[1] = GetProcAddress(hL, "AddClipboardFormatListener");
		p[2] = GetProcAddress(hL, "AdjustWindowRect");
		p[3] = GetProcAddress(hL, "AdjustWindowRectEx");
		p[4] = GetProcAddress(hL, "AlignRects");
		p[5] = GetProcAddress(hL, "AllowForegroundActivation");
		p[6] = GetProcAddress(hL, "AllowSetForegroundWindow");
		p[7] = GetProcAddress(hL, "AnimateWindow");
		p[8] = GetProcAddress(hL, "AnyPopup");
		p[9] = GetProcAddress(hL, "AppendMenuA");
		p[10] = GetProcAddress(hL, "AppendMenuW");
		p[11] = GetProcAddress(hL, "ArrangeIconicWindows");
		p[12] = GetProcAddress(hL, "AttachThreadInput");
		p[13] = GetProcAddress(hL, "BeginDeferWindowPos");
		p[14] = GetProcAddress(hL, "BeginPaint");
		p[15] = GetProcAddress(hL, "BlockInput");
		p[16] = GetProcAddress(hL, "BringWindowToTop");
		p[17] = GetProcAddress(hL, "BroadcastSystemMessage");
		p[18] = GetProcAddress(hL, "BroadcastSystemMessageA");
		p[19] = GetProcAddress(hL, "BroadcastSystemMessageExA");
		p[20] = GetProcAddress(hL, "BroadcastSystemMessageExW");
		p[21] = GetProcAddress(hL, "BroadcastSystemMessageW");
		p[22] = GetProcAddress(hL, "BuildReasonArray");
		p[23] = GetProcAddress(hL, "CalcMenuBar");
		p[24] = GetProcAddress(hL, "CalculatePopupWindowPosition");
		p[25] = GetProcAddress(hL, "CallMsgFilter");
		p[26] = GetProcAddress(hL, "CallMsgFilterA");
		p[27] = GetProcAddress(hL, "CallMsgFilterW");
		p[28] = GetProcAddress(hL, "CallNextHookEx");
		p[29] = GetProcAddress(hL, "CallWindowProcA");
		p[30] = GetProcAddress(hL, "CallWindowProcW");
		p[31] = GetProcAddress(hL, "CancelShutdown");
		p[32] = GetProcAddress(hL, "CascadeChildWindows");
		p[33] = GetProcAddress(hL, "CascadeWindows");
		p[34] = GetProcAddress(hL, "ChangeClipboardChain");
		p[35] = GetProcAddress(hL, "ChangeDisplaySettingsA");
		p[36] = GetProcAddress(hL, "ChangeDisplaySettingsExA");
		p[37] = GetProcAddress(hL, "ChangeDisplaySettingsExW");
		p[38] = GetProcAddress(hL, "ChangeDisplaySettingsW");
		p[39] = GetProcAddress(hL, "ChangeMenuA");
		p[40] = GetProcAddress(hL, "ChangeMenuW");
		p[41] = GetProcAddress(hL, "ChangeWindowMessageFilter");
		p[42] = GetProcAddress(hL, "ChangeWindowMessageFilterEx");
		p[43] = GetProcAddress(hL, "CharLowerA");
		p[44] = GetProcAddress(hL, "CharLowerBuffA");
		p[45] = GetProcAddress(hL, "CharLowerBuffW");
		p[46] = GetProcAddress(hL, "CharLowerW");
		p[47] = GetProcAddress(hL, "CharNextA");
		p[48] = GetProcAddress(hL, "CharNextExA");
		p[49] = GetProcAddress(hL, "CharNextW");
		p[50] = GetProcAddress(hL, "CharPrevA");
		p[51] = GetProcAddress(hL, "CharPrevExA");
		p[52] = GetProcAddress(hL, "CharPrevW");
		p[53] = GetProcAddress(hL, "CharToOemA");
		p[54] = GetProcAddress(hL, "CharToOemBuffA");
		p[55] = GetProcAddress(hL, "CharToOemBuffW");
		p[56] = GetProcAddress(hL, "CharToOemW");
		p[57] = GetProcAddress(hL, "CharUpperA");
		p[58] = GetProcAddress(hL, "CharUpperBuffA");
		p[59] = GetProcAddress(hL, "CharUpperBuffW");
		p[60] = GetProcAddress(hL, "CharUpperW");
		p[61] = GetProcAddress(hL, "CheckDBCSEnabledExt");
		p[62] = GetProcAddress(hL, "CheckDlgButton");
		p[63] = GetProcAddress(hL, "CheckMenuItem");
		p[64] = GetProcAddress(hL, "CheckMenuRadioItem");
		p[65] = GetProcAddress(hL, "CheckProcessForClipboardAccess");
		p[66] = GetProcAddress(hL, "CheckProcessSession");
		p[67] = GetProcAddress(hL, "CheckRadioButton");
		p[68] = GetProcAddress(hL, "CheckWindowThreadDesktop");
		p[69] = GetProcAddress(hL, "ChildWindowFromPoint");
		p[70] = GetProcAddress(hL, "ChildWindowFromPointEx");
		p[71] = GetProcAddress(hL, "CliImmSetHotKey");
		p[72] = GetProcAddress(hL, "ClientThreadSetup");
		p[73] = GetProcAddress(hL, "ClientToScreen");
		p[74] = GetProcAddress(hL, "ClipCursor");
		p[75] = GetProcAddress(hL, "CloseClipboard");
		p[76] = GetProcAddress(hL, "CloseDesktop");
		p[77] = GetProcAddress(hL, "CloseGestureInfoHandle");
		p[78] = GetProcAddress(hL, "CloseTouchInputHandle");
		p[79] = GetProcAddress(hL, "CloseWindow");
		p[80] = GetProcAddress(hL, "CloseWindowStation");
		p[81] = GetProcAddress(hL, "ConsoleControl");
		p[82] = GetProcAddress(hL, "ControlMagnification");
		p[83] = GetProcAddress(hL, "CopyAcceleratorTableA");
		p[84] = GetProcAddress(hL, "CopyAcceleratorTableW");
		p[85] = GetProcAddress(hL, "CopyIcon");
		p[86] = GetProcAddress(hL, "CopyImage");
		p[87] = GetProcAddress(hL, "CopyRect");
		p[88] = GetProcAddress(hL, "CountClipboardFormats");
		p[89] = GetProcAddress(hL, "CreateAcceleratorTableA");
		p[90] = GetProcAddress(hL, "CreateAcceleratorTableW");
		p[91] = GetProcAddress(hL, "CreateCaret");
		p[92] = GetProcAddress(hL, "CreateCursor");
		p[93] = GetProcAddress(hL, "CreateDCompositionHwndTarget");
		p[94] = GetProcAddress(hL, "CreateDesktopA");
		p[95] = GetProcAddress(hL, "CreateDesktopExA");
		p[96] = GetProcAddress(hL, "CreateDesktopExW");
		p[97] = GetProcAddress(hL, "CreateDesktopW");
		p[98] = GetProcAddress(hL, "CreateDialogIndirectParamA");
		p[99] = GetProcAddress(hL, "CreateDialogIndirectParamAorW");
		p[100] = GetProcAddress(hL, "CreateDialogIndirectParamW");
		p[101] = GetProcAddress(hL, "CreateDialogParamA");
		p[102] = GetProcAddress(hL, "CreateDialogParamW");
		p[103] = GetProcAddress(hL, "CreateIcon");
		p[104] = GetProcAddress(hL, "CreateIconFromResource");
		p[105] = GetProcAddress(hL, "CreateIconFromResourceEx");
		p[106] = GetProcAddress(hL, "CreateIconIndirect");
		p[107] = GetProcAddress(hL, "CreateMDIWindowA");
		p[108] = GetProcAddress(hL, "CreateMDIWindowW");
		p[109] = GetProcAddress(hL, "CreateMenu");
		p[110] = GetProcAddress(hL, "CreatePopupMenu");
		p[111] = GetProcAddress(hL, "CreateSystemThreads");
		p[112] = GetProcAddress(hL, "CreateWindowExA");
		p[113] = GetProcAddress(hL, "CreateWindowExW");
		p[114] = GetProcAddress(hL, "CreateWindowInBand");
		p[115] = GetProcAddress(hL, "CreateWindowInBandEx");
		p[116] = GetProcAddress(hL, "CreateWindowIndirect");
		p[117] = GetProcAddress(hL, "CreateWindowStationA");
		p[118] = GetProcAddress(hL, "CreateWindowStationW");
		p[119] = GetProcAddress(hL, "CsrBroadcastSystemMessageExW");
		p[120] = GetProcAddress(hL, "CtxInitUser32");
		p[121] = GetProcAddress(hL, "DdeAbandonTransaction");
		p[122] = GetProcAddress(hL, "DdeAccessData");
		p[123] = GetProcAddress(hL, "DdeAddData");
		p[124] = GetProcAddress(hL, "DdeClientTransaction");
		p[125] = GetProcAddress(hL, "DdeCmpStringHandles");
		p[126] = GetProcAddress(hL, "DdeConnect");
		p[127] = GetProcAddress(hL, "DdeConnectList");
		p[128] = GetProcAddress(hL, "DdeCreateDataHandle");
		p[129] = GetProcAddress(hL, "DdeCreateStringHandleA");
		p[130] = GetProcAddress(hL, "DdeCreateStringHandleW");
		p[131] = GetProcAddress(hL, "DdeDisconnect");
		p[132] = GetProcAddress(hL, "DdeDisconnectList");
		p[133] = GetProcAddress(hL, "DdeEnableCallback");
		p[134] = GetProcAddress(hL, "DdeFreeDataHandle");
		p[135] = GetProcAddress(hL, "DdeFreeStringHandle");
		p[136] = GetProcAddress(hL, "DdeGetData");
		p[137] = GetProcAddress(hL, "DdeGetLastError");
		p[138] = GetProcAddress(hL, "DdeGetQualityOfService");
		p[139] = GetProcAddress(hL, "DdeImpersonateClient");
		p[140] = GetProcAddress(hL, "DdeInitializeA");
		p[141] = GetProcAddress(hL, "DdeInitializeW");
		p[142] = GetProcAddress(hL, "DdeKeepStringHandle");
		p[143] = GetProcAddress(hL, "DdeNameService");
		p[144] = GetProcAddress(hL, "DdePostAdvise");
		p[145] = GetProcAddress(hL, "DdeQueryConvInfo");
		p[146] = GetProcAddress(hL, "DdeQueryNextServer");
		p[147] = GetProcAddress(hL, "DdeQueryStringA");
		p[148] = GetProcAddress(hL, "DdeQueryStringW");
		p[149] = GetProcAddress(hL, "DdeReconnect");
		p[150] = GetProcAddress(hL, "DdeSetQualityOfService");
		p[151] = GetProcAddress(hL, "DdeSetUserHandle");
		p[152] = GetProcAddress(hL, "DdeUnaccessData");
		p[153] = GetProcAddress(hL, "DdeUninitialize");
		p[154] = GetProcAddress(hL, "DefDlgProcA");
		p[155] = GetProcAddress(hL, "DefDlgProcW");
		p[156] = GetProcAddress(hL, "DefFrameProcA");
		p[157] = GetProcAddress(hL, "DefFrameProcW");
		p[158] = GetProcAddress(hL, "DefMDIChildProcA");
		p[159] = GetProcAddress(hL, "DefMDIChildProcW");
		p[160] = GetProcAddress(hL, "DefRawInputProc");
		p[161] = GetProcAddress(hL, "DefWindowProcA");
		p[162] = GetProcAddress(hL, "DefWindowProcW");
		p[163] = GetProcAddress(hL, "DeferWindowPos");
		p[164] = GetProcAddress(hL, "DeferWindowPosAndBand");
		p[165] = GetProcAddress(hL, "DeleteMenu");
		p[166] = GetProcAddress(hL, "DeregisterShellHookWindow");
		p[167] = GetProcAddress(hL, "DestroyAcceleratorTable");
		p[168] = GetProcAddress(hL, "DestroyCaret");
		p[169] = GetProcAddress(hL, "DestroyCursor");
		p[170] = GetProcAddress(hL, "DestroyDCompositionHwndTarget");
		p[171] = GetProcAddress(hL, "DestroyIcon");
		p[172] = GetProcAddress(hL, "DestroyMenu");
		p[173] = GetProcAddress(hL, "DestroyReasons");
		p[174] = GetProcAddress(hL, "DestroyWindow");
		p[175] = GetProcAddress(hL, "DialogBoxIndirectParamA");
		p[176] = GetProcAddress(hL, "DialogBoxIndirectParamAorW");
		p[177] = GetProcAddress(hL, "DialogBoxIndirectParamW");
		p[178] = GetProcAddress(hL, "DialogBoxParamA");
		p[179] = GetProcAddress(hL, "DialogBoxParamW");
		p[180] = GetProcAddress(hL, "DisableProcessWindowsGhosting");
		p[181] = GetProcAddress(hL, "DispatchMessageA");
		p[182] = GetProcAddress(hL, "DispatchMessageW");
		p[183] = GetProcAddress(hL, "DisplayConfigGetDeviceInfo");
		p[184] = GetProcAddress(hL, "DisplayConfigSetDeviceInfo");
		p[185] = GetProcAddress(hL, "DisplayExitWindowsWarnings");
		p[186] = GetProcAddress(hL, "DlgDirListA");
		p[187] = GetProcAddress(hL, "DlgDirListComboBoxA");
		p[188] = GetProcAddress(hL, "DlgDirListComboBoxW");
		p[189] = GetProcAddress(hL, "DlgDirListW");
		p[190] = GetProcAddress(hL, "DlgDirSelectComboBoxExA");
		p[191] = GetProcAddress(hL, "DlgDirSelectComboBoxExW");
		p[192] = GetProcAddress(hL, "DlgDirSelectExA");
		p[193] = GetProcAddress(hL, "DlgDirSelectExW");
		p[194] = GetProcAddress(hL, "DoSoundConnect");
		p[195] = GetProcAddress(hL, "DoSoundDisconnect");
		p[196] = GetProcAddress(hL, "DragDetect");
		p[197] = GetProcAddress(hL, "DragObject");
		p[198] = GetProcAddress(hL, "DrawAnimatedRects");
		p[199] = GetProcAddress(hL, "DrawCaption");
		p[200] = GetProcAddress(hL, "DrawCaptionTempA");
		p[201] = GetProcAddress(hL, "DrawCaptionTempW");
		p[202] = GetProcAddress(hL, "DrawEdge");
		p[203] = GetProcAddress(hL, "DrawFocusRect");
		p[204] = GetProcAddress(hL, "DrawFrame");
		p[205] = GetProcAddress(hL, "DrawFrameControl");
		p[206] = GetProcAddress(hL, "DrawIcon");
		p[207] = GetProcAddress(hL, "DrawIconEx");
		p[208] = GetProcAddress(hL, "DrawMenuBar");
		p[209] = GetProcAddress(hL, "DrawMenuBarTemp");
		p[210] = GetProcAddress(hL, "DrawStateA");
		p[211] = GetProcAddress(hL, "DrawStateW");
		p[212] = GetProcAddress(hL, "DrawTextA");
		p[213] = GetProcAddress(hL, "DrawTextExA");
		p[214] = GetProcAddress(hL, "DrawTextExW");
		p[215] = GetProcAddress(hL, "DrawTextW");
		p[216] = GetProcAddress(hL, "DwmGetDxSharedSurface");
		p[217] = GetProcAddress(hL, "DwmGetRemoteSessionOcclusionEvent");
		p[218] = GetProcAddress(hL, "DwmGetRemoteSessionOcclusionState");
		p[219] = GetProcAddress(hL, "DwmKernelShutdown");
		p[220] = GetProcAddress(hL, "DwmKernelStartup");
		p[221] = GetProcAddress(hL, "DwmLockScreenUpdates");
		p[222] = GetProcAddress(hL, "DwmValidateWindow");
		p[223] = GetProcAddress(hL, "EditWndProc");
		p[224] = GetProcAddress(hL, "EmptyClipboard");
		p[225] = GetProcAddress(hL, "EnableChildWindowDpiMessage");
		p[226] = GetProcAddress(hL, "EnableMenuItem");
		p[227] = GetProcAddress(hL, "EnableMouseInPointer");
		p[228] = GetProcAddress(hL, "EnableScrollBar");
		p[229] = GetProcAddress(hL, "EnableSessionForMMCSS");
		p[230] = GetProcAddress(hL, "EnableWindow");
		p[231] = GetProcAddress(hL, "EndDeferWindowPos");
		p[232] = GetProcAddress(hL, "EndDeferWindowPosEx");
		p[233] = GetProcAddress(hL, "EndDialog");
		p[234] = GetProcAddress(hL, "EndMenu");
		p[235] = GetProcAddress(hL, "EndPaint");
		p[236] = GetProcAddress(hL, "EndTask");
		p[237] = GetProcAddress(hL, "EnterReaderModeHelper");
		p[238] = GetProcAddress(hL, "EnumChildWindows");
		p[239] = GetProcAddress(hL, "EnumClipboardFormats");
		p[240] = GetProcAddress(hL, "EnumDesktopWindows");
		p[241] = GetProcAddress(hL, "EnumDesktopsA");
		p[242] = GetProcAddress(hL, "EnumDesktopsW");
		p[243] = GetProcAddress(hL, "EnumDisplayDevicesA");
		p[244] = GetProcAddress(hL, "EnumDisplayDevicesW");
		p[245] = GetProcAddress(hL, "EnumDisplayMonitors");
		p[246] = GetProcAddress(hL, "EnumDisplaySettingsA");
		p[247] = GetProcAddress(hL, "EnumDisplaySettingsExA");
		p[248] = GetProcAddress(hL, "EnumDisplaySettingsExW");
		p[249] = GetProcAddress(hL, "EnumDisplaySettingsW");
		p[250] = GetProcAddress(hL, "EnumPropsA");
		p[251] = GetProcAddress(hL, "EnumPropsExA");
		p[252] = GetProcAddress(hL, "EnumPropsExW");
		p[253] = GetProcAddress(hL, "EnumPropsW");
		p[254] = GetProcAddress(hL, "EnumThreadWindows");
		p[255] = GetProcAddress(hL, "EnumWindowStationsA");
		p[256] = GetProcAddress(hL, "EnumWindowStationsW");
		p[257] = GetProcAddress(hL, "EnumWindows");
		p[258] = GetProcAddress(hL, "EqualRect");
		p[259] = GetProcAddress(hL, "EvaluateProximityToPolygon");
		p[260] = GetProcAddress(hL, "EvaluateProximityToRect");
		p[261] = GetProcAddress(hL, "ExcludeUpdateRgn");
		p[262] = GetProcAddress(hL, "ExitWindowsEx");
		p[263] = GetProcAddress(hL, "FillRect");
		p[264] = GetProcAddress(hL, "FindWindowA");
		p[265] = GetProcAddress(hL, "FindWindowExA");
		p[266] = GetProcAddress(hL, "FindWindowExW");
		p[267] = GetProcAddress(hL, "FindWindowW");
		p[268] = GetProcAddress(hL, "FlashWindow");
		p[269] = GetProcAddress(hL, "FlashWindowEx");
		p[270] = GetProcAddress(hL, "FrameRect");
		p[271] = GetProcAddress(hL, "FreeDDElParam");
		p[272] = GetProcAddress(hL, "FrostCrashedWindow");
		p[273] = GetProcAddress(hL, "GetActiveWindow");
		p[274] = GetProcAddress(hL, "GetAltTabInfo");
		p[275] = GetProcAddress(hL, "GetAltTabInfoA");
		p[276] = GetProcAddress(hL, "GetAltTabInfoW");
		p[277] = GetProcAddress(hL, "GetAncestor");
		p[278] = GetProcAddress(hL, "GetAppCompatFlags");
		p[279] = GetProcAddress(hL, "GetAppCompatFlags2");
		p[280] = GetProcAddress(hL, "GetAsyncKeyState");
		p[281] = GetProcAddress(hL, "GetAutoRotationState");
		p[282] = GetProcAddress(hL, "GetCIMSSM");
		p[283] = GetProcAddress(hL, "GetCapture");
		p[284] = GetProcAddress(hL, "GetCaretBlinkTime");
		p[285] = GetProcAddress(hL, "GetCaretPos");
		p[286] = GetProcAddress(hL, "GetClassInfoA");
		p[287] = GetProcAddress(hL, "GetClassInfoExA");
		p[288] = GetProcAddress(hL, "GetClassInfoExW");
		p[289] = GetProcAddress(hL, "GetClassInfoW");
		p[290] = GetProcAddress(hL, "GetClassLongA");
		p[291] = GetProcAddress(hL, "GetClassLongW");
		p[292] = GetProcAddress(hL, "GetClassNameA");
		p[293] = GetProcAddress(hL, "GetClassNameW");
		p[294] = GetProcAddress(hL, "GetClassWord");
		p[295] = GetProcAddress(hL, "GetClientRect");
		p[296] = GetProcAddress(hL, "GetClipCursor");
		p[297] = GetProcAddress(hL, "GetClipboardAccessToken");
		p[298] = GetProcAddress(hL, "GetClipboardData");
		p[299] = GetProcAddress(hL, "GetClipboardFormatNameA");
		p[300] = GetProcAddress(hL, "GetClipboardFormatNameW");
		p[301] = GetProcAddress(hL, "GetClipboardOwner");
		p[302] = GetProcAddress(hL, "GetClipboardSequenceNumber");
		p[303] = GetProcAddress(hL, "GetClipboardViewer");
		p[304] = GetProcAddress(hL, "GetComboBoxInfo");
		p[305] = GetProcAddress(hL, "GetCurrentInputMessageSource");
		p[306] = GetProcAddress(hL, "GetCursor");
		p[307] = GetProcAddress(hL, "GetCursorFrameInfo");
		p[308] = GetProcAddress(hL, "GetCursorInfo");
		p[309] = GetProcAddress(hL, "GetCursorPos");
		p[310] = GetProcAddress(hL, "GetDC");
		p[311] = GetProcAddress(hL, "GetDCEx");
		p[312] = GetProcAddress(hL, "GetDesktopID");
		p[313] = GetProcAddress(hL, "GetDesktopWindow");
		p[314] = GetProcAddress(hL, "GetDialogBaseUnits");
		p[315] = GetProcAddress(hL, "GetDisplayAutoRotationPreferences");
		p[316] = GetProcAddress(hL, "GetDisplayConfigBufferSizes");
		p[317] = GetProcAddress(hL, "GetDlgCtrlID");
		p[318] = GetProcAddress(hL, "GetDlgItem");
		p[319] = GetProcAddress(hL, "GetDlgItemInt");
		p[320] = GetProcAddress(hL, "GetDlgItemTextA");
		p[321] = GetProcAddress(hL, "GetDlgItemTextW");
		p[322] = GetProcAddress(hL, "GetDoubleClickTime");
		p[323] = GetProcAddress(hL, "GetDpiForMonitorInternal");
		p[324] = GetProcAddress(hL, "GetDpiMetrics");
		p[325] = GetProcAddress(hL, "GetFocus");
		p[326] = GetProcAddress(hL, "GetForegroundWindow");
		p[327] = GetProcAddress(hL, "GetGUIThreadInfo");
		p[328] = GetProcAddress(hL, "GetGestureConfig");
		p[329] = GetProcAddress(hL, "GetGestureExtraArgs");
		p[330] = GetProcAddress(hL, "GetGestureInfo");
		p[331] = GetProcAddress(hL, "GetGuiResources");
		p[332] = GetProcAddress(hL, "GetIconInfo");
		p[333] = GetProcAddress(hL, "GetIconInfoExA");
		p[334] = GetProcAddress(hL, "GetIconInfoExW");
		p[335] = GetProcAddress(hL, "GetInputDesktop");
		p[336] = GetProcAddress(hL, "GetInputLocaleInfo");
		p[337] = GetProcAddress(hL, "GetInputState");
		p[338] = GetProcAddress(hL, "GetInternalWindowPos");
		p[339] = GetProcAddress(hL, "GetKBCodePage");
		p[340] = GetProcAddress(hL, "GetKeyNameTextA");
		p[341] = GetProcAddress(hL, "GetKeyNameTextW");
		p[342] = GetProcAddress(hL, "GetKeyState");
		p[343] = GetProcAddress(hL, "GetKeyboardLayout");
		p[344] = GetProcAddress(hL, "GetKeyboardLayoutList");
		p[345] = GetProcAddress(hL, "GetKeyboardLayoutNameA");
		p[346] = GetProcAddress(hL, "GetKeyboardLayoutNameW");
		p[347] = GetProcAddress(hL, "GetKeyboardState");
		p[348] = GetProcAddress(hL, "GetKeyboardType");
		p[349] = GetProcAddress(hL, "GetLastActivePopup");
		p[350] = GetProcAddress(hL, "GetLastInputInfo");
		p[351] = GetProcAddress(hL, "GetLayeredWindowAttributes");
		p[352] = GetProcAddress(hL, "GetListBoxInfo");
		p[353] = GetProcAddress(hL, "GetMagnificationDesktopColorEffect");
		p[354] = GetProcAddress(hL, "GetMagnificationDesktopMagnification");
		p[355] = GetProcAddress(hL, "GetMagnificationLensCtxInformation");
		p[356] = GetProcAddress(hL, "GetMenu");
		p[357] = GetProcAddress(hL, "GetMenuBarInfo");
		p[358] = GetProcAddress(hL, "GetMenuCheckMarkDimensions");
		p[359] = GetProcAddress(hL, "GetMenuContextHelpId");
		p[360] = GetProcAddress(hL, "GetMenuDefaultItem");
		p[361] = GetProcAddress(hL, "GetMenuInfo");
		p[362] = GetProcAddress(hL, "GetMenuItemCount");
		p[363] = GetProcAddress(hL, "GetMenuItemID");
		p[364] = GetProcAddress(hL, "GetMenuItemInfoA");
		p[365] = GetProcAddress(hL, "GetMenuItemInfoW");
		p[366] = GetProcAddress(hL, "GetMenuItemRect");
		p[367] = GetProcAddress(hL, "GetMenuState");
		p[368] = GetProcAddress(hL, "GetMenuStringA");
		p[369] = GetProcAddress(hL, "GetMenuStringW");
		p[370] = GetProcAddress(hL, "GetMessageA");
		p[371] = GetProcAddress(hL, "GetMessageExtraInfo");
		p[372] = GetProcAddress(hL, "GetMessagePos");
		p[373] = GetProcAddress(hL, "GetMessageTime");
		p[374] = GetProcAddress(hL, "GetMessageW");
		p[375] = GetProcAddress(hL, "GetMonitorInfoA");
		p[376] = GetProcAddress(hL, "GetMonitorInfoW");
		p[377] = GetProcAddress(hL, "GetMouseMovePointsEx");
		p[378] = GetProcAddress(hL, "GetNextDlgGroupItem");
		p[379] = GetProcAddress(hL, "GetNextDlgTabItem");
		p[380] = GetProcAddress(hL, "GetOpenClipboardWindow");
		p[381] = GetProcAddress(hL, "GetParent");
		p[382] = GetProcAddress(hL, "GetPhysicalCursorPos");
		p[383] = GetProcAddress(hL, "GetPointerCursorId");
		p[384] = GetProcAddress(hL, "GetPointerDevice");
		p[385] = GetProcAddress(hL, "GetPointerDeviceCursors");
		p[386] = GetProcAddress(hL, "GetPointerDeviceProperties");
		p[387] = GetProcAddress(hL, "GetPointerDeviceRects");
		p[388] = GetProcAddress(hL, "GetPointerDevices");
		p[389] = GetProcAddress(hL, "GetPointerFrameArrivalTimes");
		p[390] = GetProcAddress(hL, "GetPointerFrameInfo");
		p[391] = GetProcAddress(hL, "GetPointerFrameInfoHistory");
		p[392] = GetProcAddress(hL, "GetPointerFramePenInfo");
		p[393] = GetProcAddress(hL, "GetPointerFramePenInfoHistory");
		p[394] = GetProcAddress(hL, "GetPointerFrameTouchInfo");
		p[395] = GetProcAddress(hL, "GetPointerFrameTouchInfoHistory");
		p[396] = GetProcAddress(hL, "GetPointerInfo");
		p[397] = GetProcAddress(hL, "GetPointerInfoHistory");
		p[398] = GetProcAddress(hL, "GetPointerInputTransform");
		p[399] = GetProcAddress(hL, "GetPointerPenInfo");
		p[400] = GetProcAddress(hL, "GetPointerPenInfoHistory");
		p[401] = GetProcAddress(hL, "GetPointerTouchInfo");
		p[402] = GetProcAddress(hL, "GetPointerTouchInfoHistory");
		p[403] = GetProcAddress(hL, "GetPointerType");
		p[404] = GetProcAddress(hL, "GetPriorityClipboardFormat");
		p[405] = GetProcAddress(hL, "GetProcessDefaultLayout");
		p[406] = GetProcAddress(hL, "GetProcessDpiAwarenessInternal");
		p[407] = GetProcAddress(hL, "GetProcessWindowStation");
		p[408] = GetProcAddress(hL, "GetProgmanWindow");
		p[409] = GetProcAddress(hL, "GetPropA");
		p[410] = GetProcAddress(hL, "GetPropW");
		p[411] = GetProcAddress(hL, "GetQueueStatus");
		p[412] = GetProcAddress(hL, "GetRawInputBuffer");
		p[413] = GetProcAddress(hL, "GetRawInputData");
		p[414] = GetProcAddress(hL, "GetRawInputDeviceInfoA");
		p[415] = GetProcAddress(hL, "GetRawInputDeviceInfoW");
		p[416] = GetProcAddress(hL, "GetRawInputDeviceList");
		p[417] = GetProcAddress(hL, "GetRawPointerDeviceData");
		p[418] = GetProcAddress(hL, "GetReasonTitleFromReasonCode");
		p[419] = GetProcAddress(hL, "GetRegisteredRawInputDevices");
		p[420] = GetProcAddress(hL, "GetScrollBarInfo");
		p[421] = GetProcAddress(hL, "GetScrollInfo");
		p[422] = GetProcAddress(hL, "GetScrollPos");
		p[423] = GetProcAddress(hL, "GetScrollRange");
		p[424] = GetProcAddress(hL, "GetSendMessageReceiver");
		p[425] = GetProcAddress(hL, "GetShellWindow");
		p[426] = GetProcAddress(hL, "GetSubMenu");
		p[427] = GetProcAddress(hL, "GetSysColor");
		p[428] = GetProcAddress(hL, "GetSysColorBrush");
		p[429] = GetProcAddress(hL, "GetSystemMenu");
		p[430] = GetProcAddress(hL, "GetSystemMetrics");
		p[431] = GetProcAddress(hL, "GetTabbedTextExtentA");
		p[432] = GetProcAddress(hL, "GetTabbedTextExtentW");
		p[433] = GetProcAddress(hL, "GetTaskmanWindow");
		p[434] = GetProcAddress(hL, "GetThreadDesktop");
		p[435] = GetProcAddress(hL, "GetTitleBarInfo");
		p[436] = GetProcAddress(hL, "GetTopLevelWindow");
		p[437] = GetProcAddress(hL, "GetTopWindow");
		p[438] = GetProcAddress(hL, "GetTouchInputInfo");
		p[439] = GetProcAddress(hL, "GetUnpredictedMessagePos");
		p[440] = GetProcAddress(hL, "GetUpdateRect");
		p[441] = GetProcAddress(hL, "GetUpdateRgn");
		p[442] = GetProcAddress(hL, "GetUpdatedClipboardFormats");
		p[443] = GetProcAddress(hL, "GetUserObjectInformationA");
		p[444] = GetProcAddress(hL, "GetUserObjectInformationW");
		p[445] = GetProcAddress(hL, "GetUserObjectSecurity");
		p[446] = GetProcAddress(hL, "GetWinStationInfo");
		p[447] = GetProcAddress(hL, "GetWindow");
		p[448] = GetProcAddress(hL, "GetWindowBand");
		p[449] = GetProcAddress(hL, "GetWindowCompositionAttribute");
		p[450] = GetProcAddress(hL, "GetWindowCompositionInfo");
		p[451] = GetProcAddress(hL, "GetWindowContextHelpId");
		p[452] = GetProcAddress(hL, "GetWindowDC");
		p[453] = GetProcAddress(hL, "GetWindowDPI");
		p[454] = GetProcAddress(hL, "GetWindowDisplayAffinity");
		p[455] = GetProcAddress(hL, "GetWindowFeedbackSetting");
		p[456] = GetProcAddress(hL, "GetWindowInfo");
		p[457] = GetProcAddress(hL, "GetWindowLongA");
		p[458] = GetProcAddress(hL, "GetWindowLongW");
		p[459] = GetProcAddress(hL, "GetWindowMinimizeRect");
		p[460] = GetProcAddress(hL, "GetWindowModuleFileName");
		p[461] = GetProcAddress(hL, "GetWindowModuleFileNameA");
		p[462] = GetProcAddress(hL, "GetWindowModuleFileNameW");
		p[463] = GetProcAddress(hL, "GetWindowPlacement");
		p[464] = GetProcAddress(hL, "GetWindowRect");
		p[465] = GetProcAddress(hL, "GetWindowRgn");
		p[466] = GetProcAddress(hL, "GetWindowRgnBox");
		p[467] = GetProcAddress(hL, "GetWindowRgnEx");
		p[468] = GetProcAddress(hL, "GetWindowTextA");
		p[469] = GetProcAddress(hL, "GetWindowTextLengthA");
		p[470] = GetProcAddress(hL, "GetWindowTextLengthW");
		p[471] = GetProcAddress(hL, "GetWindowTextW");
		p[472] = GetProcAddress(hL, "GetWindowThreadProcessId");
		p[473] = GetProcAddress(hL, "GetWindowWord");
		p[474] = GetProcAddress(hL, "GhostWindowFromHungWindow");
		p[475] = GetProcAddress(hL, "GrayStringA");
		p[476] = GetProcAddress(hL, "GrayStringW");
		p[477] = GetProcAddress(hL, "HideCaret");
		p[478] = GetProcAddress(hL, "HiliteMenuItem");
		p[479] = GetProcAddress(hL, "HungWindowFromGhostWindow");
		p[480] = GetProcAddress(hL, "IMPGetIMEA");
		p[481] = GetProcAddress(hL, "IMPGetIMEW");
		p[482] = GetProcAddress(hL, "IMPQueryIMEA");
		p[483] = GetProcAddress(hL, "IMPQueryIMEW");
		p[484] = GetProcAddress(hL, "IMPSetIMEA");
		p[485] = GetProcAddress(hL, "IMPSetIMEW");
		p[486] = GetProcAddress(hL, "ImpersonateDdeClientWindow");
		p[487] = GetProcAddress(hL, "InSendMessage");
		p[488] = GetProcAddress(hL, "InSendMessageEx");
		p[489] = GetProcAddress(hL, "InflateRect");
		p[490] = GetProcAddress(hL, "InitDManipHook");
		p[491] = GetProcAddress(hL, "InitializeInputDeviceInjection");
		p[492] = GetProcAddress(hL, "InitializeLpkHooks");
		p[493] = GetProcAddress(hL, "InitializePointerDeviceInjection");
		p[494] = GetProcAddress(hL, "InitializeTouchInjection");
		p[495] = GetProcAddress(hL, "InjectDeviceInput");
		p[496] = GetProcAddress(hL, "InjectKeyboardInput");
		p[497] = GetProcAddress(hL, "InjectMouseInput");
		p[498] = GetProcAddress(hL, "InjectPointerInput");
		p[499] = GetProcAddress(hL, "InjectTouchInput");
		p[500] = GetProcAddress(hL, "InsertMenuA");
		p[501] = GetProcAddress(hL, "InsertMenuItemA");
		p[502] = GetProcAddress(hL, "InsertMenuItemW");
		p[503] = GetProcAddress(hL, "InsertMenuW");
		p[504] = GetProcAddress(hL, "InternalGetWindowIcon");
		p[505] = GetProcAddress(hL, "InternalGetWindowText");
		p[506] = GetProcAddress(hL, "IntersectRect");
		p[507] = GetProcAddress(hL, "InvalidateRect");
		p[508] = GetProcAddress(hL, "InvalidateRgn");
		p[509] = GetProcAddress(hL, "InvertRect");
		p[510] = GetProcAddress(hL, "IsCharAlphaA");
		p[511] = GetProcAddress(hL, "IsCharAlphaNumericA");
		p[512] = GetProcAddress(hL, "IsCharAlphaNumericW");
		p[513] = GetProcAddress(hL, "IsCharAlphaW");
		p[514] = GetProcAddress(hL, "IsCharLowerA");
		p[515] = GetProcAddress(hL, "IsCharLowerW");
		p[516] = GetProcAddress(hL, "IsCharUpperA");
		p[517] = GetProcAddress(hL, "IsCharUpperW");
		p[518] = GetProcAddress(hL, "IsChild");
		p[519] = GetProcAddress(hL, "IsChildWindowDpiMessageEnabled");
		p[520] = GetProcAddress(hL, "IsClipboardFormatAvailable");
		p[521] = GetProcAddress(hL, "IsDialogMessage");
		p[522] = GetProcAddress(hL, "IsDialogMessageA");
		p[523] = GetProcAddress(hL, "IsDialogMessageW");
		p[524] = GetProcAddress(hL, "IsDlgButtonChecked");
		p[525] = GetProcAddress(hL, "IsGUIThread");
		p[526] = GetProcAddress(hL, "IsHungAppWindow");
		p[527] = GetProcAddress(hL, "IsIconic");
		p[528] = GetProcAddress(hL, "IsImmersiveProcess");
		p[529] = GetProcAddress(hL, "IsInDesktopWindowBand");
		p[530] = GetProcAddress(hL, "IsMenu");
		p[531] = GetProcAddress(hL, "IsMouseInPointerEnabled");
		p[532] = GetProcAddress(hL, "IsProcessDPIAware");
		p[533] = GetProcAddress(hL, "IsQueueAttached");
		p[534] = GetProcAddress(hL, "IsRectEmpty");
		p[535] = GetProcAddress(hL, "IsSETEnabled");
		p[536] = GetProcAddress(hL, "IsServerSideWindow");
		p[537] = GetProcAddress(hL, "IsThreadDesktopComposited");
		p[538] = GetProcAddress(hL, "IsThreadMessageQueueAttached");
		p[539] = GetProcAddress(hL, "IsTopLevelWindow");
		p[540] = GetProcAddress(hL, "IsTouchWindow");
		p[541] = GetProcAddress(hL, "IsWinEventHookInstalled");
		p[542] = GetProcAddress(hL, "IsWindow");
		p[543] = GetProcAddress(hL, "IsWindowArranged");
		p[544] = GetProcAddress(hL, "IsWindowBroadcastingDpiToChildren");
		p[545] = GetProcAddress(hL, "IsWindowEnabled");
		p[546] = GetProcAddress(hL, "IsWindowInDestroy");
		p[547] = GetProcAddress(hL, "IsWindowRedirectedForPrint");
		p[548] = GetProcAddress(hL, "IsWindowUnicode");
		p[549] = GetProcAddress(hL, "IsWindowVisible");
		p[550] = GetProcAddress(hL, "IsWow64Message");
		p[551] = GetProcAddress(hL, "IsZoomed");
		p[552] = GetProcAddress(hL, "KillTimer");
		p[553] = GetProcAddress(hL, "LoadAcceleratorsA");
		p[554] = GetProcAddress(hL, "LoadAcceleratorsW");
		p[555] = GetProcAddress(hL, "LoadBitmapA");
		p[556] = GetProcAddress(hL, "LoadBitmapW");
		p[557] = GetProcAddress(hL, "LoadCursorA");
		p[558] = GetProcAddress(hL, "LoadCursorFromFileA");
		p[559] = GetProcAddress(hL, "LoadCursorFromFileW");
		p[560] = GetProcAddress(hL, "LoadCursorW");
		p[561] = GetProcAddress(hL, "LoadIconA");
		p[562] = GetProcAddress(hL, "LoadIconW");
		p[563] = GetProcAddress(hL, "LoadImageA");
		p[564] = GetProcAddress(hL, "LoadImageW");
		p[565] = GetProcAddress(hL, "LoadKeyboardLayoutA");
		p[566] = GetProcAddress(hL, "LoadKeyboardLayoutEx");
		p[567] = GetProcAddress(hL, "LoadKeyboardLayoutW");
		p[568] = GetProcAddress(hL, "LoadLocalFonts");
		p[569] = GetProcAddress(hL, "LoadMenuA");
		p[570] = GetProcAddress(hL, "LoadMenuIndirectA");
		p[571] = GetProcAddress(hL, "LoadMenuIndirectW");
		p[572] = GetProcAddress(hL, "LoadMenuW");
		p[573] = GetProcAddress(hL, "LoadRemoteFonts");
		p[574] = GetProcAddress(hL, "LoadStringA");
		p[575] = GetProcAddress(hL, "LoadStringW");
		p[576] = GetProcAddress(hL, "LockSetForegroundWindow");
		p[577] = GetProcAddress(hL, "LockWindowStation");
		p[578] = GetProcAddress(hL, "LockWindowUpdate");
		p[579] = GetProcAddress(hL, "LockWorkStation");
		p[580] = GetProcAddress(hL, "LogicalToPhysicalPoint");
		p[581] = GetProcAddress(hL, "LogicalToPhysicalPointForPerMonitorDPI");
		p[582] = GetProcAddress(hL, "LookupIconIdFromDirectory");
		p[583] = GetProcAddress(hL, "LookupIconIdFromDirectoryEx");
		p[584] = GetProcAddress(hL, "MBToWCSEx");
		p[585] = GetProcAddress(hL, "MBToWCSExt");
		p[586] = GetProcAddress(hL, "MB_GetString");
		p[587] = GetProcAddress(hL, "MapDialogRect");
		p[588] = GetProcAddress(hL, "MapVirtualKeyA");
		p[589] = GetProcAddress(hL, "MapVirtualKeyExA");
		p[590] = GetProcAddress(hL, "MapVirtualKeyExW");
		p[591] = GetProcAddress(hL, "MapVirtualKeyW");
		p[592] = GetProcAddress(hL, "MapWindowPoints");
		p[593] = GetProcAddress(hL, "MenuItemFromPoint");
		p[594] = GetProcAddress(hL, "MenuWindowProcA");
		p[595] = GetProcAddress(hL, "MenuWindowProcW");
		p[596] = GetProcAddress(hL, "MessageBeep");
		p[597] = GetProcAddress(hL, "MessageBoxA");
		p[598] = GetProcAddress(hL, "MessageBoxExA");
		p[599] = GetProcAddress(hL, "MessageBoxExW");
		p[600] = GetProcAddress(hL, "MessageBoxIndirectA");
		p[601] = GetProcAddress(hL, "MessageBoxIndirectW");
		p[602] = GetProcAddress(hL, "MessageBoxTimeoutA");
		p[603] = GetProcAddress(hL, "MessageBoxTimeoutW");
		p[604] = GetProcAddress(hL, "MessageBoxW");
		p[605] = GetProcAddress(hL, "ModifyMenuA");
		p[606] = GetProcAddress(hL, "ModifyMenuW");
		p[607] = GetProcAddress(hL, "MonitorFromPoint");
		p[608] = GetProcAddress(hL, "MonitorFromRect");
		p[609] = GetProcAddress(hL, "MonitorFromWindow");
		p[610] = GetProcAddress(hL, "MoveWindow");
		p[611] = GetProcAddress(hL, "MsgWaitForMultipleObjects");
		p[612] = GetProcAddress(hL, "MsgWaitForMultipleObjectsEx");
		p[613] = GetProcAddress(hL, "NotifyOverlayWindow");
		p[614] = GetProcAddress(hL, "NotifyWinEvent");
		p[615] = GetProcAddress(hL, "OemKeyScan");
		p[616] = GetProcAddress(hL, "OemToCharA");
		p[617] = GetProcAddress(hL, "OemToCharBuffA");
		p[618] = GetProcAddress(hL, "OemToCharBuffW");
		p[619] = GetProcAddress(hL, "OemToCharW");
		p[620] = GetProcAddress(hL, "OffsetRect");
		p[621] = GetProcAddress(hL, "OpenClipboard");
		p[622] = GetProcAddress(hL, "OpenDesktopA");
		p[623] = GetProcAddress(hL, "OpenDesktopW");
		p[624] = GetProcAddress(hL, "OpenIcon");
		p[625] = GetProcAddress(hL, "OpenInputDesktop");
		p[626] = GetProcAddress(hL, "OpenThreadDesktop");
		p[627] = GetProcAddress(hL, "OpenWindowStationA");
		p[628] = GetProcAddress(hL, "OpenWindowStationW");
		p[629] = GetProcAddress(hL, "PackDDElParam");
		p[630] = GetProcAddress(hL, "PackTouchHitTestingProximityEvaluation");
		p[631] = GetProcAddress(hL, "PaintDesktop");
		p[632] = GetProcAddress(hL, "PaintMenuBar");
		p[633] = GetProcAddress(hL, "PaintMonitor");
		p[634] = GetProcAddress(hL, "PeekMessageA");
		p[635] = GetProcAddress(hL, "PeekMessageW");
		p[636] = GetProcAddress(hL, "PhysicalToLogicalPoint");
		p[637] = GetProcAddress(hL, "PhysicalToLogicalPointForPerMonitorDPI");
		p[638] = GetProcAddress(hL, "PostMessageA");
		p[639] = GetProcAddress(hL, "PostMessageW");
		p[640] = GetProcAddress(hL, "PostQuitMessage");
		p[641] = GetProcAddress(hL, "PostThreadMessageA");
		p[642] = GetProcAddress(hL, "PostThreadMessageW");
		p[643] = GetProcAddress(hL, "PrintWindow");
		p[644] = GetProcAddress(hL, "PrivateExtractIconExA");
		p[645] = GetProcAddress(hL, "PrivateExtractIconExW");
		p[646] = GetProcAddress(hL, "PrivateExtractIconsA");
		p[647] = GetProcAddress(hL, "PrivateExtractIconsW");
		p[648] = GetProcAddress(hL, "PrivateRegisterICSProc");
		p[649] = GetProcAddress(hL, "PtInRect");
		p[650] = GetProcAddress(hL, "QueryBSDRWindow");
		p[651] = GetProcAddress(hL, "QueryDisplayConfig");
		p[652] = GetProcAddress(hL, "QuerySendMessage");
		p[653] = GetProcAddress(hL, "RIMAddInputObserver");
		p[654] = GetProcAddress(hL, "RIMAreSiblingDevices");
		p[655] = GetProcAddress(hL, "RIMDeviceIoControl");
		p[656] = GetProcAddress(hL, "RIMFreeInputBuffer");
		p[657] = GetProcAddress(hL, "RIMGetDevicePreparsedData");
		p[658] = GetProcAddress(hL, "RIMGetDevicePreparsedDataLockfree");
		p[659] = GetProcAddress(hL, "RIMGetDeviceProperties");
		p[660] = GetProcAddress(hL, "RIMGetPhysicalDeviceRect");
		p[661] = GetProcAddress(hL, "RIMObserveNextInput");
		p[662] = GetProcAddress(hL, "RIMOnPnpNotification");
		p[663] = GetProcAddress(hL, "RIMOnTimerNotification");
		p[664] = GetProcAddress(hL, "RIMReadInput");
		p[665] = GetProcAddress(hL, "RIMRegisterForInput");
		p[666] = GetProcAddress(hL, "RIMRemoveInputObserver");
		p[667] = GetProcAddress(hL, "RIMSetTestModeStatus");
		p[668] = GetProcAddress(hL, "RIMUnregisterForInput");
		p[669] = GetProcAddress(hL, "RIMUpdateInputObserverRegistration");
		p[670] = GetProcAddress(hL, "RealChildWindowFromPoint");
		p[671] = GetProcAddress(hL, "RealGetWindowClass");
		p[672] = GetProcAddress(hL, "RealGetWindowClassA");
		p[673] = GetProcAddress(hL, "RealGetWindowClassW");
		p[674] = GetProcAddress(hL, "ReasonCodeNeedsBugID");
		p[675] = GetProcAddress(hL, "ReasonCodeNeedsComment");
		p[676] = GetProcAddress(hL, "RecordShutdownReason");
		p[677] = GetProcAddress(hL, "RedrawWindow");
		p[678] = GetProcAddress(hL, "RegisterBSDRWindow");
		p[679] = GetProcAddress(hL, "RegisterClassA");
		p[680] = GetProcAddress(hL, "RegisterClassExA");
		p[681] = GetProcAddress(hL, "RegisterClassExW");
		p[682] = GetProcAddress(hL, "RegisterClassW");
		p[683] = GetProcAddress(hL, "RegisterClipboardFormatA");
		p[684] = GetProcAddress(hL, "RegisterClipboardFormatW");
		p[685] = GetProcAddress(hL, "RegisterDManipHook");
		p[686] = GetProcAddress(hL, "RegisterDeviceNotificationA");
		p[687] = GetProcAddress(hL, "RegisterDeviceNotificationW");
		p[688] = GetProcAddress(hL, "RegisterErrorReportingDialog");
		p[689] = GetProcAddress(hL, "RegisterFrostWindow");
		p[690] = GetProcAddress(hL, "RegisterGhostWindow");
		p[691] = GetProcAddress(hL, "RegisterHotKey");
		p[692] = GetProcAddress(hL, "RegisterLogonProcess");
		p[693] = GetProcAddress(hL, "RegisterManipulationThread");
		p[694] = GetProcAddress(hL, "RegisterMessagePumpHook");
		p[695] = GetProcAddress(hL, "RegisterPointerDeviceNotifications");
		p[696] = GetProcAddress(hL, "RegisterPointerInputTarget");
		p[697] = GetProcAddress(hL, "RegisterPointerInputTargetEx");
		p[698] = GetProcAddress(hL, "RegisterPowerSettingNotification");
		p[699] = GetProcAddress(hL, "RegisterRawInputDevices");
		p[700] = GetProcAddress(hL, "RegisterServicesProcess");
		p[701] = GetProcAddress(hL, "RegisterSessionPort");
		p[702] = GetProcAddress(hL, "RegisterShellHookWindow");
		p[703] = GetProcAddress(hL, "RegisterSuspendResumeNotification");
		p[704] = GetProcAddress(hL, "RegisterSystemThread");
		p[705] = GetProcAddress(hL, "RegisterTasklist");
		p[706] = GetProcAddress(hL, "RegisterTouchHitTestingWindow");
		p[707] = GetProcAddress(hL, "RegisterTouchWindow");
		p[708] = GetProcAddress(hL, "RegisterUserApiHook");
		p[709] = GetProcAddress(hL, "RegisterWindowMessageA");
		p[710] = GetProcAddress(hL, "RegisterWindowMessageW");
		p[711] = GetProcAddress(hL, "ReleaseCapture");
		p[712] = GetProcAddress(hL, "ReleaseDC");
		p[713] = GetProcAddress(hL, "ReleaseDwmHitTestWaiters");
		p[714] = GetProcAddress(hL, "RemoveClipboardFormatListener");
		p[715] = GetProcAddress(hL, "RemoveInjectionDevice");
		p[716] = GetProcAddress(hL, "RemoveMenu");
		p[717] = GetProcAddress(hL, "RemovePropA");
		p[718] = GetProcAddress(hL, "RemovePropW");
		p[719] = GetProcAddress(hL, "ReplyMessage");
		p[720] = GetProcAddress(hL, "ResolveDesktopForWOW");
		p[721] = GetProcAddress(hL, "ReuseDDElParam");
		p[722] = GetProcAddress(hL, "ScreenToClient");
		p[723] = GetProcAddress(hL, "ScrollChildren");
		p[724] = GetProcAddress(hL, "ScrollDC");
		p[725] = GetProcAddress(hL, "ScrollWindow");
		p[726] = GetProcAddress(hL, "ScrollWindowEx");
		p[727] = GetProcAddress(hL, "SendDlgItemMessageA");
		p[728] = GetProcAddress(hL, "SendDlgItemMessageW");
		p[729] = GetProcAddress(hL, "SendIMEMessageExA");
		p[730] = GetProcAddress(hL, "SendIMEMessageExW");
		p[731] = GetProcAddress(hL, "SendInput");
		p[732] = GetProcAddress(hL, "SendMessageA");
		p[733] = GetProcAddress(hL, "SendMessageCallbackA");
		p[734] = GetProcAddress(hL, "SendMessageCallbackW");
		p[735] = GetProcAddress(hL, "SendMessageTimeoutA");
		p[736] = GetProcAddress(hL, "SendMessageTimeoutW");
		p[737] = GetProcAddress(hL, "SendMessageW");
		p[738] = GetProcAddress(hL, "SendNotifyMessageA");
		p[739] = GetProcAddress(hL, "SendNotifyMessageW");
		p[740] = GetProcAddress(hL, "SetActiveWindow");
		p[741] = GetProcAddress(hL, "SetCapture");
		p[742] = GetProcAddress(hL, "SetCaretBlinkTime");
		p[743] = GetProcAddress(hL, "SetCaretPos");
		p[744] = GetProcAddress(hL, "SetClassLongA");
		p[745] = GetProcAddress(hL, "SetClassLongW");
		p[746] = GetProcAddress(hL, "SetClassWord");
		p[747] = GetProcAddress(hL, "SetClipboardData");
		p[748] = GetProcAddress(hL, "SetClipboardViewer");
		p[749] = GetProcAddress(hL, "SetCoalescableTimer");
		p[750] = GetProcAddress(hL, "SetCursor");
		p[751] = GetProcAddress(hL, "SetCursorContents");
		p[752] = GetProcAddress(hL, "SetCursorPos");
		p[753] = GetProcAddress(hL, "SetDebugErrorLevel");
		p[754] = GetProcAddress(hL, "SetDeskWallpaper");
		p[755] = GetProcAddress(hL, "SetDisplayAutoRotationPreferences");
		p[756] = GetProcAddress(hL, "SetDisplayConfig");
		p[757] = GetProcAddress(hL, "SetDlgItemInt");
		p[758] = GetProcAddress(hL, "SetDlgItemTextA");
		p[759] = GetProcAddress(hL, "SetDlgItemTextW");
		p[760] = GetProcAddress(hL, "SetDoubleClickTime");
		p[761] = GetProcAddress(hL, "SetFeatureReportResponse");
		p[762] = GetProcAddress(hL, "SetFocus");
		p[763] = GetProcAddress(hL, "SetForegroundWindow");
		p[764] = GetProcAddress(hL, "SetGestureConfig");
		p[765] = GetProcAddress(hL, "SetInternalWindowPos");
		p[766] = GetProcAddress(hL, "SetKeyboardState");
		p[767] = GetProcAddress(hL, "SetLastErrorEx");
		p[768] = GetProcAddress(hL, "SetLayeredWindowAttributes");
		p[769] = GetProcAddress(hL, "SetMagnificationDesktopColorEffect");
		p[770] = GetProcAddress(hL, "SetMagnificationDesktopMagnification");
		p[771] = GetProcAddress(hL, "SetMagnificationLensCtxInformation");
		p[772] = GetProcAddress(hL, "SetManipulationInputTarget");
		p[773] = GetProcAddress(hL, "SetMenu");
		p[774] = GetProcAddress(hL, "SetMenuContextHelpId");
		p[775] = GetProcAddress(hL, "SetMenuDefaultItem");
		p[776] = GetProcAddress(hL, "SetMenuInfo");
		p[777] = GetProcAddress(hL, "SetMenuItemBitmaps");
		p[778] = GetProcAddress(hL, "SetMenuItemInfoA");
		p[779] = GetProcAddress(hL, "SetMenuItemInfoW");
		p[780] = GetProcAddress(hL, "SetMessageExtraInfo");
		p[781] = GetProcAddress(hL, "SetMessageQueue");
		p[782] = GetProcAddress(hL, "SetMirrorRendering");
		p[783] = GetProcAddress(hL, "SetParent");
		p[784] = GetProcAddress(hL, "SetPhysicalCursorPos");
		p[785] = GetProcAddress(hL, "SetProcessDPIAware");
		p[786] = GetProcAddress(hL, "SetProcessDefaultLayout");
		p[787] = GetProcAddress(hL, "SetProcessDpiAwarenessInternal");
		p[788] = GetProcAddress(hL, "SetProcessRestrictionExemption");
		p[789] = GetProcAddress(hL, "SetProcessWindowStation");
		p[790] = GetProcAddress(hL, "SetProgmanWindow");
		p[791] = GetProcAddress(hL, "SetPropA");
		p[792] = GetProcAddress(hL, "SetPropW");
		p[793] = GetProcAddress(hL, "SetRect");
		p[794] = GetProcAddress(hL, "SetRectEmpty");
		p[795] = GetProcAddress(hL, "SetScrollInfo");
		p[796] = GetProcAddress(hL, "SetScrollPos");
		p[797] = GetProcAddress(hL, "SetScrollRange");
		p[798] = GetProcAddress(hL, "SetShellWindow");
		p[799] = GetProcAddress(hL, "SetShellWindowEx");
		p[800] = GetProcAddress(hL, "SetSysColors");
		p[801] = GetProcAddress(hL, "SetSysColorsTemp");
		p[802] = GetProcAddress(hL, "SetSystemCursor");
		p[803] = GetProcAddress(hL, "SetSystemMenu");
		p[804] = GetProcAddress(hL, "SetTaskmanWindow");
		p[805] = GetProcAddress(hL, "SetThreadDesktop");
		p[806] = GetProcAddress(hL, "SetThreadInputBlocked");
		p[807] = GetProcAddress(hL, "SetTimer");
		p[808] = GetProcAddress(hL, "SetUserObjectInformationA");
		p[809] = GetProcAddress(hL, "SetUserObjectInformationW");
		p[810] = GetProcAddress(hL, "SetUserObjectSecurity");
		p[811] = GetProcAddress(hL, "SetWinEventHook");
		p[812] = GetProcAddress(hL, "SetWindowBand");
		p[813] = GetProcAddress(hL, "SetWindowCompositionAttribute");
		p[814] = GetProcAddress(hL, "SetWindowCompositionTransition");
		p[815] = GetProcAddress(hL, "SetWindowContextHelpId");
		p[816] = GetProcAddress(hL, "SetWindowDisplayAffinity");
		p[817] = GetProcAddress(hL, "SetWindowFeedbackSetting");
		p[818] = GetProcAddress(hL, "SetWindowLongA");
		p[819] = GetProcAddress(hL, "SetWindowLongW");
		p[820] = GetProcAddress(hL, "SetWindowPlacement");
		p[821] = GetProcAddress(hL, "SetWindowPos");
		p[822] = GetProcAddress(hL, "SetWindowRgn");
		p[823] = GetProcAddress(hL, "SetWindowRgnEx");
		p[824] = GetProcAddress(hL, "SetWindowStationUser");
		p[825] = GetProcAddress(hL, "SetWindowTextA");
		p[826] = GetProcAddress(hL, "SetWindowTextW");
		p[827] = GetProcAddress(hL, "SetWindowWord");
		p[828] = GetProcAddress(hL, "SetWindowsHookA");
		p[829] = GetProcAddress(hL, "SetWindowsHookExA");
		p[830] = GetProcAddress(hL, "SetWindowsHookExW");
		p[831] = GetProcAddress(hL, "SetWindowsHookW");
		p[832] = GetProcAddress(hL, "ShowCaret");
		p[833] = GetProcAddress(hL, "ShowCursor");
		p[834] = GetProcAddress(hL, "ShowOwnedPopups");
		p[835] = GetProcAddress(hL, "ShowScrollBar");
		p[836] = GetProcAddress(hL, "ShowStartGlass");
		p[837] = GetProcAddress(hL, "ShowSystemCursor");
		p[838] = GetProcAddress(hL, "ShowWindow");
		p[839] = GetProcAddress(hL, "ShowWindowAsync");
		p[840] = GetProcAddress(hL, "ShutdownBlockReasonCreate");
		p[841] = GetProcAddress(hL, "ShutdownBlockReasonDestroy");
		p[842] = GetProcAddress(hL, "ShutdownBlockReasonQuery");
		p[843] = GetProcAddress(hL, "SignalRedirectionStartComplete");
		p[844] = GetProcAddress(hL, "SkipPointerFrameMessages");
		p[845] = GetProcAddress(hL, "SoftModalMessageBox");
		p[846] = GetProcAddress(hL, "SoundSentry");
		p[847] = GetProcAddress(hL, "SubtractRect");
		p[848] = GetProcAddress(hL, "SwapMouseButton");
		p[849] = GetProcAddress(hL, "SwitchDesktop");
		p[850] = GetProcAddress(hL, "SwitchDesktopWithFade");
		p[851] = GetProcAddress(hL, "SwitchToThisWindow");
		p[852] = GetProcAddress(hL, "SystemParametersInfoA");
		p[853] = GetProcAddress(hL, "SystemParametersInfoW");
		p[854] = GetProcAddress(hL, "TabbedTextOutA");
		p[855] = GetProcAddress(hL, "TabbedTextOutW");
		p[856] = GetProcAddress(hL, "TileChildWindows");
		p[857] = GetProcAddress(hL, "TileWindows");
		p[858] = GetProcAddress(hL, "ToAscii");
		p[859] = GetProcAddress(hL, "ToAsciiEx");
		p[860] = GetProcAddress(hL, "ToUnicode");
		p[861] = GetProcAddress(hL, "ToUnicodeEx");
		p[862] = GetProcAddress(hL, "TrackMouseEvent");
		p[863] = GetProcAddress(hL, "TrackPopupMenu");
		p[864] = GetProcAddress(hL, "TrackPopupMenuEx");
		p[865] = GetProcAddress(hL, "TranslateAccelerator");
		p[866] = GetProcAddress(hL, "TranslateAcceleratorA");
		p[867] = GetProcAddress(hL, "TranslateAcceleratorW");
		p[868] = GetProcAddress(hL, "TranslateMDISysAccel");
		p[869] = GetProcAddress(hL, "TranslateMessage");
		p[870] = GetProcAddress(hL, "TranslateMessageEx");
		p[871] = GetProcAddress(hL, "UnhookWinEvent");
		p[872] = GetProcAddress(hL, "UnhookWindowsHook");
		p[873] = GetProcAddress(hL, "UnhookWindowsHookEx");
		p[874] = GetProcAddress(hL, "UnionRect");
		p[875] = GetProcAddress(hL, "UnloadKeyboardLayout");
		p[876] = GetProcAddress(hL, "UnlockWindowStation");
		p[877] = GetProcAddress(hL, "UnpackDDElParam");
		p[878] = GetProcAddress(hL, "UnregisterClassA");
		p[879] = GetProcAddress(hL, "UnregisterClassW");
		p[880] = GetProcAddress(hL, "UnregisterDeviceNotification");
		p[881] = GetProcAddress(hL, "UnregisterHotKey");
		p[882] = GetProcAddress(hL, "UnregisterMessagePumpHook");
		p[883] = GetProcAddress(hL, "UnregisterPointerInputTarget");
		p[884] = GetProcAddress(hL, "UnregisterPointerInputTargetEx");
		p[885] = GetProcAddress(hL, "UnregisterPowerSettingNotification");
		p[886] = GetProcAddress(hL, "UnregisterSessionPort");
		p[887] = GetProcAddress(hL, "UnregisterSuspendResumeNotification");
		p[888] = GetProcAddress(hL, "UnregisterTouchWindow");
		p[889] = GetProcAddress(hL, "UnregisterUserApiHook");
		p[890] = GetProcAddress(hL, "UpdateDefaultDesktopThumbnail");
		p[891] = GetProcAddress(hL, "UpdateLayeredWindow");
		p[892] = GetProcAddress(hL, "UpdateLayeredWindowIndirect");
		p[893] = GetProcAddress(hL, "UpdatePerUserSystemParameters");
		p[894] = GetProcAddress(hL, "UpdateWindow");
		p[895] = GetProcAddress(hL, "UpdateWindowInputSinkHints");
		p[896] = GetProcAddress(hL, "UpdateWindowTransform");
		p[897] = GetProcAddress(hL, "User32InitializeImmEntryTable");
		p[898] = GetProcAddress(hL, "UserClientDllInitialize");
		p[899] = GetProcAddress(hL, "UserHandleGrantAccess");
		p[900] = GetProcAddress(hL, "UserLpkPSMTextOut");
		p[901] = GetProcAddress(hL, "UserLpkTabbedTextOut");
		p[902] = GetProcAddress(hL, "UserRealizePalette");
		p[903] = GetProcAddress(hL, "UserRegisterWowHandlers");
		p[904] = GetProcAddress(hL, "VRipOutput");
		p[905] = GetProcAddress(hL, "VTagOutput");
		p[906] = GetProcAddress(hL, "ValidateRect");
		p[907] = GetProcAddress(hL, "ValidateRgn");
		p[908] = GetProcAddress(hL, "VkKeyScanA");
		p[909] = GetProcAddress(hL, "VkKeyScanExA");
		p[910] = GetProcAddress(hL, "VkKeyScanExW");
		p[911] = GetProcAddress(hL, "VkKeyScanW");
		p[912] = GetProcAddress(hL, "WCSToMBEx");
		p[913] = GetProcAddress(hL, "WINNLSEnableIME");
		p[914] = GetProcAddress(hL, "WINNLSGetEnableStatus");
		p[915] = GetProcAddress(hL, "WINNLSGetIMEHotkey");
		p[916] = GetProcAddress(hL, "WaitForInputIdle");
		p[917] = GetProcAddress(hL, "WaitForRedirectionStartComplete");
		p[918] = GetProcAddress(hL, "WaitMessage");
		p[919] = GetProcAddress(hL, "WinHelpA");
		p[920] = GetProcAddress(hL, "WinHelpW");
		p[921] = GetProcAddress(hL, "WindowFromDC");
		p[922] = GetProcAddress(hL, "WindowFromPhysicalPoint");
		p[923] = GetProcAddress(hL, "WindowFromPoint");
		p[924] = GetProcAddress(hL, "_UserTestTokenForInteractive");
		p[925] = GetProcAddress(hL, "gSharedInfo");
		p[926] = GetProcAddress(hL, "gapfnScSendMessage");
		p[927] = GetProcAddress(hL, "keybd_event");
		p[928] = GetProcAddress(hL, "mouse_event");
		p[929] = GetProcAddress(hL, "wsprintfA");
		p[930] = GetProcAddress(hL, "wsprintfW");
		p[931] = GetProcAddress(hL, "wvsprintfA");
		p[932] = GetProcAddress(hL, "wvsprintfW");
		p[933] = GetProcAddress(hL, (LPCSTR)"1502");
		p[934] = GetProcAddress(hL, (LPCSTR)"1550");
		p[935] = GetProcAddress(hL, (LPCSTR)"1551");
		p[936] = GetProcAddress(hL, (LPCSTR)"1552");
		p[937] = GetProcAddress(hL, (LPCSTR)"1553");
		p[938] = GetProcAddress(hL, (LPCSTR)"1554");
		p[939] = GetProcAddress(hL, (LPCSTR)"2001");
		p[940] = GetProcAddress(hL, (LPCSTR)"2002");
		p[941] = GetProcAddress(hL, (LPCSTR)"2005");
		p[942] = GetProcAddress(hL, (LPCSTR)"2010");
		p[943] = GetProcAddress(hL, (LPCSTR)"2503");
		p[944] = GetProcAddress(hL, (LPCSTR)"2504");
		p[945] = GetProcAddress(hL, (LPCSTR)"2505");
		p[946] = GetProcAddress(hL, (LPCSTR)"2506");
		p[947] = GetProcAddress(hL, (LPCSTR)"2507");
		p[948] = GetProcAddress(hL, (LPCSTR)"2508");
		p[949] = GetProcAddress(hL, (LPCSTR)"2509");
		p[950] = GetProcAddress(hL, (LPCSTR)"2510");
		p[951] = GetProcAddress(hL, (LPCSTR)"2511");
		p[952] = GetProcAddress(hL, (LPCSTR)"2512");
		p[953] = GetProcAddress(hL, (LPCSTR)"2513");
		p[954] = GetProcAddress(hL, (LPCSTR)"2514");
		p[955] = GetProcAddress(hL, (LPCSTR)"2515");
		p[956] = GetProcAddress(hL, (LPCSTR)"2516");
		p[957] = GetProcAddress(hL, (LPCSTR)"2517");
		p[958] = GetProcAddress(hL, (LPCSTR)"2518");
		p[959] = GetProcAddress(hL, (LPCSTR)"2519");
		p[960] = GetProcAddress(hL, (LPCSTR)"2520");
		p[961] = GetProcAddress(hL, (LPCSTR)"2521");
		p[962] = GetProcAddress(hL, (LPCSTR)"2522");
		p[963] = GetProcAddress(hL, (LPCSTR)"2523");
		p[964] = GetProcAddress(hL, (LPCSTR)"2524");
		p[965] = GetProcAddress(hL, (LPCSTR)"2525");
		p[966] = GetProcAddress(hL, (LPCSTR)"2526");
		p[967] = GetProcAddress(hL, (LPCSTR)"2527");
		p[968] = GetProcAddress(hL, (LPCSTR)"2529");
		p[969] = GetProcAddress(hL, (LPCSTR)"2530");
		p[970] = GetProcAddress(hL, (LPCSTR)"2531");
		p[971] = GetProcAddress(hL, (LPCSTR)"2532");
		p[972] = GetProcAddress(hL, (LPCSTR)"2533");
		p[973] = GetProcAddress(hL, (LPCSTR)"2534");
		p[974] = GetProcAddress(hL, (LPCSTR)"2535");
		p[975] = GetProcAddress(hL, (LPCSTR)"2536");
		p[976] = GetProcAddress(hL, (LPCSTR)"2537");
		p[977] = GetProcAddress(hL, (LPCSTR)"2538");
		p[978] = GetProcAddress(hL, (LPCSTR)"2539");
		p[979] = GetProcAddress(hL, (LPCSTR)"2540");
		p[980] = GetProcAddress(hL, (LPCSTR)"2541");
		p[981] = GetProcAddress(hL, (LPCSTR)"2542");
		p[982] = GetProcAddress(hL, (LPCSTR)"2544");
		p[983] = GetProcAddress(hL, (LPCSTR)"2545");
		p[984] = GetProcAddress(hL, (LPCSTR)"2546");
		p[985] = GetProcAddress(hL, (LPCSTR)"2547");
		p[986] = GetProcAddress(hL, (LPCSTR)"2548");
		p[987] = GetProcAddress(hL, (LPCSTR)"2549");
		p[988] = GetProcAddress(hL, (LPCSTR)"2550");
		p[989] = GetProcAddress(hL, (LPCSTR)"2551");
		p[990] = GetProcAddress(hL, (LPCSTR)"2552");
		p[991] = GetProcAddress(hL, (LPCSTR)"2553");
		p[992] = GetProcAddress(hL, (LPCSTR)"2554");
		p[993] = GetProcAddress(hL, (LPCSTR)"2555");
		p[994] = GetProcAddress(hL, (LPCSTR)"2556");
		p[995] = GetProcAddress(hL, (LPCSTR)"2557");
		p[996] = GetProcAddress(hL, (LPCSTR)"2558");
		p[997] = GetProcAddress(hL, (LPCSTR)"2559");
		p[998] = GetProcAddress(hL, (LPCSTR)"2560");
		p[999] = GetProcAddress(hL, (LPCSTR)"2561");
		p[1000] = GetProcAddress(hL, (LPCSTR)"2562");
		p[1001] = GetProcAddress(hL, (LPCSTR)"2563");
		p[1002] = GetProcAddress(hL, (LPCSTR)"2564");
		p[1003] = GetProcAddress(hL, (LPCSTR)"2566");
		p[1004] = GetProcAddress(hL, (LPCSTR)"2567");
		p[1005] = GetProcAddress(hL, (LPCSTR)"2568");
		p[1006] = GetProcAddress(hL, (LPCSTR)"2569");
		p[1007] = GetProcAddress(hL, (LPCSTR)"2570");
		p[1008] = GetProcAddress(hL, (LPCSTR)"2571");
		p[1009] = GetProcAddress(hL, (LPCSTR)"2572");
		p[1010] = GetProcAddress(hL, (LPCSTR)"2573");
		p[1011] = GetProcAddress(hL, (LPCSTR)"2574");
		p[1012] = GetProcAddress(hL, (LPCSTR)"2575");
		p[1013] = GetProcAddress(hL, (LPCSTR)"2576");
		p[1014] = GetProcAddress(hL, (LPCSTR)"2577");
		p[1015] = GetProcAddress(hL, (LPCSTR)"2578");
		p[1016] = GetProcAddress(hL, (LPCSTR)"2579");
		p[1017] = GetProcAddress(hL, (LPCSTR)"2580");
		p[1018] = GetProcAddress(hL, (LPCSTR)"2581");
		p[1019] = GetProcAddress(hL, (LPCSTR)"2582");
		p[1020] = GetProcAddress(hL, (LPCSTR)"2583");
		p[1021] = GetProcAddress(hL, (LPCSTR)"2584");
		p[1022] = GetProcAddress(hL, (LPCSTR)"2585");
		p[1023] = GetProcAddress(hL, (LPCSTR)"2700");
		p[1024] = GetProcAddress(hL, (LPCSTR)"2702");


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

// ActivateKeyboardLayout
extern "C" __declspec(naked) void __stdcall __E__0__()
{
	PROXY(ActivateKeyboardLayout)
		__asm
	{
		jmp p[0 * 4];
	}
}

// AddClipboardFormatListener
extern "C" __declspec(naked) void __stdcall __E__1__()
{
	PROXY(AddClipboardFormatListener)
		__asm
	{
		jmp p[1 * 4];
	}
}

// AdjustWindowRect
extern "C" __declspec(naked) void __stdcall __E__2__()
{
	PROXY(AdjustWindowRect)
		__asm
	{
		jmp p[2 * 4];
	}
}

// AdjustWindowRectEx
extern "C" __declspec(naked) void __stdcall __E__3__()
{
	PROXY(AdjustWindowRectEx)
		__asm
	{
		jmp p[3 * 4];
	}
}

// AlignRects
extern "C" __declspec(naked) void __stdcall __E__4__()
{
	PROXY(AlignRects)
		__asm
	{
		jmp p[4 * 4];
	}
}

// AllowForegroundActivation
extern "C" __declspec(naked) void __stdcall __E__5__()
{
	PROXY(AllowForegroundActivation)
		__asm
	{
		jmp p[5 * 4];
	}
}

// AllowSetForegroundWindow
extern "C" __declspec(naked) void __stdcall __E__6__()
{
	PROXY(AllowSetForegroundWindow)
		__asm
	{
		jmp p[6 * 4];
	}
}

// AnimateWindow
extern "C" __declspec(naked) void __stdcall __E__7__()
{
	PROXY(AnimateWindow)
		__asm
	{
		jmp p[7 * 4];
	}
}

// AnyPopup
extern "C" __declspec(naked) void __stdcall __E__8__()
{
	PROXY(AnyPopup)
		__asm
	{
		jmp p[8 * 4];
	}
}

// AppendMenuA
extern "C" __declspec(naked) void __stdcall __E__9__()
{
	PROXY(AppendMenuA)
		__asm
	{
		jmp p[9 * 4];
	}
}

// AppendMenuW
extern "C" __declspec(naked) void __stdcall __E__10__()
{
	PROXY(AppendMenuW)
		__asm
	{
		jmp p[10 * 4];
	}
}

// ArrangeIconicWindows
extern "C" __declspec(naked) void __stdcall __E__11__()
{
	PROXY(ArrangeIconicWindows)
		__asm
	{
		jmp p[11 * 4];
	}
}

// AttachThreadInput
extern "C" __declspec(naked) void __stdcall __E__12__()
{
	PROXY(AttachThreadInput)
		__asm
	{
		jmp p[12 * 4];
	}
}

// BeginDeferWindowPos
extern "C" __declspec(naked) void __stdcall __E__13__()
{
	PROXY(BeginDeferWindowPos)
		__asm
	{
		jmp p[13 * 4];
	}
}

// BeginPaint
extern "C" __declspec(naked) void __stdcall __E__14__()
{
	PROXY(BeginPaint)
		__asm
	{
		jmp p[14 * 4];
	}
}

// BlockInput
extern "C" __declspec(naked) void __stdcall __E__15__()
{
	PROXY(BlockInput)
		__asm
	{
		jmp p[15 * 4];
	}
}

// BringWindowToTop
extern "C" __declspec(naked) void __stdcall __E__16__()
{
	PROXY(BringWindowToTop)
		__asm
	{
		jmp p[16 * 4];
	}
}

// BroadcastSystemMessage
extern "C" __declspec(naked) void __stdcall __E__17__()
{
	PROXY(BroadcastSystemMessage)
		__asm
	{
		jmp p[17 * 4];
	}
}

// BroadcastSystemMessageA
extern "C" __declspec(naked) void __stdcall __E__18__()
{
	PROXY(BroadcastSystemMessageA)
		__asm
	{
		jmp p[18 * 4];
	}
}

// BroadcastSystemMessageExA
extern "C" __declspec(naked) void __stdcall __E__19__()
{
	PROXY(BroadcastSystemMessageExA)
		__asm
	{
		jmp p[19 * 4];
	}
}

// BroadcastSystemMessageExW
extern "C" __declspec(naked) void __stdcall __E__20__()
{
	PROXY(BroadcastSystemMessageExW)
		__asm
	{
		jmp p[20 * 4];
	}
}

// BroadcastSystemMessageW
extern "C" __declspec(naked) void __stdcall __E__21__()
{
	PROXY(BroadcastSystemMessageW)
		__asm
	{
		jmp p[21 * 4];
	}
}

// BuildReasonArray
extern "C" __declspec(naked) void __stdcall __E__22__()
{
	PROXY(BuildReasonArray)
		__asm
	{
		jmp p[22 * 4];
	}
}

// CalcMenuBar
extern "C" __declspec(naked) void __stdcall __E__23__()
{
	PROXY(CalcMenuBar)
		__asm
	{
		jmp p[23 * 4];
	}
}

// CalculatePopupWindowPosition
extern "C" __declspec(naked) void __stdcall __E__24__()
{
	PROXY(CalculatePopupWindowPosition)
		__asm
	{
		jmp p[24 * 4];
	}
}

// CallMsgFilter
extern "C" __declspec(naked) void __stdcall __E__25__()
{
	PROXY(CallMsgFilter)
		__asm
	{
		jmp p[25 * 4];
	}
}

// CallMsgFilterA
extern "C" __declspec(naked) void __stdcall __E__26__()
{
	PROXY(CallMsgFilterA)
		__asm
	{
		jmp p[26 * 4];
	}
}

// CallMsgFilterW
extern "C" __declspec(naked) void __stdcall __E__27__()
{
	PROXY(CallMsgFilterW)
		__asm
	{
		jmp p[27 * 4];
	}
}

// CallNextHookEx
extern "C" __declspec(naked) void __stdcall __E__28__()
{
	PROXY(CallNextHookEx)
		__asm
	{
		jmp p[28 * 4];
	}
}

// CallWindowProcA
extern "C" __declspec(naked) void __stdcall __E__29__()
{
	PROXY(CallWindowProcA)
		__asm
	{
		jmp p[29 * 4];
	}
}

// CallWindowProcW
extern "C" __declspec(naked) void __stdcall __E__30__()
{
	PROXY(CallWindowProcW)
		__asm
	{
		jmp p[30 * 4];
	}
}

// CancelShutdown
extern "C" __declspec(naked) void __stdcall __E__31__()
{
	PROXY(CancelShutdown)
		__asm
	{
		jmp p[31 * 4];
	}
}

// CascadeChildWindows
extern "C" __declspec(naked) void __stdcall __E__32__()
{
	PROXY(CascadeChildWindows)
		__asm
	{
		jmp p[32 * 4];
	}
}

// CascadeWindows
extern "C" __declspec(naked) void __stdcall __E__33__()
{
	PROXY(CascadeWindows)
		__asm
	{
		jmp p[33 * 4];
	}
}

// ChangeClipboardChain
extern "C" __declspec(naked) void __stdcall __E__34__()
{
	PROXY(ChangeClipboardChain)
		__asm
	{
		jmp p[34 * 4];
	}
}

// ChangeDisplaySettingsA
extern "C" __declspec(naked) void __stdcall __E__35__()
{
	PROXY(ChangeDisplaySettingsA)
		__asm
	{
		jmp p[35 * 4];
	}
}

// ChangeDisplaySettingsExA
extern "C" __declspec(naked) void __stdcall __E__36__()
{
	PROXY(ChangeDisplaySettingsExA)
		__asm
	{
		jmp p[36 * 4];
	}
}

// ChangeDisplaySettingsExW
extern "C" __declspec(naked) void __stdcall __E__37__()
{
	PROXY(ChangeDisplaySettingsExW)
		__asm
	{
		jmp p[37 * 4];
	}
}

// ChangeDisplaySettingsW
extern "C" __declspec(naked) void __stdcall __E__38__()
{
	PROXY(ChangeDisplaySettingsW)
		__asm
	{
		jmp p[38 * 4];
	}
}

// ChangeMenuA
extern "C" __declspec(naked) void __stdcall __E__39__()
{
	PROXY(ChangeMenuA)
		__asm
	{
		jmp p[39 * 4];
	}
}

// ChangeMenuW
extern "C" __declspec(naked) void __stdcall __E__40__()
{
	PROXY(ChangeMenuW)
		__asm
	{
		jmp p[40 * 4];
	}
}

// ChangeWindowMessageFilter
extern "C" __declspec(naked) void __stdcall __E__41__()
{
	PROXY(ChangeWindowMessageFilter)
		__asm
	{
		jmp p[41 * 4];
	}
}

// ChangeWindowMessageFilterEx
extern "C" __declspec(naked) void __stdcall __E__42__()
{
	PROXY(ChangeWindowMessageFilterEx)
		__asm
	{
		jmp p[42 * 4];
	}
}

// CharLowerA
extern "C" __declspec(naked) void __stdcall __E__43__()
{
	PROXY(CharLowerA)
		__asm
	{
		jmp p[43 * 4];
	}
}

// CharLowerBuffA
extern "C" __declspec(naked) void __stdcall __E__44__()
{
	PROXY(CharLowerBuffA)
		__asm
	{
		jmp p[44 * 4];
	}
}

// CharLowerBuffW
extern "C" __declspec(naked) void __stdcall __E__45__()
{
	PROXY(CharLowerBuffW)
		__asm
	{
		jmp p[45 * 4];
	}
}

// CharLowerW
extern "C" __declspec(naked) void __stdcall __E__46__()
{
	PROXY(CharLowerW)
		__asm
	{
		jmp p[46 * 4];
	}
}

// CharNextA
extern "C" __declspec(naked) void __stdcall __E__47__()
{
	PROXY(CharNextA)
		__asm
	{
		jmp p[47 * 4];
	}
}

// CharNextExA
extern "C" __declspec(naked) void __stdcall __E__48__()
{
	PROXY(CharNextExA)
		__asm
	{
		jmp p[48 * 4];
	}
}

// CharNextW
extern "C" __declspec(naked) void __stdcall __E__49__()
{
	PROXY(CharNextW)
		__asm
	{
		jmp p[49 * 4];
	}
}

// CharPrevA
extern "C" __declspec(naked) void __stdcall __E__50__()
{
	PROXY(CharPrevA)
		__asm
	{
		jmp p[50 * 4];
	}
}

// CharPrevExA
extern "C" __declspec(naked) void __stdcall __E__51__()
{
	PROXY(CharPrevExA)
		__asm
	{
		jmp p[51 * 4];
	}
}

// CharPrevW
extern "C" __declspec(naked) void __stdcall __E__52__()
{
	PROXY(CharPrevW)
		__asm
	{
		jmp p[52 * 4];
	}
}

// CharToOemA
extern "C" __declspec(naked) void __stdcall __E__53__()
{
	PROXY(CharToOemA)
		__asm
	{
		jmp p[53 * 4];
	}
}

// CharToOemBuffA
extern "C" __declspec(naked) void __stdcall __E__54__()
{
	PROXY(CharToOemBuffA)
		__asm
	{
		jmp p[54 * 4];
	}
}

// CharToOemBuffW
extern "C" __declspec(naked) void __stdcall __E__55__()
{
	PROXY(CharToOemBuffW)
		__asm
	{
		jmp p[55 * 4];
	}
}

// CharToOemW
extern "C" __declspec(naked) void __stdcall __E__56__()
{
	PROXY(CharToOemW)
		__asm
	{
		jmp p[56 * 4];
	}
}

// CharUpperA
extern "C" __declspec(naked) void __stdcall __E__57__()
{
	PROXY(CharUpperA)
		__asm
	{
		jmp p[57 * 4];
	}
}

// CharUpperBuffA
extern "C" __declspec(naked) void __stdcall __E__58__()
{
	PROXY(CharUpperBuffA)
		__asm
	{
		jmp p[58 * 4];
	}
}

// CharUpperBuffW
extern "C" __declspec(naked) void __stdcall __E__59__()
{
	PROXY(CharUpperBuffW)
		__asm
	{
		jmp p[59 * 4];
	}
}

// CharUpperW
extern "C" __declspec(naked) void __stdcall __E__60__()
{
	PROXY(CharUpperW)
		__asm
	{
		jmp p[60 * 4];
	}
}

// CheckDBCSEnabledExt
extern "C" __declspec(naked) void __stdcall __E__61__()
{
	PROXY(CheckDBCSEnabledExt)
		__asm
	{
		jmp p[61 * 4];
	}
}

// CheckDlgButton
extern "C" __declspec(naked) void __stdcall __E__62__()
{
	PROXY(CheckDlgButton)
		__asm
	{
		jmp p[62 * 4];
	}
}

// CheckMenuItem
extern "C" __declspec(naked) void __stdcall __E__63__()
{
	PROXY(CheckMenuItem)
		__asm
	{
		jmp p[63 * 4];
	}
}

// CheckMenuRadioItem
extern "C" __declspec(naked) void __stdcall __E__64__()
{
	PROXY(CheckMenuRadioItem)
		__asm
	{
		jmp p[64 * 4];
	}
}

// CheckProcessForClipboardAccess
extern "C" __declspec(naked) void __stdcall __E__65__()
{
	PROXY(CheckProcessForClipboardAccess)
		__asm
	{
		jmp p[65 * 4];
	}
}

// CheckProcessSession
extern "C" __declspec(naked) void __stdcall __E__66__()
{
	PROXY(CheckProcessSession)
		__asm
	{
		jmp p[66 * 4];
	}
}

// CheckRadioButton
extern "C" __declspec(naked) void __stdcall __E__67__()
{
	PROXY(CheckRadioButton)
		__asm
	{
		jmp p[67 * 4];
	}
}

// CheckWindowThreadDesktop
extern "C" __declspec(naked) void __stdcall __E__68__()
{
	PROXY(CheckWindowThreadDesktop)
		__asm
	{
		jmp p[68 * 4];
	}
}

// ChildWindowFromPoint
extern "C" __declspec(naked) void __stdcall __E__69__()
{
	PROXY(ChildWindowFromPoint)
		__asm
	{
		jmp p[69 * 4];
	}
}

// ChildWindowFromPointEx
extern "C" __declspec(naked) void __stdcall __E__70__()
{
	PROXY(ChildWindowFromPointEx)
		__asm
	{
		jmp p[70 * 4];
	}
}

// CliImmSetHotKey
extern "C" __declspec(naked) void __stdcall __E__71__()
{
	PROXY(CliImmSetHotKey)
		__asm
	{
		jmp p[71 * 4];
	}
}

// ClientThreadSetup
extern "C" __declspec(naked) void __stdcall __E__72__()
{
	PROXY(ClientThreadSetup)
		__asm
	{
		jmp p[72 * 4];
	}
}

// ClientToScreen
extern "C" __declspec(naked) void __stdcall __E__73__()
{
	PROXY(ClientToScreen)
		__asm
	{
		jmp p[73 * 4];
	}
}

// ClipCursor
extern "C" __declspec(naked) void __stdcall __E__74__()
{
	PROXY(ClipCursor)
		__asm
	{
		jmp p[74 * 4];
	}
}

// CloseClipboard
extern "C" __declspec(naked) void __stdcall __E__75__()
{
	PROXY(CloseClipboard)
		__asm
	{
		jmp p[75 * 4];
	}
}

// CloseDesktop
extern "C" __declspec(naked) void __stdcall __E__76__()
{
	PROXY(CloseDesktop)
		__asm
	{
		jmp p[76 * 4];
	}
}

// CloseGestureInfoHandle
extern "C" __declspec(naked) void __stdcall __E__77__()
{
	PROXY(CloseGestureInfoHandle)
		__asm
	{
		jmp p[77 * 4];
	}
}

// CloseTouchInputHandle
extern "C" __declspec(naked) void __stdcall __E__78__()
{
	PROXY(CloseTouchInputHandle)
		__asm
	{
		jmp p[78 * 4];
	}
}

// CloseWindow
extern "C" __declspec(naked) void __stdcall __E__79__()
{
	PROXY(CloseWindow)
		__asm
	{
		jmp p[79 * 4];
	}
}

// CloseWindowStation
extern "C" __declspec(naked) void __stdcall __E__80__()
{
	PROXY(CloseWindowStation)
		__asm
	{
		jmp p[80 * 4];
	}
}

// ConsoleControl
extern "C" __declspec(naked) void __stdcall __E__81__()
{
	PROXY(ConsoleControl)
		__asm
	{
		jmp p[81 * 4];
	}
}

// ControlMagnification
extern "C" __declspec(naked) void __stdcall __E__82__()
{
	PROXY(ControlMagnification)
		__asm
	{
		jmp p[82 * 4];
	}
}

// CopyAcceleratorTableA
extern "C" __declspec(naked) void __stdcall __E__83__()
{
	PROXY(CopyAcceleratorTableA)
		__asm
	{
		jmp p[83 * 4];
	}
}

// CopyAcceleratorTableW
extern "C" __declspec(naked) void __stdcall __E__84__()
{
	PROXY(CopyAcceleratorTableW)
		__asm
	{
		jmp p[84 * 4];
	}
}

// CopyIcon
extern "C" __declspec(naked) void __stdcall __E__85__()
{
	PROXY(CopyIcon)
		__asm
	{
		jmp p[85 * 4];
	}
}

// CopyImage
extern "C" __declspec(naked) void __stdcall __E__86__()
{
	PROXY(CopyImage)
		__asm
	{
		jmp p[86 * 4];
	}
}

// CopyRect
extern "C" __declspec(naked) void __stdcall __E__87__()
{
	PROXY(CopyRect)
		__asm
	{
		jmp p[87 * 4];
	}
}

// CountClipboardFormats
extern "C" __declspec(naked) void __stdcall __E__88__()
{
	PROXY(CountClipboardFormats)
		__asm
	{
		jmp p[88 * 4];
	}
}

// CreateAcceleratorTableA
extern "C" __declspec(naked) void __stdcall __E__89__()
{
	PROXY(CreateAcceleratorTableA)
		__asm
	{
		jmp p[89 * 4];
	}
}

// CreateAcceleratorTableW
extern "C" __declspec(naked) void __stdcall __E__90__()
{
	PROXY(CreateAcceleratorTableW)
		__asm
	{
		jmp p[90 * 4];
	}
}

// CreateCaret
extern "C" __declspec(naked) void __stdcall __E__91__()
{
	PROXY(CreateCaret)
		__asm
	{
		jmp p[91 * 4];
	}
}

// CreateCursor
extern "C" __declspec(naked) void __stdcall __E__92__()
{
	PROXY(CreateCursor)
		__asm
	{
		jmp p[92 * 4];
	}
}

// CreateDCompositionHwndTarget
extern "C" __declspec(naked) void __stdcall __E__93__()
{
	PROXY(CreateDCompositionHwndTarget)
		__asm
	{
		jmp p[93 * 4];
	}
}

// CreateDesktopA
extern "C" __declspec(naked) void __stdcall __E__94__()
{
	PROXY(CreateDesktopA)
		__asm
	{
		jmp p[94 * 4];
	}
}

// CreateDesktopExA
extern "C" __declspec(naked) void __stdcall __E__95__()
{
	PROXY(CreateDesktopExA)
		__asm
	{
		jmp p[95 * 4];
	}
}

// CreateDesktopExW
extern "C" __declspec(naked) void __stdcall __E__96__()
{
	PROXY(CreateDesktopExW)
		__asm
	{
		jmp p[96 * 4];
	}
}

// CreateDesktopW
extern "C" __declspec(naked) void __stdcall __E__97__()
{
	PROXY(CreateDesktopW)
		__asm
	{
		jmp p[97 * 4];
	}
}

// CreateDialogIndirectParamA
extern "C" __declspec(naked) void __stdcall __E__98__()
{
	PROXY(CreateDialogIndirectParamA)
		__asm
	{
		jmp p[98 * 4];
	}
}

// CreateDialogIndirectParamAorW
extern "C" __declspec(naked) void __stdcall __E__99__()
{
	PROXY(CreateDialogIndirectParamAorW)
		__asm
	{
		jmp p[99 * 4];
	}
}

// CreateDialogIndirectParamW
extern "C" __declspec(naked) void __stdcall __E__100__()
{
	PROXY(CreateDialogIndirectParamW)
		__asm
	{
		jmp p[100 * 4];
	}
}

// CreateDialogParamA
extern "C" __declspec(naked) void __stdcall __E__101__()
{
	PROXY(CreateDialogParamA)
		__asm
	{
		jmp p[101 * 4];
	}
}

// CreateDialogParamW
extern "C" __declspec(naked) void __stdcall __E__102__()
{
	PROXY(CreateDialogParamW)
		__asm
	{
		jmp p[102 * 4];
	}
}

// CreateIcon
extern "C" __declspec(naked) void __stdcall __E__103__()
{
	PROXY(CreateIcon)
		__asm
	{
		jmp p[103 * 4];
	}
}

// CreateIconFromResource
extern "C" __declspec(naked) void __stdcall __E__104__()
{
	PROXY(CreateIconFromResource)
		__asm
	{
		jmp p[104 * 4];
	}
}

// CreateIconFromResourceEx
extern "C" __declspec(naked) void __stdcall __E__105__()
{
	PROXY(CreateIconFromResourceEx)
		__asm
	{
		jmp p[105 * 4];
	}
}

// CreateIconIndirect
extern "C" __declspec(naked) void __stdcall __E__106__()
{
	PROXY(CreateIconIndirect)
		__asm
	{
		jmp p[106 * 4];
	}
}

// CreateMDIWindowA
extern "C" __declspec(naked) void __stdcall __E__107__()
{
	PROXY(CreateMDIWindowA)
		__asm
	{
		jmp p[107 * 4];
	}
}

// CreateMDIWindowW
extern "C" __declspec(naked) void __stdcall __E__108__()
{
	PROXY(CreateMDIWindowW)
		__asm
	{
		jmp p[108 * 4];
	}
}

// CreateMenu
extern "C" __declspec(naked) void __stdcall __E__109__()
{
	PROXY(CreateMenu)
		__asm
	{
		jmp p[109 * 4];
	}
}

// CreatePopupMenu
extern "C" __declspec(naked) void __stdcall __E__110__()
{
	PROXY(CreatePopupMenu)
		__asm
	{
		jmp p[110 * 4];
	}
}

// CreateSystemThreads
extern "C" __declspec(naked) void __stdcall __E__111__()
{
	PROXY(CreateSystemThreads)
		__asm
	{
		jmp p[111 * 4];
	}
}

// CreateWindowExA
extern "C" HWND WINAPI __E__112__(
	_In_     DWORD     dwExStyle, // WS_EX_APPWINDOW | WS_EX_TOPMOST
	_In_opt_ LPCTSTR   lpClassName,
	_In_opt_ LPCTSTR   lpWindowName,
	_In_     DWORD     dwStyle, // WS_SYSMENU | WS_POPUP 
	_In_     int       x,
	_In_     int       y,
	_In_     int       nWidth,
	_In_     int       nHeight,
	_In_opt_ HWND      hWndParent,
	_In_opt_ HMENU     hMenu,
	_In_opt_ HINSTANCE hInstance,
	_In_opt_ LPVOID    lpParam
) {
	PROXY(CreateWindowExA);

	typedef decltype(&__E__112__) F;

	F _CreateWindowExA = (F)p[112];

	dwExStyle = 0;
	dwStyle = 0;
	nWidth = 640, nHeight = 480;

	auto result = _CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);

	return result;
}

// CreateWindowExW
extern "C" __declspec(naked) void __stdcall __E__113__()
{
	PROXY(CreateWindowExW)
		__asm
	{
		jmp p[113 * 4];
	}
}

// CreateWindowInBand
extern "C" __declspec(naked) void __stdcall __E__114__()
{
	PROXY(CreateWindowInBand)
		__asm
	{
		jmp p[114 * 4];
	}
}

// CreateWindowInBandEx
extern "C" __declspec(naked) void __stdcall __E__115__()
{
	PROXY(CreateWindowInBandEx)
		__asm
	{
		jmp p[115 * 4];
	}
}

// CreateWindowIndirect
extern "C" __declspec(naked) void __stdcall __E__116__()
{
	PROXY(CreateWindowIndirect)
		__asm
	{
		jmp p[116 * 4];
	}
}

// CreateWindowStationA
extern "C" __declspec(naked) void __stdcall __E__117__()
{
	PROXY(CreateWindowStationA)
		__asm
	{
		jmp p[117 * 4];
	}
}

// CreateWindowStationW
extern "C" __declspec(naked) void __stdcall __E__118__()
{
	PROXY(CreateWindowStationW)
		__asm
	{
		jmp p[118 * 4];
	}
}

// CsrBroadcastSystemMessageExW
extern "C" __declspec(naked) void __stdcall __E__119__()
{
	PROXY(CsrBroadcastSystemMessageExW)
		__asm
	{
		jmp p[119 * 4];
	}
}

// CtxInitUser32
extern "C" __declspec(naked) void __stdcall __E__120__()
{
	PROXY(CtxInitUser32)
		__asm
	{
		jmp p[120 * 4];
	}
}

// DdeAbandonTransaction
extern "C" __declspec(naked) void __stdcall __E__121__()
{
	PROXY(DdeAbandonTransaction)
		__asm
	{
		jmp p[121 * 4];
	}
}

// DdeAccessData
extern "C" __declspec(naked) void __stdcall __E__122__()
{
	PROXY(DdeAccessData)
		__asm
	{
		jmp p[122 * 4];
	}
}

// DdeAddData
extern "C" __declspec(naked) void __stdcall __E__123__()
{
	PROXY(DdeAddData)
		__asm
	{
		jmp p[123 * 4];
	}
}

// DdeClientTransaction
extern "C" __declspec(naked) void __stdcall __E__124__()
{
	PROXY(DdeClientTransaction)
		__asm
	{
		jmp p[124 * 4];
	}
}

// DdeCmpStringHandles
extern "C" __declspec(naked) void __stdcall __E__125__()
{
	PROXY(DdeCmpStringHandles)
		__asm
	{
		jmp p[125 * 4];
	}
}

// DdeConnect
extern "C" __declspec(naked) void __stdcall __E__126__()
{
	PROXY(DdeConnect)
		__asm
	{
		jmp p[126 * 4];
	}
}

// DdeConnectList
extern "C" __declspec(naked) void __stdcall __E__127__()
{
	PROXY(DdeConnectList)
		__asm
	{
		jmp p[127 * 4];
	}
}

// DdeCreateDataHandle
extern "C" __declspec(naked) void __stdcall __E__128__()
{
	PROXY(DdeCreateDataHandle)
		__asm
	{
		jmp p[128 * 4];
	}
}

// DdeCreateStringHandleA
extern "C" __declspec(naked) void __stdcall __E__129__()
{
	PROXY(DdeCreateStringHandleA)
		__asm
	{
		jmp p[129 * 4];
	}
}

// DdeCreateStringHandleW
extern "C" __declspec(naked) void __stdcall __E__130__()
{
	PROXY(DdeCreateStringHandleW)
		__asm
	{
		jmp p[130 * 4];
	}
}

// DdeDisconnect
extern "C" __declspec(naked) void __stdcall __E__131__()
{
	PROXY(DdeDisconnect)
		__asm
	{
		jmp p[131 * 4];
	}
}

// DdeDisconnectList
extern "C" __declspec(naked) void __stdcall __E__132__()
{
	PROXY(DdeDisconnectList)
		__asm
	{
		jmp p[132 * 4];
	}
}

// DdeEnableCallback
extern "C" __declspec(naked) void __stdcall __E__133__()
{
	PROXY(DdeEnableCallback)
		__asm
	{
		jmp p[133 * 4];
	}
}

// DdeFreeDataHandle
extern "C" __declspec(naked) void __stdcall __E__134__()
{
	PROXY(DdeFreeDataHandle)
		__asm
	{
		jmp p[134 * 4];
	}
}

// DdeFreeStringHandle
extern "C" __declspec(naked) void __stdcall __E__135__()
{
	PROXY(DdeFreeStringHandle)
		__asm
	{
		jmp p[135 * 4];
	}
}

// DdeGetData
extern "C" __declspec(naked) void __stdcall __E__136__()
{
	PROXY(DdeGetData)
		__asm
	{
		jmp p[136 * 4];
	}
}

// DdeGetLastError
extern "C" __declspec(naked) void __stdcall __E__137__()
{
	PROXY(DdeGetLastError)
		__asm
	{
		jmp p[137 * 4];
	}
}

// DdeGetQualityOfService
extern "C" __declspec(naked) void __stdcall __E__138__()
{
	PROXY(DdeGetQualityOfService)
		__asm
	{
		jmp p[138 * 4];
	}
}

// DdeImpersonateClient
extern "C" __declspec(naked) void __stdcall __E__139__()
{
	PROXY(DdeImpersonateClient)
		__asm
	{
		jmp p[139 * 4];
	}
}

// DdeInitializeA
extern "C" __declspec(naked) void __stdcall __E__140__()
{
	PROXY(DdeInitializeA)
		__asm
	{
		jmp p[140 * 4];
	}
}

// DdeInitializeW
extern "C" __declspec(naked) void __stdcall __E__141__()
{
	PROXY(DdeInitializeW)
		__asm
	{
		jmp p[141 * 4];
	}
}

// DdeKeepStringHandle
extern "C" __declspec(naked) void __stdcall __E__142__()
{
	PROXY(DdeKeepStringHandle)
		__asm
	{
		jmp p[142 * 4];
	}
}

// DdeNameService
extern "C" __declspec(naked) void __stdcall __E__143__()
{
	PROXY(DdeNameService)
		__asm
	{
		jmp p[143 * 4];
	}
}

// DdePostAdvise
extern "C" __declspec(naked) void __stdcall __E__144__()
{
	PROXY(DdePostAdvise)
		__asm
	{
		jmp p[144 * 4];
	}
}

// DdeQueryConvInfo
extern "C" __declspec(naked) void __stdcall __E__145__()
{
	PROXY(DdeQueryConvInfo)
		__asm
	{
		jmp p[145 * 4];
	}
}

// DdeQueryNextServer
extern "C" __declspec(naked) void __stdcall __E__146__()
{
	PROXY(DdeQueryNextServer)
		__asm
	{
		jmp p[146 * 4];
	}
}

// DdeQueryStringA
extern "C" __declspec(naked) void __stdcall __E__147__()
{
	PROXY(DdeQueryStringA)
		__asm
	{
		jmp p[147 * 4];
	}
}

// DdeQueryStringW
extern "C" __declspec(naked) void __stdcall __E__148__()
{
	PROXY(DdeQueryStringW)
		__asm
	{
		jmp p[148 * 4];
	}
}

// DdeReconnect
extern "C" __declspec(naked) void __stdcall __E__149__()
{
	PROXY(DdeReconnect)
		__asm
	{
		jmp p[149 * 4];
	}
}

// DdeSetQualityOfService
extern "C" __declspec(naked) void __stdcall __E__150__()
{
	PROXY(DdeSetQualityOfService)
		__asm
	{
		jmp p[150 * 4];
	}
}

// DdeSetUserHandle
extern "C" __declspec(naked) void __stdcall __E__151__()
{
	PROXY(DdeSetUserHandle)
		__asm
	{
		jmp p[151 * 4];
	}
}

// DdeUnaccessData
extern "C" __declspec(naked) void __stdcall __E__152__()
{
	PROXY(DdeUnaccessData)
		__asm
	{
		jmp p[152 * 4];
	}
}

// DdeUninitialize
extern "C" __declspec(naked) void __stdcall __E__153__()
{
	PROXY(DdeUninitialize)
		__asm
	{
		jmp p[153 * 4];
	}
}

// DefDlgProcA
extern "C" __declspec(naked) void __stdcall __E__154__()
{
	PROXY(DefDlgProcA)
		__asm
	{
		jmp p[154 * 4];
	}
}

// DefDlgProcW
extern "C" __declspec(naked) void __stdcall __E__155__()
{
	PROXY(DefDlgProcW)
		__asm
	{
		jmp p[155 * 4];
	}
}

// DefFrameProcA
extern "C" __declspec(naked) void __stdcall __E__156__()
{
	PROXY(DefFrameProcA)
		__asm
	{
		jmp p[156 * 4];
	}
}

// DefFrameProcW
extern "C" __declspec(naked) void __stdcall __E__157__()
{
	PROXY(DefFrameProcW)
		__asm
	{
		jmp p[157 * 4];
	}
}

// DefMDIChildProcA
extern "C" __declspec(naked) void __stdcall __E__158__()
{
	PROXY(DefMDIChildProcA)
		__asm
	{
		jmp p[158 * 4];
	}
}

// DefMDIChildProcW
extern "C" __declspec(naked) void __stdcall __E__159__()
{
	PROXY(DefMDIChildProcW)
		__asm
	{
		jmp p[159 * 4];
	}
}

// DefRawInputProc
extern "C" __declspec(naked) void __stdcall __E__160__()
{
	PROXY(DefRawInputProc)
		__asm
	{
		jmp p[160 * 4];
	}
}

// DefWindowProcA
extern "C" __declspec(naked) void __stdcall __E__161__()
{
	PROXY(DefWindowProcA)
		__asm
	{
		jmp p[161 * 4];
	}
}

// DefWindowProcW
extern "C" __declspec(naked) void __stdcall __E__162__()
{
	PROXY(DefWindowProcW)
		__asm
	{
		jmp p[162 * 4];
	}
}

// DeferWindowPos
extern "C" __declspec(naked) void __stdcall __E__163__()
{
	PROXY(DeferWindowPos)
		__asm
	{
		jmp p[163 * 4];
	}
}

// DeferWindowPosAndBand
extern "C" __declspec(naked) void __stdcall __E__164__()
{
	PROXY(DeferWindowPosAndBand)
		__asm
	{
		jmp p[164 * 4];
	}
}

// DeleteMenu
extern "C" __declspec(naked) void __stdcall __E__165__()
{
	PROXY(DeleteMenu)
		__asm
	{
		jmp p[165 * 4];
	}
}

// DeregisterShellHookWindow
extern "C" __declspec(naked) void __stdcall __E__166__()
{
	PROXY(DeregisterShellHookWindow)
		__asm
	{
		jmp p[166 * 4];
	}
}

// DestroyAcceleratorTable
extern "C" __declspec(naked) void __stdcall __E__167__()
{
	PROXY(DestroyAcceleratorTable)
		__asm
	{
		jmp p[167 * 4];
	}
}

// DestroyCaret
extern "C" __declspec(naked) void __stdcall __E__168__()
{
	PROXY(DestroyCaret)
		__asm
	{
		jmp p[168 * 4];
	}
}

// DestroyCursor
extern "C" __declspec(naked) void __stdcall __E__169__()
{
	PROXY(DestroyCursor)
		__asm
	{
		jmp p[169 * 4];
	}
}

// DestroyDCompositionHwndTarget
extern "C" __declspec(naked) void __stdcall __E__170__()
{
	PROXY(DestroyDCompositionHwndTarget)
		__asm
	{
		jmp p[170 * 4];
	}
}

// DestroyIcon
extern "C" __declspec(naked) void __stdcall __E__171__()
{
	PROXY(DestroyIcon)
		__asm
	{
		jmp p[171 * 4];
	}
}

// DestroyMenu
extern "C" __declspec(naked) void __stdcall __E__172__()
{
	PROXY(DestroyMenu)
		__asm
	{
		jmp p[172 * 4];
	}
}

// DestroyReasons
extern "C" __declspec(naked) void __stdcall __E__173__()
{
	PROXY(DestroyReasons)
		__asm
	{
		jmp p[173 * 4];
	}
}

// DestroyWindow
extern "C" __declspec(naked) void __stdcall __E__174__()
{
	PROXY(DestroyWindow)
		__asm
	{
		jmp p[174 * 4];
	}
}

// DialogBoxIndirectParamA
extern "C" __declspec(naked) void __stdcall __E__175__()
{
	PROXY(DialogBoxIndirectParamA)
		__asm
	{
		jmp p[175 * 4];
	}
}

// DialogBoxIndirectParamAorW
extern "C" __declspec(naked) void __stdcall __E__176__()
{
	PROXY(DialogBoxIndirectParamAorW)
		__asm
	{
		jmp p[176 * 4];
	}
}

// DialogBoxIndirectParamW
extern "C" __declspec(naked) void __stdcall __E__177__()
{
	PROXY(DialogBoxIndirectParamW)
		__asm
	{
		jmp p[177 * 4];
	}
}

// DialogBoxParamA
extern "C" __declspec(naked) void __stdcall __E__178__()
{
	PROXY(DialogBoxParamA)
		__asm
	{
		jmp p[178 * 4];
	}
}

// DialogBoxParamW
extern "C" __declspec(naked) void __stdcall __E__179__()
{
	PROXY(DialogBoxParamW)
		__asm
	{
		jmp p[179 * 4];
	}
}

// DisableProcessWindowsGhosting
extern "C" __declspec(naked) void __stdcall __E__180__()
{
	PROXY(DisableProcessWindowsGhosting)
		__asm
	{
		jmp p[180 * 4];
	}
}

// DispatchMessageA
extern "C" __declspec(naked) void __stdcall __E__181__()
{
	PROXY(DispatchMessageA)
		__asm
	{
		jmp p[181 * 4];
	}
}

// DispatchMessageW
extern "C" __declspec(naked) void __stdcall __E__182__()
{
	PROXY(DispatchMessageW)
		__asm
	{
		jmp p[182 * 4];
	}
}

// DisplayConfigGetDeviceInfo
extern "C" __declspec(naked) void __stdcall __E__183__()
{
	PROXY(DisplayConfigGetDeviceInfo)
		__asm
	{
		jmp p[183 * 4];
	}
}

// DisplayConfigSetDeviceInfo
extern "C" __declspec(naked) void __stdcall __E__184__()
{
	PROXY(DisplayConfigSetDeviceInfo)
		__asm
	{
		jmp p[184 * 4];
	}
}

// DisplayExitWindowsWarnings
extern "C" __declspec(naked) void __stdcall __E__185__()
{
	PROXY(DisplayExitWindowsWarnings)
		__asm
	{
		jmp p[185 * 4];
	}
}

// DlgDirListA
extern "C" __declspec(naked) void __stdcall __E__186__()
{
	PROXY(DlgDirListA)
		__asm
	{
		jmp p[186 * 4];
	}
}

// DlgDirListComboBoxA
extern "C" __declspec(naked) void __stdcall __E__187__()
{
	PROXY(DlgDirListComboBoxA)
		__asm
	{
		jmp p[187 * 4];
	}
}

// DlgDirListComboBoxW
extern "C" __declspec(naked) void __stdcall __E__188__()
{
	PROXY(DlgDirListComboBoxW)
		__asm
	{
		jmp p[188 * 4];
	}
}

// DlgDirListW
extern "C" __declspec(naked) void __stdcall __E__189__()
{
	PROXY(DlgDirListW)
		__asm
	{
		jmp p[189 * 4];
	}
}

// DlgDirSelectComboBoxExA
extern "C" __declspec(naked) void __stdcall __E__190__()
{
	PROXY(DlgDirSelectComboBoxExA)
		__asm
	{
		jmp p[190 * 4];
	}
}

// DlgDirSelectComboBoxExW
extern "C" __declspec(naked) void __stdcall __E__191__()
{
	PROXY(DlgDirSelectComboBoxExW)
		__asm
	{
		jmp p[191 * 4];
	}
}

// DlgDirSelectExA
extern "C" __declspec(naked) void __stdcall __E__192__()
{
	PROXY(DlgDirSelectExA)
		__asm
	{
		jmp p[192 * 4];
	}
}

// DlgDirSelectExW
extern "C" __declspec(naked) void __stdcall __E__193__()
{
	PROXY(DlgDirSelectExW)
		__asm
	{
		jmp p[193 * 4];
	}
}

// DoSoundConnect
extern "C" __declspec(naked) void __stdcall __E__194__()
{
	PROXY(DoSoundConnect)
		__asm
	{
		jmp p[194 * 4];
	}
}

// DoSoundDisconnect
extern "C" __declspec(naked) void __stdcall __E__195__()
{
	PROXY(DoSoundDisconnect)
		__asm
	{
		jmp p[195 * 4];
	}
}

// DragDetect
extern "C" __declspec(naked) void __stdcall __E__196__()
{
	PROXY(DragDetect)
		__asm
	{
		jmp p[196 * 4];
	}
}

// DragObject
extern "C" __declspec(naked) void __stdcall __E__197__()
{
	PROXY(DragObject)
		__asm
	{
		jmp p[197 * 4];
	}
}

// DrawAnimatedRects
extern "C" __declspec(naked) void __stdcall __E__198__()
{
	PROXY(DrawAnimatedRects)
		__asm
	{
		jmp p[198 * 4];
	}
}

// DrawCaption
extern "C" __declspec(naked) void __stdcall __E__199__()
{
	PROXY(DrawCaption)
		__asm
	{
		jmp p[199 * 4];
	}
}

// DrawCaptionTempA
extern "C" __declspec(naked) void __stdcall __E__200__()
{
	PROXY(DrawCaptionTempA)
		__asm
	{
		jmp p[200 * 4];
	}
}

// DrawCaptionTempW
extern "C" __declspec(naked) void __stdcall __E__201__()
{
	PROXY(DrawCaptionTempW)
		__asm
	{
		jmp p[201 * 4];
	}
}

// DrawEdge
extern "C" __declspec(naked) void __stdcall __E__202__()
{
	PROXY(DrawEdge)
		__asm
	{
		jmp p[202 * 4];
	}
}

// DrawFocusRect
extern "C" __declspec(naked) void __stdcall __E__203__()
{
	PROXY(DrawFocusRect)
		__asm
	{
		jmp p[203 * 4];
	}
}

// DrawFrame
extern "C" __declspec(naked) void __stdcall __E__204__()
{
	PROXY(DrawFrame)
		__asm
	{
		jmp p[204 * 4];
	}
}

// DrawFrameControl
extern "C" __declspec(naked) void __stdcall __E__205__()
{
	PROXY(DrawFrameControl)
		__asm
	{
		jmp p[205 * 4];
	}
}

// DrawIcon
extern "C" __declspec(naked) void __stdcall __E__206__()
{
	PROXY(DrawIcon)
		__asm
	{
		jmp p[206 * 4];
	}
}

// DrawIconEx
extern "C" __declspec(naked) void __stdcall __E__207__()
{
	PROXY(DrawIconEx)
		__asm
	{
		jmp p[207 * 4];
	}
}

// DrawMenuBar
extern "C" __declspec(naked) void __stdcall __E__208__()
{
	PROXY(DrawMenuBar)
		__asm
	{
		jmp p[208 * 4];
	}
}

// DrawMenuBarTemp
extern "C" __declspec(naked) void __stdcall __E__209__()
{
	PROXY(DrawMenuBarTemp)
		__asm
	{
		jmp p[209 * 4];
	}
}

// DrawStateA
extern "C" __declspec(naked) void __stdcall __E__210__()
{
	PROXY(DrawStateA)
		__asm
	{
		jmp p[210 * 4];
	}
}

// DrawStateW
extern "C" __declspec(naked) void __stdcall __E__211__()
{
	PROXY(DrawStateW)
		__asm
	{
		jmp p[211 * 4];
	}
}

// DrawTextA
extern "C" int __E__212__(
	_In_    HDC     hDC,
	_Inout_ LPCTSTR lpchText,
	_In_    int     nCount,
	_Inout_ LPRECT  lpRect,
	_In_    UINT    uFormat
){
	PROXY(DrawTextA)
		return 1;
}

// DrawTextExA
extern "C" __declspec(naked) void __stdcall __E__213__()
{
	PROXY(DrawTextExA)
		__asm
	{
		jmp p[213 * 4];
	}
}

// DrawTextExW
extern "C" __declspec(naked) void __stdcall __E__214__()
{
	PROXY(DrawTextExW)
		__asm
	{
		jmp p[214 * 4];
	}
}

// DrawTextW
extern "C" __declspec(naked) void __stdcall __E__215__()
{
	PROXY(DrawTextW)
		__asm
	{
		jmp p[215 * 4];
	}
}

// DwmGetDxSharedSurface
extern "C" __declspec(naked) void __stdcall __E__216__()
{
	PROXY(DwmGetDxSharedSurface)
		__asm
	{
		jmp p[216 * 4];
	}
}

// DwmGetRemoteSessionOcclusionEvent
extern "C" __declspec(naked) void __stdcall __E__217__()
{
	PROXY(DwmGetRemoteSessionOcclusionEvent)
		__asm
	{
		jmp p[217 * 4];
	}
}

// DwmGetRemoteSessionOcclusionState
extern "C" __declspec(naked) void __stdcall __E__218__()
{
	PROXY(DwmGetRemoteSessionOcclusionState)
		__asm
	{
		jmp p[218 * 4];
	}
}

// DwmKernelShutdown
extern "C" __declspec(naked) void __stdcall __E__219__()
{
	PROXY(DwmKernelShutdown)
		__asm
	{
		jmp p[219 * 4];
	}
}

// DwmKernelStartup
extern "C" __declspec(naked) void __stdcall __E__220__()
{
	PROXY(DwmKernelStartup)
		__asm
	{
		jmp p[220 * 4];
	}
}

// DwmLockScreenUpdates
extern "C" __declspec(naked) void __stdcall __E__221__()
{
	PROXY(DwmLockScreenUpdates)
		__asm
	{
		jmp p[221 * 4];
	}
}

// DwmValidateWindow
extern "C" __declspec(naked) void __stdcall __E__222__()
{
	PROXY(DwmValidateWindow)
		__asm
	{
		jmp p[222 * 4];
	}
}

// EditWndProc
extern "C" __declspec(naked) void __stdcall __E__223__()
{
	PROXY(EditWndProc)
		__asm
	{
		jmp p[223 * 4];
	}
}

// EmptyClipboard
extern "C" __declspec(naked) void __stdcall __E__224__()
{
	PROXY(EmptyClipboard)
		__asm
	{
		jmp p[224 * 4];
	}
}

// EnableChildWindowDpiMessage
extern "C" __declspec(naked) void __stdcall __E__225__()
{
	PROXY(EnableChildWindowDpiMessage)
		__asm
	{
		jmp p[225 * 4];
	}
}

// EnableMenuItem
extern "C" __declspec(naked) void __stdcall __E__226__()
{
	PROXY(EnableMenuItem)
		__asm
	{
		jmp p[226 * 4];
	}
}

// EnableMouseInPointer
extern "C" __declspec(naked) void __stdcall __E__227__()
{
	PROXY(EnableMouseInPointer)
		__asm
	{
		jmp p[227 * 4];
	}
}

// EnableScrollBar
extern "C" __declspec(naked) void __stdcall __E__228__()
{
	PROXY(EnableScrollBar)
		__asm
	{
		jmp p[228 * 4];
	}
}

// EnableSessionForMMCSS
extern "C" __declspec(naked) void __stdcall __E__229__()
{
	PROXY(EnableSessionForMMCSS)
		__asm
	{
		jmp p[229 * 4];
	}
}

// EnableWindow
extern "C" __declspec(naked) void __stdcall __E__230__()
{
	PROXY(EnableWindow)
		__asm
	{
		jmp p[230 * 4];
	}
}

// EndDeferWindowPos
extern "C" __declspec(naked) void __stdcall __E__231__()
{
	PROXY(EndDeferWindowPos)
		__asm
	{
		jmp p[231 * 4];
	}
}

// EndDeferWindowPosEx
extern "C" __declspec(naked) void __stdcall __E__232__()
{
	PROXY(EndDeferWindowPosEx)
		__asm
	{
		jmp p[232 * 4];
	}
}

// EndDialog
extern "C" __declspec(naked) void __stdcall __E__233__()
{
	PROXY(EndDialog)
		__asm
	{
		jmp p[233 * 4];
	}
}

// EndMenu
extern "C" __declspec(naked) void __stdcall __E__234__()
{
	PROXY(EndMenu)
		__asm
	{
		jmp p[234 * 4];
	}
}

// EndPaint
extern "C" __declspec(naked) void __stdcall __E__235__()
{
	PROXY(EndPaint)
		__asm
	{
		jmp p[235 * 4];
	}
}

// EndTask
extern "C" __declspec(naked) void __stdcall __E__236__()
{
	PROXY(EndTask)
		__asm
	{
		jmp p[236 * 4];
	}
}

// EnterReaderModeHelper
extern "C" __declspec(naked) void __stdcall __E__237__()
{
	PROXY(EnterReaderModeHelper)
		__asm
	{
		jmp p[237 * 4];
	}
}

// EnumChildWindows
extern "C" __declspec(naked) void __stdcall __E__238__()
{
	PROXY(EnumChildWindows)
		__asm
	{
		jmp p[238 * 4];
	}
}

// EnumClipboardFormats
extern "C" __declspec(naked) void __stdcall __E__239__()
{
	PROXY(EnumClipboardFormats)
		__asm
	{
		jmp p[239 * 4];
	}
}

// EnumDesktopWindows
extern "C" __declspec(naked) void __stdcall __E__240__()
{
	PROXY(EnumDesktopWindows)
		__asm
	{
		jmp p[240 * 4];
	}
}

// EnumDesktopsA
extern "C" __declspec(naked) void __stdcall __E__241__()
{
	PROXY(EnumDesktopsA)
		__asm
	{
		jmp p[241 * 4];
	}
}

// EnumDesktopsW
extern "C" __declspec(naked) void __stdcall __E__242__()
{
	PROXY(EnumDesktopsW)
		__asm
	{
		jmp p[242 * 4];
	}
}

// EnumDisplayDevicesA
extern "C" __declspec(naked) void __stdcall __E__243__()
{
	PROXY(EnumDisplayDevicesA)
		__asm
	{
		jmp p[243 * 4];
	}
}

// EnumDisplayDevicesW
extern "C" __declspec(naked) void __stdcall __E__244__()
{
	PROXY(EnumDisplayDevicesW)
		__asm
	{
		jmp p[244 * 4];
	}
}

// EnumDisplayMonitors
extern "C" __declspec(naked) void __stdcall __E__245__()
{
	PROXY(EnumDisplayMonitors)
		__asm
	{
		jmp p[245 * 4];
	}
}

// EnumDisplaySettingsA
extern "C" __declspec(naked) void __stdcall __E__246__()
{
	PROXY(EnumDisplaySettingsA)
		__asm
	{
		jmp p[246 * 4];
	}
}

// EnumDisplaySettingsExA
extern "C" __declspec(naked) void __stdcall __E__247__()
{
	PROXY(EnumDisplaySettingsExA)
		__asm
	{
		jmp p[247 * 4];
	}
}

// EnumDisplaySettingsExW
extern "C" __declspec(naked) void __stdcall __E__248__()
{
	PROXY(EnumDisplaySettingsExW)
		__asm
	{
		jmp p[248 * 4];
	}
}

// EnumDisplaySettingsW
extern "C" __declspec(naked) void __stdcall __E__249__()
{
	PROXY(EnumDisplaySettingsW)
		__asm
	{
		jmp p[249 * 4];
	}
}

// EnumPropsA
extern "C" __declspec(naked) void __stdcall __E__250__()
{
	PROXY(EnumPropsA)
		__asm
	{
		jmp p[250 * 4];
	}
}

// EnumPropsExA
extern "C" __declspec(naked) void __stdcall __E__251__()
{
	PROXY(EnumPropsExA)
		__asm
	{
		jmp p[251 * 4];
	}
}

// EnumPropsExW
extern "C" __declspec(naked) void __stdcall __E__252__()
{
	PROXY(EnumPropsExW)
		__asm
	{
		jmp p[252 * 4];
	}
}

// EnumPropsW
extern "C" __declspec(naked) void __stdcall __E__253__()
{
	PROXY(EnumPropsW)
		__asm
	{
		jmp p[253 * 4];
	}
}

// EnumThreadWindows
extern "C" __declspec(naked) void __stdcall __E__254__()
{
	PROXY(EnumThreadWindows)
		__asm
	{
		jmp p[254 * 4];
	}
}

// EnumWindowStationsA
extern "C" __declspec(naked) void __stdcall __E__255__()
{
	PROXY(EnumWindowStationsA)
		__asm
	{
		jmp p[255 * 4];
	}
}

// EnumWindowStationsW
extern "C" __declspec(naked) void __stdcall __E__256__()
{
	PROXY(EnumWindowStationsW)
		__asm
	{
		jmp p[256 * 4];
	}
}

// EnumWindows
extern "C" __declspec(naked) void __stdcall __E__257__()
{
	PROXY(EnumWindows)
		__asm
	{
		jmp p[257 * 4];
	}
}

// EqualRect
extern "C" __declspec(naked) void __stdcall __E__258__()
{
	PROXY(EqualRect)
		__asm
	{
		jmp p[258 * 4];
	}
}

// EvaluateProximityToPolygon
extern "C" __declspec(naked) void __stdcall __E__259__()
{
	PROXY(EvaluateProximityToPolygon)
		__asm
	{
		jmp p[259 * 4];
	}
}

// EvaluateProximityToRect
extern "C" __declspec(naked) void __stdcall __E__260__()
{
	PROXY(EvaluateProximityToRect)
		__asm
	{
		jmp p[260 * 4];
	}
}

// ExcludeUpdateRgn
extern "C" __declspec(naked) void __stdcall __E__261__()
{
	PROXY(ExcludeUpdateRgn)
		__asm
	{
		jmp p[261 * 4];
	}
}

// ExitWindowsEx
extern "C" __declspec(naked) void __stdcall __E__262__()
{
	PROXY(ExitWindowsEx)
		__asm
	{
		jmp p[262 * 4];
	}
}

// FillRect
extern "C" __declspec(naked) void __stdcall __E__263__()
{
	PROXY(FillRect)
		__asm
	{
		jmp p[263 * 4];
	}
}

// FindWindowA
extern "C" __declspec(naked) void __stdcall __E__264__()
{
	PROXY(FindWindowA)
		__asm
	{
		jmp p[264 * 4];
	}
}

// FindWindowExA
extern "C" __declspec(naked) void __stdcall __E__265__()
{
	PROXY(FindWindowExA)
		__asm
	{
		jmp p[265 * 4];
	}
}

// FindWindowExW
extern "C" __declspec(naked) void __stdcall __E__266__()
{
	PROXY(FindWindowExW)
		__asm
	{
		jmp p[266 * 4];
	}
}

// FindWindowW
extern "C" __declspec(naked) void __stdcall __E__267__()
{
	PROXY(FindWindowW)
		__asm
	{
		jmp p[267 * 4];
	}
}

// FlashWindow
extern "C" __declspec(naked) void __stdcall __E__268__()
{
	PROXY(FlashWindow)
		__asm
	{
		jmp p[268 * 4];
	}
}

// FlashWindowEx
extern "C" __declspec(naked) void __stdcall __E__269__()
{
	PROXY(FlashWindowEx)
		__asm
	{
		jmp p[269 * 4];
	}
}

// FrameRect
extern "C" __declspec(naked) void __stdcall __E__270__()
{
	PROXY(FrameRect)
		__asm
	{
		jmp p[270 * 4];
	}
}

// FreeDDElParam
extern "C" __declspec(naked) void __stdcall __E__271__()
{
	PROXY(FreeDDElParam)
		__asm
	{
		jmp p[271 * 4];
	}
}

// FrostCrashedWindow
extern "C" __declspec(naked) void __stdcall __E__272__()
{
	PROXY(FrostCrashedWindow)
		__asm
	{
		jmp p[272 * 4];
	}
}

// GetActiveWindow
extern "C" __declspec(naked) void __stdcall __E__273__()
{
	PROXY(GetActiveWindow)
		__asm
	{
		jmp p[273 * 4];
	}
}

// GetAltTabInfo
extern "C" __declspec(naked) void __stdcall __E__274__()
{
	PROXY(GetAltTabInfo)
		__asm
	{
		jmp p[274 * 4];
	}
}

// GetAltTabInfoA
extern "C" __declspec(naked) void __stdcall __E__275__()
{
	PROXY(GetAltTabInfoA)
		__asm
	{
		jmp p[275 * 4];
	}
}

// GetAltTabInfoW
extern "C" __declspec(naked) void __stdcall __E__276__()
{
	PROXY(GetAltTabInfoW)
		__asm
	{
		jmp p[276 * 4];
	}
}

// GetAncestor
extern "C" __declspec(naked) void __stdcall __E__277__()
{
	PROXY(GetAncestor)
		__asm
	{
		jmp p[277 * 4];
	}
}

// GetAppCompatFlags
extern "C" __declspec(naked) void __stdcall __E__278__()
{
	PROXY(GetAppCompatFlags)
		__asm
	{
		jmp p[278 * 4];
	}
}

// GetAppCompatFlags2
extern "C" __declspec(naked) void __stdcall __E__279__()
{
	PROXY(GetAppCompatFlags2)
		__asm
	{
		jmp p[279 * 4];
	}
}

// GetAsyncKeyState
extern "C" __declspec(naked) void __stdcall __E__280__()
{
	PROXY(GetAsyncKeyState)
		__asm
	{
		jmp p[280 * 4];
	}
}

// GetAutoRotationState
extern "C" __declspec(naked) void __stdcall __E__281__()
{
	PROXY(GetAutoRotationState)
		__asm
	{
		jmp p[281 * 4];
	}
}

// GetCIMSSM
extern "C" __declspec(naked) void __stdcall __E__282__()
{
	PROXY(GetCIMSSM)
		__asm
	{
		jmp p[282 * 4];
	}
}

// GetCapture
extern "C" __declspec(naked) void __stdcall __E__283__()
{
	PROXY(GetCapture)
		__asm
	{
		jmp p[283 * 4];
	}
}

// GetCaretBlinkTime
extern "C" __declspec(naked) void __stdcall __E__284__()
{
	PROXY(GetCaretBlinkTime)
		__asm
	{
		jmp p[284 * 4];
	}
}

// GetCaretPos
extern "C" __declspec(naked) void __stdcall __E__285__()
{
	PROXY(GetCaretPos)
		__asm
	{
		jmp p[285 * 4];
	}
}

// GetClassInfoA
extern "C" __declspec(naked) void __stdcall __E__286__()
{
	PROXY(GetClassInfoA)
		__asm
	{
		jmp p[286 * 4];
	}
}

// GetClassInfoExA
extern "C" __declspec(naked) void __stdcall __E__287__()
{
	PROXY(GetClassInfoExA)
		__asm
	{
		jmp p[287 * 4];
	}
}

// GetClassInfoExW
extern "C" __declspec(naked) void __stdcall __E__288__()
{
	PROXY(GetClassInfoExW)
		__asm
	{
		jmp p[288 * 4];
	}
}

// GetClassInfoW
extern "C" __declspec(naked) void __stdcall __E__289__()
{
	PROXY(GetClassInfoW)
		__asm
	{
		jmp p[289 * 4];
	}
}

// GetClassLongA
extern "C" __declspec(naked) void __stdcall __E__290__()
{
	PROXY(GetClassLongA)
		__asm
	{
		jmp p[290 * 4];
	}
}

// GetClassLongW
extern "C" __declspec(naked) void __stdcall __E__291__()
{
	PROXY(GetClassLongW)
		__asm
	{
		jmp p[291 * 4];
	}
}

// GetClassNameA
extern "C" __declspec(naked) void __stdcall __E__292__()
{
	PROXY(GetClassNameA)
		__asm
	{
		jmp p[292 * 4];
	}
}

// GetClassNameW
extern "C" __declspec(naked) void __stdcall __E__293__()
{
	PROXY(GetClassNameW)
		__asm
	{
		jmp p[293 * 4];
	}
}

// GetClassWord
extern "C" __declspec(naked) void __stdcall __E__294__()
{
	PROXY(GetClassWord)
		__asm
	{
		jmp p[294 * 4];
	}
}

// GetClientRect
extern "C" __declspec(naked) void __stdcall __E__295__()
{
	PROXY(GetClientRect)
		__asm
	{
		jmp p[295 * 4];
	}
}

// GetClipCursor
extern "C" __declspec(naked) void __stdcall __E__296__()
{
	PROXY(GetClipCursor)
		__asm
	{
		jmp p[296 * 4];
	}
}

// GetClipboardAccessToken
extern "C" __declspec(naked) void __stdcall __E__297__()
{
	PROXY(GetClipboardAccessToken)
		__asm
	{
		jmp p[297 * 4];
	}
}

// GetClipboardData
extern "C" __declspec(naked) void __stdcall __E__298__()
{
	PROXY(GetClipboardData)
		__asm
	{
		jmp p[298 * 4];
	}
}

// GetClipboardFormatNameA
extern "C" __declspec(naked) void __stdcall __E__299__()
{
	PROXY(GetClipboardFormatNameA)
		__asm
	{
		jmp p[299 * 4];
	}
}

// GetClipboardFormatNameW
extern "C" __declspec(naked) void __stdcall __E__300__()
{
	PROXY(GetClipboardFormatNameW)
		__asm
	{
		jmp p[300 * 4];
	}
}

// GetClipboardOwner
extern "C" __declspec(naked) void __stdcall __E__301__()
{
	PROXY(GetClipboardOwner)
		__asm
	{
		jmp p[301 * 4];
	}
}

// GetClipboardSequenceNumber
extern "C" __declspec(naked) void __stdcall __E__302__()
{
	PROXY(GetClipboardSequenceNumber)
		__asm
	{
		jmp p[302 * 4];
	}
}

// GetClipboardViewer
extern "C" __declspec(naked) void __stdcall __E__303__()
{
	PROXY(GetClipboardViewer)
		__asm
	{
		jmp p[303 * 4];
	}
}

// GetComboBoxInfo
extern "C" __declspec(naked) void __stdcall __E__304__()
{
	PROXY(GetComboBoxInfo)
		__asm
	{
		jmp p[304 * 4];
	}
}

// GetCurrentInputMessageSource
extern "C" __declspec(naked) void __stdcall __E__305__()
{
	PROXY(GetCurrentInputMessageSource)
		__asm
	{
		jmp p[305 * 4];
	}
}

// GetCursor
extern "C" __declspec(naked) void __stdcall __E__306__()
{
	PROXY(GetCursor)
		__asm
	{
		jmp p[306 * 4];
	}
}

// GetCursorFrameInfo
extern "C" __declspec(naked) void __stdcall __E__307__()
{
	PROXY(GetCursorFrameInfo)
		__asm
	{
		jmp p[307 * 4];
	}
}

// GetCursorInfo
extern "C" __declspec(naked) void __stdcall __E__308__()
{
	PROXY(GetCursorInfo)
		__asm
	{
		jmp p[308 * 4];
	}
}

// GetCursorPos
extern "C" __declspec(naked) void __stdcall __E__309__()
{
	PROXY(GetCursorPos)
		__asm
	{
		jmp p[309 * 4];
	}
}

// GetDC
extern "C" __declspec(naked) void __stdcall __E__310__()
{
	PROXY(GetDC)
		__asm
	{
		jmp p[310 * 4];
	}
}

// GetDCEx
extern "C" __declspec(naked) void __stdcall __E__311__()
{
	PROXY(GetDCEx)
		__asm
	{
		jmp p[311 * 4];
	}
}

// GetDesktopID
extern "C" __declspec(naked) void __stdcall __E__312__()
{
	PROXY(GetDesktopID)
		__asm
	{
		jmp p[312 * 4];
	}
}

// GetDesktopWindow
extern "C" __declspec(naked) void __stdcall __E__313__()
{
	PROXY(GetDesktopWindow)
		__asm
	{
		jmp p[313 * 4];
	}
}

// GetDialogBaseUnits
extern "C" __declspec(naked) void __stdcall __E__314__()
{
	PROXY(GetDialogBaseUnits)
		__asm
	{
		jmp p[314 * 4];
	}
}

// GetDisplayAutoRotationPreferences
extern "C" __declspec(naked) void __stdcall __E__315__()
{
	PROXY(GetDisplayAutoRotationPreferences)
		__asm
	{
		jmp p[315 * 4];
	}
}

// GetDisplayConfigBufferSizes
extern "C" __declspec(naked) void __stdcall __E__316__()
{
	PROXY(GetDisplayConfigBufferSizes)
		__asm
	{
		jmp p[316 * 4];
	}
}

// GetDlgCtrlID
extern "C" __declspec(naked) void __stdcall __E__317__()
{
	PROXY(GetDlgCtrlID)
		__asm
	{
		jmp p[317 * 4];
	}
}

// GetDlgItem
extern "C" __declspec(naked) void __stdcall __E__318__()
{
	PROXY(GetDlgItem)
		__asm
	{
		jmp p[318 * 4];
	}
}

// GetDlgItemInt
extern "C" __declspec(naked) void __stdcall __E__319__()
{
	PROXY(GetDlgItemInt)
		__asm
	{
		jmp p[319 * 4];
	}
}

// GetDlgItemTextA
extern "C" __declspec(naked) void __stdcall __E__320__()
{
	PROXY(GetDlgItemTextA)
		__asm
	{
		jmp p[320 * 4];
	}
}

// GetDlgItemTextW
extern "C" __declspec(naked) void __stdcall __E__321__()
{
	PROXY(GetDlgItemTextW)
		__asm
	{
		jmp p[321 * 4];
	}
}

// GetDoubleClickTime
extern "C" __declspec(naked) void __stdcall __E__322__()
{
	PROXY(GetDoubleClickTime)
		__asm
	{
		jmp p[322 * 4];
	}
}

// GetDpiForMonitorInternal
extern "C" __declspec(naked) void __stdcall __E__323__()
{
	PROXY(GetDpiForMonitorInternal)
		__asm
	{
		jmp p[323 * 4];
	}
}

// GetDpiMetrics
extern "C" __declspec(naked) void __stdcall __E__324__()
{
	PROXY(GetDpiMetrics)
		__asm
	{
		jmp p[324 * 4];
	}
}

// GetFocus
extern "C" __declspec(naked) void __stdcall __E__325__()
{
	PROXY(GetFocus)
		__asm
	{
		jmp p[325 * 4];
	}
}

// GetForegroundWindow
extern "C" __declspec(naked) void __stdcall __E__326__()
{
	PROXY(GetForegroundWindow)
		__asm
	{
		jmp p[326 * 4];
	}
}

// GetGUIThreadInfo
extern "C" __declspec(naked) void __stdcall __E__327__()
{
	PROXY(GetGUIThreadInfo)
		__asm
	{
		jmp p[327 * 4];
	}
}

// GetGestureConfig
extern "C" __declspec(naked) void __stdcall __E__328__()
{
	PROXY(GetGestureConfig)
		__asm
	{
		jmp p[328 * 4];
	}
}

// GetGestureExtraArgs
extern "C" __declspec(naked) void __stdcall __E__329__()
{
	PROXY(GetGestureExtraArgs)
		__asm
	{
		jmp p[329 * 4];
	}
}

// GetGestureInfo
extern "C" __declspec(naked) void __stdcall __E__330__()
{
	PROXY(GetGestureInfo)
		__asm
	{
		jmp p[330 * 4];
	}
}

// GetGuiResources
extern "C" __declspec(naked) void __stdcall __E__331__()
{
	PROXY(GetGuiResources)
		__asm
	{
		jmp p[331 * 4];
	}
}

// GetIconInfo
extern "C" __declspec(naked) void __stdcall __E__332__()
{
	PROXY(GetIconInfo)
		__asm
	{
		jmp p[332 * 4];
	}
}

// GetIconInfoExA
extern "C" __declspec(naked) void __stdcall __E__333__()
{
	PROXY(GetIconInfoExA)
		__asm
	{
		jmp p[333 * 4];
	}
}

// GetIconInfoExW
extern "C" __declspec(naked) void __stdcall __E__334__()
{
	PROXY(GetIconInfoExW)
		__asm
	{
		jmp p[334 * 4];
	}
}

// GetInputDesktop
extern "C" __declspec(naked) void __stdcall __E__335__()
{
	PROXY(GetInputDesktop)
		__asm
	{
		jmp p[335 * 4];
	}
}

// GetInputLocaleInfo
extern "C" __declspec(naked) void __stdcall __E__336__()
{
	PROXY(GetInputLocaleInfo)
		__asm
	{
		jmp p[336 * 4];
	}
}

// GetInputState
extern "C" __declspec(naked) void __stdcall __E__337__()
{
	PROXY(GetInputState)
		__asm
	{
		jmp p[337 * 4];
	}
}

// GetInternalWindowPos
extern "C" __declspec(naked) void __stdcall __E__338__()
{
	PROXY(GetInternalWindowPos)
		__asm
	{
		jmp p[338 * 4];
	}
}

// GetKBCodePage
extern "C" __declspec(naked) void __stdcall __E__339__()
{
	PROXY(GetKBCodePage)
		__asm
	{
		jmp p[339 * 4];
	}
}

// GetKeyNameTextA
extern "C" __declspec(naked) void __stdcall __E__340__()
{
	PROXY(GetKeyNameTextA)
		__asm
	{
		jmp p[340 * 4];
	}
}

// GetKeyNameTextW
extern "C" __declspec(naked) void __stdcall __E__341__()
{
	PROXY(GetKeyNameTextW)
		__asm
	{
		jmp p[341 * 4];
	}
}

// GetKeyState
extern "C" __declspec(naked) void __stdcall __E__342__()
{
	PROXY(GetKeyState)
		__asm
	{
		jmp p[342 * 4];
	}
}

// GetKeyboardLayout
extern "C" __declspec(naked) void __stdcall __E__343__()
{
	PROXY(GetKeyboardLayout)
		__asm
	{
		jmp p[343 * 4];
	}
}

// GetKeyboardLayoutList
extern "C" __declspec(naked) void __stdcall __E__344__()
{
	PROXY(GetKeyboardLayoutList)
		__asm
	{
		jmp p[344 * 4];
	}
}

// GetKeyboardLayoutNameA
extern "C" __declspec(naked) void __stdcall __E__345__()
{
	PROXY(GetKeyboardLayoutNameA)
		__asm
	{
		jmp p[345 * 4];
	}
}

// GetKeyboardLayoutNameW
extern "C" __declspec(naked) void __stdcall __E__346__()
{
	PROXY(GetKeyboardLayoutNameW)
		__asm
	{
		jmp p[346 * 4];
	}
}

// GetKeyboardState
extern "C" __declspec(naked) void __stdcall __E__347__()
{
	PROXY(GetKeyboardState)
		__asm
	{
		jmp p[347 * 4];
	}
}

// GetKeyboardType
extern "C" __declspec(naked) void __stdcall __E__348__()
{
	PROXY(GetKeyboardType)
		__asm
	{
		jmp p[348 * 4];
	}
}

// GetLastActivePopup
extern "C" __declspec(naked) void __stdcall __E__349__()
{
	PROXY(GetLastActivePopup)
		__asm
	{
		jmp p[349 * 4];
	}
}

// GetLastInputInfo
extern "C" __declspec(naked) void __stdcall __E__350__()
{
	PROXY(GetLastInputInfo)
		__asm
	{
		jmp p[350 * 4];
	}
}

// GetLayeredWindowAttributes
extern "C" __declspec(naked) void __stdcall __E__351__()
{
	PROXY(GetLayeredWindowAttributes)
		__asm
	{
		jmp p[351 * 4];
	}
}

// GetListBoxInfo
extern "C" __declspec(naked) void __stdcall __E__352__()
{
	PROXY(GetListBoxInfo)
		__asm
	{
		jmp p[352 * 4];
	}
}

// GetMagnificationDesktopColorEffect
extern "C" __declspec(naked) void __stdcall __E__353__()
{
	PROXY(GetMagnificationDesktopColorEffect)
		__asm
	{
		jmp p[353 * 4];
	}
}

// GetMagnificationDesktopMagnification
extern "C" __declspec(naked) void __stdcall __E__354__()
{
	PROXY(GetMagnificationDesktopMagnification)
		__asm
	{
		jmp p[354 * 4];
	}
}

// GetMagnificationLensCtxInformation
extern "C" __declspec(naked) void __stdcall __E__355__()
{
	PROXY(GetMagnificationLensCtxInformation)
		__asm
	{
		jmp p[355 * 4];
	}
}

// GetMenu
extern "C" __declspec(naked) void __stdcall __E__356__()
{
	PROXY(GetMenu)
		__asm
	{
		jmp p[356 * 4];
	}
}

// GetMenuBarInfo
extern "C" __declspec(naked) void __stdcall __E__357__()
{
	PROXY(GetMenuBarInfo)
		__asm
	{
		jmp p[357 * 4];
	}
}

// GetMenuCheckMarkDimensions
extern "C" __declspec(naked) void __stdcall __E__358__()
{
	PROXY(GetMenuCheckMarkDimensions)
		__asm
	{
		jmp p[358 * 4];
	}
}

// GetMenuContextHelpId
extern "C" __declspec(naked) void __stdcall __E__359__()
{
	PROXY(GetMenuContextHelpId)
		__asm
	{
		jmp p[359 * 4];
	}
}

// GetMenuDefaultItem
extern "C" __declspec(naked) void __stdcall __E__360__()
{
	PROXY(GetMenuDefaultItem)
		__asm
	{
		jmp p[360 * 4];
	}
}

// GetMenuInfo
extern "C" __declspec(naked) void __stdcall __E__361__()
{
	PROXY(GetMenuInfo)
		__asm
	{
		jmp p[361 * 4];
	}
}

// GetMenuItemCount
extern "C" __declspec(naked) void __stdcall __E__362__()
{
	PROXY(GetMenuItemCount)
		__asm
	{
		jmp p[362 * 4];
	}
}

// GetMenuItemID
extern "C" __declspec(naked) void __stdcall __E__363__()
{
	PROXY(GetMenuItemID)
		__asm
	{
		jmp p[363 * 4];
	}
}

// GetMenuItemInfoA
extern "C" __declspec(naked) void __stdcall __E__364__()
{
	PROXY(GetMenuItemInfoA)
		__asm
	{
		jmp p[364 * 4];
	}
}

// GetMenuItemInfoW
extern "C" __declspec(naked) void __stdcall __E__365__()
{
	PROXY(GetMenuItemInfoW)
		__asm
	{
		jmp p[365 * 4];
	}
}

// GetMenuItemRect
extern "C" __declspec(naked) void __stdcall __E__366__()
{
	PROXY(GetMenuItemRect)
		__asm
	{
		jmp p[366 * 4];
	}
}

// GetMenuState
extern "C" __declspec(naked) void __stdcall __E__367__()
{
	PROXY(GetMenuState)
		__asm
	{
		jmp p[367 * 4];
	}
}

// GetMenuStringA
extern "C" __declspec(naked) void __stdcall __E__368__()
{
	PROXY(GetMenuStringA)
		__asm
	{
		jmp p[368 * 4];
	}
}

// GetMenuStringW
extern "C" __declspec(naked) void __stdcall __E__369__()
{
	PROXY(GetMenuStringW)
		__asm
	{
		jmp p[369 * 4];
	}
}

// GetMessageA
extern "C" __declspec(naked) void __stdcall __E__370__()
{
	PROXY(GetMessageA)
		__asm
	{
		jmp p[370 * 4];
	}
}

// GetMessageExtraInfo
extern "C" __declspec(naked) void __stdcall __E__371__()
{
	PROXY(GetMessageExtraInfo)
		__asm
	{
		jmp p[371 * 4];
	}
}

// GetMessagePos
extern "C" __declspec(naked) void __stdcall __E__372__()
{
	PROXY(GetMessagePos)
		__asm
	{
		jmp p[372 * 4];
	}
}

// GetMessageTime
extern "C" __declspec(naked) void __stdcall __E__373__()
{
	PROXY(GetMessageTime)
		__asm
	{
		jmp p[373 * 4];
	}
}

// GetMessageW
extern "C" __declspec(naked) void __stdcall __E__374__()
{
	PROXY(GetMessageW)
		__asm
	{
		jmp p[374 * 4];
	}
}

// GetMonitorInfoA
extern "C" __declspec(naked) void __stdcall __E__375__()
{
	PROXY(GetMonitorInfoA)
		__asm
	{
		jmp p[375 * 4];
	}
}

// GetMonitorInfoW
extern "C" __declspec(naked) void __stdcall __E__376__()
{
	PROXY(GetMonitorInfoW)
		__asm
	{
		jmp p[376 * 4];
	}
}

// GetMouseMovePointsEx
extern "C" __declspec(naked) void __stdcall __E__377__()
{
	PROXY(GetMouseMovePointsEx)
		__asm
	{
		jmp p[377 * 4];
	}
}

// GetNextDlgGroupItem
extern "C" __declspec(naked) void __stdcall __E__378__()
{
	PROXY(GetNextDlgGroupItem)
		__asm
	{
		jmp p[378 * 4];
	}
}

// GetNextDlgTabItem
extern "C" __declspec(naked) void __stdcall __E__379__()
{
	PROXY(GetNextDlgTabItem)
		__asm
	{
		jmp p[379 * 4];
	}
}

// GetOpenClipboardWindow
extern "C" __declspec(naked) void __stdcall __E__380__()
{
	PROXY(GetOpenClipboardWindow)
		__asm
	{
		jmp p[380 * 4];
	}
}

// GetParent
extern "C" __declspec(naked) void __stdcall __E__381__()
{
	PROXY(GetParent)
		__asm
	{
		jmp p[381 * 4];
	}
}

// GetPhysicalCursorPos
extern "C" __declspec(naked) void __stdcall __E__382__()
{
	PROXY(GetPhysicalCursorPos)
		__asm
	{
		jmp p[382 * 4];
	}
}

// GetPointerCursorId
extern "C" __declspec(naked) void __stdcall __E__383__()
{
	PROXY(GetPointerCursorId)
		__asm
	{
		jmp p[383 * 4];
	}
}

// GetPointerDevice
extern "C" __declspec(naked) void __stdcall __E__384__()
{
	PROXY(GetPointerDevice)
		__asm
	{
		jmp p[384 * 4];
	}
}

// GetPointerDeviceCursors
extern "C" __declspec(naked) void __stdcall __E__385__()
{
	PROXY(GetPointerDeviceCursors)
		__asm
	{
		jmp p[385 * 4];
	}
}

// GetPointerDeviceProperties
extern "C" __declspec(naked) void __stdcall __E__386__()
{
	PROXY(GetPointerDeviceProperties)
		__asm
	{
		jmp p[386 * 4];
	}
}

// GetPointerDeviceRects
extern "C" __declspec(naked) void __stdcall __E__387__()
{
	PROXY(GetPointerDeviceRects)
		__asm
	{
		jmp p[387 * 4];
	}
}

// GetPointerDevices
extern "C" __declspec(naked) void __stdcall __E__388__()
{
	PROXY(GetPointerDevices)
		__asm
	{
		jmp p[388 * 4];
	}
}

// GetPointerFrameArrivalTimes
extern "C" __declspec(naked) void __stdcall __E__389__()
{
	PROXY(GetPointerFrameArrivalTimes)
		__asm
	{
		jmp p[389 * 4];
	}
}

// GetPointerFrameInfo
extern "C" __declspec(naked) void __stdcall __E__390__()
{
	PROXY(GetPointerFrameInfo)
		__asm
	{
		jmp p[390 * 4];
	}
}

// GetPointerFrameInfoHistory
extern "C" __declspec(naked) void __stdcall __E__391__()
{
	PROXY(GetPointerFrameInfoHistory)
		__asm
	{
		jmp p[391 * 4];
	}
}

// GetPointerFramePenInfo
extern "C" __declspec(naked) void __stdcall __E__392__()
{
	PROXY(GetPointerFramePenInfo)
		__asm
	{
		jmp p[392 * 4];
	}
}

// GetPointerFramePenInfoHistory
extern "C" __declspec(naked) void __stdcall __E__393__()
{
	PROXY(GetPointerFramePenInfoHistory)
		__asm
	{
		jmp p[393 * 4];
	}
}

// GetPointerFrameTouchInfo
extern "C" __declspec(naked) void __stdcall __E__394__()
{
	PROXY(GetPointerFrameTouchInfo)
		__asm
	{
		jmp p[394 * 4];
	}
}

// GetPointerFrameTouchInfoHistory
extern "C" __declspec(naked) void __stdcall __E__395__()
{
	PROXY(GetPointerFrameTouchInfoHistory)
		__asm
	{
		jmp p[395 * 4];
	}
}

// GetPointerInfo
extern "C" __declspec(naked) void __stdcall __E__396__()
{
	PROXY(GetPointerInfo)
		__asm
	{
		jmp p[396 * 4];
	}
}

// GetPointerInfoHistory
extern "C" __declspec(naked) void __stdcall __E__397__()
{
	PROXY(GetPointerInfoHistory)
		__asm
	{
		jmp p[397 * 4];
	}
}

// GetPointerInputTransform
extern "C" __declspec(naked) void __stdcall __E__398__()
{
	PROXY(GetPointerInputTransform)
		__asm
	{
		jmp p[398 * 4];
	}
}

// GetPointerPenInfo
extern "C" __declspec(naked) void __stdcall __E__399__()
{
	PROXY(GetPointerPenInfo)
		__asm
	{
		jmp p[399 * 4];
	}
}

// GetPointerPenInfoHistory
extern "C" __declspec(naked) void __stdcall __E__400__()
{
	PROXY(GetPointerPenInfoHistory)
		__asm
	{
		jmp p[400 * 4];
	}
}

// GetPointerTouchInfo
extern "C" __declspec(naked) void __stdcall __E__401__()
{
	PROXY(GetPointerTouchInfo)
		__asm
	{
		jmp p[401 * 4];
	}
}

// GetPointerTouchInfoHistory
extern "C" __declspec(naked) void __stdcall __E__402__()
{
	PROXY(GetPointerTouchInfoHistory)
		__asm
	{
		jmp p[402 * 4];
	}
}

// GetPointerType
extern "C" __declspec(naked) void __stdcall __E__403__()
{
	PROXY(GetPointerType)
		__asm
	{
		jmp p[403 * 4];
	}
}

// GetPriorityClipboardFormat
extern "C" __declspec(naked) void __stdcall __E__404__()
{
	PROXY(GetPriorityClipboardFormat)
		__asm
	{
		jmp p[404 * 4];
	}
}

// GetProcessDefaultLayout
extern "C" __declspec(naked) void __stdcall __E__405__()
{
	PROXY(GetProcessDefaultLayout)
		__asm
	{
		jmp p[405 * 4];
	}
}

// GetProcessDpiAwarenessInternal
extern "C" __declspec(naked) void __stdcall __E__406__()
{
	PROXY(GetProcessDpiAwarenessInternal)
		__asm
	{
		jmp p[406 * 4];
	}
}

// GetProcessWindowStation
extern "C" __declspec(naked) void __stdcall __E__407__()
{
	PROXY(GetProcessWindowStation)
		__asm
	{
		jmp p[407 * 4];
	}
}

// GetProgmanWindow
extern "C" __declspec(naked) void __stdcall __E__408__()
{
	PROXY(GetProgmanWindow)
		__asm
	{
		jmp p[408 * 4];
	}
}

// GetPropA
extern "C" __declspec(naked) void __stdcall __E__409__()
{
	PROXY(GetPropA)
		__asm
	{
		jmp p[409 * 4];
	}
}

// GetPropW
extern "C" __declspec(naked) void __stdcall __E__410__()
{
	PROXY(GetPropW)
		__asm
	{
		jmp p[410 * 4];
	}
}

// GetQueueStatus
extern "C" __declspec(naked) void __stdcall __E__411__()
{
	PROXY(GetQueueStatus)
		__asm
	{
		jmp p[411 * 4];
	}
}

// GetRawInputBuffer
extern "C" __declspec(naked) void __stdcall __E__412__()
{
	PROXY(GetRawInputBuffer)
		__asm
	{
		jmp p[412 * 4];
	}
}

// GetRawInputData
extern "C" __declspec(naked) void __stdcall __E__413__()
{
	PROXY(GetRawInputData)
		__asm
	{
		jmp p[413 * 4];
	}
}

// GetRawInputDeviceInfoA
extern "C" __declspec(naked) void __stdcall __E__414__()
{
	PROXY(GetRawInputDeviceInfoA)
		__asm
	{
		jmp p[414 * 4];
	}
}

// GetRawInputDeviceInfoW
extern "C" __declspec(naked) void __stdcall __E__415__()
{
	PROXY(GetRawInputDeviceInfoW)
		__asm
	{
		jmp p[415 * 4];
	}
}

// GetRawInputDeviceList
extern "C" __declspec(naked) void __stdcall __E__416__()
{
	PROXY(GetRawInputDeviceList)
		__asm
	{
		jmp p[416 * 4];
	}
}

// GetRawPointerDeviceData
extern "C" __declspec(naked) void __stdcall __E__417__()
{
	PROXY(GetRawPointerDeviceData)
		__asm
	{
		jmp p[417 * 4];
	}
}

// GetReasonTitleFromReasonCode
extern "C" __declspec(naked) void __stdcall __E__418__()
{
	PROXY(GetReasonTitleFromReasonCode)
		__asm
	{
		jmp p[418 * 4];
	}
}

// GetRegisteredRawInputDevices
extern "C" __declspec(naked) void __stdcall __E__419__()
{
	PROXY(GetRegisteredRawInputDevices)
		__asm
	{
		jmp p[419 * 4];
	}
}

// GetScrollBarInfo
extern "C" __declspec(naked) void __stdcall __E__420__()
{
	PROXY(GetScrollBarInfo)
		__asm
	{
		jmp p[420 * 4];
	}
}

// GetScrollInfo
extern "C" __declspec(naked) void __stdcall __E__421__()
{
	PROXY(GetScrollInfo)
		__asm
	{
		jmp p[421 * 4];
	}
}

// GetScrollPos
extern "C" __declspec(naked) void __stdcall __E__422__()
{
	PROXY(GetScrollPos)
		__asm
	{
		jmp p[422 * 4];
	}
}

// GetScrollRange
extern "C" __declspec(naked) void __stdcall __E__423__()
{
	PROXY(GetScrollRange)
		__asm
	{
		jmp p[423 * 4];
	}
}

// GetSendMessageReceiver
extern "C" __declspec(naked) void __stdcall __E__424__()
{
	PROXY(GetSendMessageReceiver)
		__asm
	{
		jmp p[424 * 4];
	}
}

// GetShellWindow
extern "C" __declspec(naked) void __stdcall __E__425__()
{
	PROXY(GetShellWindow)
		__asm
	{
		jmp p[425 * 4];
	}
}

// GetSubMenu
extern "C" __declspec(naked) void __stdcall __E__426__()
{
	PROXY(GetSubMenu)
		__asm
	{
		jmp p[426 * 4];
	}
}

// GetSysColor
extern "C" __declspec(naked) void __stdcall __E__427__()
{
	PROXY(GetSysColor)
		__asm
	{
		jmp p[427 * 4];
	}
}

// GetSysColorBrush
extern "C" __declspec(naked) void __stdcall __E__428__()
{
	PROXY(GetSysColorBrush)
		__asm
	{
		jmp p[428 * 4];
	}
}

// GetSystemMenu
extern "C" __declspec(naked) void __stdcall __E__429__()
{
	PROXY(GetSystemMenu)
		__asm
	{
		jmp p[429 * 4];
	}
}

// GetSystemMetrics
extern "C" __declspec(naked) void __stdcall __E__430__()
{
	PROXY(GetSystemMetrics)
		__asm
	{
		jmp p[430 * 4];
	}
}

// GetTabbedTextExtentA
extern "C" __declspec(naked) void __stdcall __E__431__()
{
	PROXY(GetTabbedTextExtentA)
		__asm
	{
		jmp p[431 * 4];
	}
}

// GetTabbedTextExtentW
extern "C" __declspec(naked) void __stdcall __E__432__()
{
	PROXY(GetTabbedTextExtentW)
		__asm
	{
		jmp p[432 * 4];
	}
}

// GetTaskmanWindow
extern "C" __declspec(naked) void __stdcall __E__433__()
{
	PROXY(GetTaskmanWindow)
		__asm
	{
		jmp p[433 * 4];
	}
}

// GetThreadDesktop
extern "C" __declspec(naked) void __stdcall __E__434__()
{
	PROXY(GetThreadDesktop)
		__asm
	{
		jmp p[434 * 4];
	}
}

// GetTitleBarInfo
extern "C" __declspec(naked) void __stdcall __E__435__()
{
	PROXY(GetTitleBarInfo)
		__asm
	{
		jmp p[435 * 4];
	}
}

// GetTopLevelWindow
extern "C" __declspec(naked) void __stdcall __E__436__()
{
	PROXY(GetTopLevelWindow)
		__asm
	{
		jmp p[436 * 4];
	}
}

// GetTopWindow
extern "C" __declspec(naked) void __stdcall __E__437__()
{
	PROXY(GetTopWindow)
		__asm
	{
		jmp p[437 * 4];
	}
}

// GetTouchInputInfo
extern "C" __declspec(naked) void __stdcall __E__438__()
{
	PROXY(GetTouchInputInfo)
		__asm
	{
		jmp p[438 * 4];
	}
}

// GetUnpredictedMessagePos
extern "C" __declspec(naked) void __stdcall __E__439__()
{
	PROXY(GetUnpredictedMessagePos)
		__asm
	{
		jmp p[439 * 4];
	}
}

// GetUpdateRect
extern "C" __declspec(naked) void __stdcall __E__440__()
{
	PROXY(GetUpdateRect)
		__asm
	{
		jmp p[440 * 4];
	}
}

// GetUpdateRgn
extern "C" __declspec(naked) void __stdcall __E__441__()
{
	PROXY(GetUpdateRgn)
		__asm
	{
		jmp p[441 * 4];
	}
}

// GetUpdatedClipboardFormats
extern "C" __declspec(naked) void __stdcall __E__442__()
{
	PROXY(GetUpdatedClipboardFormats)
		__asm
	{
		jmp p[442 * 4];
	}
}

// GetUserObjectInformationA
extern "C" __declspec(naked) void __stdcall __E__443__()
{
	PROXY(GetUserObjectInformationA)
		__asm
	{
		jmp p[443 * 4];
	}
}

// GetUserObjectInformationW
extern "C" __declspec(naked) void __stdcall __E__444__()
{
	PROXY(GetUserObjectInformationW)
		__asm
	{
		jmp p[444 * 4];
	}
}

// GetUserObjectSecurity
extern "C" __declspec(naked) void __stdcall __E__445__()
{
	PROXY(GetUserObjectSecurity)
		__asm
	{
		jmp p[445 * 4];
	}
}

// GetWinStationInfo
extern "C" __declspec(naked) void __stdcall __E__446__()
{
	PROXY(GetWinStationInfo)
		__asm
	{
		jmp p[446 * 4];
	}
}

// GetWindow
extern "C" __declspec(naked) void __stdcall __E__447__()
{
	PROXY(GetWindow)
		__asm
	{
		jmp p[447 * 4];
	}
}

// GetWindowBand
extern "C" __declspec(naked) void __stdcall __E__448__()
{
	PROXY(GetWindowBand)
		__asm
	{
		jmp p[448 * 4];
	}
}

// GetWindowCompositionAttribute
extern "C" __declspec(naked) void __stdcall __E__449__()
{
	PROXY(GetWindowCompositionAttribute)
		__asm
	{
		jmp p[449 * 4];
	}
}

// GetWindowCompositionInfo
extern "C" __declspec(naked) void __stdcall __E__450__()
{
	PROXY(GetWindowCompositionInfo)
		__asm
	{
		jmp p[450 * 4];
	}
}

// GetWindowContextHelpId
extern "C" __declspec(naked) void __stdcall __E__451__()
{
	PROXY(GetWindowContextHelpId)
		__asm
	{
		jmp p[451 * 4];
	}
}

// GetWindowDC
extern "C" __declspec(naked) void __stdcall __E__452__()
{
	PROXY(GetWindowDC)
		__asm
	{
		jmp p[452 * 4];
	}
}

// GetWindowDPI
extern "C" __declspec(naked) void __stdcall __E__453__()
{
	PROXY(GetWindowDPI)
		__asm
	{
		jmp p[453 * 4];
	}
}

// GetWindowDisplayAffinity
extern "C" __declspec(naked) void __stdcall __E__454__()
{
	PROXY(GetWindowDisplayAffinity)
		__asm
	{
		jmp p[454 * 4];
	}
}

// GetWindowFeedbackSetting
extern "C" __declspec(naked) void __stdcall __E__455__()
{
	PROXY(GetWindowFeedbackSetting)
		__asm
	{
		jmp p[455 * 4];
	}
}

// GetWindowInfo
extern "C" __declspec(naked) void __stdcall __E__456__()
{
	PROXY(GetWindowInfo)
		__asm
	{
		jmp p[456 * 4];
	}
}

// GetWindowLongA
extern "C" __declspec(naked) void __stdcall __E__457__()
{
	PROXY(GetWindowLongA)
		__asm
	{
		jmp p[457 * 4];
	}
}

// GetWindowLongW
extern "C" __declspec(naked) void __stdcall __E__458__()
{
	PROXY(GetWindowLongW)
		__asm
	{
		jmp p[458 * 4];
	}
}

// GetWindowMinimizeRect
extern "C" __declspec(naked) void __stdcall __E__459__()
{
	PROXY(GetWindowMinimizeRect)
		__asm
	{
		jmp p[459 * 4];
	}
}

// GetWindowModuleFileName
extern "C" __declspec(naked) void __stdcall __E__460__()
{
	PROXY(GetWindowModuleFileName)
		__asm
	{
		jmp p[460 * 4];
	}
}

// GetWindowModuleFileNameA
extern "C" __declspec(naked) void __stdcall __E__461__()
{
	PROXY(GetWindowModuleFileNameA)
		__asm
	{
		jmp p[461 * 4];
	}
}

// GetWindowModuleFileNameW
extern "C" __declspec(naked) void __stdcall __E__462__()
{
	PROXY(GetWindowModuleFileNameW)
		__asm
	{
		jmp p[462 * 4];
	}
}

// GetWindowPlacement
extern "C" __declspec(naked) void __stdcall __E__463__()
{
	PROXY(GetWindowPlacement)
		__asm
	{
		jmp p[463 * 4];
	}
}

// GetWindowRect
extern "C" __declspec(naked) void __stdcall __E__464__()
{
	PROXY(GetWindowRect)
		__asm
	{
		jmp p[464 * 4];
	}
}

// GetWindowRgn
extern "C" __declspec(naked) void __stdcall __E__465__()
{
	PROXY(GetWindowRgn)
		__asm
	{
		jmp p[465 * 4];
	}
}

// GetWindowRgnBox
extern "C" __declspec(naked) void __stdcall __E__466__()
{
	PROXY(GetWindowRgnBox)
		__asm
	{
		jmp p[466 * 4];
	}
}

// GetWindowRgnEx
extern "C" __declspec(naked) void __stdcall __E__467__()
{
	PROXY(GetWindowRgnEx)
		__asm
	{
		jmp p[467 * 4];
	}
}

// GetWindowTextA
extern "C" __declspec(naked) void __stdcall __E__468__()
{
	PROXY(GetWindowTextA)
		__asm
	{
		jmp p[468 * 4];
	}
}

// GetWindowTextLengthA
extern "C" __declspec(naked) void __stdcall __E__469__()
{
	PROXY(GetWindowTextLengthA)
		__asm
	{
		jmp p[469 * 4];
	}
}

// GetWindowTextLengthW
extern "C" __declspec(naked) void __stdcall __E__470__()
{
	PROXY(GetWindowTextLengthW)
		__asm
	{
		jmp p[470 * 4];
	}
}

// GetWindowTextW
extern "C" __declspec(naked) void __stdcall __E__471__()
{
	PROXY(GetWindowTextW)
		__asm
	{
		jmp p[471 * 4];
	}
}

// GetWindowThreadProcessId
extern "C" __declspec(naked) void __stdcall __E__472__()
{
	PROXY(GetWindowThreadProcessId)
		__asm
	{
		jmp p[472 * 4];
	}
}

// GetWindowWord
extern "C" __declspec(naked) void __stdcall __E__473__()
{
	PROXY(GetWindowWord)
		__asm
	{
		jmp p[473 * 4];
	}
}

// GhostWindowFromHungWindow
extern "C" __declspec(naked) void __stdcall __E__474__()
{
	PROXY(GhostWindowFromHungWindow)
		__asm
	{
		jmp p[474 * 4];
	}
}

// GrayStringA
extern "C" __declspec(naked) void __stdcall __E__475__()
{
	PROXY(GrayStringA)
		__asm
	{
		jmp p[475 * 4];
	}
}

// GrayStringW
extern "C" __declspec(naked) void __stdcall __E__476__()
{
	PROXY(GrayStringW)
		__asm
	{
		jmp p[476 * 4];
	}
}

// HideCaret
extern "C" __declspec(naked) void __stdcall __E__477__()
{
	PROXY(HideCaret)
		__asm
	{
		jmp p[477 * 4];
	}
}

// HiliteMenuItem
extern "C" __declspec(naked) void __stdcall __E__478__()
{
	PROXY(HiliteMenuItem)
		__asm
	{
		jmp p[478 * 4];
	}
}

// HungWindowFromGhostWindow
extern "C" __declspec(naked) void __stdcall __E__479__()
{
	PROXY(HungWindowFromGhostWindow)
		__asm
	{
		jmp p[479 * 4];
	}
}

// IMPGetIMEA
extern "C" __declspec(naked) void __stdcall __E__480__()
{
	PROXY(IMPGetIMEA)
		__asm
	{
		jmp p[480 * 4];
	}
}

// IMPGetIMEW
extern "C" __declspec(naked) void __stdcall __E__481__()
{
	PROXY(IMPGetIMEW)
		__asm
	{
		jmp p[481 * 4];
	}
}

// IMPQueryIMEA
extern "C" __declspec(naked) void __stdcall __E__482__()
{
	PROXY(IMPQueryIMEA)
		__asm
	{
		jmp p[482 * 4];
	}
}

// IMPQueryIMEW
extern "C" __declspec(naked) void __stdcall __E__483__()
{
	PROXY(IMPQueryIMEW)
		__asm
	{
		jmp p[483 * 4];
	}
}

// IMPSetIMEA
extern "C" __declspec(naked) void __stdcall __E__484__()
{
	PROXY(IMPSetIMEA)
		__asm
	{
		jmp p[484 * 4];
	}
}

// IMPSetIMEW
extern "C" __declspec(naked) void __stdcall __E__485__()
{
	PROXY(IMPSetIMEW)
		__asm
	{
		jmp p[485 * 4];
	}
}

// ImpersonateDdeClientWindow
extern "C" __declspec(naked) void __stdcall __E__486__()
{
	PROXY(ImpersonateDdeClientWindow)
		__asm
	{
		jmp p[486 * 4];
	}
}

// InSendMessage
extern "C" __declspec(naked) void __stdcall __E__487__()
{
	PROXY(InSendMessage)
		__asm
	{
		jmp p[487 * 4];
	}
}

// InSendMessageEx
extern "C" __declspec(naked) void __stdcall __E__488__()
{
	PROXY(InSendMessageEx)
		__asm
	{
		jmp p[488 * 4];
	}
}

// InflateRect
extern "C" __declspec(naked) void __stdcall __E__489__()
{
	PROXY(InflateRect)
		__asm
	{
		jmp p[489 * 4];
	}
}

// InitDManipHook
extern "C" __declspec(naked) void __stdcall __E__490__()
{
	PROXY(InitDManipHook)
		__asm
	{
		jmp p[490 * 4];
	}
}

// InitializeInputDeviceInjection
extern "C" __declspec(naked) void __stdcall __E__491__()
{
	PROXY(InitializeInputDeviceInjection)
		__asm
	{
		jmp p[491 * 4];
	}
}

// InitializeLpkHooks
extern "C" __declspec(naked) void __stdcall __E__492__()
{
	PROXY(InitializeLpkHooks)
		__asm
	{
		jmp p[492 * 4];
	}
}

// InitializePointerDeviceInjection
extern "C" __declspec(naked) void __stdcall __E__493__()
{
	PROXY(InitializePointerDeviceInjection)
		__asm
	{
		jmp p[493 * 4];
	}
}

// InitializeTouchInjection
extern "C" __declspec(naked) void __stdcall __E__494__()
{
	PROXY(InitializeTouchInjection)
		__asm
	{
		jmp p[494 * 4];
	}
}

// InjectDeviceInput
extern "C" __declspec(naked) void __stdcall __E__495__()
{
	PROXY(InjectDeviceInput)
		__asm
	{
		jmp p[495 * 4];
	}
}

// InjectKeyboardInput
extern "C" __declspec(naked) void __stdcall __E__496__()
{
	PROXY(InjectKeyboardInput)
		__asm
	{
		jmp p[496 * 4];
	}
}

// InjectMouseInput
extern "C" __declspec(naked) void __stdcall __E__497__()
{
	PROXY(InjectMouseInput)
		__asm
	{
		jmp p[497 * 4];
	}
}

// InjectPointerInput
extern "C" __declspec(naked) void __stdcall __E__498__()
{
	PROXY(InjectPointerInput)
		__asm
	{
		jmp p[498 * 4];
	}
}

// InjectTouchInput
extern "C" __declspec(naked) void __stdcall __E__499__()
{
	PROXY(InjectTouchInput)
		__asm
	{
		jmp p[499 * 4];
	}
}

// InsertMenuA
extern "C" __declspec(naked) void __stdcall __E__500__()
{
	PROXY(InsertMenuA)
		__asm
	{
		jmp p[500 * 4];
	}
}

// InsertMenuItemA
extern "C" __declspec(naked) void __stdcall __E__501__()
{
	PROXY(InsertMenuItemA)
		__asm
	{
		jmp p[501 * 4];
	}
}

// InsertMenuItemW
extern "C" __declspec(naked) void __stdcall __E__502__()
{
	PROXY(InsertMenuItemW)
		__asm
	{
		jmp p[502 * 4];
	}
}

// InsertMenuW
extern "C" __declspec(naked) void __stdcall __E__503__()
{
	PROXY(InsertMenuW)
		__asm
	{
		jmp p[503 * 4];
	}
}

// InternalGetWindowIcon
extern "C" __declspec(naked) void __stdcall __E__504__()
{
	PROXY(InternalGetWindowIcon)
		__asm
	{
		jmp p[504 * 4];
	}
}

// InternalGetWindowText
extern "C" __declspec(naked) void __stdcall __E__505__()
{
	PROXY(InternalGetWindowText)
		__asm
	{
		jmp p[505 * 4];
	}
}

// IntersectRect
extern "C" __declspec(naked) void __stdcall __E__506__()
{
	PROXY(IntersectRect)
		__asm
	{
		jmp p[506 * 4];
	}
}

// InvalidateRect
extern "C" __declspec(naked) void __stdcall __E__507__()
{
	PROXY(InvalidateRect)
		__asm
	{
		jmp p[507 * 4];
	}
}

// InvalidateRgn
extern "C" __declspec(naked) void __stdcall __E__508__()
{
	PROXY(InvalidateRgn)
		__asm
	{
		jmp p[508 * 4];
	}
}

// InvertRect
extern "C" __declspec(naked) void __stdcall __E__509__()
{
	PROXY(InvertRect)
		__asm
	{
		jmp p[509 * 4];
	}
}

// IsCharAlphaA
extern "C" __declspec(naked) void __stdcall __E__510__()
{
	PROXY(IsCharAlphaA)
		__asm
	{
		jmp p[510 * 4];
	}
}

// IsCharAlphaNumericA
extern "C" __declspec(naked) void __stdcall __E__511__()
{
	PROXY(IsCharAlphaNumericA)
		__asm
	{
		jmp p[511 * 4];
	}
}

// IsCharAlphaNumericW
extern "C" __declspec(naked) void __stdcall __E__512__()
{
	PROXY(IsCharAlphaNumericW)
		__asm
	{
		jmp p[512 * 4];
	}
}

// IsCharAlphaW
extern "C" __declspec(naked) void __stdcall __E__513__()
{
	PROXY(IsCharAlphaW)
		__asm
	{
		jmp p[513 * 4];
	}
}

// IsCharLowerA
extern "C" __declspec(naked) void __stdcall __E__514__()
{
	PROXY(IsCharLowerA)
		__asm
	{
		jmp p[514 * 4];
	}
}

// IsCharLowerW
extern "C" __declspec(naked) void __stdcall __E__515__()
{
	PROXY(IsCharLowerW)
		__asm
	{
		jmp p[515 * 4];
	}
}

// IsCharUpperA
extern "C" __declspec(naked) void __stdcall __E__516__()
{
	PROXY(IsCharUpperA)
		__asm
	{
		jmp p[516 * 4];
	}
}

// IsCharUpperW
extern "C" __declspec(naked) void __stdcall __E__517__()
{
	PROXY(IsCharUpperW)
		__asm
	{
		jmp p[517 * 4];
	}
}

// IsChild
extern "C" __declspec(naked) void __stdcall __E__518__()
{
	PROXY(IsChild)
		__asm
	{
		jmp p[518 * 4];
	}
}

// IsChildWindowDpiMessageEnabled
extern "C" __declspec(naked) void __stdcall __E__519__()
{
	PROXY(IsChildWindowDpiMessageEnabled)
		__asm
	{
		jmp p[519 * 4];
	}
}

// IsClipboardFormatAvailable
extern "C" __declspec(naked) void __stdcall __E__520__()
{
	PROXY(IsClipboardFormatAvailable)
		__asm
	{
		jmp p[520 * 4];
	}
}

// IsDialogMessage
extern "C" __declspec(naked) void __stdcall __E__521__()
{
	PROXY(IsDialogMessage)
		__asm
	{
		jmp p[521 * 4];
	}
}

// IsDialogMessageA
extern "C" __declspec(naked) void __stdcall __E__522__()
{
	PROXY(IsDialogMessageA)
		__asm
	{
		jmp p[522 * 4];
	}
}

// IsDialogMessageW
extern "C" __declspec(naked) void __stdcall __E__523__()
{
	PROXY(IsDialogMessageW)
		__asm
	{
		jmp p[523 * 4];
	}
}

// IsDlgButtonChecked
extern "C" __declspec(naked) void __stdcall __E__524__()
{
	PROXY(IsDlgButtonChecked)
		__asm
	{
		jmp p[524 * 4];
	}
}

// IsGUIThread
extern "C" __declspec(naked) void __stdcall __E__525__()
{
	PROXY(IsGUIThread)
		__asm
	{
		jmp p[525 * 4];
	}
}

// IsHungAppWindow
extern "C" __declspec(naked) void __stdcall __E__526__()
{
	PROXY(IsHungAppWindow)
		__asm
	{
		jmp p[526 * 4];
	}
}

// IsIconic
extern "C" __declspec(naked) void __stdcall __E__527__()
{
	PROXY(IsIconic)
		__asm
	{
		jmp p[527 * 4];
	}
}

// IsImmersiveProcess
extern "C" __declspec(naked) void __stdcall __E__528__()
{
	PROXY(IsImmersiveProcess)
		__asm
	{
		jmp p[528 * 4];
	}
}

// IsInDesktopWindowBand
extern "C" __declspec(naked) void __stdcall __E__529__()
{
	PROXY(IsInDesktopWindowBand)
		__asm
	{
		jmp p[529 * 4];
	}
}

// IsMenu
extern "C" __declspec(naked) void __stdcall __E__530__()
{
	PROXY(IsMenu)
		__asm
	{
		jmp p[530 * 4];
	}
}

// IsMouseInPointerEnabled
extern "C" __declspec(naked) void __stdcall __E__531__()
{
	PROXY(IsMouseInPointerEnabled)
		__asm
	{
		jmp p[531 * 4];
	}
}

// IsProcessDPIAware
extern "C" __declspec(naked) void __stdcall __E__532__()
{
	PROXY(IsProcessDPIAware)
		__asm
	{
		jmp p[532 * 4];
	}
}

// IsQueueAttached
extern "C" __declspec(naked) void __stdcall __E__533__()
{
	PROXY(IsQueueAttached)
		__asm
	{
		jmp p[533 * 4];
	}
}

// IsRectEmpty
extern "C" __declspec(naked) void __stdcall __E__534__()
{
	PROXY(IsRectEmpty)
		__asm
	{
		jmp p[534 * 4];
	}
}

// IsSETEnabled
extern "C" __declspec(naked) void __stdcall __E__535__()
{
	PROXY(IsSETEnabled)
		__asm
	{
		jmp p[535 * 4];
	}
}

// IsServerSideWindow
extern "C" __declspec(naked) void __stdcall __E__536__()
{
	PROXY(IsServerSideWindow)
		__asm
	{
		jmp p[536 * 4];
	}
}

// IsThreadDesktopComposited
extern "C" __declspec(naked) void __stdcall __E__537__()
{
	PROXY(IsThreadDesktopComposited)
		__asm
	{
		jmp p[537 * 4];
	}
}

// IsThreadMessageQueueAttached
extern "C" __declspec(naked) void __stdcall __E__538__()
{
	PROXY(IsThreadMessageQueueAttached)
		__asm
	{
		jmp p[538 * 4];
	}
}

// IsTopLevelWindow
extern "C" __declspec(naked) void __stdcall __E__539__()
{
	PROXY(IsTopLevelWindow)
		__asm
	{
		jmp p[539 * 4];
	}
}

// IsTouchWindow
extern "C" __declspec(naked) void __stdcall __E__540__()
{
	PROXY(IsTouchWindow)
		__asm
	{
		jmp p[540 * 4];
	}
}

// IsWinEventHookInstalled
extern "C" __declspec(naked) void __stdcall __E__541__()
{
	PROXY(IsWinEventHookInstalled)
		__asm
	{
		jmp p[541 * 4];
	}
}

// IsWindow
extern "C" __declspec(naked) void __stdcall __E__542__()
{
	PROXY(IsWindow)
		__asm
	{
		jmp p[542 * 4];
	}
}

// IsWindowArranged
extern "C" __declspec(naked) void __stdcall __E__543__()
{
	PROXY(IsWindowArranged)
		__asm
	{
		jmp p[543 * 4];
	}
}

// IsWindowBroadcastingDpiToChildren
extern "C" __declspec(naked) void __stdcall __E__544__()
{
	PROXY(IsWindowBroadcastingDpiToChildren)
		__asm
	{
		jmp p[544 * 4];
	}
}

// IsWindowEnabled
extern "C" __declspec(naked) void __stdcall __E__545__()
{
	PROXY(IsWindowEnabled)
		__asm
	{
		jmp p[545 * 4];
	}
}

// IsWindowInDestroy
extern "C" __declspec(naked) void __stdcall __E__546__()
{
	PROXY(IsWindowInDestroy)
		__asm
	{
		jmp p[546 * 4];
	}
}

// IsWindowRedirectedForPrint
extern "C" __declspec(naked) void __stdcall __E__547__()
{
	PROXY(IsWindowRedirectedForPrint)
		__asm
	{
		jmp p[547 * 4];
	}
}

// IsWindowUnicode
extern "C" __declspec(naked) void __stdcall __E__548__()
{
	PROXY(IsWindowUnicode)
		__asm
	{
		jmp p[548 * 4];
	}
}

// IsWindowVisible
extern "C" __declspec(naked) void __stdcall __E__549__()
{
	PROXY(IsWindowVisible)
		__asm
	{
		jmp p[549 * 4];
	}
}

// IsWow64Message
extern "C" __declspec(naked) void __stdcall __E__550__()
{
	PROXY(IsWow64Message)
		__asm
	{
		jmp p[550 * 4];
	}
}

// IsZoomed
extern "C" __declspec(naked) void __stdcall __E__551__()
{
	PROXY(IsZoomed)
		__asm
	{
		jmp p[551 * 4];
	}
}

// KillTimer
extern "C" __declspec(naked) void __stdcall __E__552__()
{
	PROXY(KillTimer)
		__asm
	{
		jmp p[552 * 4];
	}
}

// LoadAcceleratorsA
extern "C" __declspec(naked) void __stdcall __E__553__()
{
	PROXY(LoadAcceleratorsA)
		__asm
	{
		jmp p[553 * 4];
	}
}

// LoadAcceleratorsW
extern "C" __declspec(naked) void __stdcall __E__554__()
{
	PROXY(LoadAcceleratorsW)
		__asm
	{
		jmp p[554 * 4];
	}
}

// LoadBitmapA
extern "C" __declspec(naked) void __stdcall __E__555__()
{
	PROXY(LoadBitmapA)
		__asm
	{
		jmp p[555 * 4];
	}
}

// LoadBitmapW
extern "C" __declspec(naked) void __stdcall __E__556__()
{
	PROXY(LoadBitmapW)
		__asm
	{
		jmp p[556 * 4];
	}
}

// LoadCursorA
extern "C" __declspec(naked) void __stdcall __E__557__()
{
	PROXY(LoadCursorA)
		__asm
	{
		jmp p[557 * 4];
	}
}

// LoadCursorFromFileA
extern "C" __declspec(naked) void __stdcall __E__558__()
{
	PROXY(LoadCursorFromFileA)
		__asm
	{
		jmp p[558 * 4];
	}
}

// LoadCursorFromFileW
extern "C" __declspec(naked) void __stdcall __E__559__()
{
	PROXY(LoadCursorFromFileW)
		__asm
	{
		jmp p[559 * 4];
	}
}

// LoadCursorW
extern "C" __declspec(naked) void __stdcall __E__560__()
{
	PROXY(LoadCursorW)
		__asm
	{
		jmp p[560 * 4];
	}
}

// LoadIconA
extern "C" __declspec(naked) void __stdcall __E__561__()
{
	PROXY(LoadIconA)
		__asm
	{
		jmp p[561 * 4];
	}
}

// LoadIconW
extern "C" __declspec(naked) void __stdcall __E__562__()
{
	PROXY(LoadIconW)
		__asm
	{
		jmp p[562 * 4];
	}
}

// LoadImageA
extern "C" __declspec(naked) void __stdcall __E__563__()
{
	PROXY(LoadImageA)
		__asm
	{
		jmp p[563 * 4];
	}
}

// LoadImageW
extern "C" __declspec(naked) void __stdcall __E__564__()
{
	PROXY(LoadImageW)
		__asm
	{
		jmp p[564 * 4];
	}
}

// LoadKeyboardLayoutA
extern "C" __declspec(naked) void __stdcall __E__565__()
{
	PROXY(LoadKeyboardLayoutA)
		__asm
	{
		jmp p[565 * 4];
	}
}

// LoadKeyboardLayoutEx
extern "C" __declspec(naked) void __stdcall __E__566__()
{
	PROXY(LoadKeyboardLayoutEx)
		__asm
	{
		jmp p[566 * 4];
	}
}

// LoadKeyboardLayoutW
extern "C" __declspec(naked) void __stdcall __E__567__()
{
	PROXY(LoadKeyboardLayoutW)
		__asm
	{
		jmp p[567 * 4];
	}
}

// LoadLocalFonts
extern "C" __declspec(naked) void __stdcall __E__568__()
{
	PROXY(LoadLocalFonts)
		__asm
	{
		jmp p[568 * 4];
	}
}

// LoadMenuA
extern "C" __declspec(naked) void __stdcall __E__569__()
{
	PROXY(LoadMenuA)
		__asm
	{
		jmp p[569 * 4];
	}
}

// LoadMenuIndirectA
extern "C" __declspec(naked) void __stdcall __E__570__()
{
	PROXY(LoadMenuIndirectA)
		__asm
	{
		jmp p[570 * 4];
	}
}

// LoadMenuIndirectW
extern "C" __declspec(naked) void __stdcall __E__571__()
{
	PROXY(LoadMenuIndirectW)
		__asm
	{
		jmp p[571 * 4];
	}
}

// LoadMenuW
extern "C" __declspec(naked) void __stdcall __E__572__()
{
	PROXY(LoadMenuW)
		__asm
	{
		jmp p[572 * 4];
	}
}

// LoadRemoteFonts
extern "C" __declspec(naked) void __stdcall __E__573__()
{
	PROXY(LoadRemoteFonts)
		__asm
	{
		jmp p[573 * 4];
	}
}

// LoadStringA
extern "C" __declspec(naked) void __stdcall __E__574__()
{
	PROXY(LoadStringA)
		__asm
	{
		jmp p[574 * 4];
	}
}

// LoadStringW
extern "C" __declspec(naked) void __stdcall __E__575__()
{
	PROXY(LoadStringW)
		__asm
	{
		jmp p[575 * 4];
	}
}

// LockSetForegroundWindow
extern "C" __declspec(naked) void __stdcall __E__576__()
{
	PROXY(LockSetForegroundWindow)
		__asm
	{
		jmp p[576 * 4];
	}
}

// LockWindowStation
extern "C" __declspec(naked) void __stdcall __E__577__()
{
	PROXY(LockWindowStation)
		__asm
	{
		jmp p[577 * 4];
	}
}

// LockWindowUpdate
extern "C" __declspec(naked) void __stdcall __E__578__()
{
	PROXY(LockWindowUpdate)
		__asm
	{
		jmp p[578 * 4];
	}
}

// LockWorkStation
extern "C" __declspec(naked) void __stdcall __E__579__()
{
	PROXY(LockWorkStation)
		__asm
	{
		jmp p[579 * 4];
	}
}

// LogicalToPhysicalPoint
extern "C" __declspec(naked) void __stdcall __E__580__()
{
	PROXY(LogicalToPhysicalPoint)
		__asm
	{
		jmp p[580 * 4];
	}
}

// LogicalToPhysicalPointForPerMonitorDPI
extern "C" __declspec(naked) void __stdcall __E__581__()
{
	PROXY(LogicalToPhysicalPointForPerMonitorDPI)
		__asm
	{
		jmp p[581 * 4];
	}
}

// LookupIconIdFromDirectory
extern "C" __declspec(naked) void __stdcall __E__582__()
{
	PROXY(LookupIconIdFromDirectory)
		__asm
	{
		jmp p[582 * 4];
	}
}

// LookupIconIdFromDirectoryEx
extern "C" __declspec(naked) void __stdcall __E__583__()
{
	PROXY(LookupIconIdFromDirectoryEx)
		__asm
	{
		jmp p[583 * 4];
	}
}

// MBToWCSEx
extern "C" __declspec(naked) void __stdcall __E__584__()
{
	PROXY(MBToWCSEx)
		__asm
	{
		jmp p[584 * 4];
	}
}

// MBToWCSExt
extern "C" __declspec(naked) void __stdcall __E__585__()
{
	PROXY(MBToWCSExt)
		__asm
	{
		jmp p[585 * 4];
	}
}

// MB_GetString
extern "C" __declspec(naked) void __stdcall __E__586__()
{
	PROXY(MB_GetString)
		__asm
	{
		jmp p[586 * 4];
	}
}

// MapDialogRect
extern "C" __declspec(naked) void __stdcall __E__587__()
{
	PROXY(MapDialogRect)
		__asm
	{
		jmp p[587 * 4];
	}
}

// MapVirtualKeyA
extern "C" __declspec(naked) void __stdcall __E__588__()
{
	PROXY(MapVirtualKeyA)
		__asm
	{
		jmp p[588 * 4];
	}
}

// MapVirtualKeyExA
extern "C" __declspec(naked) void __stdcall __E__589__()
{
	PROXY(MapVirtualKeyExA)
		__asm
	{
		jmp p[589 * 4];
	}
}

// MapVirtualKeyExW
extern "C" __declspec(naked) void __stdcall __E__590__()
{
	PROXY(MapVirtualKeyExW)
		__asm
	{
		jmp p[590 * 4];
	}
}

// MapVirtualKeyW
extern "C" __declspec(naked) void __stdcall __E__591__()
{
	PROXY(MapVirtualKeyW)
		__asm
	{
		jmp p[591 * 4];
	}
}

// MapWindowPoints
extern "C" __declspec(naked) void __stdcall __E__592__()
{
	PROXY(MapWindowPoints)
		__asm
	{
		jmp p[592 * 4];
	}
}

// MenuItemFromPoint
extern "C" __declspec(naked) void __stdcall __E__593__()
{
	PROXY(MenuItemFromPoint)
		__asm
	{
		jmp p[593 * 4];
	}
}

// MenuWindowProcA
extern "C" __declspec(naked) void __stdcall __E__594__()
{
	PROXY(MenuWindowProcA)
		__asm
	{
		jmp p[594 * 4];
	}
}

// MenuWindowProcW
extern "C" __declspec(naked) void __stdcall __E__595__()
{
	PROXY(MenuWindowProcW)
		__asm
	{
		jmp p[595 * 4];
	}
}

// MessageBeep
extern "C" __declspec(naked) void __stdcall __E__596__()
{
	PROXY(MessageBeep)
		__asm
	{
		jmp p[596 * 4];
	}
}

// MessageBoxA
extern "C" __declspec(naked) void __stdcall __E__597__()
{
	PROXY(MessageBoxA)
		__asm
	{
		jmp p[597 * 4];
	}
}

// MessageBoxExA
extern "C" __declspec(naked) void __stdcall __E__598__()
{
	PROXY(MessageBoxExA)
		__asm
	{
		jmp p[598 * 4];
	}
}

// MessageBoxExW
extern "C" __declspec(naked) void __stdcall __E__599__()
{
	PROXY(MessageBoxExW)
		__asm
	{
		jmp p[599 * 4];
	}
}

// MessageBoxIndirectA
extern "C" __declspec(naked) void __stdcall __E__600__()
{
	PROXY(MessageBoxIndirectA)
		__asm
	{
		jmp p[600 * 4];
	}
}

// MessageBoxIndirectW
extern "C" __declspec(naked) void __stdcall __E__601__()
{
	PROXY(MessageBoxIndirectW)
		__asm
	{
		jmp p[601 * 4];
	}
}

// MessageBoxTimeoutA
extern "C" __declspec(naked) void __stdcall __E__602__()
{
	PROXY(MessageBoxTimeoutA)
		__asm
	{
		jmp p[602 * 4];
	}
}

// MessageBoxTimeoutW
extern "C" __declspec(naked) void __stdcall __E__603__()
{
	PROXY(MessageBoxTimeoutW)
		__asm
	{
		jmp p[603 * 4];
	}
}

// MessageBoxW
extern "C" __declspec(naked) void __stdcall __E__604__()
{
	PROXY(MessageBoxW)
		__asm
	{
		jmp p[604 * 4];
	}
}

// ModifyMenuA
extern "C" __declspec(naked) void __stdcall __E__605__()
{
	PROXY(ModifyMenuA)
		__asm
	{
		jmp p[605 * 4];
	}
}

// ModifyMenuW
extern "C" __declspec(naked) void __stdcall __E__606__()
{
	PROXY(ModifyMenuW)
		__asm
	{
		jmp p[606 * 4];
	}
}

// MonitorFromPoint
extern "C" __declspec(naked) void __stdcall __E__607__()
{
	PROXY(MonitorFromPoint)
		__asm
	{
		jmp p[607 * 4];
	}
}

// MonitorFromRect
extern "C" __declspec(naked) void __stdcall __E__608__()
{
	PROXY(MonitorFromRect)
		__asm
	{
		jmp p[608 * 4];
	}
}

// MonitorFromWindow
extern "C" __declspec(naked) void __stdcall __E__609__()
{
	PROXY(MonitorFromWindow)
		__asm
	{
		jmp p[609 * 4];
	}
}

// MoveWindow
extern "C" __declspec(naked) void __stdcall __E__610__()
{
	PROXY(MoveWindow)
		__asm
	{
		jmp p[610 * 4];
	}
}

// MsgWaitForMultipleObjects
extern "C" __declspec(naked) void __stdcall __E__611__()
{
	PROXY(MsgWaitForMultipleObjects)
		__asm
	{
		jmp p[611 * 4];
	}
}

// MsgWaitForMultipleObjectsEx
extern "C" __declspec(naked) void __stdcall __E__612__()
{
	PROXY(MsgWaitForMultipleObjectsEx)
		__asm
	{
		jmp p[612 * 4];
	}
}

// NotifyOverlayWindow
extern "C" __declspec(naked) void __stdcall __E__613__()
{
	PROXY(NotifyOverlayWindow)
		__asm
	{
		jmp p[613 * 4];
	}
}

// NotifyWinEvent
extern "C" __declspec(naked) void __stdcall __E__614__()
{
	PROXY(NotifyWinEvent)
		__asm
	{
		jmp p[614 * 4];
	}
}

// OemKeyScan
extern "C" __declspec(naked) void __stdcall __E__615__()
{
	PROXY(OemKeyScan)
		__asm
	{
		jmp p[615 * 4];
	}
}

// OemToCharA
extern "C" __declspec(naked) void __stdcall __E__616__()
{
	PROXY(OemToCharA)
		__asm
	{
		jmp p[616 * 4];
	}
}

// OemToCharBuffA
extern "C" __declspec(naked) void __stdcall __E__617__()
{
	PROXY(OemToCharBuffA)
		__asm
	{
		jmp p[617 * 4];
	}
}

// OemToCharBuffW
extern "C" __declspec(naked) void __stdcall __E__618__()
{
	PROXY(OemToCharBuffW)
		__asm
	{
		jmp p[618 * 4];
	}
}

// OemToCharW
extern "C" __declspec(naked) void __stdcall __E__619__()
{
	PROXY(OemToCharW)
		__asm
	{
		jmp p[619 * 4];
	}
}

// OffsetRect
extern "C" __declspec(naked) void __stdcall __E__620__()
{
	PROXY(OffsetRect)
		__asm
	{
		jmp p[620 * 4];
	}
}

// OpenClipboard
extern "C" __declspec(naked) void __stdcall __E__621__()
{
	PROXY(OpenClipboard)
		__asm
	{
		jmp p[621 * 4];
	}
}

// OpenDesktopA
extern "C" __declspec(naked) void __stdcall __E__622__()
{
	PROXY(OpenDesktopA)
		__asm
	{
		jmp p[622 * 4];
	}
}

// OpenDesktopW
extern "C" __declspec(naked) void __stdcall __E__623__()
{
	PROXY(OpenDesktopW)
		__asm
	{
		jmp p[623 * 4];
	}
}

// OpenIcon
extern "C" __declspec(naked) void __stdcall __E__624__()
{
	PROXY(OpenIcon)
		__asm
	{
		jmp p[624 * 4];
	}
}

// OpenInputDesktop
extern "C" __declspec(naked) void __stdcall __E__625__()
{
	PROXY(OpenInputDesktop)
		__asm
	{
		jmp p[625 * 4];
	}
}

// OpenThreadDesktop
extern "C" __declspec(naked) void __stdcall __E__626__()
{
	PROXY(OpenThreadDesktop)
		__asm
	{
		jmp p[626 * 4];
	}
}

// OpenWindowStationA
extern "C" __declspec(naked) void __stdcall __E__627__()
{
	PROXY(OpenWindowStationA)
		__asm
	{
		jmp p[627 * 4];
	}
}

// OpenWindowStationW
extern "C" __declspec(naked) void __stdcall __E__628__()
{
	PROXY(OpenWindowStationW)
		__asm
	{
		jmp p[628 * 4];
	}
}

// PackDDElParam
extern "C" __declspec(naked) void __stdcall __E__629__()
{
	PROXY(PackDDElParam)
		__asm
	{
		jmp p[629 * 4];
	}
}

// PackTouchHitTestingProximityEvaluation
extern "C" __declspec(naked) void __stdcall __E__630__()
{
	PROXY(PackTouchHitTestingProximityEvaluation)
		__asm
	{
		jmp p[630 * 4];
	}
}

// PaintDesktop
extern "C" __declspec(naked) void __stdcall __E__631__()
{
	PROXY(PaintDesktop)
		__asm
	{
		jmp p[631 * 4];
	}
}

// PaintMenuBar
extern "C" __declspec(naked) void __stdcall __E__632__()
{
	PROXY(PaintMenuBar)
		__asm
	{
		jmp p[632 * 4];
	}
}

// PaintMonitor
extern "C" __declspec(naked) void __stdcall __E__633__()
{
	PROXY(PaintMonitor)
		__asm
	{
		jmp p[633 * 4];
	}
}

// PeekMessageA
extern "C" __declspec(naked) void __stdcall __E__634__()
{
	PROXY(PeekMessageA)
		__asm
	{
		jmp p[634 * 4];
	}
}

// PeekMessageW
extern "C" __declspec(naked) void __stdcall __E__635__()
{
	PROXY(PeekMessageW)
		__asm
	{
		jmp p[635 * 4];
	}
}

// PhysicalToLogicalPoint
extern "C" __declspec(naked) void __stdcall __E__636__()
{
	PROXY(PhysicalToLogicalPoint)
		__asm
	{
		jmp p[636 * 4];
	}
}

// PhysicalToLogicalPointForPerMonitorDPI
extern "C" __declspec(naked) void __stdcall __E__637__()
{
	PROXY(PhysicalToLogicalPointForPerMonitorDPI)
		__asm
	{
		jmp p[637 * 4];
	}
}

// PostMessageA
extern "C" __declspec(naked) void __stdcall __E__638__()
{
	PROXY(PostMessageA)
		__asm
	{
		jmp p[638 * 4];
	}
}

// PostMessageW
extern "C" __declspec(naked) void __stdcall __E__639__()
{
	PROXY(PostMessageW)
		__asm
	{
		jmp p[639 * 4];
	}
}

// PostQuitMessage
extern "C" __declspec(naked) void __stdcall __E__640__()
{
	PROXY(PostQuitMessage)
		__asm
	{
		jmp p[640 * 4];
	}
}

// PostThreadMessageA
extern "C" __declspec(naked) void __stdcall __E__641__()
{
	PROXY(PostThreadMessageA)
		__asm
	{
		jmp p[641 * 4];
	}
}

// PostThreadMessageW
extern "C" __declspec(naked) void __stdcall __E__642__()
{
	PROXY(PostThreadMessageW)
		__asm
	{
		jmp p[642 * 4];
	}
}

// PrintWindow
extern "C" __declspec(naked) void __stdcall __E__643__()
{
	PROXY(PrintWindow)
		__asm
	{
		jmp p[643 * 4];
	}
}

// PrivateExtractIconExA
extern "C" __declspec(naked) void __stdcall __E__644__()
{
	PROXY(PrivateExtractIconExA)
		__asm
	{
		jmp p[644 * 4];
	}
}

// PrivateExtractIconExW
extern "C" __declspec(naked) void __stdcall __E__645__()
{
	PROXY(PrivateExtractIconExW)
		__asm
	{
		jmp p[645 * 4];
	}
}

// PrivateExtractIconsA
extern "C" __declspec(naked) void __stdcall __E__646__()
{
	PROXY(PrivateExtractIconsA)
		__asm
	{
		jmp p[646 * 4];
	}
}

// PrivateExtractIconsW
extern "C" __declspec(naked) void __stdcall __E__647__()
{
	PROXY(PrivateExtractIconsW)
		__asm
	{
		jmp p[647 * 4];
	}
}

// PrivateRegisterICSProc
extern "C" __declspec(naked) void __stdcall __E__648__()
{
	PROXY(PrivateRegisterICSProc)
		__asm
	{
		jmp p[648 * 4];
	}
}

// PtInRect
extern "C" __declspec(naked) void __stdcall __E__649__()
{
	PROXY(PtInRect)
		__asm
	{
		jmp p[649 * 4];
	}
}

// QueryBSDRWindow
extern "C" __declspec(naked) void __stdcall __E__650__()
{
	PROXY(QueryBSDRWindow)
		__asm
	{
		jmp p[650 * 4];
	}
}

// QueryDisplayConfig
extern "C" __declspec(naked) void __stdcall __E__651__()
{
	PROXY(QueryDisplayConfig)
		__asm
	{
		jmp p[651 * 4];
	}
}

// QuerySendMessage
extern "C" __declspec(naked) void __stdcall __E__652__()
{
	PROXY(QuerySendMessage)
		__asm
	{
		jmp p[652 * 4];
	}
}

// RIMAddInputObserver
extern "C" __declspec(naked) void __stdcall __E__653__()
{
	PROXY(RIMAddInputObserver)
		__asm
	{
		jmp p[653 * 4];
	}
}

// RIMAreSiblingDevices
extern "C" __declspec(naked) void __stdcall __E__654__()
{
	PROXY(RIMAreSiblingDevices)
		__asm
	{
		jmp p[654 * 4];
	}
}

// RIMDeviceIoControl
extern "C" __declspec(naked) void __stdcall __E__655__()
{
	PROXY(RIMDeviceIoControl)
		__asm
	{
		jmp p[655 * 4];
	}
}

// RIMFreeInputBuffer
extern "C" __declspec(naked) void __stdcall __E__656__()
{
	PROXY(RIMFreeInputBuffer)
		__asm
	{
		jmp p[656 * 4];
	}
}

// RIMGetDevicePreparsedData
extern "C" __declspec(naked) void __stdcall __E__657__()
{
	PROXY(RIMGetDevicePreparsedData)
		__asm
	{
		jmp p[657 * 4];
	}
}

// RIMGetDevicePreparsedDataLockfree
extern "C" __declspec(naked) void __stdcall __E__658__()
{
	PROXY(RIMGetDevicePreparsedDataLockfree)
		__asm
	{
		jmp p[658 * 4];
	}
}

// RIMGetDeviceProperties
extern "C" __declspec(naked) void __stdcall __E__659__()
{
	PROXY(RIMGetDeviceProperties)
		__asm
	{
		jmp p[659 * 4];
	}
}

// RIMGetPhysicalDeviceRect
extern "C" __declspec(naked) void __stdcall __E__660__()
{
	PROXY(RIMGetPhysicalDeviceRect)
		__asm
	{
		jmp p[660 * 4];
	}
}

// RIMObserveNextInput
extern "C" __declspec(naked) void __stdcall __E__661__()
{
	PROXY(RIMObserveNextInput)
		__asm
	{
		jmp p[661 * 4];
	}
}

// RIMOnPnpNotification
extern "C" __declspec(naked) void __stdcall __E__662__()
{
	PROXY(RIMOnPnpNotification)
		__asm
	{
		jmp p[662 * 4];
	}
}

// RIMOnTimerNotification
extern "C" __declspec(naked) void __stdcall __E__663__()
{
	PROXY(RIMOnTimerNotification)
		__asm
	{
		jmp p[663 * 4];
	}
}

// RIMReadInput
extern "C" __declspec(naked) void __stdcall __E__664__()
{
	PROXY(RIMReadInput)
		__asm
	{
		jmp p[664 * 4];
	}
}

// RIMRegisterForInput
extern "C" __declspec(naked) void __stdcall __E__665__()
{
	PROXY(RIMRegisterForInput)
		__asm
	{
		jmp p[665 * 4];
	}
}

// RIMRemoveInputObserver
extern "C" __declspec(naked) void __stdcall __E__666__()
{
	PROXY(RIMRemoveInputObserver)
		__asm
	{
		jmp p[666 * 4];
	}
}

// RIMSetTestModeStatus
extern "C" __declspec(naked) void __stdcall __E__667__()
{
	PROXY(RIMSetTestModeStatus)
		__asm
	{
		jmp p[667 * 4];
	}
}

// RIMUnregisterForInput
extern "C" __declspec(naked) void __stdcall __E__668__()
{
	PROXY(RIMUnregisterForInput)
		__asm
	{
		jmp p[668 * 4];
	}
}

// RIMUpdateInputObserverRegistration
extern "C" __declspec(naked) void __stdcall __E__669__()
{
	PROXY(RIMUpdateInputObserverRegistration)
		__asm
	{
		jmp p[669 * 4];
	}
}

// RealChildWindowFromPoint
extern "C" __declspec(naked) void __stdcall __E__670__()
{
	PROXY(RealChildWindowFromPoint)
		__asm
	{
		jmp p[670 * 4];
	}
}

// RealGetWindowClass
extern "C" __declspec(naked) void __stdcall __E__671__()
{
	PROXY(RealGetWindowClass)
		__asm
	{
		jmp p[671 * 4];
	}
}

// RealGetWindowClassA
extern "C" __declspec(naked) void __stdcall __E__672__()
{
	PROXY(RealGetWindowClassA)
		__asm
	{
		jmp p[672 * 4];
	}
}

// RealGetWindowClassW
extern "C" __declspec(naked) void __stdcall __E__673__()
{
	PROXY(RealGetWindowClassW)
		__asm
	{
		jmp p[673 * 4];
	}
}

// ReasonCodeNeedsBugID
extern "C" __declspec(naked) void __stdcall __E__674__()
{
	PROXY(ReasonCodeNeedsBugID)
		__asm
	{
		jmp p[674 * 4];
	}
}

// ReasonCodeNeedsComment
extern "C" __declspec(naked) void __stdcall __E__675__()
{
	PROXY(ReasonCodeNeedsComment)
		__asm
	{
		jmp p[675 * 4];
	}
}

// RecordShutdownReason
extern "C" __declspec(naked) void __stdcall __E__676__()
{
	PROXY(RecordShutdownReason)
		__asm
	{
		jmp p[676 * 4];
	}
}

// RedrawWindow
extern "C" __declspec(naked) void __stdcall __E__677__()
{
	PROXY(RedrawWindow)
		__asm
	{
		jmp p[677 * 4];
	}
}

// RegisterBSDRWindow
extern "C" __declspec(naked) void __stdcall __E__678__()
{
	PROXY(RegisterBSDRWindow)
		__asm
	{
		jmp p[678 * 4];
	}
}

// RegisterClassA
extern "C" __declspec(naked) void __stdcall __E__679__()
{
	PROXY(RegisterClassA)
		__asm
	{
		jmp p[679 * 4];
	}
}

// RegisterClassExA
extern "C" __declspec(naked) void __stdcall __E__680__()
{
	PROXY(RegisterClassExA)
		__asm
	{
		jmp p[680 * 4];
	}
}

// RegisterClassExW
extern "C" __declspec(naked) void __stdcall __E__681__()
{
	PROXY(RegisterClassExW)
		__asm
	{
		jmp p[681 * 4];
	}
}

// RegisterClassW
extern "C" __declspec(naked) void __stdcall __E__682__()
{
	PROXY(RegisterClassW)
		__asm
	{
		jmp p[682 * 4];
	}
}

// RegisterClipboardFormatA
extern "C" __declspec(naked) void __stdcall __E__683__()
{
	PROXY(RegisterClipboardFormatA)
		__asm
	{
		jmp p[683 * 4];
	}
}

// RegisterClipboardFormatW
extern "C" __declspec(naked) void __stdcall __E__684__()
{
	PROXY(RegisterClipboardFormatW)
		__asm
	{
		jmp p[684 * 4];
	}
}

// RegisterDManipHook
extern "C" __declspec(naked) void __stdcall __E__685__()
{
	PROXY(RegisterDManipHook)
		__asm
	{
		jmp p[685 * 4];
	}
}

// RegisterDeviceNotificationA
extern "C" __declspec(naked) void __stdcall __E__686__()
{
	PROXY(RegisterDeviceNotificationA)
		__asm
	{
		jmp p[686 * 4];
	}
}

// RegisterDeviceNotificationW
extern "C" __declspec(naked) void __stdcall __E__687__()
{
	PROXY(RegisterDeviceNotificationW)
		__asm
	{
		jmp p[687 * 4];
	}
}

// RegisterErrorReportingDialog
extern "C" __declspec(naked) void __stdcall __E__688__()
{
	PROXY(RegisterErrorReportingDialog)
		__asm
	{
		jmp p[688 * 4];
	}
}

// RegisterFrostWindow
extern "C" __declspec(naked) void __stdcall __E__689__()
{
	PROXY(RegisterFrostWindow)
		__asm
	{
		jmp p[689 * 4];
	}
}

// RegisterGhostWindow
extern "C" __declspec(naked) void __stdcall __E__690__()
{
	PROXY(RegisterGhostWindow)
		__asm
	{
		jmp p[690 * 4];
	}
}

// RegisterHotKey
extern "C" __declspec(naked) void __stdcall __E__691__()
{
	PROXY(RegisterHotKey)
		__asm
	{
		jmp p[691 * 4];
	}
}

// RegisterLogonProcess
extern "C" __declspec(naked) void __stdcall __E__692__()
{
	PROXY(RegisterLogonProcess)
		__asm
	{
		jmp p[692 * 4];
	}
}

// RegisterManipulationThread
extern "C" __declspec(naked) void __stdcall __E__693__()
{
	PROXY(RegisterManipulationThread)
		__asm
	{
		jmp p[693 * 4];
	}
}

// RegisterMessagePumpHook
extern "C" __declspec(naked) void __stdcall __E__694__()
{
	PROXY(RegisterMessagePumpHook)
		__asm
	{
		jmp p[694 * 4];
	}
}

// RegisterPointerDeviceNotifications
extern "C" __declspec(naked) void __stdcall __E__695__()
{
	PROXY(RegisterPointerDeviceNotifications)
		__asm
	{
		jmp p[695 * 4];
	}
}

// RegisterPointerInputTarget
extern "C" __declspec(naked) void __stdcall __E__696__()
{
	PROXY(RegisterPointerInputTarget)
		__asm
	{
		jmp p[696 * 4];
	}
}

// RegisterPointerInputTargetEx
extern "C" __declspec(naked) void __stdcall __E__697__()
{
	PROXY(RegisterPointerInputTargetEx)
		__asm
	{
		jmp p[697 * 4];
	}
}

// RegisterPowerSettingNotification
extern "C" __declspec(naked) void __stdcall __E__698__()
{
	PROXY(RegisterPowerSettingNotification)
		__asm
	{
		jmp p[698 * 4];
	}
}

// RegisterRawInputDevices
extern "C" __declspec(naked) void __stdcall __E__699__()
{
	PROXY(RegisterRawInputDevices)
		__asm
	{
		jmp p[699 * 4];
	}
}

// RegisterServicesProcess
extern "C" __declspec(naked) void __stdcall __E__700__()
{
	PROXY(RegisterServicesProcess)
		__asm
	{
		jmp p[700 * 4];
	}
}

// RegisterSessionPort
extern "C" __declspec(naked) void __stdcall __E__701__()
{
	PROXY(RegisterSessionPort)
		__asm
	{
		jmp p[701 * 4];
	}
}

// RegisterShellHookWindow
extern "C" __declspec(naked) void __stdcall __E__702__()
{
	PROXY(RegisterShellHookWindow)
		__asm
	{
		jmp p[702 * 4];
	}
}

// RegisterSuspendResumeNotification
extern "C" __declspec(naked) void __stdcall __E__703__()
{
	PROXY(RegisterSuspendResumeNotification)
		__asm
	{
		jmp p[703 * 4];
	}
}

// RegisterSystemThread
extern "C" __declspec(naked) void __stdcall __E__704__()
{
	PROXY(RegisterSystemThread)
		__asm
	{
		jmp p[704 * 4];
	}
}

// RegisterTasklist
extern "C" __declspec(naked) void __stdcall __E__705__()
{
	PROXY(RegisterTasklist)
		__asm
	{
		jmp p[705 * 4];
	}
}

// RegisterTouchHitTestingWindow
extern "C" __declspec(naked) void __stdcall __E__706__()
{
	PROXY(RegisterTouchHitTestingWindow)
		__asm
	{
		jmp p[706 * 4];
	}
}

// RegisterTouchWindow
extern "C" __declspec(naked) void __stdcall __E__707__()
{
	PROXY(RegisterTouchWindow)
		__asm
	{
		jmp p[707 * 4];
	}
}

// RegisterUserApiHook
extern "C" __declspec(naked) void __stdcall __E__708__()
{
	PROXY(RegisterUserApiHook)
		__asm
	{
		jmp p[708 * 4];
	}
}

// RegisterWindowMessageA
extern "C" __declspec(naked) void __stdcall __E__709__()
{
	PROXY(RegisterWindowMessageA)
		__asm
	{
		jmp p[709 * 4];
	}
}

// RegisterWindowMessageW
extern "C" __declspec(naked) void __stdcall __E__710__()
{
	PROXY(RegisterWindowMessageW)
		__asm
	{
		jmp p[710 * 4];
	}
}

// ReleaseCapture
extern "C" __declspec(naked) void __stdcall __E__711__()
{
	PROXY(ReleaseCapture)
		__asm
	{
		jmp p[711 * 4];
	}
}

// ReleaseDC
extern "C" __declspec(naked) void __stdcall __E__712__()
{
	PROXY(ReleaseDC)
		__asm
	{
		jmp p[712 * 4];
	}
}

// ReleaseDwmHitTestWaiters
extern "C" __declspec(naked) void __stdcall __E__713__()
{
	PROXY(ReleaseDwmHitTestWaiters)
		__asm
	{
		jmp p[713 * 4];
	}
}

// RemoveClipboardFormatListener
extern "C" __declspec(naked) void __stdcall __E__714__()
{
	PROXY(RemoveClipboardFormatListener)
		__asm
	{
		jmp p[714 * 4];
	}
}

// RemoveInjectionDevice
extern "C" __declspec(naked) void __stdcall __E__715__()
{
	PROXY(RemoveInjectionDevice)
		__asm
	{
		jmp p[715 * 4];
	}
}

// RemoveMenu
extern "C" __declspec(naked) void __stdcall __E__716__()
{
	PROXY(RemoveMenu)
		__asm
	{
		jmp p[716 * 4];
	}
}

// RemovePropA
extern "C" __declspec(naked) void __stdcall __E__717__()
{
	PROXY(RemovePropA)
		__asm
	{
		jmp p[717 * 4];
	}
}

// RemovePropW
extern "C" __declspec(naked) void __stdcall __E__718__()
{
	PROXY(RemovePropW)
		__asm
	{
		jmp p[718 * 4];
	}
}

// ReplyMessage
extern "C" __declspec(naked) void __stdcall __E__719__()
{
	PROXY(ReplyMessage)
		__asm
	{
		jmp p[719 * 4];
	}
}

// ResolveDesktopForWOW
extern "C" __declspec(naked) void __stdcall __E__720__()
{
	PROXY(ResolveDesktopForWOW)
		__asm
	{
		jmp p[720 * 4];
	}
}

// ReuseDDElParam
extern "C" __declspec(naked) void __stdcall __E__721__()
{
	PROXY(ReuseDDElParam)
		__asm
	{
		jmp p[721 * 4];
	}
}

// ScreenToClient
extern "C" __declspec(naked) void __stdcall __E__722__()
{
	PROXY(ScreenToClient)
		__asm
	{
		jmp p[722 * 4];
	}
}

// ScrollChildren
extern "C" __declspec(naked) void __stdcall __E__723__()
{
	PROXY(ScrollChildren)
		__asm
	{
		jmp p[723 * 4];
	}
}

// ScrollDC
extern "C" __declspec(naked) void __stdcall __E__724__()
{
	PROXY(ScrollDC)
		__asm
	{
		jmp p[724 * 4];
	}
}

// ScrollWindow
extern "C" __declspec(naked) void __stdcall __E__725__()
{
	PROXY(ScrollWindow)
		__asm
	{
		jmp p[725 * 4];
	}
}

// ScrollWindowEx
extern "C" __declspec(naked) void __stdcall __E__726__()
{
	PROXY(ScrollWindowEx)
		__asm
	{
		jmp p[726 * 4];
	}
}

// SendDlgItemMessageA
extern "C" __declspec(naked) void __stdcall __E__727__()
{
	PROXY(SendDlgItemMessageA)
		__asm
	{
		jmp p[727 * 4];
	}
}

// SendDlgItemMessageW
extern "C" __declspec(naked) void __stdcall __E__728__()
{
	PROXY(SendDlgItemMessageW)
		__asm
	{
		jmp p[728 * 4];
	}
}

// SendIMEMessageExA
extern "C" __declspec(naked) void __stdcall __E__729__()
{
	PROXY(SendIMEMessageExA)
		__asm
	{
		jmp p[729 * 4];
	}
}

// SendIMEMessageExW
extern "C" __declspec(naked) void __stdcall __E__730__()
{
	PROXY(SendIMEMessageExW)
		__asm
	{
		jmp p[730 * 4];
	}
}

// SendInput
extern "C" __declspec(naked) void __stdcall __E__731__()
{
	PROXY(SendInput)
		__asm
	{
		jmp p[731 * 4];
	}
}

// SendMessageA
extern "C" __declspec(naked) void __stdcall __E__732__()
{
	PROXY(SendMessageA)
		__asm
	{
		jmp p[732 * 4];
	}
}

// SendMessageCallbackA
extern "C" __declspec(naked) void __stdcall __E__733__()
{
	PROXY(SendMessageCallbackA)
		__asm
	{
		jmp p[733 * 4];
	}
}

// SendMessageCallbackW
extern "C" __declspec(naked) void __stdcall __E__734__()
{
	PROXY(SendMessageCallbackW)
		__asm
	{
		jmp p[734 * 4];
	}
}

// SendMessageTimeoutA
extern "C" __declspec(naked) void __stdcall __E__735__()
{
	PROXY(SendMessageTimeoutA)
		__asm
	{
		jmp p[735 * 4];
	}
}

// SendMessageTimeoutW
extern "C" __declspec(naked) void __stdcall __E__736__()
{
	PROXY(SendMessageTimeoutW)
		__asm
	{
		jmp p[736 * 4];
	}
}

// SendMessageW
extern "C" __declspec(naked) void __stdcall __E__737__()
{
	PROXY(SendMessageW)
		__asm
	{
		jmp p[737 * 4];
	}
}

// SendNotifyMessageA
extern "C" __declspec(naked) void __stdcall __E__738__()
{
	PROXY(SendNotifyMessageA)
		__asm
	{
		jmp p[738 * 4];
	}
}

// SendNotifyMessageW
extern "C" __declspec(naked) void __stdcall __E__739__()
{
	PROXY(SendNotifyMessageW)
		__asm
	{
		jmp p[739 * 4];
	}
}

// SetActiveWindow
extern "C" __declspec(naked) void __stdcall __E__740__()
{
	PROXY(SetActiveWindow)
		__asm
	{
		jmp p[740 * 4];
	}
}

// SetCapture
extern "C" __declspec(naked) void __stdcall __E__741__()
{
	PROXY(SetCapture)
		__asm
	{
		jmp p[741 * 4];
	}
}

// SetCaretBlinkTime
extern "C" __declspec(naked) void __stdcall __E__742__()
{
	PROXY(SetCaretBlinkTime)
		__asm
	{
		jmp p[742 * 4];
	}
}

// SetCaretPos
extern "C" __declspec(naked) void __stdcall __E__743__()
{
	PROXY(SetCaretPos)
		__asm
	{
		jmp p[743 * 4];
	}
}

// SetClassLongA
extern "C" __declspec(naked) void __stdcall __E__744__()
{
	PROXY(SetClassLongA)
		__asm
	{
		jmp p[744 * 4];
	}
}

// SetClassLongW
extern "C" __declspec(naked) void __stdcall __E__745__()
{
	PROXY(SetClassLongW)
		__asm
	{
		jmp p[745 * 4];
	}
}

// SetClassWord
extern "C" __declspec(naked) void __stdcall __E__746__()
{
	PROXY(SetClassWord)
		__asm
	{
		jmp p[746 * 4];
	}
}

// SetClipboardData
extern "C" __declspec(naked) void __stdcall __E__747__()
{
	PROXY(SetClipboardData)
		__asm
	{
		jmp p[747 * 4];
	}
}

// SetClipboardViewer
extern "C" __declspec(naked) void __stdcall __E__748__()
{
	PROXY(SetClipboardViewer)
		__asm
	{
		jmp p[748 * 4];
	}
}

// SetCoalescableTimer
extern "C" __declspec(naked) void __stdcall __E__749__()
{
	PROXY(SetCoalescableTimer)
		__asm
	{
		jmp p[749 * 4];
	}
}

// SetCursor
extern "C" __declspec(naked) void __stdcall __E__750__()
{
	PROXY(SetCursor)
		__asm
	{
		jmp p[750 * 4];
	}
}

// SetCursorContents
extern "C" __declspec(naked) void __stdcall __E__751__()
{
	PROXY(SetCursorContents)
		__asm
	{
		jmp p[751 * 4];
	}
}

// SetCursorPos
extern "C" __declspec(naked) void __stdcall __E__752__()
{
	PROXY(SetCursorPos)
		__asm
	{
		jmp p[752 * 4];
	}
}

// SetDebugErrorLevel
extern "C" __declspec(naked) void __stdcall __E__753__()
{
	PROXY(SetDebugErrorLevel)
		__asm
	{
		jmp p[753 * 4];
	}
}

// SetDeskWallpaper
extern "C" __declspec(naked) void __stdcall __E__754__()
{
	PROXY(SetDeskWallpaper)
		__asm
	{
		jmp p[754 * 4];
	}
}

// SetDisplayAutoRotationPreferences
extern "C" __declspec(naked) void __stdcall __E__755__()
{
	PROXY(SetDisplayAutoRotationPreferences)
		__asm
	{
		jmp p[755 * 4];
	}
}

// SetDisplayConfig
extern "C" __declspec(naked) void __stdcall __E__756__()
{
	PROXY(SetDisplayConfig)
		__asm
	{
		jmp p[756 * 4];
	}
}

// SetDlgItemInt
extern "C" __declspec(naked) void __stdcall __E__757__()
{
	PROXY(SetDlgItemInt)
		__asm
	{
		jmp p[757 * 4];
	}
}

// SetDlgItemTextA
extern "C" __declspec(naked) void __stdcall __E__758__()
{
	PROXY(SetDlgItemTextA)
		__asm
	{
		jmp p[758 * 4];
	}
}

// SetDlgItemTextW
extern "C" __declspec(naked) void __stdcall __E__759__()
{
	PROXY(SetDlgItemTextW)
		__asm
	{
		jmp p[759 * 4];
	}
}

// SetDoubleClickTime
extern "C" __declspec(naked) void __stdcall __E__760__()
{
	PROXY(SetDoubleClickTime)
		__asm
	{
		jmp p[760 * 4];
	}
}

// SetFeatureReportResponse
extern "C" __declspec(naked) void __stdcall __E__761__()
{
	PROXY(SetFeatureReportResponse)
		__asm
	{
		jmp p[761 * 4];
	}
}

// SetFocus
extern "C" __declspec(naked) void __stdcall __E__762__()
{
	PROXY(SetFocus)
		__asm
	{
		jmp p[762 * 4];
	}
}

// SetForegroundWindow
extern "C" __declspec(naked) void __stdcall __E__763__()
{
	PROXY(SetForegroundWindow)
		__asm
	{
		jmp p[763 * 4];
	}
}

// SetGestureConfig
extern "C" __declspec(naked) void __stdcall __E__764__()
{
	PROXY(SetGestureConfig)
		__asm
	{
		jmp p[764 * 4];
	}
}

// SetInternalWindowPos
extern "C" __declspec(naked) void __stdcall __E__765__()
{
	PROXY(SetInternalWindowPos)
		__asm
	{
		jmp p[765 * 4];
	}
}

// SetKeyboardState
extern "C" __declspec(naked) void __stdcall __E__766__()
{
	PROXY(SetKeyboardState)
		__asm
	{
		jmp p[766 * 4];
	}
}

// SetLastErrorEx
extern "C" __declspec(naked) void __stdcall __E__767__()
{
	PROXY(SetLastErrorEx)
		__asm
	{
		jmp p[767 * 4];
	}
}

// SetLayeredWindowAttributes
extern "C" __declspec(naked) void __stdcall __E__768__()
{
	PROXY(SetLayeredWindowAttributes)
		__asm
	{
		jmp p[768 * 4];
	}
}

// SetMagnificationDesktopColorEffect
extern "C" __declspec(naked) void __stdcall __E__769__()
{
	PROXY(SetMagnificationDesktopColorEffect)
		__asm
	{
		jmp p[769 * 4];
	}
}

// SetMagnificationDesktopMagnification
extern "C" __declspec(naked) void __stdcall __E__770__()
{
	PROXY(SetMagnificationDesktopMagnification)
		__asm
	{
		jmp p[770 * 4];
	}
}

// SetMagnificationLensCtxInformation
extern "C" __declspec(naked) void __stdcall __E__771__()
{
	PROXY(SetMagnificationLensCtxInformation)
		__asm
	{
		jmp p[771 * 4];
	}
}

// SetManipulationInputTarget
extern "C" __declspec(naked) void __stdcall __E__772__()
{
	PROXY(SetManipulationInputTarget)
		__asm
	{
		jmp p[772 * 4];
	}
}

// SetMenu
extern "C" __declspec(naked) void __stdcall __E__773__()
{
	PROXY(SetMenu)
		__asm
	{
		jmp p[773 * 4];
	}
}

// SetMenuContextHelpId
extern "C" __declspec(naked) void __stdcall __E__774__()
{
	PROXY(SetMenuContextHelpId)
		__asm
	{
		jmp p[774 * 4];
	}
}

// SetMenuDefaultItem
extern "C" __declspec(naked) void __stdcall __E__775__()
{
	PROXY(SetMenuDefaultItem)
		__asm
	{
		jmp p[775 * 4];
	}
}

// SetMenuInfo
extern "C" __declspec(naked) void __stdcall __E__776__()
{
	PROXY(SetMenuInfo)
		__asm
	{
		jmp p[776 * 4];
	}
}

// SetMenuItemBitmaps
extern "C" __declspec(naked) void __stdcall __E__777__()
{
	PROXY(SetMenuItemBitmaps)
		__asm
	{
		jmp p[777 * 4];
	}
}

// SetMenuItemInfoA
extern "C" __declspec(naked) void __stdcall __E__778__()
{
	PROXY(SetMenuItemInfoA)
		__asm
	{
		jmp p[778 * 4];
	}
}

// SetMenuItemInfoW
extern "C" __declspec(naked) void __stdcall __E__779__()
{
	PROXY(SetMenuItemInfoW)
		__asm
	{
		jmp p[779 * 4];
	}
}

// SetMessageExtraInfo
extern "C" __declspec(naked) void __stdcall __E__780__()
{
	PROXY(SetMessageExtraInfo)
		__asm
	{
		jmp p[780 * 4];
	}
}

// SetMessageQueue
extern "C" __declspec(naked) void __stdcall __E__781__()
{
	PROXY(SetMessageQueue)
		__asm
	{
		jmp p[781 * 4];
	}
}

// SetMirrorRendering
extern "C" __declspec(naked) void __stdcall __E__782__()
{
	PROXY(SetMirrorRendering)
		__asm
	{
		jmp p[782 * 4];
	}
}

// SetParent
extern "C" __declspec(naked) void __stdcall __E__783__()
{
	PROXY(SetParent)
		__asm
	{
		jmp p[783 * 4];
	}
}

// SetPhysicalCursorPos
extern "C" __declspec(naked) void __stdcall __E__784__()
{
	PROXY(SetPhysicalCursorPos)
		__asm
	{
		jmp p[784 * 4];
	}
}

// SetProcessDPIAware
extern "C" __declspec(naked) void __stdcall __E__785__()
{
	PROXY(SetProcessDPIAware)
		__asm
	{
		jmp p[785 * 4];
	}
}

// SetProcessDefaultLayout
extern "C" __declspec(naked) void __stdcall __E__786__()
{
	PROXY(SetProcessDefaultLayout)
		__asm
	{
		jmp p[786 * 4];
	}
}

// SetProcessDpiAwarenessInternal
extern "C" __declspec(naked) void __stdcall __E__787__()
{
	PROXY(SetProcessDpiAwarenessInternal)
		__asm
	{
		jmp p[787 * 4];
	}
}

// SetProcessRestrictionExemption
extern "C" __declspec(naked) void __stdcall __E__788__()
{
	PROXY(SetProcessRestrictionExemption)
		__asm
	{
		jmp p[788 * 4];
	}
}

// SetProcessWindowStation
extern "C" __declspec(naked) void __stdcall __E__789__()
{
	PROXY(SetProcessWindowStation)
		__asm
	{
		jmp p[789 * 4];
	}
}

// SetProgmanWindow
extern "C" __declspec(naked) void __stdcall __E__790__()
{
	PROXY(SetProgmanWindow)
		__asm
	{
		jmp p[790 * 4];
	}
}

// SetPropA
extern "C" __declspec(naked) void __stdcall __E__791__()
{
	PROXY(SetPropA)
		__asm
	{
		jmp p[791 * 4];
	}
}

// SetPropW
extern "C" __declspec(naked) void __stdcall __E__792__()
{
	PROXY(SetPropW)
		__asm
	{
		jmp p[792 * 4];
	}
}

// SetRect
extern "C" __declspec(naked) void __stdcall __E__793__()
{
	PROXY(SetRect)
		__asm
	{
		jmp p[793 * 4];
	}
}

// SetRectEmpty
extern "C" __declspec(naked) void __stdcall __E__794__()
{
	PROXY(SetRectEmpty)
		__asm
	{
		jmp p[794 * 4];
	}
}

// SetScrollInfo
extern "C" __declspec(naked) void __stdcall __E__795__()
{
	PROXY(SetScrollInfo)
		__asm
	{
		jmp p[795 * 4];
	}
}

// SetScrollPos
extern "C" __declspec(naked) void __stdcall __E__796__()
{
	PROXY(SetScrollPos)
		__asm
	{
		jmp p[796 * 4];
	}
}

// SetScrollRange
extern "C" __declspec(naked) void __stdcall __E__797__()
{
	PROXY(SetScrollRange)
		__asm
	{
		jmp p[797 * 4];
	}
}

// SetShellWindow
extern "C" __declspec(naked) void __stdcall __E__798__()
{
	PROXY(SetShellWindow)
		__asm
	{
		jmp p[798 * 4];
	}
}

// SetShellWindowEx
extern "C" __declspec(naked) void __stdcall __E__799__()
{
	PROXY(SetShellWindowEx)
		__asm
	{
		jmp p[799 * 4];
	}
}

// SetSysColors
extern "C" __declspec(naked) void __stdcall __E__800__()
{
	PROXY(SetSysColors)
		__asm
	{
		jmp p[800 * 4];
	}
}

// SetSysColorsTemp
extern "C" __declspec(naked) void __stdcall __E__801__()
{
	PROXY(SetSysColorsTemp)
		__asm
	{
		jmp p[801 * 4];
	}
}

// SetSystemCursor
extern "C" __declspec(naked) void __stdcall __E__802__()
{
	PROXY(SetSystemCursor)
		__asm
	{
		jmp p[802 * 4];
	}
}

// SetSystemMenu
extern "C" __declspec(naked) void __stdcall __E__803__()
{
	PROXY(SetSystemMenu)
		__asm
	{
		jmp p[803 * 4];
	}
}

// SetTaskmanWindow
extern "C" __declspec(naked) void __stdcall __E__804__()
{
	PROXY(SetTaskmanWindow)
		__asm
	{
		jmp p[804 * 4];
	}
}

// SetThreadDesktop
extern "C" __declspec(naked) void __stdcall __E__805__()
{
	PROXY(SetThreadDesktop)
		__asm
	{
		jmp p[805 * 4];
	}
}

// SetThreadInputBlocked
extern "C" __declspec(naked) void __stdcall __E__806__()
{
	PROXY(SetThreadInputBlocked)
		__asm
	{
		jmp p[806 * 4];
	}
}

// SetTimer
extern "C" __declspec(naked) void __stdcall __E__807__()
{
	PROXY(SetTimer)
		__asm
	{
		jmp p[807 * 4];
	}
}

// SetUserObjectInformationA
extern "C" __declspec(naked) void __stdcall __E__808__()
{
	PROXY(SetUserObjectInformationA)
		__asm
	{
		jmp p[808 * 4];
	}
}

// SetUserObjectInformationW
extern "C" __declspec(naked) void __stdcall __E__809__()
{
	PROXY(SetUserObjectInformationW)
		__asm
	{
		jmp p[809 * 4];
	}
}

// SetUserObjectSecurity
extern "C" __declspec(naked) void __stdcall __E__810__()
{
	PROXY(SetUserObjectSecurity)
		__asm
	{
		jmp p[810 * 4];
	}
}

// SetWinEventHook
extern "C" __declspec(naked) void __stdcall __E__811__()
{
	PROXY(SetWinEventHook)
		__asm
	{
		jmp p[811 * 4];
	}
}

// SetWindowBand
extern "C" __declspec(naked) void __stdcall __E__812__()
{
	PROXY(SetWindowBand)
		__asm
	{
		jmp p[812 * 4];
	}
}

// SetWindowCompositionAttribute
extern "C" __declspec(naked) void __stdcall __E__813__()
{
	PROXY(SetWindowCompositionAttribute)
		__asm
	{
		jmp p[813 * 4];
	}
}

// SetWindowCompositionTransition
extern "C" __declspec(naked) void __stdcall __E__814__()
{
	PROXY(SetWindowCompositionTransition)
		__asm
	{
		jmp p[814 * 4];
	}
}

// SetWindowContextHelpId
extern "C" __declspec(naked) void __stdcall __E__815__()
{
	PROXY(SetWindowContextHelpId)
		__asm
	{
		jmp p[815 * 4];
	}
}

// SetWindowDisplayAffinity
extern "C" __declspec(naked) void __stdcall __E__816__()
{
	PROXY(SetWindowDisplayAffinity)
		__asm
	{
		jmp p[816 * 4];
	}
}

// SetWindowFeedbackSetting
extern "C" __declspec(naked) void __stdcall __E__817__()
{
	PROXY(SetWindowFeedbackSetting)
		__asm
	{
		jmp p[817 * 4];
	}
}

// SetWindowLongA
extern "C" __declspec(naked) void __stdcall __E__818__()
{
	PROXY(SetWindowLongA)
		__asm
	{
		jmp p[818 * 4];
	}
}

// SetWindowLongW
extern "C" __declspec(naked) void __stdcall __E__819__()
{
	PROXY(SetWindowLongW)
		__asm
	{
		jmp p[819 * 4];
	}
}

// SetWindowPlacement
extern "C" __declspec(naked) void __stdcall __E__820__()
{
	PROXY(SetWindowPlacement)
		__asm
	{
		jmp p[820 * 4];
	}
}

// SetWindowPos
extern "C" __declspec(naked) void __stdcall __E__821__()
{
	PROXY(SetWindowPos)
		__asm
	{
		jmp p[821 * 4];
	}
}

// SetWindowRgn
extern "C" __declspec(naked) void __stdcall __E__822__()
{
	PROXY(SetWindowRgn)
		__asm
	{
		jmp p[822 * 4];
	}
}

// SetWindowRgnEx
extern "C" __declspec(naked) void __stdcall __E__823__()
{
	PROXY(SetWindowRgnEx)
		__asm
	{
		jmp p[823 * 4];
	}
}

// SetWindowStationUser
extern "C" __declspec(naked) void __stdcall __E__824__()
{
	PROXY(SetWindowStationUser)
		__asm
	{
		jmp p[824 * 4];
	}
}

// SetWindowTextA
extern "C" __declspec(naked) void __stdcall __E__825__()
{
	PROXY(SetWindowTextA)
		__asm
	{
		jmp p[825 * 4];
	}
}

// SetWindowTextW
extern "C" __declspec(naked) void __stdcall __E__826__()
{
	PROXY(SetWindowTextW)
		__asm
	{
		jmp p[826 * 4];
	}
}

// SetWindowWord
extern "C" __declspec(naked) void __stdcall __E__827__()
{
	PROXY(SetWindowWord)
		__asm
	{
		jmp p[827 * 4];
	}
}

// SetWindowsHookA
extern "C" __declspec(naked) void __stdcall __E__828__()
{
	PROXY(SetWindowsHookA)
		__asm
	{
		jmp p[828 * 4];
	}
}

// SetWindowsHookExA
extern "C" __declspec(naked) void __stdcall __E__829__()
{
	PROXY(SetWindowsHookExA)
		__asm
	{
		jmp p[829 * 4];
	}
}

// SetWindowsHookExW
extern "C" __declspec(naked) void __stdcall __E__830__()
{
	PROXY(SetWindowsHookExW)
		__asm
	{
		jmp p[830 * 4];
	}
}

// SetWindowsHookW
extern "C" __declspec(naked) void __stdcall __E__831__()
{
	PROXY(SetWindowsHookW)
		__asm
	{
		jmp p[831 * 4];
	}
}

// ShowCaret
extern "C" __declspec(naked) void __stdcall __E__832__()
{
	PROXY(ShowCaret)
		__asm
	{
		jmp p[832 * 4];
	}
}

// ShowCursor
extern "C" __declspec(naked) void __stdcall __E__833__()
{
	PROXY(ShowCursor)
		__asm
	{
		jmp p[833 * 4];
	}
}

// ShowOwnedPopups
extern "C" __declspec(naked) void __stdcall __E__834__()
{
	PROXY(ShowOwnedPopups)
		__asm
	{
		jmp p[834 * 4];
	}
}

// ShowScrollBar
extern "C" __declspec(naked) void __stdcall __E__835__()
{
	PROXY(ShowScrollBar)
		__asm
	{
		jmp p[835 * 4];
	}
}

// ShowStartGlass
extern "C" __declspec(naked) void __stdcall __E__836__()
{
	PROXY(ShowStartGlass)
		__asm
	{
		jmp p[836 * 4];
	}
}

// ShowSystemCursor
extern "C" __declspec(naked) void __stdcall __E__837__()
{
	PROXY(ShowSystemCursor)
		__asm
	{
		jmp p[837 * 4];
	}
}

// ShowWindow
extern "C" __declspec(naked) void __stdcall __E__838__()
{
	PROXY(ShowWindow)
		__asm
	{
		jmp p[838 * 4];
	}
}

// ShowWindowAsync
extern "C" __declspec(naked) void __stdcall __E__839__()
{
	PROXY(ShowWindowAsync)
		__asm
	{
		jmp p[839 * 4];
	}
}

// ShutdownBlockReasonCreate
extern "C" __declspec(naked) void __stdcall __E__840__()
{
	PROXY(ShutdownBlockReasonCreate)
		__asm
	{
		jmp p[840 * 4];
	}
}

// ShutdownBlockReasonDestroy
extern "C" __declspec(naked) void __stdcall __E__841__()
{
	PROXY(ShutdownBlockReasonDestroy)
		__asm
	{
		jmp p[841 * 4];
	}
}

// ShutdownBlockReasonQuery
extern "C" __declspec(naked) void __stdcall __E__842__()
{
	PROXY(ShutdownBlockReasonQuery)
		__asm
	{
		jmp p[842 * 4];
	}
}

// SignalRedirectionStartComplete
extern "C" __declspec(naked) void __stdcall __E__843__()
{
	PROXY(SignalRedirectionStartComplete)
		__asm
	{
		jmp p[843 * 4];
	}
}

// SkipPointerFrameMessages
extern "C" __declspec(naked) void __stdcall __E__844__()
{
	PROXY(SkipPointerFrameMessages)
		__asm
	{
		jmp p[844 * 4];
	}
}

// SoftModalMessageBox
extern "C" __declspec(naked) void __stdcall __E__845__()
{
	PROXY(SoftModalMessageBox)
		__asm
	{
		jmp p[845 * 4];
	}
}

// SoundSentry
extern "C" __declspec(naked) void __stdcall __E__846__()
{
	PROXY(SoundSentry)
		__asm
	{
		jmp p[846 * 4];
	}
}

// SubtractRect
extern "C" __declspec(naked) void __stdcall __E__847__()
{
	PROXY(SubtractRect)
		__asm
	{
		jmp p[847 * 4];
	}
}

// SwapMouseButton
extern "C" __declspec(naked) void __stdcall __E__848__()
{
	PROXY(SwapMouseButton)
		__asm
	{
		jmp p[848 * 4];
	}
}

// SwitchDesktop
extern "C" __declspec(naked) void __stdcall __E__849__()
{
	PROXY(SwitchDesktop)
		__asm
	{
		jmp p[849 * 4];
	}
}

// SwitchDesktopWithFade
extern "C" __declspec(naked) void __stdcall __E__850__()
{
	PROXY(SwitchDesktopWithFade)
		__asm
	{
		jmp p[850 * 4];
	}
}

// SwitchToThisWindow
extern "C" __declspec(naked) void __stdcall __E__851__()
{
	PROXY(SwitchToThisWindow)
		__asm
	{
		jmp p[851 * 4];
	}
}

// SystemParametersInfoA
extern "C" __declspec(naked) void __stdcall __E__852__()
{
	PROXY(SystemParametersInfoA)
		__asm
	{
		jmp p[852 * 4];
	}
}

// SystemParametersInfoW
extern "C" __declspec(naked) void __stdcall __E__853__()
{
	PROXY(SystemParametersInfoW)
		__asm
	{
		jmp p[853 * 4];
	}
}

// TabbedTextOutA
extern "C" __declspec(naked) void __stdcall __E__854__()
{
	PROXY(TabbedTextOutA)
		__asm
	{
		jmp p[854 * 4];
	}
}

// TabbedTextOutW
extern "C" __declspec(naked) void __stdcall __E__855__()
{
	PROXY(TabbedTextOutW)
		__asm
	{
		jmp p[855 * 4];
	}
}

// TileChildWindows
extern "C" __declspec(naked) void __stdcall __E__856__()
{
	PROXY(TileChildWindows)
		__asm
	{
		jmp p[856 * 4];
	}
}

// TileWindows
extern "C" __declspec(naked) void __stdcall __E__857__()
{
	PROXY(TileWindows)
		__asm
	{
		jmp p[857 * 4];
	}
}

// ToAscii
extern "C" __declspec(naked) void __stdcall __E__858__()
{
	PROXY(ToAscii)
		__asm
	{
		jmp p[858 * 4];
	}
}

// ToAsciiEx
extern "C" __declspec(naked) void __stdcall __E__859__()
{
	PROXY(ToAsciiEx)
		__asm
	{
		jmp p[859 * 4];
	}
}

// ToUnicode
extern "C" __declspec(naked) void __stdcall __E__860__()
{
	PROXY(ToUnicode)
		__asm
	{
		jmp p[860 * 4];
	}
}

// ToUnicodeEx
extern "C" __declspec(naked) void __stdcall __E__861__()
{
	PROXY(ToUnicodeEx)
		__asm
	{
		jmp p[861 * 4];
	}
}

// TrackMouseEvent
extern "C" __declspec(naked) void __stdcall __E__862__()
{
	PROXY(TrackMouseEvent)
		__asm
	{
		jmp p[862 * 4];
	}
}

// TrackPopupMenu
extern "C" __declspec(naked) void __stdcall __E__863__()
{
	PROXY(TrackPopupMenu)
		__asm
	{
		jmp p[863 * 4];
	}
}

// TrackPopupMenuEx
extern "C" __declspec(naked) void __stdcall __E__864__()
{
	PROXY(TrackPopupMenuEx)
		__asm
	{
		jmp p[864 * 4];
	}
}

// TranslateAccelerator
extern "C" __declspec(naked) void __stdcall __E__865__()
{
	PROXY(TranslateAccelerator)
		__asm
	{
		jmp p[865 * 4];
	}
}

// TranslateAcceleratorA
extern "C" __declspec(naked) void __stdcall __E__866__()
{
	PROXY(TranslateAcceleratorA)
		__asm
	{
		jmp p[866 * 4];
	}
}

// TranslateAcceleratorW
extern "C" __declspec(naked) void __stdcall __E__867__()
{
	PROXY(TranslateAcceleratorW)
		__asm
	{
		jmp p[867 * 4];
	}
}

// TranslateMDISysAccel
extern "C" __declspec(naked) void __stdcall __E__868__()
{
	PROXY(TranslateMDISysAccel)
		__asm
	{
		jmp p[868 * 4];
	}
}

// TranslateMessage
extern "C" __declspec(naked) void __stdcall __E__869__()
{
	PROXY(TranslateMessage)
		__asm
	{
		jmp p[869 * 4];
	}
}

// TranslateMessageEx
extern "C" __declspec(naked) void __stdcall __E__870__()
{
	PROXY(TranslateMessageEx)
		__asm
	{
		jmp p[870 * 4];
	}
}

// UnhookWinEvent
extern "C" __declspec(naked) void __stdcall __E__871__()
{
	PROXY(UnhookWinEvent)
		__asm
	{
		jmp p[871 * 4];
	}
}

// UnhookWindowsHook
extern "C" __declspec(naked) void __stdcall __E__872__()
{
	PROXY(UnhookWindowsHook)
		__asm
	{
		jmp p[872 * 4];
	}
}

// UnhookWindowsHookEx
extern "C" __declspec(naked) void __stdcall __E__873__()
{
	PROXY(UnhookWindowsHookEx)
		__asm
	{
		jmp p[873 * 4];
	}
}

// UnionRect
extern "C" __declspec(naked) void __stdcall __E__874__()
{
	PROXY(UnionRect)
		__asm
	{
		jmp p[874 * 4];
	}
}

// UnloadKeyboardLayout
extern "C" __declspec(naked) void __stdcall __E__875__()
{
	PROXY(UnloadKeyboardLayout)
		__asm
	{
		jmp p[875 * 4];
	}
}

// UnlockWindowStation
extern "C" __declspec(naked) void __stdcall __E__876__()
{
	PROXY(UnlockWindowStation)
		__asm
	{
		jmp p[876 * 4];
	}
}

// UnpackDDElParam
extern "C" __declspec(naked) void __stdcall __E__877__()
{
	PROXY(UnpackDDElParam)
		__asm
	{
		jmp p[877 * 4];
	}
}

// UnregisterClassA
extern "C" __declspec(naked) void __stdcall __E__878__()
{
	PROXY(UnregisterClassA)
		__asm
	{
		jmp p[878 * 4];
	}
}

// UnregisterClassW
extern "C" __declspec(naked) void __stdcall __E__879__()
{
	PROXY(UnregisterClassW)
		__asm
	{
		jmp p[879 * 4];
	}
}

// UnregisterDeviceNotification
extern "C" __declspec(naked) void __stdcall __E__880__()
{
	PROXY(UnregisterDeviceNotification)
		__asm
	{
		jmp p[880 * 4];
	}
}

// UnregisterHotKey
extern "C" __declspec(naked) void __stdcall __E__881__()
{
	PROXY(UnregisterHotKey)
		__asm
	{
		jmp p[881 * 4];
	}
}

// UnregisterMessagePumpHook
extern "C" __declspec(naked) void __stdcall __E__882__()
{
	PROXY(UnregisterMessagePumpHook)
		__asm
	{
		jmp p[882 * 4];
	}
}

// UnregisterPointerInputTarget
extern "C" __declspec(naked) void __stdcall __E__883__()
{
	PROXY(UnregisterPointerInputTarget)
		__asm
	{
		jmp p[883 * 4];
	}
}

// UnregisterPointerInputTargetEx
extern "C" __declspec(naked) void __stdcall __E__884__()
{
	PROXY(UnregisterPointerInputTargetEx)
		__asm
	{
		jmp p[884 * 4];
	}
}

// UnregisterPowerSettingNotification
extern "C" __declspec(naked) void __stdcall __E__885__()
{
	PROXY(UnregisterPowerSettingNotification)
		__asm
	{
		jmp p[885 * 4];
	}
}

// UnregisterSessionPort
extern "C" __declspec(naked) void __stdcall __E__886__()
{
	PROXY(UnregisterSessionPort)
		__asm
	{
		jmp p[886 * 4];
	}
}

// UnregisterSuspendResumeNotification
extern "C" __declspec(naked) void __stdcall __E__887__()
{
	PROXY(UnregisterSuspendResumeNotification)
		__asm
	{
		jmp p[887 * 4];
	}
}

// UnregisterTouchWindow
extern "C" __declspec(naked) void __stdcall __E__888__()
{
	PROXY(UnregisterTouchWindow)
		__asm
	{
		jmp p[888 * 4];
	}
}

// UnregisterUserApiHook
extern "C" __declspec(naked) void __stdcall __E__889__()
{
	PROXY(UnregisterUserApiHook)
		__asm
	{
		jmp p[889 * 4];
	}
}

// UpdateDefaultDesktopThumbnail
extern "C" __declspec(naked) void __stdcall __E__890__()
{
	PROXY(UpdateDefaultDesktopThumbnail)
		__asm
	{
		jmp p[890 * 4];
	}
}

// UpdateLayeredWindow
extern "C" __declspec(naked) void __stdcall __E__891__()
{
	PROXY(UpdateLayeredWindow)
		__asm
	{
		jmp p[891 * 4];
	}
}

// UpdateLayeredWindowIndirect
extern "C" __declspec(naked) void __stdcall __E__892__()
{
	PROXY(UpdateLayeredWindowIndirect)
		__asm
	{
		jmp p[892 * 4];
	}
}

// UpdatePerUserSystemParameters
extern "C" __declspec(naked) void __stdcall __E__893__()
{
	PROXY(UpdatePerUserSystemParameters)
		__asm
	{
		jmp p[893 * 4];
	}
}

// UpdateWindow
extern "C" __declspec(naked) void __stdcall __E__894__()
{
	PROXY(UpdateWindow)
		__asm
	{
		jmp p[894 * 4];
	}
}

// UpdateWindowInputSinkHints
extern "C" __declspec(naked) void __stdcall __E__895__()
{
	PROXY(UpdateWindowInputSinkHints)
		__asm
	{
		jmp p[895 * 4];
	}
}

// UpdateWindowTransform
extern "C" __declspec(naked) void __stdcall __E__896__()
{
	PROXY(UpdateWindowTransform)
		__asm
	{
		jmp p[896 * 4];
	}
}

// User32InitializeImmEntryTable
extern "C" __declspec(naked) void __stdcall __E__897__()
{
	PROXY(User32InitializeImmEntryTable)
		__asm
	{
		jmp p[897 * 4];
	}
}

// UserClientDllInitialize
extern "C" __declspec(naked) void __stdcall __E__898__()
{
	PROXY(UserClientDllInitialize)
		__asm
	{
		jmp p[898 * 4];
	}
}

// UserHandleGrantAccess
extern "C" __declspec(naked) void __stdcall __E__899__()
{
	PROXY(UserHandleGrantAccess)
		__asm
	{
		jmp p[899 * 4];
	}
}

// UserLpkPSMTextOut
extern "C" __declspec(naked) void __stdcall __E__900__()
{
	PROXY(UserLpkPSMTextOut)
		__asm
	{
		jmp p[900 * 4];
	}
}

// UserLpkTabbedTextOut
extern "C" __declspec(naked) void __stdcall __E__901__()
{
	PROXY(UserLpkTabbedTextOut)
		__asm
	{
		jmp p[901 * 4];
	}
}

// UserRealizePalette
extern "C" __declspec(naked) void __stdcall __E__902__()
{
	PROXY(UserRealizePalette)
		__asm
	{
		jmp p[902 * 4];
	}
}

// UserRegisterWowHandlers
extern "C" __declspec(naked) void __stdcall __E__903__()
{
	PROXY(UserRegisterWowHandlers)
		__asm
	{
		jmp p[903 * 4];
	}
}

// VRipOutput
extern "C" __declspec(naked) void __stdcall __E__904__()
{
	PROXY(VRipOutput)
		__asm
	{
		jmp p[904 * 4];
	}
}

// VTagOutput
extern "C" __declspec(naked) void __stdcall __E__905__()
{
	PROXY(VTagOutput)
		__asm
	{
		jmp p[905 * 4];
	}
}

// ValidateRect
extern "C" __declspec(naked) void __stdcall __E__906__()
{
	PROXY(ValidateRect)
		__asm
	{
		jmp p[906 * 4];
	}
}

// ValidateRgn
extern "C" __declspec(naked) void __stdcall __E__907__()
{
	PROXY(ValidateRgn)
		__asm
	{
		jmp p[907 * 4];
	}
}

// VkKeyScanA
extern "C" __declspec(naked) void __stdcall __E__908__()
{
	PROXY(VkKeyScanA)
		__asm
	{
		jmp p[908 * 4];
	}
}

// VkKeyScanExA
extern "C" __declspec(naked) void __stdcall __E__909__()
{
	PROXY(VkKeyScanExA)
		__asm
	{
		jmp p[909 * 4];
	}
}

// VkKeyScanExW
extern "C" __declspec(naked) void __stdcall __E__910__()
{
	PROXY(VkKeyScanExW)
		__asm
	{
		jmp p[910 * 4];
	}
}

// VkKeyScanW
extern "C" __declspec(naked) void __stdcall __E__911__()
{
	PROXY(VkKeyScanW)
		__asm
	{
		jmp p[911 * 4];
	}
}

// WCSToMBEx
extern "C" __declspec(naked) void __stdcall __E__912__()
{
	PROXY(WCSToMBEx)
		__asm
	{
		jmp p[912 * 4];
	}
}

// WINNLSEnableIME
extern "C" __declspec(naked) void __stdcall __E__913__()
{
	PROXY(WINNLSEnableIME)
		__asm
	{
		jmp p[913 * 4];
	}
}

// WINNLSGetEnableStatus
extern "C" __declspec(naked) void __stdcall __E__914__()
{
	PROXY(WINNLSGetEnableStatus)
		__asm
	{
		jmp p[914 * 4];
	}
}

// WINNLSGetIMEHotkey
extern "C" __declspec(naked) void __stdcall __E__915__()
{
	PROXY(WINNLSGetIMEHotkey)
		__asm
	{
		jmp p[915 * 4];
	}
}

// WaitForInputIdle
extern "C" __declspec(naked) void __stdcall __E__916__()
{
	PROXY(WaitForInputIdle)
		__asm
	{
		jmp p[916 * 4];
	}
}

// WaitForRedirectionStartComplete
extern "C" __declspec(naked) void __stdcall __E__917__()
{
	PROXY(WaitForRedirectionStartComplete)
		__asm
	{
		jmp p[917 * 4];
	}
}

// WaitMessage
extern "C" __declspec(naked) void __stdcall __E__918__()
{
	PROXY(WaitMessage)
		__asm
	{
		jmp p[918 * 4];
	}
}

// WinHelpA
extern "C" __declspec(naked) void __stdcall __E__919__()
{
	PROXY(WinHelpA)
		__asm
	{
		jmp p[919 * 4];
	}
}

// WinHelpW
extern "C" __declspec(naked) void __stdcall __E__920__()
{
	PROXY(WinHelpW)
		__asm
	{
		jmp p[920 * 4];
	}
}

// WindowFromDC
extern "C" __declspec(naked) void __stdcall __E__921__()
{
	PROXY(WindowFromDC)
		__asm
	{
		jmp p[921 * 4];
	}
}

// WindowFromPhysicalPoint
extern "C" __declspec(naked) void __stdcall __E__922__()
{
	PROXY(WindowFromPhysicalPoint)
		__asm
	{
		jmp p[922 * 4];
	}
}

// WindowFromPoint
extern "C" __declspec(naked) void __stdcall __E__923__()
{
	PROXY(WindowFromPoint)
		__asm
	{
		jmp p[923 * 4];
	}
}

// _UserTestTokenForInteractive
extern "C" __declspec(naked) void __stdcall __E__924__()
{
	PROXY(_UserTestTokenForInteractive)
		__asm
	{
		jmp p[924 * 4];
	}
}

// gSharedInfo
extern "C" __declspec(naked) void __stdcall __E__925__()
{
	PROXY(gSharedInfo)
		__asm
	{
		jmp p[925 * 4];
	}
}

// gapfnScSendMessage
extern "C" __declspec(naked) void __stdcall __E__926__()
{
	PROXY(gapfnScSendMessage)
		__asm
	{
		jmp p[926 * 4];
	}
}

// keybd_event
extern "C" __declspec(naked) void __stdcall __E__927__()
{
	PROXY(keybd_event)
		__asm
	{
		jmp p[927 * 4];
	}
}

// mouse_event
extern "C" __declspec(naked) void __stdcall __E__928__()
{
	PROXY(mouse_event)
		__asm
	{
		jmp p[928 * 4];
	}
}

// wsprintfA
extern "C" __declspec(naked) void __stdcall __E__929__()
{
	PROXY(wsprintfA)
		__asm
	{
		jmp p[929 * 4];
	}
}

// wsprintfW
extern "C" __declspec(naked) void __stdcall __E__930__()
{
	PROXY(wsprintfW)
		__asm
	{
		jmp p[930 * 4];
	}
}

// wvsprintfA
extern "C" __declspec(naked) void __stdcall __E__931__()
{
	PROXY(wvsprintfA)
		__asm
	{
		jmp p[931 * 4];
	}
}

// wvsprintfW
extern "C" __declspec(naked) void __stdcall __E__932__()
{
	PROXY(wvsprintfW)
		__asm
	{
		jmp p[932 * 4];
	}
}

// ___XXX___934
extern "C" __declspec(naked) void __stdcall __E__933__()
{
	PROXY(___XXX___934)
		__asm
	{
		jmp p[933 * 4];
	}
}

// ___XXX___935
extern "C" __declspec(naked) void __stdcall __E__934__()
{
	PROXY(___XXX___935)
		__asm
	{
		jmp p[934 * 4];
	}
}

// ___XXX___936
extern "C" __declspec(naked) void __stdcall __E__935__()
{
	PROXY(___XXX___936)
		__asm
	{
		jmp p[935 * 4];
	}
}

// ___XXX___937
extern "C" __declspec(naked) void __stdcall __E__936__()
{
	PROXY(___XXX___937)
		__asm
	{
		jmp p[936 * 4];
	}
}

// ___XXX___938
extern "C" __declspec(naked) void __stdcall __E__937__()
{
	PROXY(___XXX___938)
		__asm
	{
		jmp p[937 * 4];
	}
}

// ___XXX___939
extern "C" __declspec(naked) void __stdcall __E__938__()
{
	PROXY(___XXX___939)
		__asm
	{
		jmp p[938 * 4];
	}
}

// ___XXX___940
extern "C" __declspec(naked) void __stdcall __E__939__()
{
	PROXY(___XXX___940)
		__asm
	{
		jmp p[939 * 4];
	}
}

// ___XXX___941
extern "C" __declspec(naked) void __stdcall __E__940__()
{
	PROXY(___XXX___941)
		__asm
	{
		jmp p[940 * 4];
	}
}

// ___XXX___942
extern "C" __declspec(naked) void __stdcall __E__941__()
{
	PROXY(___XXX___942)
		__asm
	{
		jmp p[941 * 4];
	}
}

// ___XXX___943
extern "C" __declspec(naked) void __stdcall __E__942__()
{
	PROXY(___XXX___943)
		__asm
	{
		jmp p[942 * 4];
	}
}

// ___XXX___944
extern "C" __declspec(naked) void __stdcall __E__943__()
{
	PROXY(___XXX___944)
		__asm
	{
		jmp p[943 * 4];
	}
}

// ___XXX___945
extern "C" __declspec(naked) void __stdcall __E__944__()
{
	PROXY(___XXX___945)
		__asm
	{
		jmp p[944 * 4];
	}
}

// ___XXX___946
extern "C" __declspec(naked) void __stdcall __E__945__()
{
	PROXY(___XXX___946)
		__asm
	{
		jmp p[945 * 4];
	}
}

// ___XXX___947
extern "C" __declspec(naked) void __stdcall __E__946__()
{
	PROXY(___XXX___947)
		__asm
	{
		jmp p[946 * 4];
	}
}

// ___XXX___948
extern "C" __declspec(naked) void __stdcall __E__947__()
{
	PROXY(___XXX___948)
		__asm
	{
		jmp p[947 * 4];
	}
}

// ___XXX___949
extern "C" __declspec(naked) void __stdcall __E__948__()
{
	PROXY(___XXX___949)
		__asm
	{
		jmp p[948 * 4];
	}
}

// ___XXX___950
extern "C" __declspec(naked) void __stdcall __E__949__()
{
	PROXY(___XXX___950)
		__asm
	{
		jmp p[949 * 4];
	}
}

// ___XXX___951
extern "C" __declspec(naked) void __stdcall __E__950__()
{
	PROXY(___XXX___951)
		__asm
	{
		jmp p[950 * 4];
	}
}

// ___XXX___952
extern "C" __declspec(naked) void __stdcall __E__951__()
{
	PROXY(___XXX___952)
		__asm
	{
		jmp p[951 * 4];
	}
}

// ___XXX___953
extern "C" __declspec(naked) void __stdcall __E__952__()
{
	PROXY(___XXX___953)
		__asm
	{
		jmp p[952 * 4];
	}
}

// ___XXX___954
extern "C" __declspec(naked) void __stdcall __E__953__()
{
	PROXY(___XXX___954)
		__asm
	{
		jmp p[953 * 4];
	}
}

// ___XXX___955
extern "C" __declspec(naked) void __stdcall __E__954__()
{
	PROXY(___XXX___955)
		__asm
	{
		jmp p[954 * 4];
	}
}

// ___XXX___956
extern "C" __declspec(naked) void __stdcall __E__955__()
{
	PROXY(___XXX___956)
		__asm
	{
		jmp p[955 * 4];
	}
}

// ___XXX___957
extern "C" __declspec(naked) void __stdcall __E__956__()
{
	PROXY(___XXX___957)
		__asm
	{
		jmp p[956 * 4];
	}
}

// ___XXX___958
extern "C" __declspec(naked) void __stdcall __E__957__()
{
	PROXY(___XXX___958)
		__asm
	{
		jmp p[957 * 4];
	}
}

// ___XXX___959
extern "C" __declspec(naked) void __stdcall __E__958__()
{
	PROXY(___XXX___959)
		__asm
	{
		jmp p[958 * 4];
	}
}

// ___XXX___960
extern "C" __declspec(naked) void __stdcall __E__959__()
{
	PROXY(___XXX___960)
		__asm
	{
		jmp p[959 * 4];
	}
}

// ___XXX___961
extern "C" __declspec(naked) void __stdcall __E__960__()
{
	PROXY(___XXX___961)
		__asm
	{
		jmp p[960 * 4];
	}
}

// ___XXX___962
extern "C" __declspec(naked) void __stdcall __E__961__()
{
	PROXY(___XXX___962)
		__asm
	{
		jmp p[961 * 4];
	}
}

// ___XXX___963
extern "C" __declspec(naked) void __stdcall __E__962__()
{
	PROXY(___XXX___963)
		__asm
	{
		jmp p[962 * 4];
	}
}

// ___XXX___964
extern "C" __declspec(naked) void __stdcall __E__963__()
{
	PROXY(___XXX___964)
		__asm
	{
		jmp p[963 * 4];
	}
}

// ___XXX___965
extern "C" __declspec(naked) void __stdcall __E__964__()
{
	PROXY(___XXX___965)
		__asm
	{
		jmp p[964 * 4];
	}
}

// ___XXX___966
extern "C" __declspec(naked) void __stdcall __E__965__()
{
	PROXY(___XXX___966)
		__asm
	{
		jmp p[965 * 4];
	}
}

// ___XXX___967
extern "C" __declspec(naked) void __stdcall __E__966__()
{
	PROXY(___XXX___967)
		__asm
	{
		jmp p[966 * 4];
	}
}

// ___XXX___968
extern "C" __declspec(naked) void __stdcall __E__967__()
{
	PROXY(___XXX___968)
		__asm
	{
		jmp p[967 * 4];
	}
}

// ___XXX___969
extern "C" __declspec(naked) void __stdcall __E__968__()
{
	PROXY(___XXX___969)
		__asm
	{
		jmp p[968 * 4];
	}
}

// ___XXX___970
extern "C" __declspec(naked) void __stdcall __E__969__()
{
	PROXY(___XXX___970)
		__asm
	{
		jmp p[969 * 4];
	}
}

// ___XXX___971
extern "C" __declspec(naked) void __stdcall __E__970__()
{
	PROXY(___XXX___971)
		__asm
	{
		jmp p[970 * 4];
	}
}

// ___XXX___972
extern "C" __declspec(naked) void __stdcall __E__971__()
{
	PROXY(___XXX___972)
		__asm
	{
		jmp p[971 * 4];
	}
}

// ___XXX___973
extern "C" __declspec(naked) void __stdcall __E__972__()
{
	PROXY(___XXX___973)
		__asm
	{
		jmp p[972 * 4];
	}
}

// ___XXX___974
extern "C" __declspec(naked) void __stdcall __E__973__()
{
	PROXY(___XXX___974)
		__asm
	{
		jmp p[973 * 4];
	}
}

// ___XXX___975
extern "C" __declspec(naked) void __stdcall __E__974__()
{
	PROXY(___XXX___975)
		__asm
	{
		jmp p[974 * 4];
	}
}

// ___XXX___976
extern "C" __declspec(naked) void __stdcall __E__975__()
{
	PROXY(___XXX___976)
		__asm
	{
		jmp p[975 * 4];
	}
}

// ___XXX___977
extern "C" __declspec(naked) void __stdcall __E__976__()
{
	PROXY(___XXX___977)
		__asm
	{
		jmp p[976 * 4];
	}
}

// ___XXX___978
extern "C" __declspec(naked) void __stdcall __E__977__()
{
	PROXY(___XXX___978)
		__asm
	{
		jmp p[977 * 4];
	}
}

// ___XXX___979
extern "C" __declspec(naked) void __stdcall __E__978__()
{
	PROXY(___XXX___979)
		__asm
	{
		jmp p[978 * 4];
	}
}

// ___XXX___980
extern "C" __declspec(naked) void __stdcall __E__979__()
{
	PROXY(___XXX___980)
		__asm
	{
		jmp p[979 * 4];
	}
}

// ___XXX___981
extern "C" __declspec(naked) void __stdcall __E__980__()
{
	PROXY(___XXX___981)
		__asm
	{
		jmp p[980 * 4];
	}
}

// ___XXX___982
extern "C" __declspec(naked) void __stdcall __E__981__()
{
	PROXY(___XXX___982)
		__asm
	{
		jmp p[981 * 4];
	}
}

// ___XXX___983
extern "C" __declspec(naked) void __stdcall __E__982__()
{
	PROXY(___XXX___983)
		__asm
	{
		jmp p[982 * 4];
	}
}

// ___XXX___984
extern "C" __declspec(naked) void __stdcall __E__983__()
{
	PROXY(___XXX___984)
		__asm
	{
		jmp p[983 * 4];
	}
}

// ___XXX___985
extern "C" __declspec(naked) void __stdcall __E__984__()
{
	PROXY(___XXX___985)
		__asm
	{
		jmp p[984 * 4];
	}
}

// ___XXX___986
extern "C" __declspec(naked) void __stdcall __E__985__()
{
	PROXY(___XXX___986)
		__asm
	{
		jmp p[985 * 4];
	}
}

// ___XXX___987
extern "C" __declspec(naked) void __stdcall __E__986__()
{
	PROXY(___XXX___987)
		__asm
	{
		jmp p[986 * 4];
	}
}

// ___XXX___988
extern "C" __declspec(naked) void __stdcall __E__987__()
{
	PROXY(___XXX___988)
		__asm
	{
		jmp p[987 * 4];
	}
}

// ___XXX___989
extern "C" __declspec(naked) void __stdcall __E__988__()
{
	PROXY(___XXX___989)
		__asm
	{
		jmp p[988 * 4];
	}
}

// ___XXX___990
extern "C" __declspec(naked) void __stdcall __E__989__()
{
	PROXY(___XXX___990)
		__asm
	{
		jmp p[989 * 4];
	}
}

// ___XXX___991
extern "C" __declspec(naked) void __stdcall __E__990__()
{
	PROXY(___XXX___991)
		__asm
	{
		jmp p[990 * 4];
	}
}

// ___XXX___992
extern "C" __declspec(naked) void __stdcall __E__991__()
{
	PROXY(___XXX___992)
		__asm
	{
		jmp p[991 * 4];
	}
}

// ___XXX___993
extern "C" __declspec(naked) void __stdcall __E__992__()
{
	PROXY(___XXX___993)
		__asm
	{
		jmp p[992 * 4];
	}
}

// ___XXX___994
extern "C" __declspec(naked) void __stdcall __E__993__()
{
	PROXY(___XXX___994)
		__asm
	{
		jmp p[993 * 4];
	}
}

// ___XXX___995
extern "C" __declspec(naked) void __stdcall __E__994__()
{
	PROXY(___XXX___995)
		__asm
	{
		jmp p[994 * 4];
	}
}

// ___XXX___996
extern "C" __declspec(naked) void __stdcall __E__995__()
{
	PROXY(___XXX___996)
		__asm
	{
		jmp p[995 * 4];
	}
}

// ___XXX___997
extern "C" __declspec(naked) void __stdcall __E__996__()
{
	PROXY(___XXX___997)
		__asm
	{
		jmp p[996 * 4];
	}
}

// ___XXX___998
extern "C" __declspec(naked) void __stdcall __E__997__()
{
	PROXY(___XXX___998)
		__asm
	{
		jmp p[997 * 4];
	}
}

// ___XXX___999
extern "C" __declspec(naked) void __stdcall __E__998__()
{
	PROXY(___XXX___999)
		__asm
	{
		jmp p[998 * 4];
	}
}

// ___XXX___1000
extern "C" __declspec(naked) void __stdcall __E__999__()
{
	PROXY(___XXX___1000)
		__asm
	{
		jmp p[999 * 4];
	}
}

// ___XXX___1001
extern "C" __declspec(naked) void __stdcall __E__1000__()
{
	PROXY(___XXX___1001)
		__asm
	{
		jmp p[1000 * 4];
	}
}

// ___XXX___1002
extern "C" __declspec(naked) void __stdcall __E__1001__()
{
	PROXY(___XXX___1002)
		__asm
	{
		jmp p[1001 * 4];
	}
}

// ___XXX___1003
extern "C" __declspec(naked) void __stdcall __E__1002__()
{
	PROXY(___XXX___1003)
		__asm
	{
		jmp p[1002 * 4];
	}
}

// ___XXX___1004
extern "C" __declspec(naked) void __stdcall __E__1003__()
{
	PROXY(___XXX___1004)
		__asm
	{
		jmp p[1003 * 4];
	}
}

// ___XXX___1005
extern "C" __declspec(naked) void __stdcall __E__1004__()
{
	PROXY(___XXX___1005)
		__asm
	{
		jmp p[1004 * 4];
	}
}

// ___XXX___1006
extern "C" __declspec(naked) void __stdcall __E__1005__()
{
	PROXY(___XXX___1006)
		__asm
	{
		jmp p[1005 * 4];
	}
}

// ___XXX___1007
extern "C" __declspec(naked) void __stdcall __E__1006__()
{
	PROXY(___XXX___1007)
		__asm
	{
		jmp p[1006 * 4];
	}
}

// ___XXX___1008
extern "C" __declspec(naked) void __stdcall __E__1007__()
{
	PROXY(___XXX___1008)
		__asm
	{
		jmp p[1007 * 4];
	}
}

// ___XXX___1009
extern "C" __declspec(naked) void __stdcall __E__1008__()
{
	PROXY(___XXX___1009)
		__asm
	{
		jmp p[1008 * 4];
	}
}

// ___XXX___1010
extern "C" __declspec(naked) void __stdcall __E__1009__()
{
	PROXY(___XXX___1010)
		__asm
	{
		jmp p[1009 * 4];
	}
}

// ___XXX___1011
extern "C" __declspec(naked) void __stdcall __E__1010__()
{
	PROXY(___XXX___1011)
		__asm
	{
		jmp p[1010 * 4];
	}
}

// ___XXX___1012
extern "C" __declspec(naked) void __stdcall __E__1011__()
{
	PROXY(___XXX___1012)
		__asm
	{
		jmp p[1011 * 4];
	}
}

// ___XXX___1013
extern "C" __declspec(naked) void __stdcall __E__1012__()
{
	PROXY(___XXX___1013)
		__asm
	{
		jmp p[1012 * 4];
	}
}

// ___XXX___1014
extern "C" __declspec(naked) void __stdcall __E__1013__()
{
	PROXY(___XXX___1014)
		__asm
	{
		jmp p[1013 * 4];
	}
}

// ___XXX___1015
extern "C" __declspec(naked) void __stdcall __E__1014__()
{
	PROXY(___XXX___1015)
		__asm
	{
		jmp p[1014 * 4];
	}
}

// ___XXX___1016
extern "C" __declspec(naked) void __stdcall __E__1015__()
{
	PROXY(___XXX___1016)
		__asm
	{
		jmp p[1015 * 4];
	}
}

// ___XXX___1017
extern "C" __declspec(naked) void __stdcall __E__1016__()
{
	PROXY(___XXX___1017)
		__asm
	{
		jmp p[1016 * 4];
	}
}

// ___XXX___1018
extern "C" __declspec(naked) void __stdcall __E__1017__()
{
	PROXY(___XXX___1018)
		__asm
	{
		jmp p[1017 * 4];
	}
}

// ___XXX___1019
extern "C" __declspec(naked) void __stdcall __E__1018__()
{
	PROXY(___XXX___1019)
		__asm
	{
		jmp p[1018 * 4];
	}
}

// ___XXX___1020
extern "C" __declspec(naked) void __stdcall __E__1019__()
{
	PROXY(___XXX___1020)
		__asm
	{
		jmp p[1019 * 4];
	}
}

// ___XXX___1021
extern "C" __declspec(naked) void __stdcall __E__1020__()
{
	PROXY(___XXX___1021)
		__asm
	{
		jmp p[1020 * 4];
	}
}

// ___XXX___1022
extern "C" __declspec(naked) void __stdcall __E__1021__()
{
	PROXY(___XXX___1022)
		__asm
	{
		jmp p[1021 * 4];
	}
}

// ___XXX___1023
extern "C" __declspec(naked) void __stdcall __E__1022__()
{
	PROXY(___XXX___1023)
		__asm
	{
		jmp p[1022 * 4];
	}
}

// ___XXX___1024
extern "C" __declspec(naked) void __stdcall __E__1023__()
{
	PROXY(___XXX___1024)
		__asm
	{
		jmp p[1023 * 4];
	}
}

// ___XXX___1025
extern "C" __declspec(naked) void __stdcall __E__1024__()
{
	PROXY(___XXX___1025)
		__asm
	{
		jmp p[1024 * 4];
	}
}

