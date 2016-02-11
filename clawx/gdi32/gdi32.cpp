#define DLL_NAME "GDI32"

#include "../proxy/proxy.h"
#include <windows.h>

#pragma pack(1)

HINSTANCE hLThis = 0;
HINSTANCE hL = 0;
FARPROC p[879] = { 0 };

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		//log(DLL_NAME, "DLL_PROCESS_ATTACH");

		hLThis = hInst;
		hL = LoadLibrary("C:\\Windows\\System32\\gdi32.dll");

		if (!hL) return false;

		p[0] = GetProcAddress(hL, "AbortDoc");
		p[1] = GetProcAddress(hL, "AbortPath");
		p[2] = GetProcAddress(hL, "AddFontMemResourceEx");
		p[3] = GetProcAddress(hL, "AddFontResourceA");
		p[4] = GetProcAddress(hL, "AddFontResourceExA");
		p[5] = GetProcAddress(hL, "AddFontResourceExW");
		p[6] = GetProcAddress(hL, "AddFontResourceTracking");
		p[7] = GetProcAddress(hL, "AddFontResourceW");
		p[8] = GetProcAddress(hL, "AngleArc");
		p[9] = GetProcAddress(hL, "AnimatePalette");
		p[10] = GetProcAddress(hL, "AnyLinkedFonts");
		p[11] = GetProcAddress(hL, "Arc");
		p[12] = GetProcAddress(hL, "ArcTo");
		p[13] = GetProcAddress(hL, "BRUSHOBJ_hGetColorTransform");
		p[14] = GetProcAddress(hL, "BRUSHOBJ_pvAllocRbrush");
		p[15] = GetProcAddress(hL, "BRUSHOBJ_pvGetRbrush");
		p[16] = GetProcAddress(hL, "BRUSHOBJ_ulGetBrushColor");
		p[17] = GetProcAddress(hL, "BeginGdiRendering");
		p[18] = GetProcAddress(hL, "BeginPath");
		p[19] = GetProcAddress(hL, "BitBlt");
		p[20] = GetProcAddress(hL, "CLIPOBJ_bEnum");
		p[21] = GetProcAddress(hL, "CLIPOBJ_cEnumStart");
		p[22] = GetProcAddress(hL, "CLIPOBJ_ppoGetPath");
		p[23] = GetProcAddress(hL, "CancelDC");
		p[24] = GetProcAddress(hL, "CheckColorsInGamut");
		p[25] = GetProcAddress(hL, "ChoosePixelFormat");
		p[26] = GetProcAddress(hL, "Chord");
		p[27] = GetProcAddress(hL, "ClearBitmapAttributes");
		p[28] = GetProcAddress(hL, "ClearBrushAttributes");
		p[29] = GetProcAddress(hL, "CloseEnhMetaFile");
		p[30] = GetProcAddress(hL, "CloseFigure");
		p[31] = GetProcAddress(hL, "CloseMetaFile");
		p[32] = GetProcAddress(hL, "ColorCorrectPalette");
		p[33] = GetProcAddress(hL, "ColorMatchToTarget");
		p[34] = GetProcAddress(hL, "CombineRgn");
		p[35] = GetProcAddress(hL, "CombineTransform");
		p[36] = GetProcAddress(hL, "ConfigureOPMProtectedOutput");
		p[37] = GetProcAddress(hL, "CopyEnhMetaFileA");
		p[38] = GetProcAddress(hL, "CopyEnhMetaFileW");
		p[39] = GetProcAddress(hL, "CopyMetaFileA");
		p[40] = GetProcAddress(hL, "CopyMetaFileW");
		p[41] = GetProcAddress(hL, "CreateBitmap");
		p[42] = GetProcAddress(hL, "CreateBitmapFromDxSurface");
		p[43] = GetProcAddress(hL, "CreateBitmapFromDxSurface2");
		p[44] = GetProcAddress(hL, "CreateBitmapIndirect");
		p[45] = GetProcAddress(hL, "CreateBrushIndirect");
		p[46] = GetProcAddress(hL, "CreateColorSpaceA");
		p[47] = GetProcAddress(hL, "CreateColorSpaceW");
		p[48] = GetProcAddress(hL, "CreateCompatibleBitmap");
		p[49] = GetProcAddress(hL, "CreateCompatibleDC");
		p[50] = GetProcAddress(hL, "CreateDCA");
		p[51] = GetProcAddress(hL, "CreateDCW");
		p[52] = GetProcAddress(hL, "CreateDIBPatternBrush");
		p[53] = GetProcAddress(hL, "CreateDIBPatternBrushPt");
		p[54] = GetProcAddress(hL, "CreateDIBSection");
		p[55] = GetProcAddress(hL, "CreateDIBitmap");
		p[56] = GetProcAddress(hL, "CreateDiscardableBitmap");
		p[57] = GetProcAddress(hL, "CreateEllipticRgn");
		p[58] = GetProcAddress(hL, "CreateEllipticRgnIndirect");
		p[59] = GetProcAddress(hL, "CreateEnhMetaFileA");
		p[60] = GetProcAddress(hL, "CreateEnhMetaFileW");
		p[61] = GetProcAddress(hL, "CreateFontA");
		p[62] = GetProcAddress(hL, "CreateFontIndirectA");
		p[63] = GetProcAddress(hL, "CreateFontIndirectExA");
		p[64] = GetProcAddress(hL, "CreateFontIndirectExW");
		p[65] = GetProcAddress(hL, "CreateFontIndirectW");
		p[66] = GetProcAddress(hL, "CreateFontW");
		p[67] = GetProcAddress(hL, "CreateHalftonePalette");
		p[68] = GetProcAddress(hL, "CreateHatchBrush");
		p[69] = GetProcAddress(hL, "CreateICA");
		p[70] = GetProcAddress(hL, "CreateICW");
		p[71] = GetProcAddress(hL, "CreateMetaFileA");
		p[72] = GetProcAddress(hL, "CreateMetaFileW");
		p[73] = GetProcAddress(hL, "CreateOPMProtectedOutputs");
		p[74] = GetProcAddress(hL, "CreatePalette");
		p[75] = GetProcAddress(hL, "CreatePatternBrush");
		p[76] = GetProcAddress(hL, "CreatePen");
		p[77] = GetProcAddress(hL, "CreatePenIndirect");
		p[78] = GetProcAddress(hL, "CreatePolyPolygonRgn");
		p[79] = GetProcAddress(hL, "CreatePolygonRgn");
		p[80] = GetProcAddress(hL, "CreateRectRgn");
		p[81] = GetProcAddress(hL, "CreateRectRgnIndirect");
		p[82] = GetProcAddress(hL, "CreateRoundRectRgn");
		p[83] = GetProcAddress(hL, "CreateScalableFontResourceA");
		p[84] = GetProcAddress(hL, "CreateScalableFontResourceW");
		p[85] = GetProcAddress(hL, "CreateSessionMappedDIBSection");
		p[86] = GetProcAddress(hL, "CreateSolidBrush");
		p[87] = GetProcAddress(hL, "D3DKMTAbandonSwapChain");
		p[88] = GetProcAddress(hL, "D3DKMTAcquireKeyedMutex");
		p[89] = GetProcAddress(hL, "D3DKMTAcquireKeyedMutex2");
		p[90] = GetProcAddress(hL, "D3DKMTAcquireSwapChain");
		p[91] = GetProcAddress(hL, "D3DKMTAdjustFullscreenGamma");
		p[92] = GetProcAddress(hL, "D3DKMTCacheHybridQueryValue");
		p[93] = GetProcAddress(hL, "D3DKMTChangeVideoMemoryReservation");
		p[94] = GetProcAddress(hL, "D3DKMTCheckExclusiveOwnership");
		p[95] = GetProcAddress(hL, "D3DKMTCheckMonitorPowerState");
		p[96] = GetProcAddress(hL, "D3DKMTCheckMultiPlaneOverlaySupport");
		p[97] = GetProcAddress(hL, "D3DKMTCheckMultiPlaneOverlaySupport2");
		p[98] = GetProcAddress(hL, "D3DKMTCheckOcclusion");
		p[99] = GetProcAddress(hL, "D3DKMTCheckSharedResourceAccess");
		p[100] = GetProcAddress(hL, "D3DKMTCheckVidPnExclusiveOwnership");
		p[101] = GetProcAddress(hL, "D3DKMTCloseAdapter");
		p[102] = GetProcAddress(hL, "D3DKMTConfigureSharedResource");
		p[103] = GetProcAddress(hL, "D3DKMTCreateAllocation");
		p[104] = GetProcAddress(hL, "D3DKMTCreateAllocation2");
		p[105] = GetProcAddress(hL, "D3DKMTCreateContext");
		p[106] = GetProcAddress(hL, "D3DKMTCreateContextVirtual");
		p[107] = GetProcAddress(hL, "D3DKMTCreateDCFromMemory");
		p[108] = GetProcAddress(hL, "D3DKMTCreateDevice");
		p[109] = GetProcAddress(hL, "D3DKMTCreateKeyedMutex");
		p[110] = GetProcAddress(hL, "D3DKMTCreateKeyedMutex2");
		p[111] = GetProcAddress(hL, "D3DKMTCreateOutputDupl");
		p[112] = GetProcAddress(hL, "D3DKMTCreateOverlay");
		p[113] = GetProcAddress(hL, "D3DKMTCreatePagingQueue");
		p[114] = GetProcAddress(hL, "D3DKMTCreateSwapChain");
		p[115] = GetProcAddress(hL, "D3DKMTCreateSynchronizationObject");
		p[116] = GetProcAddress(hL, "D3DKMTCreateSynchronizationObject2");
		p[117] = GetProcAddress(hL, "D3DKMTDestroyAllocation");
		p[118] = GetProcAddress(hL, "D3DKMTDestroyAllocation2");
		p[119] = GetProcAddress(hL, "D3DKMTDestroyContext");
		p[120] = GetProcAddress(hL, "D3DKMTDestroyDCFromMemory");
		p[121] = GetProcAddress(hL, "D3DKMTDestroyDevice");
		p[122] = GetProcAddress(hL, "D3DKMTDestroyKeyedMutex");
		p[123] = GetProcAddress(hL, "D3DKMTDestroyOutputDupl");
		p[124] = GetProcAddress(hL, "D3DKMTDestroyOverlay");
		p[125] = GetProcAddress(hL, "D3DKMTDestroyPagingQueue");
		p[126] = GetProcAddress(hL, "D3DKMTDestroySynchronizationObject");
		p[127] = GetProcAddress(hL, "D3DKMTEnumAdapters");
		p[128] = GetProcAddress(hL, "D3DKMTEnumAdapters2");
		p[129] = GetProcAddress(hL, "D3DKMTEscape");
		p[130] = GetProcAddress(hL, "D3DKMTEvict");
		p[131] = GetProcAddress(hL, "D3DKMTFlipOverlay");
		p[132] = GetProcAddress(hL, "D3DKMTFlushHeapTransitions");
		p[133] = GetProcAddress(hL, "D3DKMTFreeGpuVirtualAddress");
		p[134] = GetProcAddress(hL, "D3DKMTGetCachedHybridQueryValue");
		p[135] = GetProcAddress(hL, "D3DKMTGetContextInProcessSchedulingPriority");
		p[136] = GetProcAddress(hL, "D3DKMTGetContextSchedulingPriority");
		p[137] = GetProcAddress(hL, "D3DKMTGetDWMVerticalBlankEvent");
		p[138] = GetProcAddress(hL, "D3DKMTGetDeviceState");
		p[139] = GetProcAddress(hL, "D3DKMTGetDisplayModeList");
		p[140] = GetProcAddress(hL, "D3DKMTGetMultisampleMethodList");
		p[141] = GetProcAddress(hL, "D3DKMTGetOverlayState");
		p[142] = GetProcAddress(hL, "D3DKMTGetPresentHistory");
		p[143] = GetProcAddress(hL, "D3DKMTGetPresentQueueEvent");
		p[144] = GetProcAddress(hL, "D3DKMTGetProcessSchedulingPriorityClass");
		p[145] = GetProcAddress(hL, "D3DKMTGetResourcePresentPrivateDriverData");
		p[146] = GetProcAddress(hL, "D3DKMTGetRuntimeData");
		p[147] = GetProcAddress(hL, "D3DKMTGetScanLine");
		p[148] = GetProcAddress(hL, "D3DKMTGetSetSwapChainMetadata");
		p[149] = GetProcAddress(hL, "D3DKMTGetSharedPrimaryHandle");
		p[150] = GetProcAddress(hL, "D3DKMTGetSharedResourceAdapterLuid");
		p[151] = GetProcAddress(hL, "D3DKMTInvalidateActiveVidPn");
		p[152] = GetProcAddress(hL, "D3DKMTInvalidateCache");
		p[153] = GetProcAddress(hL, "D3DKMTLock");
		p[154] = GetProcAddress(hL, "D3DKMTLock2");
		p[155] = GetProcAddress(hL, "D3DKMTMakeResident");
		p[156] = GetProcAddress(hL, "D3DKMTMapGpuVirtualAddress");
		p[157] = GetProcAddress(hL, "D3DKMTMarkDeviceAsError");
		p[158] = GetProcAddress(hL, "D3DKMTNetDispGetNextChunkInfo");
		p[159] = GetProcAddress(hL, "D3DKMTNetDispQueryMiracastDisplayDeviceStatus");
		p[160] = GetProcAddress(hL, "D3DKMTNetDispQueryMiracastDisplayDeviceSupport");
		p[161] = GetProcAddress(hL, "D3DKMTNetDispStartMiracastDisplayDevice");
		p[162] = GetProcAddress(hL, "D3DKMTNetDispStartMiracastDisplayDevice2");
		p[163] = GetProcAddress(hL, "D3DKMTNetDispStartMiracastDisplayDeviceEx");
		p[164] = GetProcAddress(hL, "D3DKMTNetDispStopMiracastDisplayDevice");
		p[165] = GetProcAddress(hL, "D3DKMTNetDispStopSessions");
		p[166] = GetProcAddress(hL, "D3DKMTOfferAllocations");
		p[167] = GetProcAddress(hL, "D3DKMTOpenAdapterFromDeviceName");
		p[168] = GetProcAddress(hL, "D3DKMTOpenAdapterFromGdiDisplayName");
		p[169] = GetProcAddress(hL, "D3DKMTOpenAdapterFromHdc");
		p[170] = GetProcAddress(hL, "D3DKMTOpenAdapterFromLuid");
		p[171] = GetProcAddress(hL, "D3DKMTOpenKeyedMutex");
		p[172] = GetProcAddress(hL, "D3DKMTOpenKeyedMutex2");
		p[173] = GetProcAddress(hL, "D3DKMTOpenNtHandleFromName");
		p[174] = GetProcAddress(hL, "D3DKMTOpenResource");
		p[175] = GetProcAddress(hL, "D3DKMTOpenResource2");
		p[176] = GetProcAddress(hL, "D3DKMTOpenResourceFromNtHandle");
		p[177] = GetProcAddress(hL, "D3DKMTOpenSwapChain");
		p[178] = GetProcAddress(hL, "D3DKMTOpenSyncObjectFromNtHandle");
		p[179] = GetProcAddress(hL, "D3DKMTOpenSyncObjectFromNtHandle2");
		p[180] = GetProcAddress(hL, "D3DKMTOpenSyncObjectNtHandleFromName");
		p[181] = GetProcAddress(hL, "D3DKMTOpenSynchronizationObject");
		p[182] = GetProcAddress(hL, "D3DKMTOutputDuplGetFrameInfo");
		p[183] = GetProcAddress(hL, "D3DKMTOutputDuplGetMetaData");
		p[184] = GetProcAddress(hL, "D3DKMTOutputDuplGetPointerShapeData");
		p[185] = GetProcAddress(hL, "D3DKMTOutputDuplPresent");
		p[186] = GetProcAddress(hL, "D3DKMTOutputDuplReleaseFrame");
		p[187] = GetProcAddress(hL, "D3DKMTPinDirectFlipResources");
		p[188] = GetProcAddress(hL, "D3DKMTPollDisplayChildren");
		p[189] = GetProcAddress(hL, "D3DKMTPresent");
		p[190] = GetProcAddress(hL, "D3DKMTPresentMultiPlaneOverlay");
		p[191] = GetProcAddress(hL, "D3DKMTPresentMultiPlaneOverlay2");
		p[192] = GetProcAddress(hL, "D3DKMTQueryAdapterInfo");
		p[193] = GetProcAddress(hL, "D3DKMTQueryAllocationResidency");
		p[194] = GetProcAddress(hL, "D3DKMTQueryClockCalibration");
		p[195] = GetProcAddress(hL, "D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName");
		p[196] = GetProcAddress(hL, "D3DKMTQueryResourceInfo");
		p[197] = GetProcAddress(hL, "D3DKMTQueryResourceInfoFromNtHandle");
		p[198] = GetProcAddress(hL, "D3DKMTQueryStatistics");
		p[199] = GetProcAddress(hL, "D3DKMTQueryVidPnExclusiveOwnership");
		p[200] = GetProcAddress(hL, "D3DKMTQueryVideoMemoryInfo");
		p[201] = GetProcAddress(hL, "D3DKMTReclaimAllocations");
		p[202] = GetProcAddress(hL, "D3DKMTReclaimAllocations2");
		p[203] = GetProcAddress(hL, "D3DKMTRegisterTrimNotification");
		p[204] = GetProcAddress(hL, "D3DKMTReleaseKeyedMutex");
		p[205] = GetProcAddress(hL, "D3DKMTReleaseKeyedMutex2");
		p[206] = GetProcAddress(hL, "D3DKMTReleaseProcessVidPnSourceOwners");
		p[207] = GetProcAddress(hL, "D3DKMTReleaseSwapChain");
		p[208] = GetProcAddress(hL, "D3DKMTRender");
		p[209] = GetProcAddress(hL, "D3DKMTReserveGpuVirtualAddress");
		p[210] = GetProcAddress(hL, "D3DKMTSetAllocationPriority");
		p[211] = GetProcAddress(hL, "D3DKMTSetContextInProcessSchedulingPriority");
		p[212] = GetProcAddress(hL, "D3DKMTSetContextSchedulingPriority");
		p[213] = GetProcAddress(hL, "D3DKMTSetDisplayMode");
		p[214] = GetProcAddress(hL, "D3DKMTSetDisplayPrivateDriverFormat");
		p[215] = GetProcAddress(hL, "D3DKMTSetDodIndirectSwapchain");
		p[216] = GetProcAddress(hL, "D3DKMTSetGammaRamp");
		p[217] = GetProcAddress(hL, "D3DKMTSetHwProtectionTeardownRecovery");
		p[218] = GetProcAddress(hL, "D3DKMTSetProcessSchedulingPriorityClass");
		p[219] = GetProcAddress(hL, "D3DKMTSetQueuedLimit");
		p[220] = GetProcAddress(hL, "D3DKMTSetStablePowerState");
		p[221] = GetProcAddress(hL, "D3DKMTSetStereoEnabled");
		p[222] = GetProcAddress(hL, "D3DKMTSetSyncRefreshCountWaitTarget");
		p[223] = GetProcAddress(hL, "D3DKMTSetVidPnSourceHwProtection");
		p[224] = GetProcAddress(hL, "D3DKMTSetVidPnSourceOwner");
		p[225] = GetProcAddress(hL, "D3DKMTSetVidPnSourceOwner1");
		p[226] = GetProcAddress(hL, "D3DKMTShareObjects");
		p[227] = GetProcAddress(hL, "D3DKMTSharedPrimaryLockNotification");
		p[228] = GetProcAddress(hL, "D3DKMTSharedPrimaryUnLockNotification");
		p[229] = GetProcAddress(hL, "D3DKMTSignalSynchronizationObject");
		p[230] = GetProcAddress(hL, "D3DKMTSignalSynchronizationObject2");
		p[231] = GetProcAddress(hL, "D3DKMTSignalSynchronizationObjectFromCpu");
		p[232] = GetProcAddress(hL, "D3DKMTSignalSynchronizationObjectFromGpu");
		p[233] = GetProcAddress(hL, "D3DKMTSignalSynchronizationObjectFromGpu2");
		p[234] = GetProcAddress(hL, "D3DKMTSubmitCommand");
		p[235] = GetProcAddress(hL, "D3DKMTUnlock");
		p[236] = GetProcAddress(hL, "D3DKMTUnlock2");
		p[237] = GetProcAddress(hL, "D3DKMTUnpinDirectFlipResources");
		p[238] = GetProcAddress(hL, "D3DKMTUnregisterTrimNotification");
		p[239] = GetProcAddress(hL, "D3DKMTUpdateGpuVirtualAddress");
		p[240] = GetProcAddress(hL, "D3DKMTUpdateOverlay");
		p[241] = GetProcAddress(hL, "D3DKMTWaitForIdle");
		p[242] = GetProcAddress(hL, "D3DKMTWaitForSynchronizationObject");
		p[243] = GetProcAddress(hL, "D3DKMTWaitForSynchronizationObject2");
		p[244] = GetProcAddress(hL, "D3DKMTWaitForSynchronizationObjectFromCpu");
		p[245] = GetProcAddress(hL, "D3DKMTWaitForSynchronizationObjectFromGpu");
		p[246] = GetProcAddress(hL, "D3DKMTWaitForVerticalBlankEvent");
		p[247] = GetProcAddress(hL, "D3DKMTWaitForVerticalBlankEvent2");
		p[248] = GetProcAddress(hL, "DDCCIGetCapabilitiesString");
		p[249] = GetProcAddress(hL, "DDCCIGetCapabilitiesStringLength");
		p[250] = GetProcAddress(hL, "DDCCIGetTimingReport");
		p[251] = GetProcAddress(hL, "DDCCIGetVCPFeature");
		p[252] = GetProcAddress(hL, "DDCCISaveCurrentSettings");
		p[253] = GetProcAddress(hL, "DDCCISetVCPFeature");
		p[254] = GetProcAddress(hL, "DPtoLP");
		p[255] = GetProcAddress(hL, "DdCreateFullscreenSprite");
		p[256] = GetProcAddress(hL, "DdDestroyFullscreenSprite");
		p[257] = GetProcAddress(hL, "DdEntry0");
		p[258] = GetProcAddress(hL, "DdEntry1");
		p[259] = GetProcAddress(hL, "DdEntry10");
		p[260] = GetProcAddress(hL, "DdEntry11");
		p[261] = GetProcAddress(hL, "DdEntry12");
		p[262] = GetProcAddress(hL, "DdEntry13");
		p[263] = GetProcAddress(hL, "DdEntry14");
		p[264] = GetProcAddress(hL, "DdEntry15");
		p[265] = GetProcAddress(hL, "DdEntry16");
		p[266] = GetProcAddress(hL, "DdEntry17");
		p[267] = GetProcAddress(hL, "DdEntry18");
		p[268] = GetProcAddress(hL, "DdEntry19");
		p[269] = GetProcAddress(hL, "DdEntry2");
		p[270] = GetProcAddress(hL, "DdEntry20");
		p[271] = GetProcAddress(hL, "DdEntry21");
		p[272] = GetProcAddress(hL, "DdEntry22");
		p[273] = GetProcAddress(hL, "DdEntry23");
		p[274] = GetProcAddress(hL, "DdEntry24");
		p[275] = GetProcAddress(hL, "DdEntry25");
		p[276] = GetProcAddress(hL, "DdEntry26");
		p[277] = GetProcAddress(hL, "DdEntry27");
		p[278] = GetProcAddress(hL, "DdEntry28");
		p[279] = GetProcAddress(hL, "DdEntry29");
		p[280] = GetProcAddress(hL, "DdEntry3");
		p[281] = GetProcAddress(hL, "DdEntry30");
		p[282] = GetProcAddress(hL, "DdEntry31");
		p[283] = GetProcAddress(hL, "DdEntry32");
		p[284] = GetProcAddress(hL, "DdEntry33");
		p[285] = GetProcAddress(hL, "DdEntry34");
		p[286] = GetProcAddress(hL, "DdEntry35");
		p[287] = GetProcAddress(hL, "DdEntry36");
		p[288] = GetProcAddress(hL, "DdEntry37");
		p[289] = GetProcAddress(hL, "DdEntry38");
		p[290] = GetProcAddress(hL, "DdEntry39");
		p[291] = GetProcAddress(hL, "DdEntry4");
		p[292] = GetProcAddress(hL, "DdEntry40");
		p[293] = GetProcAddress(hL, "DdEntry41");
		p[294] = GetProcAddress(hL, "DdEntry42");
		p[295] = GetProcAddress(hL, "DdEntry43");
		p[296] = GetProcAddress(hL, "DdEntry44");
		p[297] = GetProcAddress(hL, "DdEntry45");
		p[298] = GetProcAddress(hL, "DdEntry46");
		p[299] = GetProcAddress(hL, "DdEntry47");
		p[300] = GetProcAddress(hL, "DdEntry48");
		p[301] = GetProcAddress(hL, "DdEntry49");
		p[302] = GetProcAddress(hL, "DdEntry5");
		p[303] = GetProcAddress(hL, "DdEntry50");
		p[304] = GetProcAddress(hL, "DdEntry51");
		p[305] = GetProcAddress(hL, "DdEntry52");
		p[306] = GetProcAddress(hL, "DdEntry53");
		p[307] = GetProcAddress(hL, "DdEntry54");
		p[308] = GetProcAddress(hL, "DdEntry55");
		p[309] = GetProcAddress(hL, "DdEntry56");
		p[310] = GetProcAddress(hL, "DdEntry6");
		p[311] = GetProcAddress(hL, "DdEntry7");
		p[312] = GetProcAddress(hL, "DdEntry8");
		p[313] = GetProcAddress(hL, "DdEntry9");
		p[314] = GetProcAddress(hL, "DdNotifyFullscreenSpriteUpdate");
		p[315] = GetProcAddress(hL, "DdQueryVisRgnUniqueness");
		p[316] = GetProcAddress(hL, "DeleteColorSpace");
		p[317] = GetProcAddress(hL, "DeleteDC");
		p[318] = GetProcAddress(hL, "DeleteEnhMetaFile");
		p[319] = GetProcAddress(hL, "DeleteMetaFile");
		p[320] = GetProcAddress(hL, "DeleteObject");
		p[321] = GetProcAddress(hL, "DescribePixelFormat");
		p[322] = GetProcAddress(hL, "DestroyOPMProtectedOutput");
		p[323] = GetProcAddress(hL, "DestroyPhysicalMonitorInternal");
		p[324] = GetProcAddress(hL, "DeviceCapabilitiesExA");
		p[325] = GetProcAddress(hL, "DeviceCapabilitiesExW");
		p[326] = GetProcAddress(hL, "DrawEscape");
		p[327] = GetProcAddress(hL, "Ellipse");
		p[328] = GetProcAddress(hL, "EnableEUDC");
		p[329] = GetProcAddress(hL, "EndDoc");
		p[330] = GetProcAddress(hL, "EndFormPage");
		p[331] = GetProcAddress(hL, "EndGdiRendering");
		p[332] = GetProcAddress(hL, "EndPage");
		p[333] = GetProcAddress(hL, "EndPath");
		p[334] = GetProcAddress(hL, "EngAcquireSemaphore");
		p[335] = GetProcAddress(hL, "EngAlphaBlend");
		p[336] = GetProcAddress(hL, "EngAssociateSurface");
		p[337] = GetProcAddress(hL, "EngBitBlt");
		p[338] = GetProcAddress(hL, "EngCheckAbort");
		p[339] = GetProcAddress(hL, "EngComputeGlyphSet");
		p[340] = GetProcAddress(hL, "EngCopyBits");
		p[341] = GetProcAddress(hL, "EngCreateBitmap");
		p[342] = GetProcAddress(hL, "EngCreateClip");
		p[343] = GetProcAddress(hL, "EngCreateDeviceBitmap");
		p[344] = GetProcAddress(hL, "EngCreateDeviceSurface");
		p[345] = GetProcAddress(hL, "EngCreatePalette");
		p[346] = GetProcAddress(hL, "EngCreateSemaphore");
		p[347] = GetProcAddress(hL, "EngDeleteClip");
		p[348] = GetProcAddress(hL, "EngDeletePalette");
		p[349] = GetProcAddress(hL, "EngDeletePath");
		p[350] = GetProcAddress(hL, "EngDeleteSemaphore");
		p[351] = GetProcAddress(hL, "EngDeleteSurface");
		p[352] = GetProcAddress(hL, "EngEraseSurface");
		p[353] = GetProcAddress(hL, "EngFillPath");
		p[354] = GetProcAddress(hL, "EngFindResource");
		p[355] = GetProcAddress(hL, "EngFreeModule");
		p[356] = GetProcAddress(hL, "EngGetCurrentCodePage");
		p[357] = GetProcAddress(hL, "EngGetDriverName");
		p[358] = GetProcAddress(hL, "EngGetPrinterDataFileName");
		p[359] = GetProcAddress(hL, "EngGradientFill");
		p[360] = GetProcAddress(hL, "EngLineTo");
		p[361] = GetProcAddress(hL, "EngLoadModule");
		p[362] = GetProcAddress(hL, "EngLockSurface");
		p[363] = GetProcAddress(hL, "EngMarkBandingSurface");
		p[364] = GetProcAddress(hL, "EngMultiByteToUnicodeN");
		p[365] = GetProcAddress(hL, "EngMultiByteToWideChar");
		p[366] = GetProcAddress(hL, "EngPaint");
		p[367] = GetProcAddress(hL, "EngPlgBlt");
		p[368] = GetProcAddress(hL, "EngQueryEMFInfo");
		p[369] = GetProcAddress(hL, "EngQueryLocalTime");
		p[370] = GetProcAddress(hL, "EngReleaseSemaphore");
		p[371] = GetProcAddress(hL, "EngStretchBlt");
		p[372] = GetProcAddress(hL, "EngStretchBltROP");
		p[373] = GetProcAddress(hL, "EngStrokeAndFillPath");
		p[374] = GetProcAddress(hL, "EngStrokePath");
		p[375] = GetProcAddress(hL, "EngTextOut");
		p[376] = GetProcAddress(hL, "EngTransparentBlt");
		p[377] = GetProcAddress(hL, "EngUnicodeToMultiByteN");
		p[378] = GetProcAddress(hL, "EngUnlockSurface");
		p[379] = GetProcAddress(hL, "EngWideCharToMultiByte");
		p[380] = GetProcAddress(hL, "EnumEnhMetaFile");
		p[381] = GetProcAddress(hL, "EnumFontFamiliesA");
		p[382] = GetProcAddress(hL, "EnumFontFamiliesExA");
		p[383] = GetProcAddress(hL, "EnumFontFamiliesExW");
		p[384] = GetProcAddress(hL, "EnumFontFamiliesW");
		p[385] = GetProcAddress(hL, "EnumFontsA");
		p[386] = GetProcAddress(hL, "EnumFontsW");
		p[387] = GetProcAddress(hL, "EnumICMProfilesA");
		p[388] = GetProcAddress(hL, "EnumICMProfilesW");
		p[389] = GetProcAddress(hL, "EnumMetaFile");
		p[390] = GetProcAddress(hL, "EnumObjects");
		p[391] = GetProcAddress(hL, "EqualRgn");
		p[392] = GetProcAddress(hL, "Escape");
		p[393] = GetProcAddress(hL, "EudcLoadLinkW");
		p[394] = GetProcAddress(hL, "EudcUnloadLinkW");
		p[395] = GetProcAddress(hL, "ExcludeClipRect");
		p[396] = GetProcAddress(hL, "ExtCreatePen");
		p[397] = GetProcAddress(hL, "ExtCreateRegion");
		p[398] = GetProcAddress(hL, "ExtEscape");
		p[399] = GetProcAddress(hL, "ExtFloodFill");
		p[400] = GetProcAddress(hL, "ExtSelectClipRgn");
		p[401] = GetProcAddress(hL, "ExtTextOutA");
		p[402] = GetProcAddress(hL, "ExtTextOutW");
		p[403] = GetProcAddress(hL, "FONTOBJ_cGetAllGlyphHandles");
		p[404] = GetProcAddress(hL, "FONTOBJ_cGetGlyphs");
		p[405] = GetProcAddress(hL, "FONTOBJ_pQueryGlyphAttrs");
		p[406] = GetProcAddress(hL, "FONTOBJ_pfdg");
		p[407] = GetProcAddress(hL, "FONTOBJ_pifi");
		p[408] = GetProcAddress(hL, "FONTOBJ_pvTrueTypeFontFile");
		p[409] = GetProcAddress(hL, "FONTOBJ_pxoGetXform");
		p[410] = GetProcAddress(hL, "FONTOBJ_vGetInfo");
		p[411] = GetProcAddress(hL, "FillPath");
		p[412] = GetProcAddress(hL, "FillRgn");
		p[413] = GetProcAddress(hL, "FixBrushOrgEx");
		p[414] = GetProcAddress(hL, "FlattenPath");
		p[415] = GetProcAddress(hL, "FloodFill");
		p[416] = GetProcAddress(hL, "FontIsLinked");
		p[417] = GetProcAddress(hL, "FrameRgn");
		p[418] = GetProcAddress(hL, "GdiAddFontResourceW");
		p[419] = GetProcAddress(hL, "GdiAddGlsBounds");
		p[420] = GetProcAddress(hL, "GdiAddGlsRecord");
		p[421] = GetProcAddress(hL, "GdiAlphaBlend");
		p[422] = GetProcAddress(hL, "GdiArtificialDecrementDriver");
		p[423] = GetProcAddress(hL, "GdiCleanCacheDC");
		p[424] = GetProcAddress(hL, "GdiClearStockObjectCache");
		p[425] = GetProcAddress(hL, "GdiComment");
		p[426] = GetProcAddress(hL, "GdiConsoleTextOut");
		p[427] = GetProcAddress(hL, "GdiConvertAndCheckDC");
		p[428] = GetProcAddress(hL, "GdiConvertBitmap");
		p[429] = GetProcAddress(hL, "GdiConvertBitmapV5");
		p[430] = GetProcAddress(hL, "GdiConvertBrush");
		p[431] = GetProcAddress(hL, "GdiConvertDC");
		p[432] = GetProcAddress(hL, "GdiConvertEnhMetaFile");
		p[433] = GetProcAddress(hL, "GdiConvertFont");
		p[434] = GetProcAddress(hL, "GdiConvertMetaFilePict");
		p[435] = GetProcAddress(hL, "GdiConvertPalette");
		p[436] = GetProcAddress(hL, "GdiConvertRegion");
		p[437] = GetProcAddress(hL, "GdiConvertToDevmodeW");
		p[438] = GetProcAddress(hL, "GdiCreateLocalEnhMetaFile");
		p[439] = GetProcAddress(hL, "GdiCreateLocalMetaFilePict");
		p[440] = GetProcAddress(hL, "GdiDeleteLocalDC");
		p[441] = GetProcAddress(hL, "GdiDeleteSpoolFileHandle");
		p[442] = GetProcAddress(hL, "GdiDescribePixelFormat");
		p[443] = GetProcAddress(hL, "GdiDllInitialize");
		p[444] = GetProcAddress(hL, "GdiDrawStream");
		p[445] = GetProcAddress(hL, "GdiEndDocEMF");
		p[446] = GetProcAddress(hL, "GdiEndPageEMF");
		p[447] = GetProcAddress(hL, "GdiEntry1");
		p[448] = GetProcAddress(hL, "GdiEntry10");
		p[449] = GetProcAddress(hL, "GdiEntry11");
		p[450] = GetProcAddress(hL, "GdiEntry12");
		p[451] = GetProcAddress(hL, "GdiEntry13");
		p[452] = GetProcAddress(hL, "GdiEntry14");
		p[453] = GetProcAddress(hL, "GdiEntry15");
		p[454] = GetProcAddress(hL, "GdiEntry16");
		p[455] = GetProcAddress(hL, "GdiEntry2");
		p[456] = GetProcAddress(hL, "GdiEntry3");
		p[457] = GetProcAddress(hL, "GdiEntry4");
		p[458] = GetProcAddress(hL, "GdiEntry5");
		p[459] = GetProcAddress(hL, "GdiEntry6");
		p[460] = GetProcAddress(hL, "GdiEntry7");
		p[461] = GetProcAddress(hL, "GdiEntry8");
		p[462] = GetProcAddress(hL, "GdiEntry9");
		p[463] = GetProcAddress(hL, "GdiFixUpHandle");
		p[464] = GetProcAddress(hL, "GdiFlush");
		p[465] = GetProcAddress(hL, "GdiFullscreenControl");
		p[466] = GetProcAddress(hL, "GdiGetBatchLimit");
		p[467] = GetProcAddress(hL, "GdiGetBitmapBitsSize");
		p[468] = GetProcAddress(hL, "GdiGetCharDimensions");
		p[469] = GetProcAddress(hL, "GdiGetCodePage");
		p[470] = GetProcAddress(hL, "GdiGetDC");
		p[471] = GetProcAddress(hL, "GdiGetDevmodeForPage");
		p[472] = GetProcAddress(hL, "GdiGetLocalBrush");
		p[473] = GetProcAddress(hL, "GdiGetLocalDC");
		p[474] = GetProcAddress(hL, "GdiGetLocalFont");
		p[475] = GetProcAddress(hL, "GdiGetPageCount");
		p[476] = GetProcAddress(hL, "GdiGetPageHandle");
		p[477] = GetProcAddress(hL, "GdiGetSpoolFileHandle");
		p[478] = GetProcAddress(hL, "GdiGetSpoolMessage");
		p[479] = GetProcAddress(hL, "GdiGradientFill");
		p[480] = GetProcAddress(hL, "GdiInitSpool");
		p[481] = GetProcAddress(hL, "GdiInitializeLanguagePack");
		p[482] = GetProcAddress(hL, "GdiIsMetaFileDC");
		p[483] = GetProcAddress(hL, "GdiIsMetaPrintDC");
		p[484] = GetProcAddress(hL, "GdiIsPlayMetafileDC");
		p[485] = GetProcAddress(hL, "GdiIsScreenDC");
		p[486] = GetProcAddress(hL, "GdiIsUMPDSandboxingEnabled");
		p[487] = GetProcAddress(hL, "GdiLoadType1Fonts");
		p[488] = GetProcAddress(hL, "GdiPlayDCScript");
		p[489] = GetProcAddress(hL, "GdiPlayEMF");
		p[490] = GetProcAddress(hL, "GdiPlayJournal");
		p[491] = GetProcAddress(hL, "GdiPlayPageEMF");
		p[492] = GetProcAddress(hL, "GdiPlayPrivatePageEMF");
		p[493] = GetProcAddress(hL, "GdiPlayScript");
		p[494] = GetProcAddress(hL, "GdiPrinterThunk");
		p[495] = GetProcAddress(hL, "GdiProcessSetup");
		p[496] = GetProcAddress(hL, "GdiQueryFonts");
		p[497] = GetProcAddress(hL, "GdiQueryTable");
		p[498] = GetProcAddress(hL, "GdiRealizationInfo");
		p[499] = GetProcAddress(hL, "GdiReleaseDC");
		p[500] = GetProcAddress(hL, "GdiReleaseLocalDC");
		p[501] = GetProcAddress(hL, "GdiResetDCEMF");
		p[502] = GetProcAddress(hL, "GdiSetAttrs");
		p[503] = GetProcAddress(hL, "GdiSetBatchLimit");
		p[504] = GetProcAddress(hL, "GdiSetLastError");
		p[505] = GetProcAddress(hL, "GdiSetPixelFormat");
		p[506] = GetProcAddress(hL, "GdiSetServerAttr");
		p[507] = GetProcAddress(hL, "GdiStartDocEMF");
		p[508] = GetProcAddress(hL, "GdiStartPageEMF");
		p[509] = GetProcAddress(hL, "GdiSupportsFontChangeEvent");
		p[510] = GetProcAddress(hL, "GdiSwapBuffers");
		p[511] = GetProcAddress(hL, "GdiTransparentBlt");
		p[512] = GetProcAddress(hL, "GdiValidateHandle");
		p[513] = GetProcAddress(hL, "GetArcDirection");
		p[514] = GetProcAddress(hL, "GetAspectRatioFilterEx");
		p[515] = GetProcAddress(hL, "GetBitmapAttributes");
		p[516] = GetProcAddress(hL, "GetBitmapBits");
		p[517] = GetProcAddress(hL, "GetBitmapDimensionEx");
		p[518] = GetProcAddress(hL, "GetBkColor");
		p[519] = GetProcAddress(hL, "GetBkMode");
		p[520] = GetProcAddress(hL, "GetBoundsRect");
		p[521] = GetProcAddress(hL, "GetBrushAttributes");
		p[522] = GetProcAddress(hL, "GetBrushOrgEx");
		p[523] = GetProcAddress(hL, "GetCOPPCompatibleOPMInformation");
		p[524] = GetProcAddress(hL, "GetCertificate");
		p[525] = GetProcAddress(hL, "GetCertificateByHandle");
		p[526] = GetProcAddress(hL, "GetCertificateSize");
		p[527] = GetProcAddress(hL, "GetCertificateSizeByHandle");
		p[528] = GetProcAddress(hL, "GetCharABCWidthsA");
		p[529] = GetProcAddress(hL, "GetCharABCWidthsFloatA");
		p[530] = GetProcAddress(hL, "GetCharABCWidthsFloatW");
		p[531] = GetProcAddress(hL, "GetCharABCWidthsI");
		p[532] = GetProcAddress(hL, "GetCharABCWidthsW");
		p[533] = GetProcAddress(hL, "GetCharWidth32A");
		p[534] = GetProcAddress(hL, "GetCharWidth32W");
		p[535] = GetProcAddress(hL, "GetCharWidthA");
		p[536] = GetProcAddress(hL, "GetCharWidthFloatA");
		p[537] = GetProcAddress(hL, "GetCharWidthFloatW");
		p[538] = GetProcAddress(hL, "GetCharWidthI");
		p[539] = GetProcAddress(hL, "GetCharWidthInfo");
		p[540] = GetProcAddress(hL, "GetCharWidthW");
		p[541] = GetProcAddress(hL, "GetCharacterPlacementA");
		p[542] = GetProcAddress(hL, "GetCharacterPlacementW");
		p[543] = GetProcAddress(hL, "GetClipBox");
		p[544] = GetProcAddress(hL, "GetClipRgn");
		p[545] = GetProcAddress(hL, "GetColorAdjustment");
		p[546] = GetProcAddress(hL, "GetColorSpace");
		p[547] = GetProcAddress(hL, "GetCurrentDpiInfo");
		p[548] = GetProcAddress(hL, "GetCurrentObject");
		p[549] = GetProcAddress(hL, "GetCurrentPositionEx");
		p[550] = GetProcAddress(hL, "GetDCBrushColor");
		p[551] = GetProcAddress(hL, "GetDCOrgEx");
		p[552] = GetProcAddress(hL, "GetDCPenColor");
		p[553] = GetProcAddress(hL, "GetDIBColorTable");
		p[554] = GetProcAddress(hL, "GetDIBits");
		p[555] = GetProcAddress(hL, "GetDeviceCaps");
		p[556] = GetProcAddress(hL, "GetDeviceGammaRamp");
		p[557] = GetProcAddress(hL, "GetETM");
		p[558] = GetProcAddress(hL, "GetEUDCTimeStamp");
		p[559] = GetProcAddress(hL, "GetEUDCTimeStampExW");
		p[560] = GetProcAddress(hL, "GetEnhMetaFileA");
		p[561] = GetProcAddress(hL, "GetEnhMetaFileBits");
		p[562] = GetProcAddress(hL, "GetEnhMetaFileDescriptionA");
		p[563] = GetProcAddress(hL, "GetEnhMetaFileDescriptionW");
		p[564] = GetProcAddress(hL, "GetEnhMetaFileHeader");
		p[565] = GetProcAddress(hL, "GetEnhMetaFilePaletteEntries");
		p[566] = GetProcAddress(hL, "GetEnhMetaFilePixelFormat");
		p[567] = GetProcAddress(hL, "GetEnhMetaFileW");
		p[568] = GetProcAddress(hL, "GetFontAssocStatus");
		p[569] = GetProcAddress(hL, "GetFontData");
		p[570] = GetProcAddress(hL, "GetFontFileData");
		p[571] = GetProcAddress(hL, "GetFontFileInfo");
		p[572] = GetProcAddress(hL, "GetFontLanguageInfo");
		p[573] = GetProcAddress(hL, "GetFontRealizationInfo");
		p[574] = GetProcAddress(hL, "GetFontResourceInfoW");
		p[575] = GetProcAddress(hL, "GetFontUnicodeRanges");
		p[576] = GetProcAddress(hL, "GetGlyphIndicesA");
		p[577] = GetProcAddress(hL, "GetGlyphIndicesW");
		p[578] = GetProcAddress(hL, "GetGlyphOutline");
		p[579] = GetProcAddress(hL, "GetGlyphOutlineA");
		p[580] = GetProcAddress(hL, "GetGlyphOutlineW");
		p[581] = GetProcAddress(hL, "GetGlyphOutlineWow");
		p[582] = GetProcAddress(hL, "GetGraphicsMode");
		p[583] = GetProcAddress(hL, "GetHFONT");
		p[584] = GetProcAddress(hL, "GetICMProfileA");
		p[585] = GetProcAddress(hL, "GetICMProfileW");
		p[586] = GetProcAddress(hL, "GetKerningPairs");
		p[587] = GetProcAddress(hL, "GetKerningPairsA");
		p[588] = GetProcAddress(hL, "GetKerningPairsW");
		p[589] = GetProcAddress(hL, "GetLayout");
		p[590] = GetProcAddress(hL, "GetLogColorSpaceA");
		p[591] = GetProcAddress(hL, "GetLogColorSpaceW");
		p[592] = GetProcAddress(hL, "GetMapMode");
		p[593] = GetProcAddress(hL, "GetMetaFileA");
		p[594] = GetProcAddress(hL, "GetMetaFileBitsEx");
		p[595] = GetProcAddress(hL, "GetMetaFileW");
		p[596] = GetProcAddress(hL, "GetMetaRgn");
		p[597] = GetProcAddress(hL, "GetMiterLimit");
		p[598] = GetProcAddress(hL, "GetNearestColor");
		p[599] = GetProcAddress(hL, "GetNearestPaletteIndex");
		p[600] = GetProcAddress(hL, "GetNumberOfPhysicalMonitors");
		p[601] = GetProcAddress(hL, "GetOPMInformation");
		p[602] = GetProcAddress(hL, "GetOPMRandomNumber");
		p[603] = GetProcAddress(hL, "GetObjectA");
		p[604] = GetProcAddress(hL, "GetObjectType");
		p[605] = GetProcAddress(hL, "GetObjectW");
		p[606] = GetProcAddress(hL, "GetOutlineTextMetricsA");
		p[607] = GetProcAddress(hL, "GetOutlineTextMetricsW");
		p[608] = GetProcAddress(hL, "GetPaletteEntries");
		p[609] = GetProcAddress(hL, "GetPath");
		p[610] = GetProcAddress(hL, "GetPhysicalMonitorDescription");
		p[611] = GetProcAddress(hL, "GetPhysicalMonitors");
		p[612] = GetProcAddress(hL, "GetPixel");
		p[613] = GetProcAddress(hL, "GetPixelFormat");
		p[614] = GetProcAddress(hL, "GetPolyFillMode");
		p[615] = GetProcAddress(hL, "GetROP2");
		p[616] = GetProcAddress(hL, "GetRandomRgn");
		p[617] = GetProcAddress(hL, "GetRasterizerCaps");
		p[618] = GetProcAddress(hL, "GetRegionData");
		p[619] = GetProcAddress(hL, "GetRelAbs");
		p[620] = GetProcAddress(hL, "GetRgnBox");
		p[621] = GetProcAddress(hL, "GetStockObject");
		p[622] = GetProcAddress(hL, "GetStretchBltMode");
		p[623] = GetProcAddress(hL, "GetStringBitmapA");
		p[624] = GetProcAddress(hL, "GetStringBitmapW");
		p[625] = GetProcAddress(hL, "GetSuggestedOPMProtectedOutputArraySize");
		p[626] = GetProcAddress(hL, "GetSystemPaletteEntries");
		p[627] = GetProcAddress(hL, "GetSystemPaletteUse");
		p[628] = GetProcAddress(hL, "GetTextAlign");
		p[629] = GetProcAddress(hL, "GetTextCharacterExtra");
		p[630] = GetProcAddress(hL, "GetTextCharset");
		p[631] = GetProcAddress(hL, "GetTextCharsetInfo");
		p[632] = GetProcAddress(hL, "GetTextColor");
		p[633] = GetProcAddress(hL, "GetTextExtentExPointA");
		p[634] = GetProcAddress(hL, "GetTextExtentExPointI");
		p[635] = GetProcAddress(hL, "GetTextExtentExPointW");
		p[636] = GetProcAddress(hL, "GetTextExtentExPointWPri");
		p[637] = GetProcAddress(hL, "GetTextExtentPoint32A");
		p[638] = GetProcAddress(hL, "GetTextExtentPoint32W");
		p[639] = GetProcAddress(hL, "GetTextExtentPointA");
		p[640] = GetProcAddress(hL, "GetTextExtentPointI");
		p[641] = GetProcAddress(hL, "GetTextExtentPointW");
		p[642] = GetProcAddress(hL, "GetTextFaceA");
		p[643] = GetProcAddress(hL, "GetTextFaceAliasW");
		p[644] = GetProcAddress(hL, "GetTextFaceW");
		p[645] = GetProcAddress(hL, "GetTextMetricsA");
		p[646] = GetProcAddress(hL, "GetTextMetricsW");
		p[647] = GetProcAddress(hL, "GetTransform");
		p[648] = GetProcAddress(hL, "GetViewportExtEx");
		p[649] = GetProcAddress(hL, "GetViewportOrgEx");
		p[650] = GetProcAddress(hL, "GetWinMetaFileBits");
		p[651] = GetProcAddress(hL, "GetWindowExtEx");
		p[652] = GetProcAddress(hL, "GetWindowOrgEx");
		p[653] = GetProcAddress(hL, "GetWorldTransform");
		p[654] = GetProcAddress(hL, "HT_Get8BPPFormatPalette");
		p[655] = GetProcAddress(hL, "HT_Get8BPPMaskPalette");
		p[656] = GetProcAddress(hL, "IntersectClipRect");
		p[657] = GetProcAddress(hL, "InvertRgn");
		p[658] = GetProcAddress(hL, "IsValidEnhMetaRecord");
		p[659] = GetProcAddress(hL, "IsValidEnhMetaRecordOffExt");
		p[660] = GetProcAddress(hL, "LPtoDP");
		p[661] = GetProcAddress(hL, "LineDDA");
		p[662] = GetProcAddress(hL, "LineTo");
		p[663] = GetProcAddress(hL, "LpkDrawTextEx");
		p[664] = GetProcAddress(hL, "LpkEditControl");
		p[665] = GetProcAddress(hL, "LpkExtTextOut");
		p[666] = GetProcAddress(hL, "LpkGetCharacterPlacement");
		p[667] = GetProcAddress(hL, "LpkGetTextExtentExPoint");
		p[668] = GetProcAddress(hL, "LpkInitialize");
		p[669] = GetProcAddress(hL, "LpkPSMTextOut");
		p[670] = GetProcAddress(hL, "LpkPresent");
		p[671] = GetProcAddress(hL, "LpkTabbedTextOut");
		p[672] = GetProcAddress(hL, "LpkUseGDIWidthCache");
		p[673] = GetProcAddress(hL, "MaskBlt");
		p[674] = GetProcAddress(hL, "MirrorRgn");
		p[675] = GetProcAddress(hL, "ModifyWorldTransform");
		p[676] = GetProcAddress(hL, "MoveToEx");
		p[677] = GetProcAddress(hL, "NamedEscape");
		p[678] = GetProcAddress(hL, "OffsetClipRgn");
		p[679] = GetProcAddress(hL, "OffsetRgn");
		p[680] = GetProcAddress(hL, "OffsetViewportOrgEx");
		p[681] = GetProcAddress(hL, "OffsetWindowOrgEx");
		p[682] = GetProcAddress(hL, "PATHOBJ_bEnum");
		p[683] = GetProcAddress(hL, "PATHOBJ_bEnumClipLines");
		p[684] = GetProcAddress(hL, "PATHOBJ_vEnumStart");
		p[685] = GetProcAddress(hL, "PATHOBJ_vEnumStartClipLines");
		p[686] = GetProcAddress(hL, "PATHOBJ_vGetBounds");
		p[687] = GetProcAddress(hL, "PaintRgn");
		p[688] = GetProcAddress(hL, "PatBlt");
		p[689] = GetProcAddress(hL, "PathToRegion");
		p[690] = GetProcAddress(hL, "Pie");
		p[691] = GetProcAddress(hL, "PlayEnhMetaFile");
		p[692] = GetProcAddress(hL, "PlayEnhMetaFileRecord");
		p[693] = GetProcAddress(hL, "PlayMetaFile");
		p[694] = GetProcAddress(hL, "PlayMetaFileRecord");
		p[695] = GetProcAddress(hL, "PlgBlt");
		p[696] = GetProcAddress(hL, "PolyBezier");
		p[697] = GetProcAddress(hL, "PolyBezierTo");
		p[698] = GetProcAddress(hL, "PolyDraw");
		p[699] = GetProcAddress(hL, "PolyPatBlt");
		p[700] = GetProcAddress(hL, "PolyPolygon");
		p[701] = GetProcAddress(hL, "PolyPolyline");
		p[702] = GetProcAddress(hL, "PolyTextOutA");
		p[703] = GetProcAddress(hL, "PolyTextOutW");
		p[704] = GetProcAddress(hL, "Polygon");
		p[705] = GetProcAddress(hL, "Polyline");
		p[706] = GetProcAddress(hL, "PolylineTo");
		p[707] = GetProcAddress(hL, "PtInRegion");
		p[708] = GetProcAddress(hL, "PtVisible");
		p[709] = GetProcAddress(hL, "QueryFontAssocStatus");
		p[710] = GetProcAddress(hL, "RealizePalette");
		p[711] = GetProcAddress(hL, "RectInRegion");
		p[712] = GetProcAddress(hL, "RectVisible");
		p[713] = GetProcAddress(hL, "Rectangle");
		p[714] = GetProcAddress(hL, "RemoveFontMemResourceEx");
		p[715] = GetProcAddress(hL, "RemoveFontResourceA");
		p[716] = GetProcAddress(hL, "RemoveFontResourceExA");
		p[717] = GetProcAddress(hL, "RemoveFontResourceExW");
		p[718] = GetProcAddress(hL, "RemoveFontResourceTracking");
		p[719] = GetProcAddress(hL, "RemoveFontResourceW");
		p[720] = GetProcAddress(hL, "ResetDCA");
		p[721] = GetProcAddress(hL, "ResetDCW");
		p[722] = GetProcAddress(hL, "ResizePalette");
		p[723] = GetProcAddress(hL, "RestoreDC");
		p[724] = GetProcAddress(hL, "RoundRect");
		p[725] = GetProcAddress(hL, "STROBJ_bEnum");
		p[726] = GetProcAddress(hL, "STROBJ_bEnumPositionsOnly");
		p[727] = GetProcAddress(hL, "STROBJ_bGetAdvanceWidths");
		p[728] = GetProcAddress(hL, "STROBJ_dwGetCodePage");
		p[729] = GetProcAddress(hL, "STROBJ_vEnumStart");
		p[730] = GetProcAddress(hL, "SaveDC");
		p[731] = GetProcAddress(hL, "ScaleViewportExtEx");
		p[732] = GetProcAddress(hL, "ScaleWindowExtEx");
		p[733] = GetProcAddress(hL, "ScriptApplyDigitSubstitution");
		p[734] = GetProcAddress(hL, "ScriptApplyLogicalWidth");
		p[735] = GetProcAddress(hL, "ScriptBreak");
		p[736] = GetProcAddress(hL, "ScriptCPtoX");
		p[737] = GetProcAddress(hL, "ScriptCacheGetHeight");
		p[738] = GetProcAddress(hL, "ScriptFreeCache");
		p[739] = GetProcAddress(hL, "ScriptGetCMap");
		p[740] = GetProcAddress(hL, "ScriptGetFontAlternateGlyphs");
		p[741] = GetProcAddress(hL, "ScriptGetFontFeatureTags");
		p[742] = GetProcAddress(hL, "ScriptGetFontLanguageTags");
		p[743] = GetProcAddress(hL, "ScriptGetFontProperties");
		p[744] = GetProcAddress(hL, "ScriptGetFontScriptTags");
		p[745] = GetProcAddress(hL, "ScriptGetGlyphABCWidth");
		p[746] = GetProcAddress(hL, "ScriptGetLogicalWidths");
		p[747] = GetProcAddress(hL, "ScriptGetProperties");
		p[748] = GetProcAddress(hL, "ScriptIsComplex");
		p[749] = GetProcAddress(hL, "ScriptItemize");
		p[750] = GetProcAddress(hL, "ScriptItemizeOpenType");
		p[751] = GetProcAddress(hL, "ScriptJustify");
		p[752] = GetProcAddress(hL, "ScriptLayout");
		p[753] = GetProcAddress(hL, "ScriptPlace");
		p[754] = GetProcAddress(hL, "ScriptPlaceOpenType");
		p[755] = GetProcAddress(hL, "ScriptPositionSingleGlyph");
		p[756] = GetProcAddress(hL, "ScriptRecordDigitSubstitution");
		p[757] = GetProcAddress(hL, "ScriptShape");
		p[758] = GetProcAddress(hL, "ScriptShapeOpenType");
		p[759] = GetProcAddress(hL, "ScriptStringAnalyse");
		p[760] = GetProcAddress(hL, "ScriptStringCPtoX");
		p[761] = GetProcAddress(hL, "ScriptStringFree");
		p[762] = GetProcAddress(hL, "ScriptStringGetLogicalWidths");
		p[763] = GetProcAddress(hL, "ScriptStringGetOrder");
		p[764] = GetProcAddress(hL, "ScriptStringOut");
		p[765] = GetProcAddress(hL, "ScriptStringValidate");
		p[766] = GetProcAddress(hL, "ScriptStringXtoCP");
		p[767] = GetProcAddress(hL, "ScriptString_pLogAttr");
		p[768] = GetProcAddress(hL, "ScriptString_pSize");
		p[769] = GetProcAddress(hL, "ScriptString_pcOutChars");
		p[770] = GetProcAddress(hL, "ScriptSubstituteSingleGlyph");
		p[771] = GetProcAddress(hL, "ScriptTextOut");
		p[772] = GetProcAddress(hL, "ScriptXtoCP");
		p[773] = GetProcAddress(hL, "SelectBrushLocal");
		p[774] = GetProcAddress(hL, "SelectClipPath");
		p[775] = GetProcAddress(hL, "SelectClipRgn");
		p[776] = GetProcAddress(hL, "SelectFontLocal");
		p[777] = GetProcAddress(hL, "SelectObject");
		p[778] = GetProcAddress(hL, "SelectPalette");
		p[779] = GetProcAddress(hL, "SetAbortProc");
		p[780] = GetProcAddress(hL, "SetArcDirection");
		p[781] = GetProcAddress(hL, "SetBitmapAttributes");
		p[782] = GetProcAddress(hL, "SetBitmapBits");
		p[783] = GetProcAddress(hL, "SetBitmapDimensionEx");
		p[784] = GetProcAddress(hL, "SetBkColor");
		p[785] = GetProcAddress(hL, "SetBkMode");
		p[786] = GetProcAddress(hL, "SetBoundsRect");
		p[787] = GetProcAddress(hL, "SetBrushAttributes");
		p[788] = GetProcAddress(hL, "SetBrushOrgEx");
		p[789] = GetProcAddress(hL, "SetColorAdjustment");
		p[790] = GetProcAddress(hL, "SetColorSpace");
		p[791] = GetProcAddress(hL, "SetDCBrushColor");
		p[792] = GetProcAddress(hL, "SetDCPenColor");
		p[793] = GetProcAddress(hL, "SetDIBColorTable");
		p[794] = GetProcAddress(hL, "SetDIBits");
		p[795] = GetProcAddress(hL, "SetDIBitsToDevice");
		p[796] = GetProcAddress(hL, "SetDeviceGammaRamp");
		p[797] = GetProcAddress(hL, "SetEnhMetaFileBits");
		p[798] = GetProcAddress(hL, "SetFontEnumeration");
		p[799] = GetProcAddress(hL, "SetGraphicsMode");
		p[800] = GetProcAddress(hL, "SetICMMode");
		p[801] = GetProcAddress(hL, "SetICMProfileA");
		p[802] = GetProcAddress(hL, "SetICMProfileW");
		p[803] = GetProcAddress(hL, "SetLayout");
		p[804] = GetProcAddress(hL, "SetLayoutWidth");
		p[805] = GetProcAddress(hL, "SetMagicColors");
		p[806] = GetProcAddress(hL, "SetMapMode");
		p[807] = GetProcAddress(hL, "SetMapperFlags");
		p[808] = GetProcAddress(hL, "SetMetaFileBitsEx");
		p[809] = GetProcAddress(hL, "SetMetaRgn");
		p[810] = GetProcAddress(hL, "SetMiterLimit");
		p[811] = GetProcAddress(hL, "SetOPMSigningKeyAndSequenceNumbers");
		p[812] = GetProcAddress(hL, "SetPaletteEntries");
		p[813] = GetProcAddress(hL, "SetPixel");
		p[814] = GetProcAddress(hL, "SetPixelFormat");
		p[815] = GetProcAddress(hL, "SetPixelV");
		p[816] = GetProcAddress(hL, "SetPolyFillMode");
		p[817] = GetProcAddress(hL, "SetROP2");
		p[818] = GetProcAddress(hL, "SetRectRgn");
		p[819] = GetProcAddress(hL, "SetRelAbs");
		p[820] = GetProcAddress(hL, "SetStretchBltMode");
		p[821] = GetProcAddress(hL, "SetSystemPaletteUse");
		p[822] = GetProcAddress(hL, "SetTextAlign");
		p[823] = GetProcAddress(hL, "SetTextCharacterExtra");
		p[824] = GetProcAddress(hL, "SetTextColor");
		p[825] = GetProcAddress(hL, "SetTextJustification");
		p[826] = GetProcAddress(hL, "SetViewportExtEx");
		p[827] = GetProcAddress(hL, "SetViewportOrgEx");
		p[828] = GetProcAddress(hL, "SetVirtualResolution");
		p[829] = GetProcAddress(hL, "SetWinMetaFileBits");
		p[830] = GetProcAddress(hL, "SetWindowExtEx");
		p[831] = GetProcAddress(hL, "SetWindowOrgEx");
		p[832] = GetProcAddress(hL, "SetWorldTransform");
		p[833] = GetProcAddress(hL, "StartDocA");
		p[834] = GetProcAddress(hL, "StartDocW");
		p[835] = GetProcAddress(hL, "StartFormPage");
		p[836] = GetProcAddress(hL, "StartPage");
		p[837] = GetProcAddress(hL, "StretchBlt");
		p[838] = GetProcAddress(hL, "StretchDIBits");
		p[839] = GetProcAddress(hL, "StrokeAndFillPath");
		p[840] = GetProcAddress(hL, "StrokePath");
		p[841] = GetProcAddress(hL, "SwapBuffers");
		p[842] = GetProcAddress(hL, "TextOutA");
		p[843] = GetProcAddress(hL, "TextOutW");
		p[844] = GetProcAddress(hL, "TranslateCharsetInfo");
		p[845] = GetProcAddress(hL, "UnloadNetworkFonts");
		p[846] = GetProcAddress(hL, "UnrealizeObject");
		p[847] = GetProcAddress(hL, "UpdateColors");
		p[848] = GetProcAddress(hL, "UpdateICMRegKeyA");
		p[849] = GetProcAddress(hL, "UpdateICMRegKeyW");
		p[850] = GetProcAddress(hL, "UspAllocCache");
		p[851] = GetProcAddress(hL, "UspAllocTemp");
		p[852] = GetProcAddress(hL, "UspFreeMem");
		p[853] = GetProcAddress(hL, "WidenPath");
		p[854] = GetProcAddress(hL, "XFORMOBJ_bApplyXform");
		p[855] = GetProcAddress(hL, "XFORMOBJ_iGetXform");
		p[856] = GetProcAddress(hL, "XLATEOBJ_cGetPalette");
		p[857] = GetProcAddress(hL, "XLATEOBJ_hGetColorTransform");
		p[858] = GetProcAddress(hL, "XLATEOBJ_iXlate");
		p[859] = GetProcAddress(hL, "XLATEOBJ_piVector");
		p[860] = GetProcAddress(hL, "bInitSystemAndFontsDirectoriesW");
		p[861] = GetProcAddress(hL, "bMakePathNameW");
		p[862] = GetProcAddress(hL, "cGetTTFFromFOT");
		p[863] = GetProcAddress(hL, "ftsWordBreak");
		p[864] = GetProcAddress(hL, "gdiPlaySpoolStream");
		p[865] = GetProcAddress(hL, (LPCSTR)"1000");
		p[866] = GetProcAddress(hL, (LPCSTR)"1001");
		p[867] = GetProcAddress(hL, (LPCSTR)"1002");
		p[868] = GetProcAddress(hL, (LPCSTR)"1003");
		p[869] = GetProcAddress(hL, (LPCSTR)"1004");
		p[870] = GetProcAddress(hL, (LPCSTR)"1005");
		p[871] = GetProcAddress(hL, (LPCSTR)"1006");
		p[872] = GetProcAddress(hL, (LPCSTR)"1007");
		p[873] = GetProcAddress(hL, (LPCSTR)"1008");
		p[874] = GetProcAddress(hL, (LPCSTR)"1009");
		p[875] = GetProcAddress(hL, (LPCSTR)"1010");
		p[876] = GetProcAddress(hL, (LPCSTR)"1013");
		p[877] = GetProcAddress(hL, (LPCSTR)"1014");
		p[878] = GetProcAddress(hL, (LPCSTR)"2000");


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

// AbortDoc
extern "C" __declspec(naked) void __stdcall __E__0__()
{
	PROXY(AbortDoc)
		__asm
	{
		jmp p[0 * 4];
	}
}

// AbortPath
extern "C" __declspec(naked) void __stdcall __E__1__()
{
	PROXY(AbortPath)
		__asm
	{
		jmp p[1 * 4];
	}
}

// AddFontMemResourceEx
extern "C" __declspec(naked) void __stdcall __E__2__()
{
	PROXY(AddFontMemResourceEx)
		__asm
	{
		jmp p[2 * 4];
	}
}

// AddFontResourceA
extern "C" __declspec(naked) void __stdcall __E__3__()
{
	PROXY(AddFontResourceA)
		__asm
	{
		jmp p[3 * 4];
	}
}

// AddFontResourceExA
extern "C" __declspec(naked) void __stdcall __E__4__()
{
	PROXY(AddFontResourceExA)
		__asm
	{
		jmp p[4 * 4];
	}
}

// AddFontResourceExW
extern "C" __declspec(naked) void __stdcall __E__5__()
{
	PROXY(AddFontResourceExW)
		__asm
	{
		jmp p[5 * 4];
	}
}

// AddFontResourceTracking
extern "C" __declspec(naked) void __stdcall __E__6__()
{
	PROXY(AddFontResourceTracking)
		__asm
	{
		jmp p[6 * 4];
	}
}

// AddFontResourceW
extern "C" __declspec(naked) void __stdcall __E__7__()
{
	PROXY(AddFontResourceW)
		__asm
	{
		jmp p[7 * 4];
	}
}

// AngleArc
extern "C" __declspec(naked) void __stdcall __E__8__()
{
	PROXY(AngleArc)
		__asm
	{
		jmp p[8 * 4];
	}
}

// AnimatePalette
extern "C" __declspec(naked) void __stdcall __E__9__()
{
	PROXY(AnimatePalette)
		__asm
	{
		jmp p[9 * 4];
	}
}

// AnyLinkedFonts
extern "C" __declspec(naked) void __stdcall __E__10__()
{
	PROXY(AnyLinkedFonts)
		__asm
	{
		jmp p[10 * 4];
	}
}

// Arc
extern "C" __declspec(naked) void __stdcall __E__11__()
{
	PROXY(Arc)
		__asm
	{
		jmp p[11 * 4];
	}
}

// ArcTo
extern "C" __declspec(naked) void __stdcall __E__12__()
{
	PROXY(ArcTo)
		__asm
	{
		jmp p[12 * 4];
	}
}

// BRUSHOBJ_hGetColorTransform
extern "C" __declspec(naked) void __stdcall __E__13__()
{
	PROXY(BRUSHOBJ_hGetColorTransform)
		__asm
	{
		jmp p[13 * 4];
	}
}

// BRUSHOBJ_pvAllocRbrush
extern "C" __declspec(naked) void __stdcall __E__14__()
{
	PROXY(BRUSHOBJ_pvAllocRbrush)
		__asm
	{
		jmp p[14 * 4];
	}
}

// BRUSHOBJ_pvGetRbrush
extern "C" __declspec(naked) void __stdcall __E__15__()
{
	PROXY(BRUSHOBJ_pvGetRbrush)
		__asm
	{
		jmp p[15 * 4];
	}
}

// BRUSHOBJ_ulGetBrushColor
extern "C" __declspec(naked) void __stdcall __E__16__()
{
	PROXY(BRUSHOBJ_ulGetBrushColor)
		__asm
	{
		jmp p[16 * 4];
	}
}

// BeginGdiRendering
extern "C" __declspec(naked) void __stdcall __E__17__()
{
	PROXY(BeginGdiRendering)
		__asm
	{
		jmp p[17 * 4];
	}
}

// BeginPath
extern "C" __declspec(naked) void __stdcall __E__18__()
{
	PROXY(BeginPath)
		__asm
	{
		jmp p[18 * 4];
	}
}

// BitBlt
extern "C" __declspec(naked) void __stdcall __E__19__()
{
	PROXY(BitBlt)
		__asm
	{
		jmp p[19 * 4];
	}
}

// CLIPOBJ_bEnum
extern "C" __declspec(naked) void __stdcall __E__20__()
{
	PROXY(CLIPOBJ_bEnum)
		__asm
	{
		jmp p[20 * 4];
	}
}

// CLIPOBJ_cEnumStart
extern "C" __declspec(naked) void __stdcall __E__21__()
{
	PROXY(CLIPOBJ_cEnumStart)
		__asm
	{
		jmp p[21 * 4];
	}
}

// CLIPOBJ_ppoGetPath
extern "C" __declspec(naked) void __stdcall __E__22__()
{
	PROXY(CLIPOBJ_ppoGetPath)
		__asm
	{
		jmp p[22 * 4];
	}
}

// CancelDC
extern "C" __declspec(naked) void __stdcall __E__23__()
{
	PROXY(CancelDC)
		__asm
	{
		jmp p[23 * 4];
	}
}

// CheckColorsInGamut
extern "C" __declspec(naked) void __stdcall __E__24__()
{
	PROXY(CheckColorsInGamut)
		__asm
	{
		jmp p[24 * 4];
	}
}

// ChoosePixelFormat
extern "C" __declspec(naked) void __stdcall __E__25__()
{
	PROXY(ChoosePixelFormat)
		__asm
	{
		jmp p[25 * 4];
	}
}

// Chord
extern "C" __declspec(naked) void __stdcall __E__26__()
{
	PROXY(Chord)
		__asm
	{
		jmp p[26 * 4];
	}
}

// ClearBitmapAttributes
extern "C" __declspec(naked) void __stdcall __E__27__()
{
	PROXY(ClearBitmapAttributes)
		__asm
	{
		jmp p[27 * 4];
	}
}

// ClearBrushAttributes
extern "C" __declspec(naked) void __stdcall __E__28__()
{
	PROXY(ClearBrushAttributes)
		__asm
	{
		jmp p[28 * 4];
	}
}

// CloseEnhMetaFile
extern "C" __declspec(naked) void __stdcall __E__29__()
{
	PROXY(CloseEnhMetaFile)
		__asm
	{
		jmp p[29 * 4];
	}
}

// CloseFigure
extern "C" __declspec(naked) void __stdcall __E__30__()
{
	PROXY(CloseFigure)
		__asm
	{
		jmp p[30 * 4];
	}
}

// CloseMetaFile
extern "C" __declspec(naked) void __stdcall __E__31__()
{
	PROXY(CloseMetaFile)
		__asm
	{
		jmp p[31 * 4];
	}
}

// ColorCorrectPalette
extern "C" __declspec(naked) void __stdcall __E__32__()
{
	PROXY(ColorCorrectPalette)
		__asm
	{
		jmp p[32 * 4];
	}
}

// ColorMatchToTarget
extern "C" __declspec(naked) void __stdcall __E__33__()
{
	PROXY(ColorMatchToTarget)
		__asm
	{
		jmp p[33 * 4];
	}
}

// CombineRgn
extern "C" __declspec(naked) void __stdcall __E__34__()
{
	PROXY(CombineRgn)
		__asm
	{
		jmp p[34 * 4];
	}
}

// CombineTransform
extern "C" __declspec(naked) void __stdcall __E__35__()
{
	PROXY(CombineTransform)
		__asm
	{
		jmp p[35 * 4];
	}
}

// ConfigureOPMProtectedOutput
extern "C" __declspec(naked) void __stdcall __E__36__()
{
	PROXY(ConfigureOPMProtectedOutput)
		__asm
	{
		jmp p[36 * 4];
	}
}

// CopyEnhMetaFileA
extern "C" __declspec(naked) void __stdcall __E__37__()
{
	PROXY(CopyEnhMetaFileA)
		__asm
	{
		jmp p[37 * 4];
	}
}

// CopyEnhMetaFileW
extern "C" __declspec(naked) void __stdcall __E__38__()
{
	PROXY(CopyEnhMetaFileW)
		__asm
	{
		jmp p[38 * 4];
	}
}

// CopyMetaFileA
extern "C" __declspec(naked) void __stdcall __E__39__()
{
	PROXY(CopyMetaFileA)
		__asm
	{
		jmp p[39 * 4];
	}
}

// CopyMetaFileW
extern "C" __declspec(naked) void __stdcall __E__40__()
{
	PROXY(CopyMetaFileW)
		__asm
	{
		jmp p[40 * 4];
	}
}

// CreateBitmap
extern "C" __declspec(naked) void __stdcall __E__41__()
{
	PROXY(CreateBitmap)
		__asm
	{
		jmp p[41 * 4];
	}
}

// CreateBitmapFromDxSurface
extern "C" __declspec(naked) void __stdcall __E__42__()
{
	PROXY(CreateBitmapFromDxSurface)
		__asm
	{
		jmp p[42 * 4];
	}
}

// CreateBitmapFromDxSurface2
extern "C" __declspec(naked) void __stdcall __E__43__()
{
	PROXY(CreateBitmapFromDxSurface2)
		__asm
	{
		jmp p[43 * 4];
	}
}

// CreateBitmapIndirect
extern "C" __declspec(naked) void __stdcall __E__44__()
{
	PROXY(CreateBitmapIndirect)
		__asm
	{
		jmp p[44 * 4];
	}
}

// CreateBrushIndirect
extern "C" __declspec(naked) void __stdcall __E__45__()
{
	PROXY(CreateBrushIndirect)
		__asm
	{
		jmp p[45 * 4];
	}
}

// CreateColorSpaceA
extern "C" __declspec(naked) void __stdcall __E__46__()
{
	PROXY(CreateColorSpaceA)
		__asm
	{
		jmp p[46 * 4];
	}
}

// CreateColorSpaceW
extern "C" __declspec(naked) void __stdcall __E__47__()
{
	PROXY(CreateColorSpaceW)
		__asm
	{
		jmp p[47 * 4];
	}
}

// CreateCompatibleBitmap
extern "C" __declspec(naked) void __stdcall __E__48__()
{
	PROXY(CreateCompatibleBitmap)
		__asm
	{
		jmp p[48 * 4];
	}
}

// CreateCompatibleDC
extern "C" __declspec(naked) void __stdcall __E__49__()
{
	PROXY(CreateCompatibleDC)
		__asm
	{
		jmp p[49 * 4];
	}
}

// CreateDCA
extern "C" __declspec(naked) void __stdcall __E__50__()
{
	PROXY(CreateDCA)
		__asm
	{
		jmp p[50 * 4];
	}
}

// CreateDCW
extern "C" __declspec(naked) void __stdcall __E__51__()
{
	PROXY(CreateDCW)
		__asm
	{
		jmp p[51 * 4];
	}
}

// CreateDIBPatternBrush
extern "C" __declspec(naked) void __stdcall __E__52__()
{
	PROXY(CreateDIBPatternBrush)
		__asm
	{
		jmp p[52 * 4];
	}
}

// CreateDIBPatternBrushPt
extern "C" __declspec(naked) void __stdcall __E__53__()
{
	PROXY(CreateDIBPatternBrushPt)
		__asm
	{
		jmp p[53 * 4];
	}
}

// CreateDIBSection
extern "C" __declspec(naked) void __stdcall __E__54__()
{
	PROXY(CreateDIBSection)
		__asm
	{
		jmp p[54 * 4];
	}
}

// CreateDIBitmap
extern "C" __declspec(naked) void __stdcall __E__55__()
{
	PROXY(CreateDIBitmap)
		__asm
	{
		jmp p[55 * 4];
	}
}

// CreateDiscardableBitmap
extern "C" __declspec(naked) void __stdcall __E__56__()
{
	PROXY(CreateDiscardableBitmap)
		__asm
	{
		jmp p[56 * 4];
	}
}

// CreateEllipticRgn
extern "C" __declspec(naked) void __stdcall __E__57__()
{
	PROXY(CreateEllipticRgn)
		__asm
	{
		jmp p[57 * 4];
	}
}

// CreateEllipticRgnIndirect
extern "C" __declspec(naked) void __stdcall __E__58__()
{
	PROXY(CreateEllipticRgnIndirect)
		__asm
	{
		jmp p[58 * 4];
	}
}

// CreateEnhMetaFileA
extern "C" __declspec(naked) void __stdcall __E__59__()
{
	PROXY(CreateEnhMetaFileA)
		__asm
	{
		jmp p[59 * 4];
	}
}

// CreateEnhMetaFileW
extern "C" __declspec(naked) void __stdcall __E__60__()
{
	PROXY(CreateEnhMetaFileW)
		__asm
	{
		jmp p[60 * 4];
	}
}

// CreateFontA
extern "C" __declspec(naked) void __stdcall __E__61__()
{
	PROXY(CreateFontA)
		__asm
	{
		jmp p[61 * 4];
	}
}

// CreateFontIndirectA
extern "C" __declspec(naked) void __stdcall __E__62__()
{
	PROXY(CreateFontIndirectA)
		__asm
	{
		jmp p[62 * 4];
	}
}

// CreateFontIndirectExA
extern "C" __declspec(naked) void __stdcall __E__63__()
{
	PROXY(CreateFontIndirectExA)
		__asm
	{
		jmp p[63 * 4];
	}
}

// CreateFontIndirectExW
extern "C" __declspec(naked) void __stdcall __E__64__()
{
	PROXY(CreateFontIndirectExW)
		__asm
	{
		jmp p[64 * 4];
	}
}

// CreateFontIndirectW
extern "C" __declspec(naked) void __stdcall __E__65__()
{
	PROXY(CreateFontIndirectW)
		__asm
	{
		jmp p[65 * 4];
	}
}

// CreateFontW
extern "C" __declspec(naked) void __stdcall __E__66__()
{
	PROXY(CreateFontW)
		__asm
	{
		jmp p[66 * 4];
	}
}

// CreateHalftonePalette
extern "C" __declspec(naked) void __stdcall __E__67__()
{
	PROXY(CreateHalftonePalette)
		__asm
	{
		jmp p[67 * 4];
	}
}

// CreateHatchBrush
extern "C" __declspec(naked) void __stdcall __E__68__()
{
	PROXY(CreateHatchBrush)
		__asm
	{
		jmp p[68 * 4];
	}
}

// CreateICA
extern "C" __declspec(naked) void __stdcall __E__69__()
{
	PROXY(CreateICA)
		__asm
	{
		jmp p[69 * 4];
	}
}

// CreateICW
extern "C" __declspec(naked) void __stdcall __E__70__()
{
	PROXY(CreateICW)
		__asm
	{
		jmp p[70 * 4];
	}
}

// CreateMetaFileA
extern "C" __declspec(naked) void __stdcall __E__71__()
{
	PROXY(CreateMetaFileA)
		__asm
	{
		jmp p[71 * 4];
	}
}

// CreateMetaFileW
extern "C" __declspec(naked) void __stdcall __E__72__()
{
	PROXY(CreateMetaFileW)
		__asm
	{
		jmp p[72 * 4];
	}
}

// CreateOPMProtectedOutputs
extern "C" __declspec(naked) void __stdcall __E__73__()
{
	PROXY(CreateOPMProtectedOutputs)
		__asm
	{
		jmp p[73 * 4];
	}
}

// CreatePalette
extern "C" __declspec(naked) void __stdcall __E__74__()
{
	PROXY(CreatePalette)
		__asm
	{
		jmp p[74 * 4];
	}
}

// CreatePatternBrush
extern "C" __declspec(naked) void __stdcall __E__75__()
{
	PROXY(CreatePatternBrush)
		__asm
	{
		jmp p[75 * 4];
	}
}

// CreatePen
extern "C" __declspec(naked) void __stdcall __E__76__()
{
	PROXY(CreatePen)
		__asm
	{
		jmp p[76 * 4];
	}
}

// CreatePenIndirect
extern "C" __declspec(naked) void __stdcall __E__77__()
{
	PROXY(CreatePenIndirect)
		__asm
	{
		jmp p[77 * 4];
	}
}

// CreatePolyPolygonRgn
extern "C" __declspec(naked) void __stdcall __E__78__()
{
	PROXY(CreatePolyPolygonRgn)
		__asm
	{
		jmp p[78 * 4];
	}
}

// CreatePolygonRgn
extern "C" __declspec(naked) void __stdcall __E__79__()
{
	PROXY(CreatePolygonRgn)
		__asm
	{
		jmp p[79 * 4];
	}
}

// CreateRectRgn
extern "C" __declspec(naked) void __stdcall __E__80__()
{
	PROXY(CreateRectRgn)
		__asm
	{
		jmp p[80 * 4];
	}
}

// CreateRectRgnIndirect
extern "C" __declspec(naked) void __stdcall __E__81__()
{
	PROXY(CreateRectRgnIndirect)
		__asm
	{
		jmp p[81 * 4];
	}
}

// CreateRoundRectRgn
extern "C" __declspec(naked) void __stdcall __E__82__()
{
	PROXY(CreateRoundRectRgn)
		__asm
	{
		jmp p[82 * 4];
	}
}

// CreateScalableFontResourceA
extern "C" __declspec(naked) void __stdcall __E__83__()
{
	PROXY(CreateScalableFontResourceA)
		__asm
	{
		jmp p[83 * 4];
	}
}

// CreateScalableFontResourceW
extern "C" __declspec(naked) void __stdcall __E__84__()
{
	PROXY(CreateScalableFontResourceW)
		__asm
	{
		jmp p[84 * 4];
	}
}

// CreateSessionMappedDIBSection
extern "C" __declspec(naked) void __stdcall __E__85__()
{
	PROXY(CreateSessionMappedDIBSection)
		__asm
	{
		jmp p[85 * 4];
	}
}

// CreateSolidBrush
extern "C" __declspec(naked) void __stdcall __E__86__()
{
	PROXY(CreateSolidBrush)
		__asm
	{
		jmp p[86 * 4];
	}
}

// D3DKMTAbandonSwapChain
extern "C" __declspec(naked) void __stdcall __E__87__()
{
	PROXY(D3DKMTAbandonSwapChain)
		__asm
	{
		jmp p[87 * 4];
	}
}

// D3DKMTAcquireKeyedMutex
extern "C" __declspec(naked) void __stdcall __E__88__()
{
	PROXY(D3DKMTAcquireKeyedMutex)
		__asm
	{
		jmp p[88 * 4];
	}
}

// D3DKMTAcquireKeyedMutex2
extern "C" __declspec(naked) void __stdcall __E__89__()
{
	PROXY(D3DKMTAcquireKeyedMutex2)
		__asm
	{
		jmp p[89 * 4];
	}
}

// D3DKMTAcquireSwapChain
extern "C" __declspec(naked) void __stdcall __E__90__()
{
	PROXY(D3DKMTAcquireSwapChain)
		__asm
	{
		jmp p[90 * 4];
	}
}

// D3DKMTAdjustFullscreenGamma
extern "C" __declspec(naked) void __stdcall __E__91__()
{
	PROXY(D3DKMTAdjustFullscreenGamma)
		__asm
	{
		jmp p[91 * 4];
	}
}

// D3DKMTCacheHybridQueryValue
extern "C" __declspec(naked) void __stdcall __E__92__()
{
	PROXY(D3DKMTCacheHybridQueryValue)
		__asm
	{
		jmp p[92 * 4];
	}
}

// D3DKMTChangeVideoMemoryReservation
extern "C" __declspec(naked) void __stdcall __E__93__()
{
	PROXY(D3DKMTChangeVideoMemoryReservation)
		__asm
	{
		jmp p[93 * 4];
	}
}

// D3DKMTCheckExclusiveOwnership
extern "C" __declspec(naked) void __stdcall __E__94__()
{
	PROXY(D3DKMTCheckExclusiveOwnership)
		__asm
	{
		jmp p[94 * 4];
	}
}

// D3DKMTCheckMonitorPowerState
extern "C" __declspec(naked) void __stdcall __E__95__()
{
	PROXY(D3DKMTCheckMonitorPowerState)
		__asm
	{
		jmp p[95 * 4];
	}
}

// D3DKMTCheckMultiPlaneOverlaySupport
extern "C" __declspec(naked) void __stdcall __E__96__()
{
	PROXY(D3DKMTCheckMultiPlaneOverlaySupport)
		__asm
	{
		jmp p[96 * 4];
	}
}

// D3DKMTCheckMultiPlaneOverlaySupport2
extern "C" __declspec(naked) void __stdcall __E__97__()
{
	PROXY(D3DKMTCheckMultiPlaneOverlaySupport2)
		__asm
	{
		jmp p[97 * 4];
	}
}

// D3DKMTCheckOcclusion
extern "C" __declspec(naked) void __stdcall __E__98__()
{
	PROXY(D3DKMTCheckOcclusion)
		__asm
	{
		jmp p[98 * 4];
	}
}

// D3DKMTCheckSharedResourceAccess
extern "C" __declspec(naked) void __stdcall __E__99__()
{
	PROXY(D3DKMTCheckSharedResourceAccess)
		__asm
	{
		jmp p[99 * 4];
	}
}

// D3DKMTCheckVidPnExclusiveOwnership
extern "C" __declspec(naked) void __stdcall __E__100__()
{
	PROXY(D3DKMTCheckVidPnExclusiveOwnership)
		__asm
	{
		jmp p[100 * 4];
	}
}

// D3DKMTCloseAdapter
extern "C" __declspec(naked) void __stdcall __E__101__()
{
	PROXY(D3DKMTCloseAdapter)
		__asm
	{
		jmp p[101 * 4];
	}
}

// D3DKMTConfigureSharedResource
extern "C" __declspec(naked) void __stdcall __E__102__()
{
	PROXY(D3DKMTConfigureSharedResource)
		__asm
	{
		jmp p[102 * 4];
	}
}

// D3DKMTCreateAllocation
extern "C" __declspec(naked) void __stdcall __E__103__()
{
	PROXY(D3DKMTCreateAllocation)
		__asm
	{
		jmp p[103 * 4];
	}
}

// D3DKMTCreateAllocation2
extern "C" __declspec(naked) void __stdcall __E__104__()
{
	PROXY(D3DKMTCreateAllocation2)
		__asm
	{
		jmp p[104 * 4];
	}
}

// D3DKMTCreateContext
extern "C" __declspec(naked) void __stdcall __E__105__()
{
	PROXY(D3DKMTCreateContext)
		__asm
	{
		jmp p[105 * 4];
	}
}

// D3DKMTCreateContextVirtual
extern "C" __declspec(naked) void __stdcall __E__106__()
{
	PROXY(D3DKMTCreateContextVirtual)
		__asm
	{
		jmp p[106 * 4];
	}
}

// D3DKMTCreateDCFromMemory
extern "C" __declspec(naked) void __stdcall __E__107__()
{
	PROXY(D3DKMTCreateDCFromMemory)
		__asm
	{
		jmp p[107 * 4];
	}
}

// D3DKMTCreateDevice
extern "C" __declspec(naked) void __stdcall __E__108__()
{
	PROXY(D3DKMTCreateDevice)
		__asm
	{
		jmp p[108 * 4];
	}
}

// D3DKMTCreateKeyedMutex
extern "C" __declspec(naked) void __stdcall __E__109__()
{
	PROXY(D3DKMTCreateKeyedMutex)
		__asm
	{
		jmp p[109 * 4];
	}
}

// D3DKMTCreateKeyedMutex2
extern "C" __declspec(naked) void __stdcall __E__110__()
{
	PROXY(D3DKMTCreateKeyedMutex2)
		__asm
	{
		jmp p[110 * 4];
	}
}

// D3DKMTCreateOutputDupl
extern "C" __declspec(naked) void __stdcall __E__111__()
{
	PROXY(D3DKMTCreateOutputDupl)
		__asm
	{
		jmp p[111 * 4];
	}
}

// D3DKMTCreateOverlay
extern "C" __declspec(naked) void __stdcall __E__112__()
{
	PROXY(D3DKMTCreateOverlay)
		__asm
	{
		jmp p[112 * 4];
	}
}

// D3DKMTCreatePagingQueue
extern "C" __declspec(naked) void __stdcall __E__113__()
{
	PROXY(D3DKMTCreatePagingQueue)
		__asm
	{
		jmp p[113 * 4];
	}
}

// D3DKMTCreateSwapChain
extern "C" __declspec(naked) void __stdcall __E__114__()
{
	PROXY(D3DKMTCreateSwapChain)
		__asm
	{
		jmp p[114 * 4];
	}
}

// D3DKMTCreateSynchronizationObject
extern "C" __declspec(naked) void __stdcall __E__115__()
{
	PROXY(D3DKMTCreateSynchronizationObject)
		__asm
	{
		jmp p[115 * 4];
	}
}

// D3DKMTCreateSynchronizationObject2
extern "C" __declspec(naked) void __stdcall __E__116__()
{
	PROXY(D3DKMTCreateSynchronizationObject2)
		__asm
	{
		jmp p[116 * 4];
	}
}

// D3DKMTDestroyAllocation
extern "C" __declspec(naked) void __stdcall __E__117__()
{
	PROXY(D3DKMTDestroyAllocation)
		__asm
	{
		jmp p[117 * 4];
	}
}

// D3DKMTDestroyAllocation2
extern "C" __declspec(naked) void __stdcall __E__118__()
{
	PROXY(D3DKMTDestroyAllocation2)
		__asm
	{
		jmp p[118 * 4];
	}
}

// D3DKMTDestroyContext
extern "C" __declspec(naked) void __stdcall __E__119__()
{
	PROXY(D3DKMTDestroyContext)
		__asm
	{
		jmp p[119 * 4];
	}
}

// D3DKMTDestroyDCFromMemory
extern "C" __declspec(naked) void __stdcall __E__120__()
{
	PROXY(D3DKMTDestroyDCFromMemory)
		__asm
	{
		jmp p[120 * 4];
	}
}

// D3DKMTDestroyDevice
extern "C" __declspec(naked) void __stdcall __E__121__()
{
	PROXY(D3DKMTDestroyDevice)
		__asm
	{
		jmp p[121 * 4];
	}
}

// D3DKMTDestroyKeyedMutex
extern "C" __declspec(naked) void __stdcall __E__122__()
{
	PROXY(D3DKMTDestroyKeyedMutex)
		__asm
	{
		jmp p[122 * 4];
	}
}

// D3DKMTDestroyOutputDupl
extern "C" __declspec(naked) void __stdcall __E__123__()
{
	PROXY(D3DKMTDestroyOutputDupl)
		__asm
	{
		jmp p[123 * 4];
	}
}

// D3DKMTDestroyOverlay
extern "C" __declspec(naked) void __stdcall __E__124__()
{
	PROXY(D3DKMTDestroyOverlay)
		__asm
	{
		jmp p[124 * 4];
	}
}

// D3DKMTDestroyPagingQueue
extern "C" __declspec(naked) void __stdcall __E__125__()
{
	PROXY(D3DKMTDestroyPagingQueue)
		__asm
	{
		jmp p[125 * 4];
	}
}

// D3DKMTDestroySynchronizationObject
extern "C" __declspec(naked) void __stdcall __E__126__()
{
	PROXY(D3DKMTDestroySynchronizationObject)
		__asm
	{
		jmp p[126 * 4];
	}
}

// D3DKMTEnumAdapters
extern "C" __declspec(naked) void __stdcall __E__127__()
{
	PROXY(D3DKMTEnumAdapters)
		__asm
	{
		jmp p[127 * 4];
	}
}

// D3DKMTEnumAdapters2
extern "C" __declspec(naked) void __stdcall __E__128__()
{
	PROXY(D3DKMTEnumAdapters2)
		__asm
	{
		jmp p[128 * 4];
	}
}

// D3DKMTEscape
extern "C" __declspec(naked) void __stdcall __E__129__()
{
	PROXY(D3DKMTEscape)
		__asm
	{
		jmp p[129 * 4];
	}
}

// D3DKMTEvict
extern "C" __declspec(naked) void __stdcall __E__130__()
{
	PROXY(D3DKMTEvict)
		__asm
	{
		jmp p[130 * 4];
	}
}

// D3DKMTFlipOverlay
extern "C" __declspec(naked) void __stdcall __E__131__()
{
	PROXY(D3DKMTFlipOverlay)
		__asm
	{
		jmp p[131 * 4];
	}
}

// D3DKMTFlushHeapTransitions
extern "C" __declspec(naked) void __stdcall __E__132__()
{
	PROXY(D3DKMTFlushHeapTransitions)
		__asm
	{
		jmp p[132 * 4];
	}
}

// D3DKMTFreeGpuVirtualAddress
extern "C" __declspec(naked) void __stdcall __E__133__()
{
	PROXY(D3DKMTFreeGpuVirtualAddress)
		__asm
	{
		jmp p[133 * 4];
	}
}

// D3DKMTGetCachedHybridQueryValue
extern "C" __declspec(naked) void __stdcall __E__134__()
{
	PROXY(D3DKMTGetCachedHybridQueryValue)
		__asm
	{
		jmp p[134 * 4];
	}
}

// D3DKMTGetContextInProcessSchedulingPriority
extern "C" __declspec(naked) void __stdcall __E__135__()
{
	PROXY(D3DKMTGetContextInProcessSchedulingPriority)
		__asm
	{
		jmp p[135 * 4];
	}
}

// D3DKMTGetContextSchedulingPriority
extern "C" __declspec(naked) void __stdcall __E__136__()
{
	PROXY(D3DKMTGetContextSchedulingPriority)
		__asm
	{
		jmp p[136 * 4];
	}
}

// D3DKMTGetDWMVerticalBlankEvent
extern "C" __declspec(naked) void __stdcall __E__137__()
{
	PROXY(D3DKMTGetDWMVerticalBlankEvent)
		__asm
	{
		jmp p[137 * 4];
	}
}

// D3DKMTGetDeviceState
extern "C" __declspec(naked) void __stdcall __E__138__()
{
	PROXY(D3DKMTGetDeviceState)
		__asm
	{
		jmp p[138 * 4];
	}
}

// D3DKMTGetDisplayModeList
extern "C" __declspec(naked) void __stdcall __E__139__()
{
	PROXY(D3DKMTGetDisplayModeList)
		__asm
	{
		jmp p[139 * 4];
	}
}

// D3DKMTGetMultisampleMethodList
extern "C" __declspec(naked) void __stdcall __E__140__()
{
	PROXY(D3DKMTGetMultisampleMethodList)
		__asm
	{
		jmp p[140 * 4];
	}
}

// D3DKMTGetOverlayState
extern "C" __declspec(naked) void __stdcall __E__141__()
{
	PROXY(D3DKMTGetOverlayState)
		__asm
	{
		jmp p[141 * 4];
	}
}

// D3DKMTGetPresentHistory
extern "C" __declspec(naked) void __stdcall __E__142__()
{
	PROXY(D3DKMTGetPresentHistory)
		__asm
	{
		jmp p[142 * 4];
	}
}

// D3DKMTGetPresentQueueEvent
extern "C" __declspec(naked) void __stdcall __E__143__()
{
	PROXY(D3DKMTGetPresentQueueEvent)
		__asm
	{
		jmp p[143 * 4];
	}
}

// D3DKMTGetProcessSchedulingPriorityClass
extern "C" __declspec(naked) void __stdcall __E__144__()
{
	PROXY(D3DKMTGetProcessSchedulingPriorityClass)
		__asm
	{
		jmp p[144 * 4];
	}
}

// D3DKMTGetResourcePresentPrivateDriverData
extern "C" __declspec(naked) void __stdcall __E__145__()
{
	PROXY(D3DKMTGetResourcePresentPrivateDriverData)
		__asm
	{
		jmp p[145 * 4];
	}
}

// D3DKMTGetRuntimeData
extern "C" __declspec(naked) void __stdcall __E__146__()
{
	PROXY(D3DKMTGetRuntimeData)
		__asm
	{
		jmp p[146 * 4];
	}
}

// D3DKMTGetScanLine
extern "C" __declspec(naked) void __stdcall __E__147__()
{
	PROXY(D3DKMTGetScanLine)
		__asm
	{
		jmp p[147 * 4];
	}
}

// D3DKMTGetSetSwapChainMetadata
extern "C" __declspec(naked) void __stdcall __E__148__()
{
	PROXY(D3DKMTGetSetSwapChainMetadata)
		__asm
	{
		jmp p[148 * 4];
	}
}

// D3DKMTGetSharedPrimaryHandle
extern "C" __declspec(naked) void __stdcall __E__149__()
{
	PROXY(D3DKMTGetSharedPrimaryHandle)
		__asm
	{
		jmp p[149 * 4];
	}
}

// D3DKMTGetSharedResourceAdapterLuid
extern "C" __declspec(naked) void __stdcall __E__150__()
{
	PROXY(D3DKMTGetSharedResourceAdapterLuid)
		__asm
	{
		jmp p[150 * 4];
	}
}

// D3DKMTInvalidateActiveVidPn
extern "C" __declspec(naked) void __stdcall __E__151__()
{
	PROXY(D3DKMTInvalidateActiveVidPn)
		__asm
	{
		jmp p[151 * 4];
	}
}

// D3DKMTInvalidateCache
extern "C" __declspec(naked) void __stdcall __E__152__()
{
	PROXY(D3DKMTInvalidateCache)
		__asm
	{
		jmp p[152 * 4];
	}
}

// D3DKMTLock
extern "C" __declspec(naked) void __stdcall __E__153__()
{
	PROXY(D3DKMTLock)
		__asm
	{
		jmp p[153 * 4];
	}
}

// D3DKMTLock2
extern "C" __declspec(naked) void __stdcall __E__154__()
{
	PROXY(D3DKMTLock2)
		__asm
	{
		jmp p[154 * 4];
	}
}

// D3DKMTMakeResident
extern "C" __declspec(naked) void __stdcall __E__155__()
{
	PROXY(D3DKMTMakeResident)
		__asm
	{
		jmp p[155 * 4];
	}
}

// D3DKMTMapGpuVirtualAddress
extern "C" __declspec(naked) void __stdcall __E__156__()
{
	PROXY(D3DKMTMapGpuVirtualAddress)
		__asm
	{
		jmp p[156 * 4];
	}
}

// D3DKMTMarkDeviceAsError
extern "C" __declspec(naked) void __stdcall __E__157__()
{
	PROXY(D3DKMTMarkDeviceAsError)
		__asm
	{
		jmp p[157 * 4];
	}
}

// D3DKMTNetDispGetNextChunkInfo
extern "C" __declspec(naked) void __stdcall __E__158__()
{
	PROXY(D3DKMTNetDispGetNextChunkInfo)
		__asm
	{
		jmp p[158 * 4];
	}
}

// D3DKMTNetDispQueryMiracastDisplayDeviceStatus
extern "C" __declspec(naked) void __stdcall __E__159__()
{
	PROXY(D3DKMTNetDispQueryMiracastDisplayDeviceStatus)
		__asm
	{
		jmp p[159 * 4];
	}
}

// D3DKMTNetDispQueryMiracastDisplayDeviceSupport
extern "C" __declspec(naked) void __stdcall __E__160__()
{
	PROXY(D3DKMTNetDispQueryMiracastDisplayDeviceSupport)
		__asm
	{
		jmp p[160 * 4];
	}
}

// D3DKMTNetDispStartMiracastDisplayDevice
extern "C" __declspec(naked) void __stdcall __E__161__()
{
	PROXY(D3DKMTNetDispStartMiracastDisplayDevice)
		__asm
	{
		jmp p[161 * 4];
	}
}

// D3DKMTNetDispStartMiracastDisplayDevice2
extern "C" __declspec(naked) void __stdcall __E__162__()
{
	PROXY(D3DKMTNetDispStartMiracastDisplayDevice2)
		__asm
	{
		jmp p[162 * 4];
	}
}

// D3DKMTNetDispStartMiracastDisplayDeviceEx
extern "C" __declspec(naked) void __stdcall __E__163__()
{
	PROXY(D3DKMTNetDispStartMiracastDisplayDeviceEx)
		__asm
	{
		jmp p[163 * 4];
	}
}

// D3DKMTNetDispStopMiracastDisplayDevice
extern "C" __declspec(naked) void __stdcall __E__164__()
{
	PROXY(D3DKMTNetDispStopMiracastDisplayDevice)
		__asm
	{
		jmp p[164 * 4];
	}
}

// D3DKMTNetDispStopSessions
extern "C" __declspec(naked) void __stdcall __E__165__()
{
	PROXY(D3DKMTNetDispStopSessions)
		__asm
	{
		jmp p[165 * 4];
	}
}

// D3DKMTOfferAllocations
extern "C" __declspec(naked) void __stdcall __E__166__()
{
	PROXY(D3DKMTOfferAllocations)
		__asm
	{
		jmp p[166 * 4];
	}
}

// D3DKMTOpenAdapterFromDeviceName
extern "C" __declspec(naked) void __stdcall __E__167__()
{
	PROXY(D3DKMTOpenAdapterFromDeviceName)
		__asm
	{
		jmp p[167 * 4];
	}
}

// D3DKMTOpenAdapterFromGdiDisplayName
extern "C" __declspec(naked) void __stdcall __E__168__()
{
	PROXY(D3DKMTOpenAdapterFromGdiDisplayName)
		__asm
	{
		jmp p[168 * 4];
	}
}

// D3DKMTOpenAdapterFromHdc
extern "C" __declspec(naked) void __stdcall __E__169__()
{
	PROXY(D3DKMTOpenAdapterFromHdc)
		__asm
	{
		jmp p[169 * 4];
	}
}

// D3DKMTOpenAdapterFromLuid
extern "C" __declspec(naked) void __stdcall __E__170__()
{
	PROXY(D3DKMTOpenAdapterFromLuid)
		__asm
	{
		jmp p[170 * 4];
	}
}

// D3DKMTOpenKeyedMutex
extern "C" __declspec(naked) void __stdcall __E__171__()
{
	PROXY(D3DKMTOpenKeyedMutex)
		__asm
	{
		jmp p[171 * 4];
	}
}

// D3DKMTOpenKeyedMutex2
extern "C" __declspec(naked) void __stdcall __E__172__()
{
	PROXY(D3DKMTOpenKeyedMutex2)
		__asm
	{
		jmp p[172 * 4];
	}
}

// D3DKMTOpenNtHandleFromName
extern "C" __declspec(naked) void __stdcall __E__173__()
{
	PROXY(D3DKMTOpenNtHandleFromName)
		__asm
	{
		jmp p[173 * 4];
	}
}

// D3DKMTOpenResource
extern "C" __declspec(naked) void __stdcall __E__174__()
{
	PROXY(D3DKMTOpenResource)
		__asm
	{
		jmp p[174 * 4];
	}
}

// D3DKMTOpenResource2
extern "C" __declspec(naked) void __stdcall __E__175__()
{
	PROXY(D3DKMTOpenResource2)
		__asm
	{
		jmp p[175 * 4];
	}
}

// D3DKMTOpenResourceFromNtHandle
extern "C" __declspec(naked) void __stdcall __E__176__()
{
	PROXY(D3DKMTOpenResourceFromNtHandle)
		__asm
	{
		jmp p[176 * 4];
	}
}

// D3DKMTOpenSwapChain
extern "C" __declspec(naked) void __stdcall __E__177__()
{
	PROXY(D3DKMTOpenSwapChain)
		__asm
	{
		jmp p[177 * 4];
	}
}

// D3DKMTOpenSyncObjectFromNtHandle
extern "C" __declspec(naked) void __stdcall __E__178__()
{
	PROXY(D3DKMTOpenSyncObjectFromNtHandle)
		__asm
	{
		jmp p[178 * 4];
	}
}

// D3DKMTOpenSyncObjectFromNtHandle2
extern "C" __declspec(naked) void __stdcall __E__179__()
{
	PROXY(D3DKMTOpenSyncObjectFromNtHandle2)
		__asm
	{
		jmp p[179 * 4];
	}
}

// D3DKMTOpenSyncObjectNtHandleFromName
extern "C" __declspec(naked) void __stdcall __E__180__()
{
	PROXY(D3DKMTOpenSyncObjectNtHandleFromName)
		__asm
	{
		jmp p[180 * 4];
	}
}

// D3DKMTOpenSynchronizationObject
extern "C" __declspec(naked) void __stdcall __E__181__()
{
	PROXY(D3DKMTOpenSynchronizationObject)
		__asm
	{
		jmp p[181 * 4];
	}
}

// D3DKMTOutputDuplGetFrameInfo
extern "C" __declspec(naked) void __stdcall __E__182__()
{
	PROXY(D3DKMTOutputDuplGetFrameInfo)
		__asm
	{
		jmp p[182 * 4];
	}
}

// D3DKMTOutputDuplGetMetaData
extern "C" __declspec(naked) void __stdcall __E__183__()
{
	PROXY(D3DKMTOutputDuplGetMetaData)
		__asm
	{
		jmp p[183 * 4];
	}
}

// D3DKMTOutputDuplGetPointerShapeData
extern "C" __declspec(naked) void __stdcall __E__184__()
{
	PROXY(D3DKMTOutputDuplGetPointerShapeData)
		__asm
	{
		jmp p[184 * 4];
	}
}

// D3DKMTOutputDuplPresent
extern "C" __declspec(naked) void __stdcall __E__185__()
{
	PROXY(D3DKMTOutputDuplPresent)
		__asm
	{
		jmp p[185 * 4];
	}
}

// D3DKMTOutputDuplReleaseFrame
extern "C" __declspec(naked) void __stdcall __E__186__()
{
	PROXY(D3DKMTOutputDuplReleaseFrame)
		__asm
	{
		jmp p[186 * 4];
	}
}

// D3DKMTPinDirectFlipResources
extern "C" __declspec(naked) void __stdcall __E__187__()
{
	PROXY(D3DKMTPinDirectFlipResources)
		__asm
	{
		jmp p[187 * 4];
	}
}

// D3DKMTPollDisplayChildren
extern "C" __declspec(naked) void __stdcall __E__188__()
{
	PROXY(D3DKMTPollDisplayChildren)
		__asm
	{
		jmp p[188 * 4];
	}
}

// D3DKMTPresent
extern "C" __declspec(naked) void __stdcall __E__189__()
{
	PROXY(D3DKMTPresent)
		__asm
	{
		jmp p[189 * 4];
	}
}

// D3DKMTPresentMultiPlaneOverlay
extern "C" __declspec(naked) void __stdcall __E__190__()
{
	PROXY(D3DKMTPresentMultiPlaneOverlay)
		__asm
	{
		jmp p[190 * 4];
	}
}

// D3DKMTPresentMultiPlaneOverlay2
extern "C" __declspec(naked) void __stdcall __E__191__()
{
	PROXY(D3DKMTPresentMultiPlaneOverlay2)
		__asm
	{
		jmp p[191 * 4];
	}
}

// D3DKMTQueryAdapterInfo
extern "C" __declspec(naked) void __stdcall __E__192__()
{
	PROXY(D3DKMTQueryAdapterInfo)
		__asm
	{
		jmp p[192 * 4];
	}
}

// D3DKMTQueryAllocationResidency
extern "C" __declspec(naked) void __stdcall __E__193__()
{
	PROXY(D3DKMTQueryAllocationResidency)
		__asm
	{
		jmp p[193 * 4];
	}
}

// D3DKMTQueryClockCalibration
extern "C" __declspec(naked) void __stdcall __E__194__()
{
	PROXY(D3DKMTQueryClockCalibration)
		__asm
	{
		jmp p[194 * 4];
	}
}

// D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName
extern "C" __declspec(naked) void __stdcall __E__195__()
{
	PROXY(D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName)
		__asm
	{
		jmp p[195 * 4];
	}
}

// D3DKMTQueryResourceInfo
extern "C" __declspec(naked) void __stdcall __E__196__()
{
	PROXY(D3DKMTQueryResourceInfo)
		__asm
	{
		jmp p[196 * 4];
	}
}

// D3DKMTQueryResourceInfoFromNtHandle
extern "C" __declspec(naked) void __stdcall __E__197__()
{
	PROXY(D3DKMTQueryResourceInfoFromNtHandle)
		__asm
	{
		jmp p[197 * 4];
	}
}

// D3DKMTQueryStatistics
extern "C" __declspec(naked) void __stdcall __E__198__()
{
	PROXY(D3DKMTQueryStatistics)
		__asm
	{
		jmp p[198 * 4];
	}
}

// D3DKMTQueryVidPnExclusiveOwnership
extern "C" __declspec(naked) void __stdcall __E__199__()
{
	PROXY(D3DKMTQueryVidPnExclusiveOwnership)
		__asm
	{
		jmp p[199 * 4];
	}
}

// D3DKMTQueryVideoMemoryInfo
extern "C" __declspec(naked) void __stdcall __E__200__()
{
	PROXY(D3DKMTQueryVideoMemoryInfo)
		__asm
	{
		jmp p[200 * 4];
	}
}

// D3DKMTReclaimAllocations
extern "C" __declspec(naked) void __stdcall __E__201__()
{
	PROXY(D3DKMTReclaimAllocations)
		__asm
	{
		jmp p[201 * 4];
	}
}

// D3DKMTReclaimAllocations2
extern "C" __declspec(naked) void __stdcall __E__202__()
{
	PROXY(D3DKMTReclaimAllocations2)
		__asm
	{
		jmp p[202 * 4];
	}
}

// D3DKMTRegisterTrimNotification
extern "C" __declspec(naked) void __stdcall __E__203__()
{
	PROXY(D3DKMTRegisterTrimNotification)
		__asm
	{
		jmp p[203 * 4];
	}
}

// D3DKMTReleaseKeyedMutex
extern "C" __declspec(naked) void __stdcall __E__204__()
{
	PROXY(D3DKMTReleaseKeyedMutex)
		__asm
	{
		jmp p[204 * 4];
	}
}

// D3DKMTReleaseKeyedMutex2
extern "C" __declspec(naked) void __stdcall __E__205__()
{
	PROXY(D3DKMTReleaseKeyedMutex2)
		__asm
	{
		jmp p[205 * 4];
	}
}

// D3DKMTReleaseProcessVidPnSourceOwners
extern "C" __declspec(naked) void __stdcall __E__206__()
{
	PROXY(D3DKMTReleaseProcessVidPnSourceOwners)
		__asm
	{
		jmp p[206 * 4];
	}
}

// D3DKMTReleaseSwapChain
extern "C" __declspec(naked) void __stdcall __E__207__()
{
	PROXY(D3DKMTReleaseSwapChain)
		__asm
	{
		jmp p[207 * 4];
	}
}

// D3DKMTRender
extern "C" __declspec(naked) void __stdcall __E__208__()
{
	PROXY(D3DKMTRender)
		__asm
	{
		jmp p[208 * 4];
	}
}

// D3DKMTReserveGpuVirtualAddress
extern "C" __declspec(naked) void __stdcall __E__209__()
{
	PROXY(D3DKMTReserveGpuVirtualAddress)
		__asm
	{
		jmp p[209 * 4];
	}
}

// D3DKMTSetAllocationPriority
extern "C" __declspec(naked) void __stdcall __E__210__()
{
	PROXY(D3DKMTSetAllocationPriority)
		__asm
	{
		jmp p[210 * 4];
	}
}

// D3DKMTSetContextInProcessSchedulingPriority
extern "C" __declspec(naked) void __stdcall __E__211__()
{
	PROXY(D3DKMTSetContextInProcessSchedulingPriority)
		__asm
	{
		jmp p[211 * 4];
	}
}

// D3DKMTSetContextSchedulingPriority
extern "C" __declspec(naked) void __stdcall __E__212__()
{
	PROXY(D3DKMTSetContextSchedulingPriority)
		__asm
	{
		jmp p[212 * 4];
	}
}

// D3DKMTSetDisplayMode
extern "C" __declspec(naked) void __stdcall __E__213__()
{
	PROXY(D3DKMTSetDisplayMode)
		__asm
	{
		jmp p[213 * 4];
	}
}

// D3DKMTSetDisplayPrivateDriverFormat
extern "C" __declspec(naked) void __stdcall __E__214__()
{
	PROXY(D3DKMTSetDisplayPrivateDriverFormat)
		__asm
	{
		jmp p[214 * 4];
	}
}

// D3DKMTSetDodIndirectSwapchain
extern "C" __declspec(naked) void __stdcall __E__215__()
{
	PROXY(D3DKMTSetDodIndirectSwapchain)
		__asm
	{
		jmp p[215 * 4];
	}
}

// D3DKMTSetGammaRamp
extern "C" __declspec(naked) void __stdcall __E__216__()
{
	PROXY(D3DKMTSetGammaRamp)
		__asm
	{
		jmp p[216 * 4];
	}
}

// D3DKMTSetHwProtectionTeardownRecovery
extern "C" __declspec(naked) void __stdcall __E__217__()
{
	PROXY(D3DKMTSetHwProtectionTeardownRecovery)
		__asm
	{
		jmp p[217 * 4];
	}
}

// D3DKMTSetProcessSchedulingPriorityClass
extern "C" __declspec(naked) void __stdcall __E__218__()
{
	PROXY(D3DKMTSetProcessSchedulingPriorityClass)
		__asm
	{
		jmp p[218 * 4];
	}
}

// D3DKMTSetQueuedLimit
extern "C" __declspec(naked) void __stdcall __E__219__()
{
	PROXY(D3DKMTSetQueuedLimit)
		__asm
	{
		jmp p[219 * 4];
	}
}

// D3DKMTSetStablePowerState
extern "C" __declspec(naked) void __stdcall __E__220__()
{
	PROXY(D3DKMTSetStablePowerState)
		__asm
	{
		jmp p[220 * 4];
	}
}

// D3DKMTSetStereoEnabled
extern "C" __declspec(naked) void __stdcall __E__221__()
{
	PROXY(D3DKMTSetStereoEnabled)
		__asm
	{
		jmp p[221 * 4];
	}
}

// D3DKMTSetSyncRefreshCountWaitTarget
extern "C" __declspec(naked) void __stdcall __E__222__()
{
	PROXY(D3DKMTSetSyncRefreshCountWaitTarget)
		__asm
	{
		jmp p[222 * 4];
	}
}

// D3DKMTSetVidPnSourceHwProtection
extern "C" __declspec(naked) void __stdcall __E__223__()
{
	PROXY(D3DKMTSetVidPnSourceHwProtection)
		__asm
	{
		jmp p[223 * 4];
	}
}

// D3DKMTSetVidPnSourceOwner
extern "C" __declspec(naked) void __stdcall __E__224__()
{
	PROXY(D3DKMTSetVidPnSourceOwner)
		__asm
	{
		jmp p[224 * 4];
	}
}

// D3DKMTSetVidPnSourceOwner1
extern "C" __declspec(naked) void __stdcall __E__225__()
{
	PROXY(D3DKMTSetVidPnSourceOwner1)
		__asm
	{
		jmp p[225 * 4];
	}
}

// D3DKMTShareObjects
extern "C" __declspec(naked) void __stdcall __E__226__()
{
	PROXY(D3DKMTShareObjects)
		__asm
	{
		jmp p[226 * 4];
	}
}

// D3DKMTSharedPrimaryLockNotification
extern "C" __declspec(naked) void __stdcall __E__227__()
{
	PROXY(D3DKMTSharedPrimaryLockNotification)
		__asm
	{
		jmp p[227 * 4];
	}
}

// D3DKMTSharedPrimaryUnLockNotification
extern "C" __declspec(naked) void __stdcall __E__228__()
{
	PROXY(D3DKMTSharedPrimaryUnLockNotification)
		__asm
	{
		jmp p[228 * 4];
	}
}

// D3DKMTSignalSynchronizationObject
extern "C" __declspec(naked) void __stdcall __E__229__()
{
	PROXY(D3DKMTSignalSynchronizationObject)
		__asm
	{
		jmp p[229 * 4];
	}
}

// D3DKMTSignalSynchronizationObject2
extern "C" __declspec(naked) void __stdcall __E__230__()
{
	PROXY(D3DKMTSignalSynchronizationObject2)
		__asm
	{
		jmp p[230 * 4];
	}
}

// D3DKMTSignalSynchronizationObjectFromCpu
extern "C" __declspec(naked) void __stdcall __E__231__()
{
	PROXY(D3DKMTSignalSynchronizationObjectFromCpu)
		__asm
	{
		jmp p[231 * 4];
	}
}

// D3DKMTSignalSynchronizationObjectFromGpu
extern "C" __declspec(naked) void __stdcall __E__232__()
{
	PROXY(D3DKMTSignalSynchronizationObjectFromGpu)
		__asm
	{
		jmp p[232 * 4];
	}
}

// D3DKMTSignalSynchronizationObjectFromGpu2
extern "C" __declspec(naked) void __stdcall __E__233__()
{
	PROXY(D3DKMTSignalSynchronizationObjectFromGpu2)
		__asm
	{
		jmp p[233 * 4];
	}
}

// D3DKMTSubmitCommand
extern "C" __declspec(naked) void __stdcall __E__234__()
{
	PROXY(D3DKMTSubmitCommand)
		__asm
	{
		jmp p[234 * 4];
	}
}

// D3DKMTUnlock
extern "C" __declspec(naked) void __stdcall __E__235__()
{
	PROXY(D3DKMTUnlock)
		__asm
	{
		jmp p[235 * 4];
	}
}

// D3DKMTUnlock2
extern "C" __declspec(naked) void __stdcall __E__236__()
{
	PROXY(D3DKMTUnlock2)
		__asm
	{
		jmp p[236 * 4];
	}
}

// D3DKMTUnpinDirectFlipResources
extern "C" __declspec(naked) void __stdcall __E__237__()
{
	PROXY(D3DKMTUnpinDirectFlipResources)
		__asm
	{
		jmp p[237 * 4];
	}
}

// D3DKMTUnregisterTrimNotification
extern "C" __declspec(naked) void __stdcall __E__238__()
{
	PROXY(D3DKMTUnregisterTrimNotification)
		__asm
	{
		jmp p[238 * 4];
	}
}

// D3DKMTUpdateGpuVirtualAddress
extern "C" __declspec(naked) void __stdcall __E__239__()
{
	PROXY(D3DKMTUpdateGpuVirtualAddress)
		__asm
	{
		jmp p[239 * 4];
	}
}

// D3DKMTUpdateOverlay
extern "C" __declspec(naked) void __stdcall __E__240__()
{
	PROXY(D3DKMTUpdateOverlay)
		__asm
	{
		jmp p[240 * 4];
	}
}

// D3DKMTWaitForIdle
extern "C" __declspec(naked) void __stdcall __E__241__()
{
	PROXY(D3DKMTWaitForIdle)
		__asm
	{
		jmp p[241 * 4];
	}
}

// D3DKMTWaitForSynchronizationObject
extern "C" __declspec(naked) void __stdcall __E__242__()
{
	PROXY(D3DKMTWaitForSynchronizationObject)
		__asm
	{
		jmp p[242 * 4];
	}
}

// D3DKMTWaitForSynchronizationObject2
extern "C" __declspec(naked) void __stdcall __E__243__()
{
	PROXY(D3DKMTWaitForSynchronizationObject2)
		__asm
	{
		jmp p[243 * 4];
	}
}

// D3DKMTWaitForSynchronizationObjectFromCpu
extern "C" __declspec(naked) void __stdcall __E__244__()
{
	PROXY(D3DKMTWaitForSynchronizationObjectFromCpu)
		__asm
	{
		jmp p[244 * 4];
	}
}

// D3DKMTWaitForSynchronizationObjectFromGpu
extern "C" __declspec(naked) void __stdcall __E__245__()
{
	PROXY(D3DKMTWaitForSynchronizationObjectFromGpu)
		__asm
	{
		jmp p[245 * 4];
	}
}

// D3DKMTWaitForVerticalBlankEvent
extern "C" __declspec(naked) void __stdcall __E__246__()
{
	PROXY(D3DKMTWaitForVerticalBlankEvent)
		__asm
	{
		jmp p[246 * 4];
	}
}

// D3DKMTWaitForVerticalBlankEvent2
extern "C" __declspec(naked) void __stdcall __E__247__()
{
	PROXY(D3DKMTWaitForVerticalBlankEvent2)
		__asm
	{
		jmp p[247 * 4];
	}
}

// DDCCIGetCapabilitiesString
extern "C" __declspec(naked) void __stdcall __E__248__()
{
	PROXY(DDCCIGetCapabilitiesString)
		__asm
	{
		jmp p[248 * 4];
	}
}

// DDCCIGetCapabilitiesStringLength
extern "C" __declspec(naked) void __stdcall __E__249__()
{
	PROXY(DDCCIGetCapabilitiesStringLength)
		__asm
	{
		jmp p[249 * 4];
	}
}

// DDCCIGetTimingReport
extern "C" __declspec(naked) void __stdcall __E__250__()
{
	PROXY(DDCCIGetTimingReport)
		__asm
	{
		jmp p[250 * 4];
	}
}

// DDCCIGetVCPFeature
extern "C" __declspec(naked) void __stdcall __E__251__()
{
	PROXY(DDCCIGetVCPFeature)
		__asm
	{
		jmp p[251 * 4];
	}
}

// DDCCISaveCurrentSettings
extern "C" __declspec(naked) void __stdcall __E__252__()
{
	PROXY(DDCCISaveCurrentSettings)
		__asm
	{
		jmp p[252 * 4];
	}
}

// DDCCISetVCPFeature
extern "C" __declspec(naked) void __stdcall __E__253__()
{
	PROXY(DDCCISetVCPFeature)
		__asm
	{
		jmp p[253 * 4];
	}
}

// DPtoLP
extern "C" __declspec(naked) void __stdcall __E__254__()
{
	PROXY(DPtoLP)
		__asm
	{
		jmp p[254 * 4];
	}
}

// DdCreateFullscreenSprite
extern "C" __declspec(naked) void __stdcall __E__255__()
{
	PROXY(DdCreateFullscreenSprite)
		__asm
	{
		jmp p[255 * 4];
	}
}

// DdDestroyFullscreenSprite
extern "C" __declspec(naked) void __stdcall __E__256__()
{
	PROXY(DdDestroyFullscreenSprite)
		__asm
	{
		jmp p[256 * 4];
	}
}

// DdEntry0
extern "C" __declspec(naked) void __stdcall __E__257__()
{
	PROXY(DdEntry0)
		__asm
	{
		jmp p[257 * 4];
	}
}

// DdEntry1
extern "C" __declspec(naked) void __stdcall __E__258__()
{
	PROXY(DdEntry1)
		__asm
	{
		jmp p[258 * 4];
	}
}

// DdEntry10
extern "C" __declspec(naked) void __stdcall __E__259__()
{
	PROXY(DdEntry10)
		__asm
	{
		jmp p[259 * 4];
	}
}

// DdEntry11
extern "C" __declspec(naked) void __stdcall __E__260__()
{
	PROXY(DdEntry11)
		__asm
	{
		jmp p[260 * 4];
	}
}

// DdEntry12
extern "C" __declspec(naked) void __stdcall __E__261__()
{
	PROXY(DdEntry12)
		__asm
	{
		jmp p[261 * 4];
	}
}

// DdEntry13
extern "C" __declspec(naked) void __stdcall __E__262__()
{
	PROXY(DdEntry13)
		__asm
	{
		jmp p[262 * 4];
	}
}

// DdEntry14
extern "C" __declspec(naked) void __stdcall __E__263__()
{
	PROXY(DdEntry14)
		__asm
	{
		jmp p[263 * 4];
	}
}

// DdEntry15
extern "C" __declspec(naked) void __stdcall __E__264__()
{
	PROXY(DdEntry15)
		__asm
	{
		jmp p[264 * 4];
	}
}

// DdEntry16
extern "C" __declspec(naked) void __stdcall __E__265__()
{
	PROXY(DdEntry16)
		__asm
	{
		jmp p[265 * 4];
	}
}

// DdEntry17
extern "C" __declspec(naked) void __stdcall __E__266__()
{
	PROXY(DdEntry17)
		__asm
	{
		jmp p[266 * 4];
	}
}

// DdEntry18
extern "C" __declspec(naked) void __stdcall __E__267__()
{
	PROXY(DdEntry18)
		__asm
	{
		jmp p[267 * 4];
	}
}

// DdEntry19
extern "C" __declspec(naked) void __stdcall __E__268__()
{
	PROXY(DdEntry19)
		__asm
	{
		jmp p[268 * 4];
	}
}

// DdEntry2
extern "C" __declspec(naked) void __stdcall __E__269__()
{
	PROXY(DdEntry2)
		__asm
	{
		jmp p[269 * 4];
	}
}

// DdEntry20
extern "C" __declspec(naked) void __stdcall __E__270__()
{
	PROXY(DdEntry20)
		__asm
	{
		jmp p[270 * 4];
	}
}

// DdEntry21
extern "C" __declspec(naked) void __stdcall __E__271__()
{
	PROXY(DdEntry21)
		__asm
	{
		jmp p[271 * 4];
	}
}

// DdEntry22
extern "C" __declspec(naked) void __stdcall __E__272__()
{
	PROXY(DdEntry22)
		__asm
	{
		jmp p[272 * 4];
	}
}

// DdEntry23
extern "C" __declspec(naked) void __stdcall __E__273__()
{
	PROXY(DdEntry23)
		__asm
	{
		jmp p[273 * 4];
	}
}

// DdEntry24
extern "C" __declspec(naked) void __stdcall __E__274__()
{
	PROXY(DdEntry24)
		__asm
	{
		jmp p[274 * 4];
	}
}

// DdEntry25
extern "C" __declspec(naked) void __stdcall __E__275__()
{
	PROXY(DdEntry25)
		__asm
	{
		jmp p[275 * 4];
	}
}

// DdEntry26
extern "C" __declspec(naked) void __stdcall __E__276__()
{
	PROXY(DdEntry26)
		__asm
	{
		jmp p[276 * 4];
	}
}

// DdEntry27
extern "C" __declspec(naked) void __stdcall __E__277__()
{
	PROXY(DdEntry27)
		__asm
	{
		jmp p[277 * 4];
	}
}

// DdEntry28
extern "C" __declspec(naked) void __stdcall __E__278__()
{
	PROXY(DdEntry28)
		__asm
	{
		jmp p[278 * 4];
	}
}

// DdEntry29
extern "C" __declspec(naked) void __stdcall __E__279__()
{
	PROXY(DdEntry29)
		__asm
	{
		jmp p[279 * 4];
	}
}

// DdEntry3
extern "C" __declspec(naked) void __stdcall __E__280__()
{
	PROXY(DdEntry3)
		__asm
	{
		jmp p[280 * 4];
	}
}

// DdEntry30
extern "C" __declspec(naked) void __stdcall __E__281__()
{
	PROXY(DdEntry30)
		__asm
	{
		jmp p[281 * 4];
	}
}

// DdEntry31
extern "C" __declspec(naked) void __stdcall __E__282__()
{
	PROXY(DdEntry31)
		__asm
	{
		jmp p[282 * 4];
	}
}

// DdEntry32
extern "C" __declspec(naked) void __stdcall __E__283__()
{
	PROXY(DdEntry32)
		__asm
	{
		jmp p[283 * 4];
	}
}

// DdEntry33
extern "C" __declspec(naked) void __stdcall __E__284__()
{
	PROXY(DdEntry33)
		__asm
	{
		jmp p[284 * 4];
	}
}

// DdEntry34
extern "C" __declspec(naked) void __stdcall __E__285__()
{
	PROXY(DdEntry34)
		__asm
	{
		jmp p[285 * 4];
	}
}

// DdEntry35
extern "C" __declspec(naked) void __stdcall __E__286__()
{
	PROXY(DdEntry35)
		__asm
	{
		jmp p[286 * 4];
	}
}

// DdEntry36
extern "C" __declspec(naked) void __stdcall __E__287__()
{
	PROXY(DdEntry36)
		__asm
	{
		jmp p[287 * 4];
	}
}

// DdEntry37
extern "C" __declspec(naked) void __stdcall __E__288__()
{
	PROXY(DdEntry37)
		__asm
	{
		jmp p[288 * 4];
	}
}

// DdEntry38
extern "C" __declspec(naked) void __stdcall __E__289__()
{
	PROXY(DdEntry38)
		__asm
	{
		jmp p[289 * 4];
	}
}

// DdEntry39
extern "C" __declspec(naked) void __stdcall __E__290__()
{
	PROXY(DdEntry39)
		__asm
	{
		jmp p[290 * 4];
	}
}

// DdEntry4
extern "C" __declspec(naked) void __stdcall __E__291__()
{
	PROXY(DdEntry4)
		__asm
	{
		jmp p[291 * 4];
	}
}

// DdEntry40
extern "C" __declspec(naked) void __stdcall __E__292__()
{
	PROXY(DdEntry40)
		__asm
	{
		jmp p[292 * 4];
	}
}

// DdEntry41
extern "C" __declspec(naked) void __stdcall __E__293__()
{
	PROXY(DdEntry41)
		__asm
	{
		jmp p[293 * 4];
	}
}

// DdEntry42
extern "C" __declspec(naked) void __stdcall __E__294__()
{
	PROXY(DdEntry42)
		__asm
	{
		jmp p[294 * 4];
	}
}

// DdEntry43
extern "C" __declspec(naked) void __stdcall __E__295__()
{
	PROXY(DdEntry43)
		__asm
	{
		jmp p[295 * 4];
	}
}

// DdEntry44
extern "C" __declspec(naked) void __stdcall __E__296__()
{
	PROXY(DdEntry44)
		__asm
	{
		jmp p[296 * 4];
	}
}

// DdEntry45
extern "C" __declspec(naked) void __stdcall __E__297__()
{
	PROXY(DdEntry45)
		__asm
	{
		jmp p[297 * 4];
	}
}

// DdEntry46
extern "C" __declspec(naked) void __stdcall __E__298__()
{
	PROXY(DdEntry46)
		__asm
	{
		jmp p[298 * 4];
	}
}

// DdEntry47
extern "C" __declspec(naked) void __stdcall __E__299__()
{
	PROXY(DdEntry47)
		__asm
	{
		jmp p[299 * 4];
	}
}

// DdEntry48
extern "C" __declspec(naked) void __stdcall __E__300__()
{
	PROXY(DdEntry48)
		__asm
	{
		jmp p[300 * 4];
	}
}

// DdEntry49
extern "C" __declspec(naked) void __stdcall __E__301__()
{
	PROXY(DdEntry49)
		__asm
	{
		jmp p[301 * 4];
	}
}

// DdEntry5
extern "C" __declspec(naked) void __stdcall __E__302__()
{
	PROXY(DdEntry5)
		__asm
	{
		jmp p[302 * 4];
	}
}

// DdEntry50
extern "C" __declspec(naked) void __stdcall __E__303__()
{
	PROXY(DdEntry50)
		__asm
	{
		jmp p[303 * 4];
	}
}

// DdEntry51
extern "C" __declspec(naked) void __stdcall __E__304__()
{
	PROXY(DdEntry51)
		__asm
	{
		jmp p[304 * 4];
	}
}

// DdEntry52
extern "C" __declspec(naked) void __stdcall __E__305__()
{
	PROXY(DdEntry52)
		__asm
	{
		jmp p[305 * 4];
	}
}

// DdEntry53
extern "C" __declspec(naked) void __stdcall __E__306__()
{
	PROXY(DdEntry53)
		__asm
	{
		jmp p[306 * 4];
	}
}

// DdEntry54
extern "C" __declspec(naked) void __stdcall __E__307__()
{
	PROXY(DdEntry54)
		__asm
	{
		jmp p[307 * 4];
	}
}

// DdEntry55
extern "C" __declspec(naked) void __stdcall __E__308__()
{
	PROXY(DdEntry55)
		__asm
	{
		jmp p[308 * 4];
	}
}

// DdEntry56
extern "C" __declspec(naked) void __stdcall __E__309__()
{
	PROXY(DdEntry56)
		__asm
	{
		jmp p[309 * 4];
	}
}

// DdEntry6
extern "C" __declspec(naked) void __stdcall __E__310__()
{
	PROXY(DdEntry6)
		__asm
	{
		jmp p[310 * 4];
	}
}

// DdEntry7
extern "C" __declspec(naked) void __stdcall __E__311__()
{
	PROXY(DdEntry7)
		__asm
	{
		jmp p[311 * 4];
	}
}

// DdEntry8
extern "C" __declspec(naked) void __stdcall __E__312__()
{
	PROXY(DdEntry8)
		__asm
	{
		jmp p[312 * 4];
	}
}

// DdEntry9
extern "C" __declspec(naked) void __stdcall __E__313__()
{
	PROXY(DdEntry9)
		__asm
	{
		jmp p[313 * 4];
	}
}

// DdNotifyFullscreenSpriteUpdate
extern "C" __declspec(naked) void __stdcall __E__314__()
{
	PROXY(DdNotifyFullscreenSpriteUpdate)
		__asm
	{
		jmp p[314 * 4];
	}
}

// DdQueryVisRgnUniqueness
extern "C" __declspec(naked) void __stdcall __E__315__()
{
	PROXY(DdQueryVisRgnUniqueness)
		__asm
	{
		jmp p[315 * 4];
	}
}

// DeleteColorSpace
extern "C" __declspec(naked) void __stdcall __E__316__()
{
	PROXY(DeleteColorSpace)
		__asm
	{
		jmp p[316 * 4];
	}
}

// DeleteDC
extern "C" __declspec(naked) void __stdcall __E__317__()
{
	PROXY(DeleteDC)
		__asm
	{
		jmp p[317 * 4];
	}
}

// DeleteEnhMetaFile
extern "C" __declspec(naked) void __stdcall __E__318__()
{
	PROXY(DeleteEnhMetaFile)
		__asm
	{
		jmp p[318 * 4];
	}
}

// DeleteMetaFile
extern "C" __declspec(naked) void __stdcall __E__319__()
{
	PROXY(DeleteMetaFile)
		__asm
	{
		jmp p[319 * 4];
	}
}

// DeleteObject
extern "C" __declspec(naked) void __stdcall __E__320__()
{
	PROXY(DeleteObject)
		__asm
	{
		jmp p[320 * 4];
	}
}

// DescribePixelFormat
extern "C" __declspec(naked) void __stdcall __E__321__()
{
	PROXY(DescribePixelFormat)
		__asm
	{
		jmp p[321 * 4];
	}
}

// DestroyOPMProtectedOutput
extern "C" __declspec(naked) void __stdcall __E__322__()
{
	PROXY(DestroyOPMProtectedOutput)
		__asm
	{
		jmp p[322 * 4];
	}
}

// DestroyPhysicalMonitorInternal
extern "C" __declspec(naked) void __stdcall __E__323__()
{
	PROXY(DestroyPhysicalMonitorInternal)
		__asm
	{
		jmp p[323 * 4];
	}
}

// DeviceCapabilitiesExA
extern "C" __declspec(naked) void __stdcall __E__324__()
{
	PROXY(DeviceCapabilitiesExA)
		__asm
	{
		jmp p[324 * 4];
	}
}

// DeviceCapabilitiesExW
extern "C" __declspec(naked) void __stdcall __E__325__()
{
	PROXY(DeviceCapabilitiesExW)
		__asm
	{
		jmp p[325 * 4];
	}
}

// DrawEscape
extern "C" __declspec(naked) void __stdcall __E__326__()
{
	PROXY(DrawEscape)
		__asm
	{
		jmp p[326 * 4];
	}
}

// Ellipse
extern "C" __declspec(naked) void __stdcall __E__327__()
{
	PROXY(Ellipse)
		__asm
	{
		jmp p[327 * 4];
	}
}

// EnableEUDC
extern "C" __declspec(naked) void __stdcall __E__328__()
{
	PROXY(EnableEUDC)
		__asm
	{
		jmp p[328 * 4];
	}
}

// EndDoc
extern "C" __declspec(naked) void __stdcall __E__329__()
{
	PROXY(EndDoc)
		__asm
	{
		jmp p[329 * 4];
	}
}

// EndFormPage
extern "C" __declspec(naked) void __stdcall __E__330__()
{
	PROXY(EndFormPage)
		__asm
	{
		jmp p[330 * 4];
	}
}

// EndGdiRendering
extern "C" __declspec(naked) void __stdcall __E__331__()
{
	PROXY(EndGdiRendering)
		__asm
	{
		jmp p[331 * 4];
	}
}

// EndPage
extern "C" __declspec(naked) void __stdcall __E__332__()
{
	PROXY(EndPage)
		__asm
	{
		jmp p[332 * 4];
	}
}

// EndPath
extern "C" __declspec(naked) void __stdcall __E__333__()
{
	PROXY(EndPath)
		__asm
	{
		jmp p[333 * 4];
	}
}

// EngAcquireSemaphore
extern "C" __declspec(naked) void __stdcall __E__334__()
{
	PROXY(EngAcquireSemaphore)
		__asm
	{
		jmp p[334 * 4];
	}
}

// EngAlphaBlend
extern "C" __declspec(naked) void __stdcall __E__335__()
{
	PROXY(EngAlphaBlend)
		__asm
	{
		jmp p[335 * 4];
	}
}

// EngAssociateSurface
extern "C" __declspec(naked) void __stdcall __E__336__()
{
	PROXY(EngAssociateSurface)
		__asm
	{
		jmp p[336 * 4];
	}
}

// EngBitBlt
extern "C" __declspec(naked) void __stdcall __E__337__()
{
	PROXY(EngBitBlt)
		__asm
	{
		jmp p[337 * 4];
	}
}

// EngCheckAbort
extern "C" __declspec(naked) void __stdcall __E__338__()
{
	PROXY(EngCheckAbort)
		__asm
	{
		jmp p[338 * 4];
	}
}

// EngComputeGlyphSet
extern "C" __declspec(naked) void __stdcall __E__339__()
{
	PROXY(EngComputeGlyphSet)
		__asm
	{
		jmp p[339 * 4];
	}
}

// EngCopyBits
extern "C" __declspec(naked) void __stdcall __E__340__()
{
	PROXY(EngCopyBits)
		__asm
	{
		jmp p[340 * 4];
	}
}

// EngCreateBitmap
extern "C" __declspec(naked) void __stdcall __E__341__()
{
	PROXY(EngCreateBitmap)
		__asm
	{
		jmp p[341 * 4];
	}
}

// EngCreateClip
extern "C" __declspec(naked) void __stdcall __E__342__()
{
	PROXY(EngCreateClip)
		__asm
	{
		jmp p[342 * 4];
	}
}

// EngCreateDeviceBitmap
extern "C" __declspec(naked) void __stdcall __E__343__()
{
	PROXY(EngCreateDeviceBitmap)
		__asm
	{
		jmp p[343 * 4];
	}
}

// EngCreateDeviceSurface
extern "C" __declspec(naked) void __stdcall __E__344__()
{
	PROXY(EngCreateDeviceSurface)
		__asm
	{
		jmp p[344 * 4];
	}
}

// EngCreatePalette
extern "C" __declspec(naked) void __stdcall __E__345__()
{
	PROXY(EngCreatePalette)
		__asm
	{
		jmp p[345 * 4];
	}
}

// EngCreateSemaphore
extern "C" __declspec(naked) void __stdcall __E__346__()
{
	PROXY(EngCreateSemaphore)
		__asm
	{
		jmp p[346 * 4];
	}
}

// EngDeleteClip
extern "C" __declspec(naked) void __stdcall __E__347__()
{
	PROXY(EngDeleteClip)
		__asm
	{
		jmp p[347 * 4];
	}
}

// EngDeletePalette
extern "C" __declspec(naked) void __stdcall __E__348__()
{
	PROXY(EngDeletePalette)
		__asm
	{
		jmp p[348 * 4];
	}
}

// EngDeletePath
extern "C" __declspec(naked) void __stdcall __E__349__()
{
	PROXY(EngDeletePath)
		__asm
	{
		jmp p[349 * 4];
	}
}

// EngDeleteSemaphore
extern "C" __declspec(naked) void __stdcall __E__350__()
{
	PROXY(EngDeleteSemaphore)
		__asm
	{
		jmp p[350 * 4];
	}
}

// EngDeleteSurface
extern "C" __declspec(naked) void __stdcall __E__351__()
{
	PROXY(EngDeleteSurface)
		__asm
	{
		jmp p[351 * 4];
	}
}

// EngEraseSurface
extern "C" __declspec(naked) void __stdcall __E__352__()
{
	PROXY(EngEraseSurface)
		__asm
	{
		jmp p[352 * 4];
	}
}

// EngFillPath
extern "C" __declspec(naked) void __stdcall __E__353__()
{
	PROXY(EngFillPath)
		__asm
	{
		jmp p[353 * 4];
	}
}

// EngFindResource
extern "C" __declspec(naked) void __stdcall __E__354__()
{
	PROXY(EngFindResource)
		__asm
	{
		jmp p[354 * 4];
	}
}

// EngFreeModule
extern "C" __declspec(naked) void __stdcall __E__355__()
{
	PROXY(EngFreeModule)
		__asm
	{
		jmp p[355 * 4];
	}
}

// EngGetCurrentCodePage
extern "C" __declspec(naked) void __stdcall __E__356__()
{
	PROXY(EngGetCurrentCodePage)
		__asm
	{
		jmp p[356 * 4];
	}
}

// EngGetDriverName
extern "C" __declspec(naked) void __stdcall __E__357__()
{
	PROXY(EngGetDriverName)
		__asm
	{
		jmp p[357 * 4];
	}
}

// EngGetPrinterDataFileName
extern "C" __declspec(naked) void __stdcall __E__358__()
{
	PROXY(EngGetPrinterDataFileName)
		__asm
	{
		jmp p[358 * 4];
	}
}

// EngGradientFill
extern "C" __declspec(naked) void __stdcall __E__359__()
{
	PROXY(EngGradientFill)
		__asm
	{
		jmp p[359 * 4];
	}
}

// EngLineTo
extern "C" __declspec(naked) void __stdcall __E__360__()
{
	PROXY(EngLineTo)
		__asm
	{
		jmp p[360 * 4];
	}
}

// EngLoadModule
extern "C" __declspec(naked) void __stdcall __E__361__()
{
	PROXY(EngLoadModule)
		__asm
	{
		jmp p[361 * 4];
	}
}

// EngLockSurface
extern "C" __declspec(naked) void __stdcall __E__362__()
{
	PROXY(EngLockSurface)
		__asm
	{
		jmp p[362 * 4];
	}
}

// EngMarkBandingSurface
extern "C" __declspec(naked) void __stdcall __E__363__()
{
	PROXY(EngMarkBandingSurface)
		__asm
	{
		jmp p[363 * 4];
	}
}

// EngMultiByteToUnicodeN
extern "C" __declspec(naked) void __stdcall __E__364__()
{
	PROXY(EngMultiByteToUnicodeN)
		__asm
	{
		jmp p[364 * 4];
	}
}

// EngMultiByteToWideChar
extern "C" __declspec(naked) void __stdcall __E__365__()
{
	PROXY(EngMultiByteToWideChar)
		__asm
	{
		jmp p[365 * 4];
	}
}

// EngPaint
extern "C" __declspec(naked) void __stdcall __E__366__()
{
	PROXY(EngPaint)
		__asm
	{
		jmp p[366 * 4];
	}
}

// EngPlgBlt
extern "C" __declspec(naked) void __stdcall __E__367__()
{
	PROXY(EngPlgBlt)
		__asm
	{
		jmp p[367 * 4];
	}
}

// EngQueryEMFInfo
extern "C" __declspec(naked) void __stdcall __E__368__()
{
	PROXY(EngQueryEMFInfo)
		__asm
	{
		jmp p[368 * 4];
	}
}

// EngQueryLocalTime
extern "C" __declspec(naked) void __stdcall __E__369__()
{
	PROXY(EngQueryLocalTime)
		__asm
	{
		jmp p[369 * 4];
	}
}

// EngReleaseSemaphore
extern "C" __declspec(naked) void __stdcall __E__370__()
{
	PROXY(EngReleaseSemaphore)
		__asm
	{
		jmp p[370 * 4];
	}
}

// EngStretchBlt
extern "C" __declspec(naked) void __stdcall __E__371__()
{
	PROXY(EngStretchBlt)
		__asm
	{
		jmp p[371 * 4];
	}
}

// EngStretchBltROP
extern "C" __declspec(naked) void __stdcall __E__372__()
{
	PROXY(EngStretchBltROP)
		__asm
	{
		jmp p[372 * 4];
	}
}

// EngStrokeAndFillPath
extern "C" __declspec(naked) void __stdcall __E__373__()
{
	PROXY(EngStrokeAndFillPath)
		__asm
	{
		jmp p[373 * 4];
	}
}

// EngStrokePath
extern "C" __declspec(naked) void __stdcall __E__374__()
{
	PROXY(EngStrokePath)
		__asm
	{
		jmp p[374 * 4];
	}
}

// EngTextOut
extern "C" __declspec(naked) void __stdcall __E__375__()
{
	PROXY(EngTextOut)
		__asm
	{
		jmp p[375 * 4];
	}
}

// EngTransparentBlt
extern "C" __declspec(naked) void __stdcall __E__376__()
{
	PROXY(EngTransparentBlt)
		__asm
	{
		jmp p[376 * 4];
	}
}

// EngUnicodeToMultiByteN
extern "C" __declspec(naked) void __stdcall __E__377__()
{
	PROXY(EngUnicodeToMultiByteN)
		__asm
	{
		jmp p[377 * 4];
	}
}

// EngUnlockSurface
extern "C" __declspec(naked) void __stdcall __E__378__()
{
	PROXY(EngUnlockSurface)
		__asm
	{
		jmp p[378 * 4];
	}
}

// EngWideCharToMultiByte
extern "C" __declspec(naked) void __stdcall __E__379__()
{
	PROXY(EngWideCharToMultiByte)
		__asm
	{
		jmp p[379 * 4];
	}
}

// EnumEnhMetaFile
extern "C" __declspec(naked) void __stdcall __E__380__()
{
	PROXY(EnumEnhMetaFile)
		__asm
	{
		jmp p[380 * 4];
	}
}

// EnumFontFamiliesA
extern "C" __declspec(naked) void __stdcall __E__381__()
{
	PROXY(EnumFontFamiliesA)
		__asm
	{
		jmp p[381 * 4];
	}
}

// EnumFontFamiliesExA
extern "C" __declspec(naked) void __stdcall __E__382__()
{
	PROXY(EnumFontFamiliesExA)
		__asm
	{
		jmp p[382 * 4];
	}
}

// EnumFontFamiliesExW
extern "C" __declspec(naked) void __stdcall __E__383__()
{
	PROXY(EnumFontFamiliesExW)
		__asm
	{
		jmp p[383 * 4];
	}
}

// EnumFontFamiliesW
extern "C" __declspec(naked) void __stdcall __E__384__()
{
	PROXY(EnumFontFamiliesW)
		__asm
	{
		jmp p[384 * 4];
	}
}

// EnumFontsA
extern "C" __declspec(naked) void __stdcall __E__385__()
{
	PROXY(EnumFontsA)
		__asm
	{
		jmp p[385 * 4];
	}
}

// EnumFontsW
extern "C" __declspec(naked) void __stdcall __E__386__()
{
	PROXY(EnumFontsW)
		__asm
	{
		jmp p[386 * 4];
	}
}

// EnumICMProfilesA
extern "C" __declspec(naked) void __stdcall __E__387__()
{
	PROXY(EnumICMProfilesA)
		__asm
	{
		jmp p[387 * 4];
	}
}

// EnumICMProfilesW
extern "C" __declspec(naked) void __stdcall __E__388__()
{
	PROXY(EnumICMProfilesW)
		__asm
	{
		jmp p[388 * 4];
	}
}

// EnumMetaFile
extern "C" __declspec(naked) void __stdcall __E__389__()
{
	PROXY(EnumMetaFile)
		__asm
	{
		jmp p[389 * 4];
	}
}

// EnumObjects
extern "C" __declspec(naked) void __stdcall __E__390__()
{
	PROXY(EnumObjects)
		__asm
	{
		jmp p[390 * 4];
	}
}

// EqualRgn
extern "C" __declspec(naked) void __stdcall __E__391__()
{
	PROXY(EqualRgn)
		__asm
	{
		jmp p[391 * 4];
	}
}

// Escape
extern "C" __declspec(naked) void __stdcall __E__392__()
{
	PROXY(Escape)
		__asm
	{
		jmp p[392 * 4];
	}
}

// EudcLoadLinkW
extern "C" __declspec(naked) void __stdcall __E__393__()
{
	PROXY(EudcLoadLinkW)
		__asm
	{
		jmp p[393 * 4];
	}
}

// EudcUnloadLinkW
extern "C" __declspec(naked) void __stdcall __E__394__()
{
	PROXY(EudcUnloadLinkW)
		__asm
	{
		jmp p[394 * 4];
	}
}

// ExcludeClipRect
extern "C" __declspec(naked) void __stdcall __E__395__()
{
	PROXY(ExcludeClipRect)
		__asm
	{
		jmp p[395 * 4];
	}
}

// ExtCreatePen
extern "C" __declspec(naked) void __stdcall __E__396__()
{
	PROXY(ExtCreatePen)
		__asm
	{
		jmp p[396 * 4];
	}
}

// ExtCreateRegion
extern "C" __declspec(naked) void __stdcall __E__397__()
{
	PROXY(ExtCreateRegion)
		__asm
	{
		jmp p[397 * 4];
	}
}

// ExtEscape
extern "C" __declspec(naked) void __stdcall __E__398__()
{
	PROXY(ExtEscape)
		__asm
	{
		jmp p[398 * 4];
	}
}

// ExtFloodFill
extern "C" __declspec(naked) void __stdcall __E__399__()
{
	PROXY(ExtFloodFill)
		__asm
	{
		jmp p[399 * 4];
	}
}

// ExtSelectClipRgn
extern "C" __declspec(naked) void __stdcall __E__400__()
{
	PROXY(ExtSelectClipRgn)
		__asm
	{
		jmp p[400 * 4];
	}
}

// ExtTextOutA
extern "C" __declspec(naked) void __stdcall __E__401__()
{
	PROXY(ExtTextOutA)
		__asm
	{
		jmp p[401 * 4];
	}
}

// ExtTextOutW
extern "C" __declspec(naked) void __stdcall __E__402__()
{
	PROXY(ExtTextOutW)
		__asm
	{
		jmp p[402 * 4];
	}
}

// FONTOBJ_cGetAllGlyphHandles
extern "C" __declspec(naked) void __stdcall __E__403__()
{
	PROXY(FONTOBJ_cGetAllGlyphHandles)
		__asm
	{
		jmp p[403 * 4];
	}
}

// FONTOBJ_cGetGlyphs
extern "C" __declspec(naked) void __stdcall __E__404__()
{
	PROXY(FONTOBJ_cGetGlyphs)
		__asm
	{
		jmp p[404 * 4];
	}
}

// FONTOBJ_pQueryGlyphAttrs
extern "C" __declspec(naked) void __stdcall __E__405__()
{
	PROXY(FONTOBJ_pQueryGlyphAttrs)
		__asm
	{
		jmp p[405 * 4];
	}
}

// FONTOBJ_pfdg
extern "C" __declspec(naked) void __stdcall __E__406__()
{
	PROXY(FONTOBJ_pfdg)
		__asm
	{
		jmp p[406 * 4];
	}
}

// FONTOBJ_pifi
extern "C" __declspec(naked) void __stdcall __E__407__()
{
	PROXY(FONTOBJ_pifi)
		__asm
	{
		jmp p[407 * 4];
	}
}

// FONTOBJ_pvTrueTypeFontFile
extern "C" __declspec(naked) void __stdcall __E__408__()
{
	PROXY(FONTOBJ_pvTrueTypeFontFile)
		__asm
	{
		jmp p[408 * 4];
	}
}

// FONTOBJ_pxoGetXform
extern "C" __declspec(naked) void __stdcall __E__409__()
{
	PROXY(FONTOBJ_pxoGetXform)
		__asm
	{
		jmp p[409 * 4];
	}
}

// FONTOBJ_vGetInfo
extern "C" __declspec(naked) void __stdcall __E__410__()
{
	PROXY(FONTOBJ_vGetInfo)
		__asm
	{
		jmp p[410 * 4];
	}
}

// FillPath
extern "C" __declspec(naked) void __stdcall __E__411__()
{
	PROXY(FillPath)
		__asm
	{
		jmp p[411 * 4];
	}
}

// FillRgn
extern "C" __declspec(naked) void __stdcall __E__412__()
{
	PROXY(FillRgn)
		__asm
	{
		jmp p[412 * 4];
	}
}

// FixBrushOrgEx
extern "C" __declspec(naked) void __stdcall __E__413__()
{
	PROXY(FixBrushOrgEx)
		__asm
	{
		jmp p[413 * 4];
	}
}

// FlattenPath
extern "C" __declspec(naked) void __stdcall __E__414__()
{
	PROXY(FlattenPath)
		__asm
	{
		jmp p[414 * 4];
	}
}

// FloodFill
extern "C" __declspec(naked) void __stdcall __E__415__()
{
	PROXY(FloodFill)
		__asm
	{
		jmp p[415 * 4];
	}
}

// FontIsLinked
extern "C" __declspec(naked) void __stdcall __E__416__()
{
	PROXY(FontIsLinked)
		__asm
	{
		jmp p[416 * 4];
	}
}

// FrameRgn
extern "C" __declspec(naked) void __stdcall __E__417__()
{
	PROXY(FrameRgn)
		__asm
	{
		jmp p[417 * 4];
	}
}

// GdiAddFontResourceW
extern "C" __declspec(naked) void __stdcall __E__418__()
{
	PROXY(GdiAddFontResourceW)
		__asm
	{
		jmp p[418 * 4];
	}
}

// GdiAddGlsBounds
extern "C" __declspec(naked) void __stdcall __E__419__()
{
	PROXY(GdiAddGlsBounds)
		__asm
	{
		jmp p[419 * 4];
	}
}

// GdiAddGlsRecord
extern "C" __declspec(naked) void __stdcall __E__420__()
{
	PROXY(GdiAddGlsRecord)
		__asm
	{
		jmp p[420 * 4];
	}
}

// GdiAlphaBlend
extern "C" __declspec(naked) void __stdcall __E__421__()
{
	PROXY(GdiAlphaBlend)
		__asm
	{
		jmp p[421 * 4];
	}
}

// GdiArtificialDecrementDriver
extern "C" __declspec(naked) void __stdcall __E__422__()
{
	PROXY(GdiArtificialDecrementDriver)
		__asm
	{
		jmp p[422 * 4];
	}
}

// GdiCleanCacheDC
extern "C" __declspec(naked) void __stdcall __E__423__()
{
	PROXY(GdiCleanCacheDC)
		__asm
	{
		jmp p[423 * 4];
	}
}

// GdiClearStockObjectCache
extern "C" __declspec(naked) void __stdcall __E__424__()
{
	PROXY(GdiClearStockObjectCache)
		__asm
	{
		jmp p[424 * 4];
	}
}

// GdiComment
extern "C" __declspec(naked) void __stdcall __E__425__()
{
	PROXY(GdiComment)
		__asm
	{
		jmp p[425 * 4];
	}
}

// GdiConsoleTextOut
extern "C" __declspec(naked) void __stdcall __E__426__()
{
	PROXY(GdiConsoleTextOut)
		__asm
	{
		jmp p[426 * 4];
	}
}

// GdiConvertAndCheckDC
extern "C" __declspec(naked) void __stdcall __E__427__()
{
	PROXY(GdiConvertAndCheckDC)
		__asm
	{
		jmp p[427 * 4];
	}
}

// GdiConvertBitmap
extern "C" __declspec(naked) void __stdcall __E__428__()
{
	PROXY(GdiConvertBitmap)
		__asm
	{
		jmp p[428 * 4];
	}
}

// GdiConvertBitmapV5
extern "C" __declspec(naked) void __stdcall __E__429__()
{
	PROXY(GdiConvertBitmapV5)
		__asm
	{
		jmp p[429 * 4];
	}
}

// GdiConvertBrush
extern "C" __declspec(naked) void __stdcall __E__430__()
{
	PROXY(GdiConvertBrush)
		__asm
	{
		jmp p[430 * 4];
	}
}

// GdiConvertDC
extern "C" __declspec(naked) void __stdcall __E__431__()
{
	PROXY(GdiConvertDC)
		__asm
	{
		jmp p[431 * 4];
	}
}

// GdiConvertEnhMetaFile
extern "C" __declspec(naked) void __stdcall __E__432__()
{
	PROXY(GdiConvertEnhMetaFile)
		__asm
	{
		jmp p[432 * 4];
	}
}

// GdiConvertFont
extern "C" __declspec(naked) void __stdcall __E__433__()
{
	PROXY(GdiConvertFont)
		__asm
	{
		jmp p[433 * 4];
	}
}

// GdiConvertMetaFilePict
extern "C" __declspec(naked) void __stdcall __E__434__()
{
	PROXY(GdiConvertMetaFilePict)
		__asm
	{
		jmp p[434 * 4];
	}
}

// GdiConvertPalette
extern "C" __declspec(naked) void __stdcall __E__435__()
{
	PROXY(GdiConvertPalette)
		__asm
	{
		jmp p[435 * 4];
	}
}

// GdiConvertRegion
extern "C" __declspec(naked) void __stdcall __E__436__()
{
	PROXY(GdiConvertRegion)
		__asm
	{
		jmp p[436 * 4];
	}
}

// GdiConvertToDevmodeW
extern "C" __declspec(naked) void __stdcall __E__437__()
{
	PROXY(GdiConvertToDevmodeW)
		__asm
	{
		jmp p[437 * 4];
	}
}

// GdiCreateLocalEnhMetaFile
extern "C" __declspec(naked) void __stdcall __E__438__()
{
	PROXY(GdiCreateLocalEnhMetaFile)
		__asm
	{
		jmp p[438 * 4];
	}
}

// GdiCreateLocalMetaFilePict
extern "C" __declspec(naked) void __stdcall __E__439__()
{
	PROXY(GdiCreateLocalMetaFilePict)
		__asm
	{
		jmp p[439 * 4];
	}
}

// GdiDeleteLocalDC
extern "C" __declspec(naked) void __stdcall __E__440__()
{
	PROXY(GdiDeleteLocalDC)
		__asm
	{
		jmp p[440 * 4];
	}
}

// GdiDeleteSpoolFileHandle
extern "C" __declspec(naked) void __stdcall __E__441__()
{
	PROXY(GdiDeleteSpoolFileHandle)
		__asm
	{
		jmp p[441 * 4];
	}
}

// GdiDescribePixelFormat
extern "C" __declspec(naked) void __stdcall __E__442__()
{
	PROXY(GdiDescribePixelFormat)
		__asm
	{
		jmp p[442 * 4];
	}
}

// GdiDllInitialize
extern "C" __declspec(naked) void __stdcall __E__443__()
{
	PROXY(GdiDllInitialize)
		__asm
	{
		jmp p[443 * 4];
	}
}

// GdiDrawStream
extern "C" __declspec(naked) void __stdcall __E__444__()
{
	PROXY(GdiDrawStream)
		__asm
	{
		jmp p[444 * 4];
	}
}

// GdiEndDocEMF
extern "C" __declspec(naked) void __stdcall __E__445__()
{
	PROXY(GdiEndDocEMF)
		__asm
	{
		jmp p[445 * 4];
	}
}

// GdiEndPageEMF
extern "C" __declspec(naked) void __stdcall __E__446__()
{
	PROXY(GdiEndPageEMF)
		__asm
	{
		jmp p[446 * 4];
	}
}

// GdiEntry1
extern "C" __declspec(naked) void __stdcall __E__447__()
{
	PROXY(GdiEntry1)
		__asm
	{
		jmp p[447 * 4];
	}
}

// GdiEntry10
extern "C" __declspec(naked) void __stdcall __E__448__()
{
	PROXY(GdiEntry10)
		__asm
	{
		jmp p[448 * 4];
	}
}

// GdiEntry11
extern "C" __declspec(naked) void __stdcall __E__449__()
{
	PROXY(GdiEntry11)
		__asm
	{
		jmp p[449 * 4];
	}
}

// GdiEntry12
extern "C" __declspec(naked) void __stdcall __E__450__()
{
	PROXY(GdiEntry12)
		__asm
	{
		jmp p[450 * 4];
	}
}

// GdiEntry13
extern "C" __declspec(naked) void __stdcall __E__451__()
{
	PROXY(GdiEntry13)
		__asm
	{
		jmp p[451 * 4];
	}
}

// GdiEntry14
extern "C" __declspec(naked) void __stdcall __E__452__()
{
	PROXY(GdiEntry14)
		__asm
	{
		jmp p[452 * 4];
	}
}

// GdiEntry15
extern "C" __declspec(naked) void __stdcall __E__453__()
{
	PROXY(GdiEntry15)
		__asm
	{
		jmp p[453 * 4];
	}
}

// GdiEntry16
extern "C" __declspec(naked) void __stdcall __E__454__()
{
	PROXY(GdiEntry16)
		__asm
	{
		jmp p[454 * 4];
	}
}

// GdiEntry2
extern "C" __declspec(naked) void __stdcall __E__455__()
{
	PROXY(GdiEntry2)
		__asm
	{
		jmp p[455 * 4];
	}
}

// GdiEntry3
extern "C" __declspec(naked) void __stdcall __E__456__()
{
	PROXY(GdiEntry3)
		__asm
	{
		jmp p[456 * 4];
	}
}

// GdiEntry4
extern "C" __declspec(naked) void __stdcall __E__457__()
{
	PROXY(GdiEntry4)
		__asm
	{
		jmp p[457 * 4];
	}
}

// GdiEntry5
extern "C" __declspec(naked) void __stdcall __E__458__()
{
	PROXY(GdiEntry5)
		__asm
	{
		jmp p[458 * 4];
	}
}

// GdiEntry6
extern "C" __declspec(naked) void __stdcall __E__459__()
{
	PROXY(GdiEntry6)
		__asm
	{
		jmp p[459 * 4];
	}
}

// GdiEntry7
extern "C" __declspec(naked) void __stdcall __E__460__()
{
	PROXY(GdiEntry7)
		__asm
	{
		jmp p[460 * 4];
	}
}

// GdiEntry8
extern "C" __declspec(naked) void __stdcall __E__461__()
{
	PROXY(GdiEntry8)
		__asm
	{
		jmp p[461 * 4];
	}
}

// GdiEntry9
extern "C" __declspec(naked) void __stdcall __E__462__()
{
	PROXY(GdiEntry9)
		__asm
	{
		jmp p[462 * 4];
	}
}

// GdiFixUpHandle
extern "C" __declspec(naked) void __stdcall __E__463__()
{
	PROXY(GdiFixUpHandle)
		__asm
	{
		jmp p[463 * 4];
	}
}

// GdiFlush
extern "C" __declspec(naked) void __stdcall __E__464__()
{
	PROXY(GdiFlush)
		__asm
	{
		jmp p[464 * 4];
	}
}

// GdiFullscreenControl
extern "C" __declspec(naked) void __stdcall __E__465__()
{
	PROXY(GdiFullscreenControl)
		__asm
	{
		jmp p[465 * 4];
	}
}

// GdiGetBatchLimit
extern "C" __declspec(naked) void __stdcall __E__466__()
{
	PROXY(GdiGetBatchLimit)
		__asm
	{
		jmp p[466 * 4];
	}
}

// GdiGetBitmapBitsSize
extern "C" __declspec(naked) void __stdcall __E__467__()
{
	PROXY(GdiGetBitmapBitsSize)
		__asm
	{
		jmp p[467 * 4];
	}
}

// GdiGetCharDimensions
extern "C" __declspec(naked) void __stdcall __E__468__()
{
	PROXY(GdiGetCharDimensions)
		__asm
	{
		jmp p[468 * 4];
	}
}

// GdiGetCodePage
extern "C" __declspec(naked) void __stdcall __E__469__()
{
	PROXY(GdiGetCodePage)
		__asm
	{
		jmp p[469 * 4];
	}
}

// GdiGetDC
extern "C" __declspec(naked) void __stdcall __E__470__()
{
	PROXY(GdiGetDC)
		__asm
	{
		jmp p[470 * 4];
	}
}

// GdiGetDevmodeForPage
extern "C" __declspec(naked) void __stdcall __E__471__()
{
	PROXY(GdiGetDevmodeForPage)
		__asm
	{
		jmp p[471 * 4];
	}
}

// GdiGetLocalBrush
extern "C" __declspec(naked) void __stdcall __E__472__()
{
	PROXY(GdiGetLocalBrush)
		__asm
	{
		jmp p[472 * 4];
	}
}

// GdiGetLocalDC
extern "C" __declspec(naked) void __stdcall __E__473__()
{
	PROXY(GdiGetLocalDC)
		__asm
	{
		jmp p[473 * 4];
	}
}

// GdiGetLocalFont
extern "C" __declspec(naked) void __stdcall __E__474__()
{
	PROXY(GdiGetLocalFont)
		__asm
	{
		jmp p[474 * 4];
	}
}

// GdiGetPageCount
extern "C" __declspec(naked) void __stdcall __E__475__()
{
	PROXY(GdiGetPageCount)
		__asm
	{
		jmp p[475 * 4];
	}
}

// GdiGetPageHandle
extern "C" __declspec(naked) void __stdcall __E__476__()
{
	PROXY(GdiGetPageHandle)
		__asm
	{
		jmp p[476 * 4];
	}
}

// GdiGetSpoolFileHandle
extern "C" __declspec(naked) void __stdcall __E__477__()
{
	PROXY(GdiGetSpoolFileHandle)
		__asm
	{
		jmp p[477 * 4];
	}
}

// GdiGetSpoolMessage
extern "C" __declspec(naked) void __stdcall __E__478__()
{
	PROXY(GdiGetSpoolMessage)
		__asm
	{
		jmp p[478 * 4];
	}
}

// GdiGradientFill
extern "C" __declspec(naked) void __stdcall __E__479__()
{
	PROXY(GdiGradientFill)
		__asm
	{
		jmp p[479 * 4];
	}
}

// GdiInitSpool
extern "C" __declspec(naked) void __stdcall __E__480__()
{
	PROXY(GdiInitSpool)
		__asm
	{
		jmp p[480 * 4];
	}
}

// GdiInitializeLanguagePack
extern "C" __declspec(naked) void __stdcall __E__481__()
{
	PROXY(GdiInitializeLanguagePack)
		__asm
	{
		jmp p[481 * 4];
	}
}

// GdiIsMetaFileDC
extern "C" __declspec(naked) void __stdcall __E__482__()
{
	PROXY(GdiIsMetaFileDC)
		__asm
	{
		jmp p[482 * 4];
	}
}

// GdiIsMetaPrintDC
extern "C" __declspec(naked) void __stdcall __E__483__()
{
	PROXY(GdiIsMetaPrintDC)
		__asm
	{
		jmp p[483 * 4];
	}
}

// GdiIsPlayMetafileDC
extern "C" __declspec(naked) void __stdcall __E__484__()
{
	PROXY(GdiIsPlayMetafileDC)
		__asm
	{
		jmp p[484 * 4];
	}
}

// GdiIsScreenDC
extern "C" __declspec(naked) void __stdcall __E__485__()
{
	PROXY(GdiIsScreenDC)
		__asm
	{
		jmp p[485 * 4];
	}
}

// GdiIsUMPDSandboxingEnabled
extern "C" __declspec(naked) void __stdcall __E__486__()
{
	PROXY(GdiIsUMPDSandboxingEnabled)
		__asm
	{
		jmp p[486 * 4];
	}
}

// GdiLoadType1Fonts
extern "C" __declspec(naked) void __stdcall __E__487__()
{
	PROXY(GdiLoadType1Fonts)
		__asm
	{
		jmp p[487 * 4];
	}
}

// GdiPlayDCScript
extern "C" __declspec(naked) void __stdcall __E__488__()
{
	PROXY(GdiPlayDCScript)
		__asm
	{
		jmp p[488 * 4];
	}
}

// GdiPlayEMF
extern "C" __declspec(naked) void __stdcall __E__489__()
{
	PROXY(GdiPlayEMF)
		__asm
	{
		jmp p[489 * 4];
	}
}

// GdiPlayJournal
extern "C" __declspec(naked) void __stdcall __E__490__()
{
	PROXY(GdiPlayJournal)
		__asm
	{
		jmp p[490 * 4];
	}
}

// GdiPlayPageEMF
extern "C" __declspec(naked) void __stdcall __E__491__()
{
	PROXY(GdiPlayPageEMF)
		__asm
	{
		jmp p[491 * 4];
	}
}

// GdiPlayPrivatePageEMF
extern "C" __declspec(naked) void __stdcall __E__492__()
{
	PROXY(GdiPlayPrivatePageEMF)
		__asm
	{
		jmp p[492 * 4];
	}
}

// GdiPlayScript
extern "C" __declspec(naked) void __stdcall __E__493__()
{
	PROXY(GdiPlayScript)
		__asm
	{
		jmp p[493 * 4];
	}
}

// GdiPrinterThunk
extern "C" __declspec(naked) void __stdcall __E__494__()
{
	PROXY(GdiPrinterThunk)
		__asm
	{
		jmp p[494 * 4];
	}
}

// GdiProcessSetup
extern "C" __declspec(naked) void __stdcall __E__495__()
{
	PROXY(GdiProcessSetup)
		__asm
	{
		jmp p[495 * 4];
	}
}

// GdiQueryFonts
extern "C" __declspec(naked) void __stdcall __E__496__()
{
	PROXY(GdiQueryFonts)
		__asm
	{
		jmp p[496 * 4];
	}
}

// GdiQueryTable
extern "C" __declspec(naked) void __stdcall __E__497__()
{
	PROXY(GdiQueryTable)
		__asm
	{
		jmp p[497 * 4];
	}
}

// GdiRealizationInfo
extern "C" __declspec(naked) void __stdcall __E__498__()
{
	PROXY(GdiRealizationInfo)
		__asm
	{
		jmp p[498 * 4];
	}
}

// GdiReleaseDC
extern "C" __declspec(naked) void __stdcall __E__499__()
{
	PROXY(GdiReleaseDC)
		__asm
	{
		jmp p[499 * 4];
	}
}

// GdiReleaseLocalDC
extern "C" __declspec(naked) void __stdcall __E__500__()
{
	PROXY(GdiReleaseLocalDC)
		__asm
	{
		jmp p[500 * 4];
	}
}

// GdiResetDCEMF
extern "C" __declspec(naked) void __stdcall __E__501__()
{
	PROXY(GdiResetDCEMF)
		__asm
	{
		jmp p[501 * 4];
	}
}

// GdiSetAttrs
extern "C" __declspec(naked) void __stdcall __E__502__()
{
	PROXY(GdiSetAttrs)
		__asm
	{
		jmp p[502 * 4];
	}
}

// GdiSetBatchLimit
extern "C" __declspec(naked) void __stdcall __E__503__()
{
	PROXY(GdiSetBatchLimit)
		__asm
	{
		jmp p[503 * 4];
	}
}

// GdiSetLastError
extern "C" __declspec(naked) void __stdcall __E__504__()
{
	PROXY(GdiSetLastError)
		__asm
	{
		jmp p[504 * 4];
	}
}

// GdiSetPixelFormat
extern "C" __declspec(naked) void __stdcall __E__505__()
{
	PROXY(GdiSetPixelFormat)
		__asm
	{
		jmp p[505 * 4];
	}
}

// GdiSetServerAttr
extern "C" __declspec(naked) void __stdcall __E__506__()
{
	PROXY(GdiSetServerAttr)
		__asm
	{
		jmp p[506 * 4];
	}
}

// GdiStartDocEMF
extern "C" __declspec(naked) void __stdcall __E__507__()
{
	PROXY(GdiStartDocEMF)
		__asm
	{
		jmp p[507 * 4];
	}
}

// GdiStartPageEMF
extern "C" __declspec(naked) void __stdcall __E__508__()
{
	PROXY(GdiStartPageEMF)
		__asm
	{
		jmp p[508 * 4];
	}
}

// GdiSupportsFontChangeEvent
extern "C" __declspec(naked) void __stdcall __E__509__()
{
	PROXY(GdiSupportsFontChangeEvent)
		__asm
	{
		jmp p[509 * 4];
	}
}

// GdiSwapBuffers
extern "C" __declspec(naked) void __stdcall __E__510__()
{
	PROXY(GdiSwapBuffers)
		__asm
	{
		jmp p[510 * 4];
	}
}

// GdiTransparentBlt
extern "C" __declspec(naked) void __stdcall __E__511__()
{
	PROXY(GdiTransparentBlt)
		__asm
	{
		jmp p[511 * 4];
	}
}

// GdiValidateHandle
extern "C" __declspec(naked) void __stdcall __E__512__()
{
	PROXY(GdiValidateHandle)
		__asm
	{
		jmp p[512 * 4];
	}
}

// GetArcDirection
extern "C" __declspec(naked) void __stdcall __E__513__()
{
	PROXY(GetArcDirection)
		__asm
	{
		jmp p[513 * 4];
	}
}

// GetAspectRatioFilterEx
extern "C" __declspec(naked) void __stdcall __E__514__()
{
	PROXY(GetAspectRatioFilterEx)
		__asm
	{
		jmp p[514 * 4];
	}
}

// GetBitmapAttributes
extern "C" __declspec(naked) void __stdcall __E__515__()
{
	PROXY(GetBitmapAttributes)
		__asm
	{
		jmp p[515 * 4];
	}
}

// GetBitmapBits
extern "C" __declspec(naked) void __stdcall __E__516__()
{
	PROXY(GetBitmapBits)
		__asm
	{
		jmp p[516 * 4];
	}
}

// GetBitmapDimensionEx
extern "C" __declspec(naked) void __stdcall __E__517__()
{
	PROXY(GetBitmapDimensionEx)
		__asm
	{
		jmp p[517 * 4];
	}
}

// GetBkColor
extern "C" __declspec(naked) void __stdcall __E__518__()
{
	PROXY(GetBkColor)
		__asm
	{
		jmp p[518 * 4];
	}
}

// GetBkMode
extern "C" __declspec(naked) void __stdcall __E__519__()
{
	PROXY(GetBkMode)
		__asm
	{
		jmp p[519 * 4];
	}
}

// GetBoundsRect
extern "C" __declspec(naked) void __stdcall __E__520__()
{
	PROXY(GetBoundsRect)
		__asm
	{
		jmp p[520 * 4];
	}
}

// GetBrushAttributes
extern "C" __declspec(naked) void __stdcall __E__521__()
{
	PROXY(GetBrushAttributes)
		__asm
	{
		jmp p[521 * 4];
	}
}

// GetBrushOrgEx
extern "C" __declspec(naked) void __stdcall __E__522__()
{
	PROXY(GetBrushOrgEx)
		__asm
	{
		jmp p[522 * 4];
	}
}

// GetCOPPCompatibleOPMInformation
extern "C" __declspec(naked) void __stdcall __E__523__()
{
	PROXY(GetCOPPCompatibleOPMInformation)
		__asm
	{
		jmp p[523 * 4];
	}
}

// GetCertificate
extern "C" __declspec(naked) void __stdcall __E__524__()
{
	PROXY(GetCertificate)
		__asm
	{
		jmp p[524 * 4];
	}
}

// GetCertificateByHandle
extern "C" __declspec(naked) void __stdcall __E__525__()
{
	PROXY(GetCertificateByHandle)
		__asm
	{
		jmp p[525 * 4];
	}
}

// GetCertificateSize
extern "C" __declspec(naked) void __stdcall __E__526__()
{
	PROXY(GetCertificateSize)
		__asm
	{
		jmp p[526 * 4];
	}
}

// GetCertificateSizeByHandle
extern "C" __declspec(naked) void __stdcall __E__527__()
{
	PROXY(GetCertificateSizeByHandle)
		__asm
	{
		jmp p[527 * 4];
	}
}

// GetCharABCWidthsA
extern "C" __declspec(naked) void __stdcall __E__528__()
{
	PROXY(GetCharABCWidthsA)
		__asm
	{
		jmp p[528 * 4];
	}
}

// GetCharABCWidthsFloatA
extern "C" __declspec(naked) void __stdcall __E__529__()
{
	PROXY(GetCharABCWidthsFloatA)
		__asm
	{
		jmp p[529 * 4];
	}
}

// GetCharABCWidthsFloatW
extern "C" __declspec(naked) void __stdcall __E__530__()
{
	PROXY(GetCharABCWidthsFloatW)
		__asm
	{
		jmp p[530 * 4];
	}
}

// GetCharABCWidthsI
extern "C" __declspec(naked) void __stdcall __E__531__()
{
	PROXY(GetCharABCWidthsI)
		__asm
	{
		jmp p[531 * 4];
	}
}

// GetCharABCWidthsW
extern "C" __declspec(naked) void __stdcall __E__532__()
{
	PROXY(GetCharABCWidthsW)
		__asm
	{
		jmp p[532 * 4];
	}
}

// GetCharWidth32A
extern "C" __declspec(naked) void __stdcall __E__533__()
{
	PROXY(GetCharWidth32A)
		__asm
	{
		jmp p[533 * 4];
	}
}

// GetCharWidth32W
extern "C" __declspec(naked) void __stdcall __E__534__()
{
	PROXY(GetCharWidth32W)
		__asm
	{
		jmp p[534 * 4];
	}
}

// GetCharWidthA
extern "C" __declspec(naked) void __stdcall __E__535__()
{
	PROXY(GetCharWidthA)
		__asm
	{
		jmp p[535 * 4];
	}
}

// GetCharWidthFloatA
extern "C" __declspec(naked) void __stdcall __E__536__()
{
	PROXY(GetCharWidthFloatA)
		__asm
	{
		jmp p[536 * 4];
	}
}

// GetCharWidthFloatW
extern "C" __declspec(naked) void __stdcall __E__537__()
{
	PROXY(GetCharWidthFloatW)
		__asm
	{
		jmp p[537 * 4];
	}
}

// GetCharWidthI
extern "C" __declspec(naked) void __stdcall __E__538__()
{
	PROXY(GetCharWidthI)
		__asm
	{
		jmp p[538 * 4];
	}
}

// GetCharWidthInfo
extern "C" __declspec(naked) void __stdcall __E__539__()
{
	PROXY(GetCharWidthInfo)
		__asm
	{
		jmp p[539 * 4];
	}
}

// GetCharWidthW
extern "C" __declspec(naked) void __stdcall __E__540__()
{
	PROXY(GetCharWidthW)
		__asm
	{
		jmp p[540 * 4];
	}
}

// GetCharacterPlacementA
extern "C" __declspec(naked) void __stdcall __E__541__()
{
	PROXY(GetCharacterPlacementA)
		__asm
	{
		jmp p[541 * 4];
	}
}

// GetCharacterPlacementW
extern "C" __declspec(naked) void __stdcall __E__542__()
{
	PROXY(GetCharacterPlacementW)
		__asm
	{
		jmp p[542 * 4];
	}
}

// GetClipBox
extern "C" __declspec(naked) void __stdcall __E__543__()
{
	PROXY(GetClipBox)
		__asm
	{
		jmp p[543 * 4];
	}
}

// GetClipRgn
extern "C" __declspec(naked) void __stdcall __E__544__()
{
	PROXY(GetClipRgn)
		__asm
	{
		jmp p[544 * 4];
	}
}

// GetColorAdjustment
extern "C" __declspec(naked) void __stdcall __E__545__()
{
	PROXY(GetColorAdjustment)
		__asm
	{
		jmp p[545 * 4];
	}
}

// GetColorSpace
extern "C" __declspec(naked) void __stdcall __E__546__()
{
	PROXY(GetColorSpace)
		__asm
	{
		jmp p[546 * 4];
	}
}

// GetCurrentDpiInfo
extern "C" __declspec(naked) void __stdcall __E__547__()
{
	PROXY(GetCurrentDpiInfo)
		__asm
	{
		jmp p[547 * 4];
	}
}

// GetCurrentObject
extern "C" __declspec(naked) void __stdcall __E__548__()
{
	PROXY(GetCurrentObject)
		__asm
	{
		jmp p[548 * 4];
	}
}

// GetCurrentPositionEx
extern "C" __declspec(naked) void __stdcall __E__549__()
{
	PROXY(GetCurrentPositionEx)
		__asm
	{
		jmp p[549 * 4];
	}
}

// GetDCBrushColor
extern "C" __declspec(naked) void __stdcall __E__550__()
{
	PROXY(GetDCBrushColor)
		__asm
	{
		jmp p[550 * 4];
	}
}

// GetDCOrgEx
extern "C" __declspec(naked) void __stdcall __E__551__()
{
	PROXY(GetDCOrgEx)
		__asm
	{
		jmp p[551 * 4];
	}
}

// GetDCPenColor
extern "C" __declspec(naked) void __stdcall __E__552__()
{
	PROXY(GetDCPenColor)
		__asm
	{
		jmp p[552 * 4];
	}
}

// GetDIBColorTable
extern "C" __declspec(naked) void __stdcall __E__553__()
{
	PROXY(GetDIBColorTable)
		__asm
	{
		jmp p[553 * 4];
	}
}

// GetDIBits
extern "C" __declspec(naked) void __stdcall __E__554__()
{
	PROXY(GetDIBits)
		__asm
	{
		jmp p[554 * 4];
	}
}

// GetDeviceCaps
extern "C" __declspec(naked) void __stdcall __E__555__()
{
	PROXY(GetDeviceCaps)
		__asm
	{
		jmp p[555 * 4];
	}
}

// GetDeviceGammaRamp
extern "C" __declspec(naked) void __stdcall __E__556__()
{
	PROXY(GetDeviceGammaRamp)
		__asm
	{
		jmp p[556 * 4];
	}
}

// GetETM
extern "C" __declspec(naked) void __stdcall __E__557__()
{
	PROXY(GetETM)
		__asm
	{
		jmp p[557 * 4];
	}
}

// GetEUDCTimeStamp
extern "C" __declspec(naked) void __stdcall __E__558__()
{
	PROXY(GetEUDCTimeStamp)
		__asm
	{
		jmp p[558 * 4];
	}
}

// GetEUDCTimeStampExW
extern "C" __declspec(naked) void __stdcall __E__559__()
{
	PROXY(GetEUDCTimeStampExW)
		__asm
	{
		jmp p[559 * 4];
	}
}

// GetEnhMetaFileA
extern "C" __declspec(naked) void __stdcall __E__560__()
{
	PROXY(GetEnhMetaFileA)
		__asm
	{
		jmp p[560 * 4];
	}
}

// GetEnhMetaFileBits
extern "C" __declspec(naked) void __stdcall __E__561__()
{
	PROXY(GetEnhMetaFileBits)
		__asm
	{
		jmp p[561 * 4];
	}
}

// GetEnhMetaFileDescriptionA
extern "C" __declspec(naked) void __stdcall __E__562__()
{
	PROXY(GetEnhMetaFileDescriptionA)
		__asm
	{
		jmp p[562 * 4];
	}
}

// GetEnhMetaFileDescriptionW
extern "C" __declspec(naked) void __stdcall __E__563__()
{
	PROXY(GetEnhMetaFileDescriptionW)
		__asm
	{
		jmp p[563 * 4];
	}
}

// GetEnhMetaFileHeader
extern "C" __declspec(naked) void __stdcall __E__564__()
{
	PROXY(GetEnhMetaFileHeader)
		__asm
	{
		jmp p[564 * 4];
	}
}

// GetEnhMetaFilePaletteEntries
extern "C" __declspec(naked) void __stdcall __E__565__()
{
	PROXY(GetEnhMetaFilePaletteEntries)
		__asm
	{
		jmp p[565 * 4];
	}
}

// GetEnhMetaFilePixelFormat
extern "C" __declspec(naked) void __stdcall __E__566__()
{
	PROXY(GetEnhMetaFilePixelFormat)
		__asm
	{
		jmp p[566 * 4];
	}
}

// GetEnhMetaFileW
extern "C" __declspec(naked) void __stdcall __E__567__()
{
	PROXY(GetEnhMetaFileW)
		__asm
	{
		jmp p[567 * 4];
	}
}

// GetFontAssocStatus
extern "C" __declspec(naked) void __stdcall __E__568__()
{
	PROXY(GetFontAssocStatus)
		__asm
	{
		jmp p[568 * 4];
	}
}

// GetFontData
extern "C" __declspec(naked) void __stdcall __E__569__()
{
	PROXY(GetFontData)
		__asm
	{
		jmp p[569 * 4];
	}
}

// GetFontFileData
extern "C" __declspec(naked) void __stdcall __E__570__()
{
	PROXY(GetFontFileData)
		__asm
	{
		jmp p[570 * 4];
	}
}

// GetFontFileInfo
extern "C" __declspec(naked) void __stdcall __E__571__()
{
	PROXY(GetFontFileInfo)
		__asm
	{
		jmp p[571 * 4];
	}
}

// GetFontLanguageInfo
extern "C" __declspec(naked) void __stdcall __E__572__()
{
	PROXY(GetFontLanguageInfo)
		__asm
	{
		jmp p[572 * 4];
	}
}

// GetFontRealizationInfo
extern "C" __declspec(naked) void __stdcall __E__573__()
{
	PROXY(GetFontRealizationInfo)
		__asm
	{
		jmp p[573 * 4];
	}
}

// GetFontResourceInfoW
extern "C" __declspec(naked) void __stdcall __E__574__()
{
	PROXY(GetFontResourceInfoW)
		__asm
	{
		jmp p[574 * 4];
	}
}

// GetFontUnicodeRanges
extern "C" __declspec(naked) void __stdcall __E__575__()
{
	PROXY(GetFontUnicodeRanges)
		__asm
	{
		jmp p[575 * 4];
	}
}

// GetGlyphIndicesA
extern "C" __declspec(naked) void __stdcall __E__576__()
{
	PROXY(GetGlyphIndicesA)
		__asm
	{
		jmp p[576 * 4];
	}
}

// GetGlyphIndicesW
extern "C" __declspec(naked) void __stdcall __E__577__()
{
	PROXY(GetGlyphIndicesW)
		__asm
	{
		jmp p[577 * 4];
	}
}

// GetGlyphOutline
extern "C" __declspec(naked) void __stdcall __E__578__()
{
	PROXY(GetGlyphOutline)
		__asm
	{
		jmp p[578 * 4];
	}
}

// GetGlyphOutlineA
extern "C" __declspec(naked) void __stdcall __E__579__()
{
	PROXY(GetGlyphOutlineA)
		__asm
	{
		jmp p[579 * 4];
	}
}

// GetGlyphOutlineW
extern "C" __declspec(naked) void __stdcall __E__580__()
{
	PROXY(GetGlyphOutlineW)
		__asm
	{
		jmp p[580 * 4];
	}
}

// GetGlyphOutlineWow
extern "C" __declspec(naked) void __stdcall __E__581__()
{
	PROXY(GetGlyphOutlineWow)
		__asm
	{
		jmp p[581 * 4];
	}
}

// GetGraphicsMode
extern "C" __declspec(naked) void __stdcall __E__582__()
{
	PROXY(GetGraphicsMode)
		__asm
	{
		jmp p[582 * 4];
	}
}

// GetHFONT
extern "C" __declspec(naked) void __stdcall __E__583__()
{
	PROXY(GetHFONT)
		__asm
	{
		jmp p[583 * 4];
	}
}

// GetICMProfileA
extern "C" __declspec(naked) void __stdcall __E__584__()
{
	PROXY(GetICMProfileA)
		__asm
	{
		jmp p[584 * 4];
	}
}

// GetICMProfileW
extern "C" __declspec(naked) void __stdcall __E__585__()
{
	PROXY(GetICMProfileW)
		__asm
	{
		jmp p[585 * 4];
	}
}

// GetKerningPairs
extern "C" __declspec(naked) void __stdcall __E__586__()
{
	PROXY(GetKerningPairs)
		__asm
	{
		jmp p[586 * 4];
	}
}

// GetKerningPairsA
extern "C" __declspec(naked) void __stdcall __E__587__()
{
	PROXY(GetKerningPairsA)
		__asm
	{
		jmp p[587 * 4];
	}
}

// GetKerningPairsW
extern "C" __declspec(naked) void __stdcall __E__588__()
{
	PROXY(GetKerningPairsW)
		__asm
	{
		jmp p[588 * 4];
	}
}

// GetLayout
extern "C" __declspec(naked) void __stdcall __E__589__()
{
	PROXY(GetLayout)
		__asm
	{
		jmp p[589 * 4];
	}
}

// GetLogColorSpaceA
extern "C" __declspec(naked) void __stdcall __E__590__()
{
	PROXY(GetLogColorSpaceA)
		__asm
	{
		jmp p[590 * 4];
	}
}

// GetLogColorSpaceW
extern "C" __declspec(naked) void __stdcall __E__591__()
{
	PROXY(GetLogColorSpaceW)
		__asm
	{
		jmp p[591 * 4];
	}
}

// GetMapMode
extern "C" __declspec(naked) void __stdcall __E__592__()
{
	PROXY(GetMapMode)
		__asm
	{
		jmp p[592 * 4];
	}
}

// GetMetaFileA
extern "C" __declspec(naked) void __stdcall __E__593__()
{
	PROXY(GetMetaFileA)
		__asm
	{
		jmp p[593 * 4];
	}
}

// GetMetaFileBitsEx
extern "C" __declspec(naked) void __stdcall __E__594__()
{
	PROXY(GetMetaFileBitsEx)
		__asm
	{
		jmp p[594 * 4];
	}
}

// GetMetaFileW
extern "C" __declspec(naked) void __stdcall __E__595__()
{
	PROXY(GetMetaFileW)
		__asm
	{
		jmp p[595 * 4];
	}
}

// GetMetaRgn
extern "C" __declspec(naked) void __stdcall __E__596__()
{
	PROXY(GetMetaRgn)
		__asm
	{
		jmp p[596 * 4];
	}
}

// GetMiterLimit
extern "C" __declspec(naked) void __stdcall __E__597__()
{
	PROXY(GetMiterLimit)
		__asm
	{
		jmp p[597 * 4];
	}
}

// GetNearestColor
extern "C" __declspec(naked) void __stdcall __E__598__()
{
	PROXY(GetNearestColor)
		__asm
	{
		jmp p[598 * 4];
	}
}

// GetNearestPaletteIndex
extern "C" __declspec(naked) void __stdcall __E__599__()
{
	PROXY(GetNearestPaletteIndex)
		__asm
	{
		jmp p[599 * 4];
	}
}

// GetNumberOfPhysicalMonitors
extern "C" __declspec(naked) void __stdcall __E__600__()
{
	PROXY(GetNumberOfPhysicalMonitors)
		__asm
	{
		jmp p[600 * 4];
	}
}

// GetOPMInformation
extern "C" __declspec(naked) void __stdcall __E__601__()
{
	PROXY(GetOPMInformation)
		__asm
	{
		jmp p[601 * 4];
	}
}

// GetOPMRandomNumber
extern "C" __declspec(naked) void __stdcall __E__602__()
{
	PROXY(GetOPMRandomNumber)
		__asm
	{
		jmp p[602 * 4];
	}
}

// GetObjectA
extern "C" __declspec(naked) void __stdcall __E__603__()
{
	PROXY(GetObjectA)
		__asm
	{
		jmp p[603 * 4];
	}
}

// GetObjectType
extern "C" __declspec(naked) void __stdcall __E__604__()
{
	PROXY(GetObjectType)
		__asm
	{
		jmp p[604 * 4];
	}
}

// GetObjectW
extern "C" __declspec(naked) void __stdcall __E__605__()
{
	PROXY(GetObjectW)
		__asm
	{
		jmp p[605 * 4];
	}
}

// GetOutlineTextMetricsA
extern "C" __declspec(naked) void __stdcall __E__606__()
{
	PROXY(GetOutlineTextMetricsA)
		__asm
	{
		jmp p[606 * 4];
	}
}

// GetOutlineTextMetricsW
extern "C" __declspec(naked) void __stdcall __E__607__()
{
	PROXY(GetOutlineTextMetricsW)
		__asm
	{
		jmp p[607 * 4];
	}
}

// GetPaletteEntries
extern "C" __declspec(naked) void __stdcall __E__608__()
{
	PROXY(GetPaletteEntries)
		__asm
	{
		jmp p[608 * 4];
	}
}

// GetPath
extern "C" __declspec(naked) void __stdcall __E__609__()
{
	PROXY(GetPath)
		__asm
	{
		jmp p[609 * 4];
	}
}

// GetPhysicalMonitorDescription
extern "C" __declspec(naked) void __stdcall __E__610__()
{
	PROXY(GetPhysicalMonitorDescription)
		__asm
	{
		jmp p[610 * 4];
	}
}

// GetPhysicalMonitors
extern "C" __declspec(naked) void __stdcall __E__611__()
{
	PROXY(GetPhysicalMonitors)
		__asm
	{
		jmp p[611 * 4];
	}
}

// GetPixel
extern "C" __declspec(naked) void __stdcall __E__612__()
{
	PROXY(GetPixel)
		__asm
	{
		jmp p[612 * 4];
	}
}

// GetPixelFormat
extern "C" __declspec(naked) void __stdcall __E__613__()
{
	PROXY(GetPixelFormat)
		__asm
	{
		jmp p[613 * 4];
	}
}

// GetPolyFillMode
extern "C" __declspec(naked) void __stdcall __E__614__()
{
	PROXY(GetPolyFillMode)
		__asm
	{
		jmp p[614 * 4];
	}
}

// GetROP2
extern "C" __declspec(naked) void __stdcall __E__615__()
{
	PROXY(GetROP2)
		__asm
	{
		jmp p[615 * 4];
	}
}

// GetRandomRgn
extern "C" __declspec(naked) void __stdcall __E__616__()
{
	PROXY(GetRandomRgn)
		__asm
	{
		jmp p[616 * 4];
	}
}

// GetRasterizerCaps
extern "C" __declspec(naked) void __stdcall __E__617__()
{
	PROXY(GetRasterizerCaps)
		__asm
	{
		jmp p[617 * 4];
	}
}

// GetRegionData
extern "C" __declspec(naked) void __stdcall __E__618__()
{
	PROXY(GetRegionData)
		__asm
	{
		jmp p[618 * 4];
	}
}

// GetRelAbs
extern "C" __declspec(naked) void __stdcall __E__619__()
{
	PROXY(GetRelAbs)
		__asm
	{
		jmp p[619 * 4];
	}
}

// GetRgnBox
extern "C" __declspec(naked) void __stdcall __E__620__()
{
	PROXY(GetRgnBox)
		__asm
	{
		jmp p[620 * 4];
	}
}

// GetStockObject
extern "C" __declspec(naked) void __stdcall __E__621__()
{
	PROXY(GetStockObject)
		__asm
	{
		jmp p[621 * 4];
	}
}

// GetStretchBltMode
extern "C" __declspec(naked) void __stdcall __E__622__()
{
	PROXY(GetStretchBltMode)
		__asm
	{
		jmp p[622 * 4];
	}
}

// GetStringBitmapA
extern "C" __declspec(naked) void __stdcall __E__623__()
{
	PROXY(GetStringBitmapA)
		__asm
	{
		jmp p[623 * 4];
	}
}

// GetStringBitmapW
extern "C" __declspec(naked) void __stdcall __E__624__()
{
	PROXY(GetStringBitmapW)
		__asm
	{
		jmp p[624 * 4];
	}
}

// GetSuggestedOPMProtectedOutputArraySize
extern "C" __declspec(naked) void __stdcall __E__625__()
{
	PROXY(GetSuggestedOPMProtectedOutputArraySize)
		__asm
	{
		jmp p[625 * 4];
	}
}

// GetSystemPaletteEntries
extern "C" __declspec(naked) void __stdcall __E__626__()
{
	PROXY(GetSystemPaletteEntries)
		__asm
	{
		jmp p[626 * 4];
	}
}

// GetSystemPaletteUse
extern "C" __declspec(naked) void __stdcall __E__627__()
{
	PROXY(GetSystemPaletteUse)
		__asm
	{
		jmp p[627 * 4];
	}
}

// GetTextAlign
extern "C" __declspec(naked) void __stdcall __E__628__()
{
	PROXY(GetTextAlign)
		__asm
	{
		jmp p[628 * 4];
	}
}

// GetTextCharacterExtra
extern "C" __declspec(naked) void __stdcall __E__629__()
{
	PROXY(GetTextCharacterExtra)
		__asm
	{
		jmp p[629 * 4];
	}
}

// GetTextCharset
extern "C" __declspec(naked) void __stdcall __E__630__()
{
	PROXY(GetTextCharset)
		__asm
	{
		jmp p[630 * 4];
	}
}

// GetTextCharsetInfo
extern "C" __declspec(naked) void __stdcall __E__631__()
{
	PROXY(GetTextCharsetInfo)
		__asm
	{
		jmp p[631 * 4];
	}
}

// GetTextColor
extern "C" __declspec(naked) void __stdcall __E__632__()
{
	PROXY(GetTextColor)
		__asm
	{
		jmp p[632 * 4];
	}
}

// GetTextExtentExPointA
extern "C" __declspec(naked) void __stdcall __E__633__()
{
	PROXY(GetTextExtentExPointA)
		__asm
	{
		jmp p[633 * 4];
	}
}

// GetTextExtentExPointI
extern "C" __declspec(naked) void __stdcall __E__634__()
{
	PROXY(GetTextExtentExPointI)
		__asm
	{
		jmp p[634 * 4];
	}
}

// GetTextExtentExPointW
extern "C" __declspec(naked) void __stdcall __E__635__()
{
	PROXY(GetTextExtentExPointW)
		__asm
	{
		jmp p[635 * 4];
	}
}

// GetTextExtentExPointWPri
extern "C" __declspec(naked) void __stdcall __E__636__()
{
	PROXY(GetTextExtentExPointWPri)
		__asm
	{
		jmp p[636 * 4];
	}
}

// GetTextExtentPoint32A
extern "C" __declspec(naked) void __stdcall __E__637__()
{
	PROXY(GetTextExtentPoint32A)
		__asm
	{
		jmp p[637 * 4];
	}
}

// GetTextExtentPoint32W
extern "C" __declspec(naked) void __stdcall __E__638__()
{
	PROXY(GetTextExtentPoint32W)
		__asm
	{
		jmp p[638 * 4];
	}
}

// GetTextExtentPointA
extern "C" __declspec(naked) void __stdcall __E__639__()
{
	PROXY(GetTextExtentPointA)
		__asm
	{
		jmp p[639 * 4];
	}
}

// GetTextExtentPointI
extern "C" __declspec(naked) void __stdcall __E__640__()
{
	PROXY(GetTextExtentPointI)
		__asm
	{
		jmp p[640 * 4];
	}
}

// GetTextExtentPointW
extern "C" __declspec(naked) void __stdcall __E__641__()
{
	PROXY(GetTextExtentPointW)
		__asm
	{
		jmp p[641 * 4];
	}
}

// GetTextFaceA
extern "C" __declspec(naked) void __stdcall __E__642__()
{
	PROXY(GetTextFaceA)
		__asm
	{
		jmp p[642 * 4];
	}
}

// GetTextFaceAliasW
extern "C" __declspec(naked) void __stdcall __E__643__()
{
	PROXY(GetTextFaceAliasW)
		__asm
	{
		jmp p[643 * 4];
	}
}

// GetTextFaceW
extern "C" __declspec(naked) void __stdcall __E__644__()
{
	PROXY(GetTextFaceW)
		__asm
	{
		jmp p[644 * 4];
	}
}

// GetTextMetricsA
extern "C" __declspec(naked) void __stdcall __E__645__()
{
	PROXY(GetTextMetricsA)
		__asm
	{
		jmp p[645 * 4];
	}
}

// GetTextMetricsW
extern "C" __declspec(naked) void __stdcall __E__646__()
{
	PROXY(GetTextMetricsW)
		__asm
	{
		jmp p[646 * 4];
	}
}

// GetTransform
extern "C" __declspec(naked) void __stdcall __E__647__()
{
	PROXY(GetTransform)
		__asm
	{
		jmp p[647 * 4];
	}
}

// GetViewportExtEx
extern "C" __declspec(naked) void __stdcall __E__648__()
{
	PROXY(GetViewportExtEx)
		__asm
	{
		jmp p[648 * 4];
	}
}

// GetViewportOrgEx
extern "C" __declspec(naked) void __stdcall __E__649__()
{
	PROXY(GetViewportOrgEx)
		__asm
	{
		jmp p[649 * 4];
	}
}

// GetWinMetaFileBits
extern "C" __declspec(naked) void __stdcall __E__650__()
{
	PROXY(GetWinMetaFileBits)
		__asm
	{
		jmp p[650 * 4];
	}
}

// GetWindowExtEx
extern "C" __declspec(naked) void __stdcall __E__651__()
{
	PROXY(GetWindowExtEx)
		__asm
	{
		jmp p[651 * 4];
	}
}

// GetWindowOrgEx
extern "C" __declspec(naked) void __stdcall __E__652__()
{
	PROXY(GetWindowOrgEx)
		__asm
	{
		jmp p[652 * 4];
	}
}

// GetWorldTransform
extern "C" __declspec(naked) void __stdcall __E__653__()
{
	PROXY(GetWorldTransform)
		__asm
	{
		jmp p[653 * 4];
	}
}

// HT_Get8BPPFormatPalette
extern "C" __declspec(naked) void __stdcall __E__654__()
{
	PROXY(HT_Get8BPPFormatPalette)
		__asm
	{
		jmp p[654 * 4];
	}
}

// HT_Get8BPPMaskPalette
extern "C" __declspec(naked) void __stdcall __E__655__()
{
	PROXY(HT_Get8BPPMaskPalette)
		__asm
	{
		jmp p[655 * 4];
	}
}

// IntersectClipRect
extern "C" __declspec(naked) void __stdcall __E__656__()
{
	PROXY(IntersectClipRect)
		__asm
	{
		jmp p[656 * 4];
	}
}

// InvertRgn
extern "C" __declspec(naked) void __stdcall __E__657__()
{
	PROXY(InvertRgn)
		__asm
	{
		jmp p[657 * 4];
	}
}

// IsValidEnhMetaRecord
extern "C" __declspec(naked) void __stdcall __E__658__()
{
	PROXY(IsValidEnhMetaRecord)
		__asm
	{
		jmp p[658 * 4];
	}
}

// IsValidEnhMetaRecordOffExt
extern "C" __declspec(naked) void __stdcall __E__659__()
{
	PROXY(IsValidEnhMetaRecordOffExt)
		__asm
	{
		jmp p[659 * 4];
	}
}

// LPtoDP
extern "C" __declspec(naked) void __stdcall __E__660__()
{
	PROXY(LPtoDP)
		__asm
	{
		jmp p[660 * 4];
	}
}

// LineDDA
extern "C" __declspec(naked) void __stdcall __E__661__()
{
	PROXY(LineDDA)
		__asm
	{
		jmp p[661 * 4];
	}
}

// LineTo
extern "C" __declspec(naked) void __stdcall __E__662__()
{
	PROXY(LineTo)
		__asm
	{
		jmp p[662 * 4];
	}
}

// LpkDrawTextEx
extern "C" __declspec(naked) void __stdcall __E__663__()
{
	PROXY(LpkDrawTextEx)
		__asm
	{
		jmp p[663 * 4];
	}
}

// LpkEditControl
extern "C" __declspec(naked) void __stdcall __E__664__()
{
	PROXY(LpkEditControl)
		__asm
	{
		jmp p[664 * 4];
	}
}

// LpkExtTextOut
extern "C" __declspec(naked) void __stdcall __E__665__()
{
	PROXY(LpkExtTextOut)
		__asm
	{
		jmp p[665 * 4];
	}
}

// LpkGetCharacterPlacement
extern "C" __declspec(naked) void __stdcall __E__666__()
{
	PROXY(LpkGetCharacterPlacement)
		__asm
	{
		jmp p[666 * 4];
	}
}

// LpkGetTextExtentExPoint
extern "C" __declspec(naked) void __stdcall __E__667__()
{
	PROXY(LpkGetTextExtentExPoint)
		__asm
	{
		jmp p[667 * 4];
	}
}

// LpkInitialize
extern "C" __declspec(naked) void __stdcall __E__668__()
{
	PROXY(LpkInitialize)
		__asm
	{
		jmp p[668 * 4];
	}
}

// LpkPSMTextOut
extern "C" __declspec(naked) void __stdcall __E__669__()
{
	PROXY(LpkPSMTextOut)
		__asm
	{
		jmp p[669 * 4];
	}
}

// LpkPresent
extern "C" __declspec(naked) void __stdcall __E__670__()
{
	PROXY(LpkPresent)
		__asm
	{
		jmp p[670 * 4];
	}
}

// LpkTabbedTextOut
extern "C" __declspec(naked) void __stdcall __E__671__()
{
	PROXY(LpkTabbedTextOut)
		__asm
	{
		jmp p[671 * 4];
	}
}

// LpkUseGDIWidthCache
extern "C" __declspec(naked) void __stdcall __E__672__()
{
	PROXY(LpkUseGDIWidthCache)
		__asm
	{
		jmp p[672 * 4];
	}
}

// MaskBlt
extern "C" __declspec(naked) void __stdcall __E__673__()
{
	PROXY(MaskBlt)
		__asm
	{
		jmp p[673 * 4];
	}
}

// MirrorRgn
extern "C" __declspec(naked) void __stdcall __E__674__()
{
	PROXY(MirrorRgn)
		__asm
	{
		jmp p[674 * 4];
	}
}

// ModifyWorldTransform
extern "C" __declspec(naked) void __stdcall __E__675__()
{
	PROXY(ModifyWorldTransform)
		__asm
	{
		jmp p[675 * 4];
	}
}

// MoveToEx
extern "C" __declspec(naked) void __stdcall __E__676__()
{
	PROXY(MoveToEx)
		__asm
	{
		jmp p[676 * 4];
	}
}

// NamedEscape
extern "C" __declspec(naked) void __stdcall __E__677__()
{
	PROXY(NamedEscape)
		__asm
	{
		jmp p[677 * 4];
	}
}

// OffsetClipRgn
extern "C" __declspec(naked) void __stdcall __E__678__()
{
	PROXY(OffsetClipRgn)
		__asm
	{
		jmp p[678 * 4];
	}
}

// OffsetRgn
extern "C" __declspec(naked) void __stdcall __E__679__()
{
	PROXY(OffsetRgn)
		__asm
	{
		jmp p[679 * 4];
	}
}

// OffsetViewportOrgEx
extern "C" __declspec(naked) void __stdcall __E__680__()
{
	PROXY(OffsetViewportOrgEx)
		__asm
	{
		jmp p[680 * 4];
	}
}

// OffsetWindowOrgEx
extern "C" __declspec(naked) void __stdcall __E__681__()
{
	PROXY(OffsetWindowOrgEx)
		__asm
	{
		jmp p[681 * 4];
	}
}

// PATHOBJ_bEnum
extern "C" __declspec(naked) void __stdcall __E__682__()
{
	PROXY(PATHOBJ_bEnum)
		__asm
	{
		jmp p[682 * 4];
	}
}

// PATHOBJ_bEnumClipLines
extern "C" __declspec(naked) void __stdcall __E__683__()
{
	PROXY(PATHOBJ_bEnumClipLines)
		__asm
	{
		jmp p[683 * 4];
	}
}

// PATHOBJ_vEnumStart
extern "C" __declspec(naked) void __stdcall __E__684__()
{
	PROXY(PATHOBJ_vEnumStart)
		__asm
	{
		jmp p[684 * 4];
	}
}

// PATHOBJ_vEnumStartClipLines
extern "C" __declspec(naked) void __stdcall __E__685__()
{
	PROXY(PATHOBJ_vEnumStartClipLines)
		__asm
	{
		jmp p[685 * 4];
	}
}

// PATHOBJ_vGetBounds
extern "C" __declspec(naked) void __stdcall __E__686__()
{
	PROXY(PATHOBJ_vGetBounds)
		__asm
	{
		jmp p[686 * 4];
	}
}

// PaintRgn
extern "C" __declspec(naked) void __stdcall __E__687__()
{
	PROXY(PaintRgn)
		__asm
	{
		jmp p[687 * 4];
	}
}

// PatBlt
extern "C" __declspec(naked) void __stdcall __E__688__()
{
	PROXY(PatBlt)
		__asm
	{
		jmp p[688 * 4];
	}
}

// PathToRegion
extern "C" __declspec(naked) void __stdcall __E__689__()
{
	PROXY(PathToRegion)
		__asm
	{
		jmp p[689 * 4];
	}
}

// Pie
extern "C" __declspec(naked) void __stdcall __E__690__()
{
	PROXY(Pie)
		__asm
	{
		jmp p[690 * 4];
	}
}

// PlayEnhMetaFile
extern "C" __declspec(naked) void __stdcall __E__691__()
{
	PROXY(PlayEnhMetaFile)
		__asm
	{
		jmp p[691 * 4];
	}
}

// PlayEnhMetaFileRecord
extern "C" __declspec(naked) void __stdcall __E__692__()
{
	PROXY(PlayEnhMetaFileRecord)
		__asm
	{
		jmp p[692 * 4];
	}
}

// PlayMetaFile
extern "C" __declspec(naked) void __stdcall __E__693__()
{
	PROXY(PlayMetaFile)
		__asm
	{
		jmp p[693 * 4];
	}
}

// PlayMetaFileRecord
extern "C" __declspec(naked) void __stdcall __E__694__()
{
	PROXY(PlayMetaFileRecord)
		__asm
	{
		jmp p[694 * 4];
	}
}

// PlgBlt
extern "C" __declspec(naked) void __stdcall __E__695__()
{
	PROXY(PlgBlt)
		__asm
	{
		jmp p[695 * 4];
	}
}

// PolyBezier
extern "C" __declspec(naked) void __stdcall __E__696__()
{
	PROXY(PolyBezier)
		__asm
	{
		jmp p[696 * 4];
	}
}

// PolyBezierTo
extern "C" __declspec(naked) void __stdcall __E__697__()
{
	PROXY(PolyBezierTo)
		__asm
	{
		jmp p[697 * 4];
	}
}

// PolyDraw
extern "C" __declspec(naked) void __stdcall __E__698__()
{
	PROXY(PolyDraw)
		__asm
	{
		jmp p[698 * 4];
	}
}

// PolyPatBlt
extern "C" __declspec(naked) void __stdcall __E__699__()
{
	PROXY(PolyPatBlt)
		__asm
	{
		jmp p[699 * 4];
	}
}

// PolyPolygon
extern "C" __declspec(naked) void __stdcall __E__700__()
{
	PROXY(PolyPolygon)
		__asm
	{
		jmp p[700 * 4];
	}
}

// PolyPolyline
extern "C" __declspec(naked) void __stdcall __E__701__()
{
	PROXY(PolyPolyline)
		__asm
	{
		jmp p[701 * 4];
	}
}

// PolyTextOutA
extern "C" __declspec(naked) void __stdcall __E__702__()
{
	PROXY(PolyTextOutA)
		__asm
	{
		jmp p[702 * 4];
	}
}

// PolyTextOutW
extern "C" __declspec(naked) void __stdcall __E__703__()
{
	PROXY(PolyTextOutW)
		__asm
	{
		jmp p[703 * 4];
	}
}

// Polygon
extern "C" __declspec(naked) void __stdcall __E__704__()
{
	PROXY(Polygon)
		__asm
	{
		jmp p[704 * 4];
	}
}

// Polyline
extern "C" __declspec(naked) void __stdcall __E__705__()
{
	PROXY(Polyline)
		__asm
	{
		jmp p[705 * 4];
	}
}

// PolylineTo
extern "C" __declspec(naked) void __stdcall __E__706__()
{
	PROXY(PolylineTo)
		__asm
	{
		jmp p[706 * 4];
	}
}

// PtInRegion
extern "C" __declspec(naked) void __stdcall __E__707__()
{
	PROXY(PtInRegion)
		__asm
	{
		jmp p[707 * 4];
	}
}

// PtVisible
extern "C" __declspec(naked) void __stdcall __E__708__()
{
	PROXY(PtVisible)
		__asm
	{
		jmp p[708 * 4];
	}
}

// QueryFontAssocStatus
extern "C" __declspec(naked) void __stdcall __E__709__()
{
	PROXY(QueryFontAssocStatus)
		__asm
	{
		jmp p[709 * 4];
	}
}

// RealizePalette
extern "C" __declspec(naked) void __stdcall __E__710__()
{
	PROXY(RealizePalette)
		__asm
	{
		jmp p[710 * 4];
	}
}

// RectInRegion
extern "C" __declspec(naked) void __stdcall __E__711__()
{
	PROXY(RectInRegion)
		__asm
	{
		jmp p[711 * 4];
	}
}

// RectVisible
extern "C" __declspec(naked) void __stdcall __E__712__()
{
	PROXY(RectVisible)
		__asm
	{
		jmp p[712 * 4];
	}
}

// Rectangle
extern "C" __declspec(naked) void __stdcall __E__713__()
{
	PROXY(Rectangle)
		__asm
	{
		jmp p[713 * 4];
	}
}

// RemoveFontMemResourceEx
extern "C" __declspec(naked) void __stdcall __E__714__()
{
	PROXY(RemoveFontMemResourceEx)
		__asm
	{
		jmp p[714 * 4];
	}
}

// RemoveFontResourceA
extern "C" __declspec(naked) void __stdcall __E__715__()
{
	PROXY(RemoveFontResourceA)
		__asm
	{
		jmp p[715 * 4];
	}
}

// RemoveFontResourceExA
extern "C" __declspec(naked) void __stdcall __E__716__()
{
	PROXY(RemoveFontResourceExA)
		__asm
	{
		jmp p[716 * 4];
	}
}

// RemoveFontResourceExW
extern "C" __declspec(naked) void __stdcall __E__717__()
{
	PROXY(RemoveFontResourceExW)
		__asm
	{
		jmp p[717 * 4];
	}
}

// RemoveFontResourceTracking
extern "C" __declspec(naked) void __stdcall __E__718__()
{
	PROXY(RemoveFontResourceTracking)
		__asm
	{
		jmp p[718 * 4];
	}
}

// RemoveFontResourceW
extern "C" __declspec(naked) void __stdcall __E__719__()
{
	PROXY(RemoveFontResourceW)
		__asm
	{
		jmp p[719 * 4];
	}
}

// ResetDCA
extern "C" __declspec(naked) void __stdcall __E__720__()
{
	PROXY(ResetDCA)
		__asm
	{
		jmp p[720 * 4];
	}
}

// ResetDCW
extern "C" __declspec(naked) void __stdcall __E__721__()
{
	PROXY(ResetDCW)
		__asm
	{
		jmp p[721 * 4];
	}
}

// ResizePalette
extern "C" __declspec(naked) void __stdcall __E__722__()
{
	PROXY(ResizePalette)
		__asm
	{
		jmp p[722 * 4];
	}
}

// RestoreDC
extern "C" __declspec(naked) void __stdcall __E__723__()
{
	PROXY(RestoreDC)
		__asm
	{
		jmp p[723 * 4];
	}
}

// RoundRect
extern "C" __declspec(naked) void __stdcall __E__724__()
{
	PROXY(RoundRect)
		__asm
	{
		jmp p[724 * 4];
	}
}

// STROBJ_bEnum
extern "C" __declspec(naked) void __stdcall __E__725__()
{
	PROXY(STROBJ_bEnum)
		__asm
	{
		jmp p[725 * 4];
	}
}

// STROBJ_bEnumPositionsOnly
extern "C" __declspec(naked) void __stdcall __E__726__()
{
	PROXY(STROBJ_bEnumPositionsOnly)
		__asm
	{
		jmp p[726 * 4];
	}
}

// STROBJ_bGetAdvanceWidths
extern "C" __declspec(naked) void __stdcall __E__727__()
{
	PROXY(STROBJ_bGetAdvanceWidths)
		__asm
	{
		jmp p[727 * 4];
	}
}

// STROBJ_dwGetCodePage
extern "C" __declspec(naked) void __stdcall __E__728__()
{
	PROXY(STROBJ_dwGetCodePage)
		__asm
	{
		jmp p[728 * 4];
	}
}

// STROBJ_vEnumStart
extern "C" __declspec(naked) void __stdcall __E__729__()
{
	PROXY(STROBJ_vEnumStart)
		__asm
	{
		jmp p[729 * 4];
	}
}

// SaveDC
extern "C" __declspec(naked) void __stdcall __E__730__()
{
	PROXY(SaveDC)
		__asm
	{
		jmp p[730 * 4];
	}
}

// ScaleViewportExtEx
extern "C" __declspec(naked) void __stdcall __E__731__()
{
	PROXY(ScaleViewportExtEx)
		__asm
	{
		jmp p[731 * 4];
	}
}

// ScaleWindowExtEx
extern "C" __declspec(naked) void __stdcall __E__732__()
{
	PROXY(ScaleWindowExtEx)
		__asm
	{
		jmp p[732 * 4];
	}
}

// ScriptApplyDigitSubstitution
extern "C" __declspec(naked) void __stdcall __E__733__()
{
	PROXY(ScriptApplyDigitSubstitution)
		__asm
	{
		jmp p[733 * 4];
	}
}

// ScriptApplyLogicalWidth
extern "C" __declspec(naked) void __stdcall __E__734__()
{
	PROXY(ScriptApplyLogicalWidth)
		__asm
	{
		jmp p[734 * 4];
	}
}

// ScriptBreak
extern "C" __declspec(naked) void __stdcall __E__735__()
{
	PROXY(ScriptBreak)
		__asm
	{
		jmp p[735 * 4];
	}
}

// ScriptCPtoX
extern "C" __declspec(naked) void __stdcall __E__736__()
{
	PROXY(ScriptCPtoX)
		__asm
	{
		jmp p[736 * 4];
	}
}

// ScriptCacheGetHeight
extern "C" __declspec(naked) void __stdcall __E__737__()
{
	PROXY(ScriptCacheGetHeight)
		__asm
	{
		jmp p[737 * 4];
	}
}

// ScriptFreeCache
extern "C" __declspec(naked) void __stdcall __E__738__()
{
	PROXY(ScriptFreeCache)
		__asm
	{
		jmp p[738 * 4];
	}
}

// ScriptGetCMap
extern "C" __declspec(naked) void __stdcall __E__739__()
{
	PROXY(ScriptGetCMap)
		__asm
	{
		jmp p[739 * 4];
	}
}

// ScriptGetFontAlternateGlyphs
extern "C" __declspec(naked) void __stdcall __E__740__()
{
	PROXY(ScriptGetFontAlternateGlyphs)
		__asm
	{
		jmp p[740 * 4];
	}
}

// ScriptGetFontFeatureTags
extern "C" __declspec(naked) void __stdcall __E__741__()
{
	PROXY(ScriptGetFontFeatureTags)
		__asm
	{
		jmp p[741 * 4];
	}
}

// ScriptGetFontLanguageTags
extern "C" __declspec(naked) void __stdcall __E__742__()
{
	PROXY(ScriptGetFontLanguageTags)
		__asm
	{
		jmp p[742 * 4];
	}
}

// ScriptGetFontProperties
extern "C" __declspec(naked) void __stdcall __E__743__()
{
	PROXY(ScriptGetFontProperties)
		__asm
	{
		jmp p[743 * 4];
	}
}

// ScriptGetFontScriptTags
extern "C" __declspec(naked) void __stdcall __E__744__()
{
	PROXY(ScriptGetFontScriptTags)
		__asm
	{
		jmp p[744 * 4];
	}
}

// ScriptGetGlyphABCWidth
extern "C" __declspec(naked) void __stdcall __E__745__()
{
	PROXY(ScriptGetGlyphABCWidth)
		__asm
	{
		jmp p[745 * 4];
	}
}

// ScriptGetLogicalWidths
extern "C" __declspec(naked) void __stdcall __E__746__()
{
	PROXY(ScriptGetLogicalWidths)
		__asm
	{
		jmp p[746 * 4];
	}
}

// ScriptGetProperties
extern "C" __declspec(naked) void __stdcall __E__747__()
{
	PROXY(ScriptGetProperties)
		__asm
	{
		jmp p[747 * 4];
	}
}

// ScriptIsComplex
extern "C" __declspec(naked) void __stdcall __E__748__()
{
	PROXY(ScriptIsComplex)
		__asm
	{
		jmp p[748 * 4];
	}
}

// ScriptItemize
extern "C" __declspec(naked) void __stdcall __E__749__()
{
	PROXY(ScriptItemize)
		__asm
	{
		jmp p[749 * 4];
	}
}

// ScriptItemizeOpenType
extern "C" __declspec(naked) void __stdcall __E__750__()
{
	PROXY(ScriptItemizeOpenType)
		__asm
	{
		jmp p[750 * 4];
	}
}

// ScriptJustify
extern "C" __declspec(naked) void __stdcall __E__751__()
{
	PROXY(ScriptJustify)
		__asm
	{
		jmp p[751 * 4];
	}
}

// ScriptLayout
extern "C" __declspec(naked) void __stdcall __E__752__()
{
	PROXY(ScriptLayout)
		__asm
	{
		jmp p[752 * 4];
	}
}

// ScriptPlace
extern "C" __declspec(naked) void __stdcall __E__753__()
{
	PROXY(ScriptPlace)
		__asm
	{
		jmp p[753 * 4];
	}
}

// ScriptPlaceOpenType
extern "C" __declspec(naked) void __stdcall __E__754__()
{
	PROXY(ScriptPlaceOpenType)
		__asm
	{
		jmp p[754 * 4];
	}
}

// ScriptPositionSingleGlyph
extern "C" __declspec(naked) void __stdcall __E__755__()
{
	PROXY(ScriptPositionSingleGlyph)
		__asm
	{
		jmp p[755 * 4];
	}
}

// ScriptRecordDigitSubstitution
extern "C" __declspec(naked) void __stdcall __E__756__()
{
	PROXY(ScriptRecordDigitSubstitution)
		__asm
	{
		jmp p[756 * 4];
	}
}

// ScriptShape
extern "C" __declspec(naked) void __stdcall __E__757__()
{
	PROXY(ScriptShape)
		__asm
	{
		jmp p[757 * 4];
	}
}

// ScriptShapeOpenType
extern "C" __declspec(naked) void __stdcall __E__758__()
{
	PROXY(ScriptShapeOpenType)
		__asm
	{
		jmp p[758 * 4];
	}
}

// ScriptStringAnalyse
extern "C" __declspec(naked) void __stdcall __E__759__()
{
	PROXY(ScriptStringAnalyse)
		__asm
	{
		jmp p[759 * 4];
	}
}

// ScriptStringCPtoX
extern "C" __declspec(naked) void __stdcall __E__760__()
{
	PROXY(ScriptStringCPtoX)
		__asm
	{
		jmp p[760 * 4];
	}
}

// ScriptStringFree
extern "C" __declspec(naked) void __stdcall __E__761__()
{
	PROXY(ScriptStringFree)
		__asm
	{
		jmp p[761 * 4];
	}
}

// ScriptStringGetLogicalWidths
extern "C" __declspec(naked) void __stdcall __E__762__()
{
	PROXY(ScriptStringGetLogicalWidths)
		__asm
	{
		jmp p[762 * 4];
	}
}

// ScriptStringGetOrder
extern "C" __declspec(naked) void __stdcall __E__763__()
{
	PROXY(ScriptStringGetOrder)
		__asm
	{
		jmp p[763 * 4];
	}
}

// ScriptStringOut
extern "C" __declspec(naked) void __stdcall __E__764__()
{
	PROXY(ScriptStringOut)
		__asm
	{
		jmp p[764 * 4];
	}
}

// ScriptStringValidate
extern "C" __declspec(naked) void __stdcall __E__765__()
{
	PROXY(ScriptStringValidate)
		__asm
	{
		jmp p[765 * 4];
	}
}

// ScriptStringXtoCP
extern "C" __declspec(naked) void __stdcall __E__766__()
{
	PROXY(ScriptStringXtoCP)
		__asm
	{
		jmp p[766 * 4];
	}
}

// ScriptString_pLogAttr
extern "C" __declspec(naked) void __stdcall __E__767__()
{
	PROXY(ScriptString_pLogAttr)
		__asm
	{
		jmp p[767 * 4];
	}
}

// ScriptString_pSize
extern "C" __declspec(naked) void __stdcall __E__768__()
{
	PROXY(ScriptString_pSize)
		__asm
	{
		jmp p[768 * 4];
	}
}

// ScriptString_pcOutChars
extern "C" __declspec(naked) void __stdcall __E__769__()
{
	PROXY(ScriptString_pcOutChars)
		__asm
	{
		jmp p[769 * 4];
	}
}

// ScriptSubstituteSingleGlyph
extern "C" __declspec(naked) void __stdcall __E__770__()
{
	PROXY(ScriptSubstituteSingleGlyph)
		__asm
	{
		jmp p[770 * 4];
	}
}

// ScriptTextOut
extern "C" __declspec(naked) void __stdcall __E__771__()
{
	PROXY(ScriptTextOut)
		__asm
	{
		jmp p[771 * 4];
	}
}

// ScriptXtoCP
extern "C" __declspec(naked) void __stdcall __E__772__()
{
	PROXY(ScriptXtoCP)
		__asm
	{
		jmp p[772 * 4];
	}
}

// SelectBrushLocal
extern "C" __declspec(naked) void __stdcall __E__773__()
{
	PROXY(SelectBrushLocal)
		__asm
	{
		jmp p[773 * 4];
	}
}

// SelectClipPath
extern "C" __declspec(naked) void __stdcall __E__774__()
{
	PROXY(SelectClipPath)
		__asm
	{
		jmp p[774 * 4];
	}
}

// SelectClipRgn
extern "C" __declspec(naked) void __stdcall __E__775__()
{
	PROXY(SelectClipRgn)
		__asm
	{
		jmp p[775 * 4];
	}
}

// SelectFontLocal
extern "C" __declspec(naked) void __stdcall __E__776__()
{
	PROXY(SelectFontLocal)
		__asm
	{
		jmp p[776 * 4];
	}
}

// SelectObject
extern "C" __declspec(naked) void __stdcall __E__777__()
{
	PROXY(SelectObject)
		__asm
	{
		jmp p[777 * 4];
	}
}

// SelectPalette
extern "C" __declspec(naked) void __stdcall __E__778__()
{
	PROXY(SelectPalette)
		__asm
	{
		jmp p[778 * 4];
	}
}

// SetAbortProc
extern "C" __declspec(naked) void __stdcall __E__779__()
{
	PROXY(SetAbortProc)
		__asm
	{
		jmp p[779 * 4];
	}
}

// SetArcDirection
extern "C" __declspec(naked) void __stdcall __E__780__()
{
	PROXY(SetArcDirection)
		__asm
	{
		jmp p[780 * 4];
	}
}

// SetBitmapAttributes
extern "C" __declspec(naked) void __stdcall __E__781__()
{
	PROXY(SetBitmapAttributes)
		__asm
	{
		jmp p[781 * 4];
	}
}

// SetBitmapBits
extern "C" __declspec(naked) void __stdcall __E__782__()
{
	PROXY(SetBitmapBits)
		__asm
	{
		jmp p[782 * 4];
	}
}

// SetBitmapDimensionEx
extern "C" __declspec(naked) void __stdcall __E__783__()
{
	PROXY(SetBitmapDimensionEx)
		__asm
	{
		jmp p[783 * 4];
	}
}

// SetBkColor
extern "C" int __E__784__( // !!!
	_In_ HDC hdc,
	_In_ int iBkMode
) {
	PROXY(SetBkColor)
		
	typedef decltype(&__E__784__) F;

	F _SetBkColor = (F)p[784];

	return OPAQUE;
}

// SetBkMode
extern "C" int WINAPI __E__785__(
	_In_ HDC hdc,
	_In_ int iBkMode
	) {
	PROXY(SetBkColor)

	typedef decltype(&__E__785__) F;

	F _SetBkColor = (F)p[785];

	return OPAQUE;
}

// SetBoundsRect
extern "C" __declspec(naked) void __stdcall __E__786__()
{
	PROXY(SetBoundsRect)
		__asm
	{
		jmp p[786 * 4];
	}
}

// SetBrushAttributes
extern "C" __declspec(naked) void __stdcall __E__787__()
{
	PROXY(SetBrushAttributes)
		__asm
	{
		jmp p[787 * 4];
	}
}

// SetBrushOrgEx
extern "C" __declspec(naked) void __stdcall __E__788__()
{
	PROXY(SetBrushOrgEx)
		__asm
	{
		jmp p[788 * 4];
	}
}

// SetColorAdjustment
extern "C" __declspec(naked) void __stdcall __E__789__()
{
	PROXY(SetColorAdjustment)
		__asm
	{
		jmp p[789 * 4];
	}
}

// SetColorSpace
extern "C" __declspec(naked) void __stdcall __E__790__()
{
	PROXY(SetColorSpace)
		__asm
	{
		jmp p[790 * 4];
	}
}

// SetDCBrushColor
extern "C" __declspec(naked) void __stdcall __E__791__()
{
	PROXY(SetDCBrushColor)
		__asm
	{
		jmp p[791 * 4];
	}
}

// SetDCPenColor
extern "C" __declspec(naked) void __stdcall __E__792__()
{
	PROXY(SetDCPenColor)
		__asm
	{
		jmp p[792 * 4];
	}
}

// SetDIBColorTable
extern "C" __declspec(naked) void __stdcall __E__793__()
{
	PROXY(SetDIBColorTable)
		__asm
	{
		jmp p[793 * 4];
	}
}

// SetDIBits
extern "C" __declspec(naked) void __stdcall __E__794__()
{
	PROXY(SetDIBits)
		__asm
	{
		jmp p[794 * 4];
	}
}

// SetDIBitsToDevice
extern "C" __declspec(naked) void __stdcall __E__795__()
{
	PROXY(SetDIBitsToDevice)
		__asm
	{
		jmp p[795 * 4];
	}
}

// SetDeviceGammaRamp
extern "C" __declspec(naked) void __stdcall __E__796__()
{
	PROXY(SetDeviceGammaRamp)
		__asm
	{
		jmp p[796 * 4];
	}
}

// SetEnhMetaFileBits
extern "C" __declspec(naked) void __stdcall __E__797__()
{
	PROXY(SetEnhMetaFileBits)
		__asm
	{
		jmp p[797 * 4];
	}
}

// SetFontEnumeration
extern "C" __declspec(naked) void __stdcall __E__798__()
{
	PROXY(SetFontEnumeration)
		__asm
	{
		jmp p[798 * 4];
	}
}

// SetGraphicsMode
extern "C" __declspec(naked) void __stdcall __E__799__()
{
	PROXY(SetGraphicsMode)
		__asm
	{
		jmp p[799 * 4];
	}
}

// SetICMMode
extern "C" __declspec(naked) void __stdcall __E__800__()
{
	PROXY(SetICMMode)
		__asm
	{
		jmp p[800 * 4];
	}
}

// SetICMProfileA
extern "C" __declspec(naked) void __stdcall __E__801__()
{
	PROXY(SetICMProfileA)
		__asm
	{
		jmp p[801 * 4];
	}
}

// SetICMProfileW
extern "C" __declspec(naked) void __stdcall __E__802__()
{
	PROXY(SetICMProfileW)
		__asm
	{
		jmp p[802 * 4];
	}
}

// SetLayout
extern "C" __declspec(naked) void __stdcall __E__803__()
{
	PROXY(SetLayout)
		__asm
	{
		jmp p[803 * 4];
	}
}

// SetLayoutWidth
extern "C" __declspec(naked) void __stdcall __E__804__()
{
	PROXY(SetLayoutWidth)
		__asm
	{
		jmp p[804 * 4];
	}
}

// SetMagicColors
extern "C" __declspec(naked) void __stdcall __E__805__()
{
	PROXY(SetMagicColors)
		__asm
	{
		jmp p[805 * 4];
	}
}

// SetMapMode
extern "C" __declspec(naked) void __stdcall __E__806__()
{
	PROXY(SetMapMode)
		__asm
	{
		jmp p[806 * 4];
	}
}

// SetMapperFlags
extern "C" __declspec(naked) void __stdcall __E__807__()
{
	PROXY(SetMapperFlags)
		__asm
	{
		jmp p[807 * 4];
	}
}

// SetMetaFileBitsEx
extern "C" __declspec(naked) void __stdcall __E__808__()
{
	PROXY(SetMetaFileBitsEx)
		__asm
	{
		jmp p[808 * 4];
	}
}

// SetMetaRgn
extern "C" __declspec(naked) void __stdcall __E__809__()
{
	PROXY(SetMetaRgn)
		__asm
	{
		jmp p[809 * 4];
	}
}

// SetMiterLimit
extern "C" __declspec(naked) void __stdcall __E__810__()
{
	PROXY(SetMiterLimit)
		__asm
	{
		jmp p[810 * 4];
	}
}

// SetOPMSigningKeyAndSequenceNumbers
extern "C" __declspec(naked) void __stdcall __E__811__()
{
	PROXY(SetOPMSigningKeyAndSequenceNumbers)
		__asm
	{
		jmp p[811 * 4];
	}
}

// SetPaletteEntries
extern "C" __declspec(naked) void __stdcall __E__812__()
{
	PROXY(SetPaletteEntries)
		__asm
	{
		jmp p[812 * 4];
	}
}

// SetPixel
extern "C" __declspec(naked) void __stdcall __E__813__()
{
	PROXY(SetPixel)
		__asm
	{
		jmp p[813 * 4];
	}
}

// SetPixelFormat
extern "C" __declspec(naked) void __stdcall __E__814__()
{
	PROXY(SetPixelFormat)
		__asm
	{
		jmp p[814 * 4];
	}
}

// SetPixelV
extern "C" __declspec(naked) void __stdcall __E__815__()
{
	PROXY(SetPixelV)
		__asm
	{
		jmp p[815 * 4];
	}
}

// SetPolyFillMode
extern "C" __declspec(naked) void __stdcall __E__816__()
{
	PROXY(SetPolyFillMode)
		__asm
	{
		jmp p[816 * 4];
	}
}

// SetROP2
extern "C" __declspec(naked) void __stdcall __E__817__()
{
	PROXY(SetROP2)
		__asm
	{
		jmp p[817 * 4];
	}
}

// SetRectRgn
extern "C" __declspec(naked) void __stdcall __E__818__()
{
	PROXY(SetRectRgn)
		__asm
	{
		jmp p[818 * 4];
	}
}

// SetRelAbs
extern "C" __declspec(naked) void __stdcall __E__819__()
{
	PROXY(SetRelAbs)
		__asm
	{
		jmp p[819 * 4];
	}
}

// SetStretchBltMode
extern "C" __declspec(naked) void __stdcall __E__820__()
{
	PROXY(SetStretchBltMode)
		__asm
	{
		jmp p[820 * 4];
	}
}

// SetSystemPaletteUse
extern "C" __declspec(naked) void __stdcall __E__821__()
{
	PROXY(SetSystemPaletteUse)
		__asm
	{
		jmp p[821 * 4];
	}
}

// SetTextAlign
extern "C" __declspec(naked) void __stdcall __E__822__()
{
	PROXY(SetTextAlign)
		__asm
	{
		jmp p[822 * 4];
	}
}

// SetTextCharacterExtra
extern "C" __declspec(naked) void __stdcall __E__823__()
{
	PROXY(SetTextCharacterExtra)
		__asm
	{
		jmp p[823 * 4];
	}
}

// SetTextColor
extern "C" COLORREF WINAPI __E__824__(
	_In_ HDC      hdc,
	_In_ COLORREF crColor
){
	PROXY(SetTextColor)
	
	typedef decltype(&__E__824__) F;

	F _SetTextColor = (F)p[824];

	return 0;
}

// SetTextJustification
extern "C" __declspec(naked) void __stdcall __E__825__()
{
	PROXY(SetTextJustification)
		__asm
	{
		jmp p[825 * 4];
	}
}

// SetViewportExtEx
extern "C" __declspec(naked) void __stdcall __E__826__()
{
	PROXY(SetViewportExtEx)
		__asm
	{
		jmp p[826 * 4];
	}
}

// SetViewportOrgEx
extern "C" __declspec(naked) void __stdcall __E__827__()
{
	PROXY(SetViewportOrgEx)
		__asm
	{
		jmp p[827 * 4];
	}
}

// SetVirtualResolution
extern "C" __declspec(naked) void __stdcall __E__828__()
{
	PROXY(SetVirtualResolution)
		__asm
	{
		jmp p[828 * 4];
	}
}

// SetWinMetaFileBits
extern "C" __declspec(naked) void __stdcall __E__829__()
{
	PROXY(SetWinMetaFileBits)
		__asm
	{
		jmp p[829 * 4];
	}
}

// SetWindowExtEx
extern "C" __declspec(naked) void __stdcall __E__830__()
{
	PROXY(SetWindowExtEx)
		__asm
	{
		jmp p[830 * 4];
	}
}

// SetWindowOrgEx
extern "C" __declspec(naked) void __stdcall __E__831__()
{
	PROXY(SetWindowOrgEx)
		__asm
	{
		jmp p[831 * 4];
	}
}

// SetWorldTransform
extern "C" __declspec(naked) void __stdcall __E__832__()
{
	PROXY(SetWorldTransform)
		__asm
	{
		jmp p[832 * 4];
	}
}

// StartDocA
extern "C" __declspec(naked) void __stdcall __E__833__()
{
	PROXY(StartDocA)
		__asm
	{
		jmp p[833 * 4];
	}
}

// StartDocW
extern "C" __declspec(naked) void __stdcall __E__834__()
{
	PROXY(StartDocW)
		__asm
	{
		jmp p[834 * 4];
	}
}

// StartFormPage
extern "C" __declspec(naked) void __stdcall __E__835__()
{
	PROXY(StartFormPage)
		__asm
	{
		jmp p[835 * 4];
	}
}

// StartPage
extern "C" __declspec(naked) void __stdcall __E__836__()
{
	PROXY(StartPage)
		__asm
	{
		jmp p[836 * 4];
	}
}

// StretchBlt
extern "C" __declspec(naked) void __stdcall __E__837__()
{
	PROXY(StretchBlt)
		__asm
	{
		jmp p[837 * 4];
	}
}

// StretchDIBits
extern "C" __declspec(naked) void __stdcall __E__838__()
{
	PROXY(StretchDIBits)
		__asm
	{
		jmp p[838 * 4];
	}
}

// StrokeAndFillPath
extern "C" __declspec(naked) void __stdcall __E__839__()
{
	PROXY(StrokeAndFillPath)
		__asm
	{
		jmp p[839 * 4];
	}
}

// StrokePath
extern "C" __declspec(naked) void __stdcall __E__840__()
{
	PROXY(StrokePath)
		__asm
	{
		jmp p[840 * 4];
	}
}

// SwapBuffers
extern "C" __declspec(naked) void __stdcall __E__841__()
{
	PROXY(SwapBuffers)
		__asm
	{
		jmp p[841 * 4];
	}
}

// TextOutA
extern "C" __declspec(naked) void __stdcall __E__842__()
{
	PROXY(TextOutA)
		__asm
	{
		jmp p[842 * 4];
	}
}

// TextOutW
extern "C" __declspec(naked) void __stdcall __E__843__()
{
	PROXY(TextOutW)
		__asm
	{
		jmp p[843 * 4];
	}
}

// TranslateCharsetInfo
extern "C" __declspec(naked) void __stdcall __E__844__()
{
	PROXY(TranslateCharsetInfo)
		__asm
	{
		jmp p[844 * 4];
	}
}

// UnloadNetworkFonts
extern "C" __declspec(naked) void __stdcall __E__845__()
{
	PROXY(UnloadNetworkFonts)
		__asm
	{
		jmp p[845 * 4];
	}
}

// UnrealizeObject
extern "C" __declspec(naked) void __stdcall __E__846__()
{
	PROXY(UnrealizeObject)
		__asm
	{
		jmp p[846 * 4];
	}
}

// UpdateColors
extern "C" __declspec(naked) void __stdcall __E__847__()
{
	PROXY(UpdateColors)
		__asm
	{
		jmp p[847 * 4];
	}
}

// UpdateICMRegKeyA
extern "C" __declspec(naked) void __stdcall __E__848__()
{
	PROXY(UpdateICMRegKeyA)
		__asm
	{
		jmp p[848 * 4];
	}
}

// UpdateICMRegKeyW
extern "C" __declspec(naked) void __stdcall __E__849__()
{
	PROXY(UpdateICMRegKeyW)
		__asm
	{
		jmp p[849 * 4];
	}
}

// UspAllocCache
extern "C" __declspec(naked) void __stdcall __E__850__()
{
	PROXY(UspAllocCache)
		__asm
	{
		jmp p[850 * 4];
	}
}

// UspAllocTemp
extern "C" __declspec(naked) void __stdcall __E__851__()
{
	PROXY(UspAllocTemp)
		__asm
	{
		jmp p[851 * 4];
	}
}

// UspFreeMem
extern "C" __declspec(naked) void __stdcall __E__852__()
{
	PROXY(UspFreeMem)
		__asm
	{
		jmp p[852 * 4];
	}
}

// WidenPath
extern "C" __declspec(naked) void __stdcall __E__853__()
{
	PROXY(WidenPath)
		__asm
	{
		jmp p[853 * 4];
	}
}

// XFORMOBJ_bApplyXform
extern "C" __declspec(naked) void __stdcall __E__854__()
{
	PROXY(XFORMOBJ_bApplyXform)
		__asm
	{
		jmp p[854 * 4];
	}
}

// XFORMOBJ_iGetXform
extern "C" __declspec(naked) void __stdcall __E__855__()
{
	PROXY(XFORMOBJ_iGetXform)
		__asm
	{
		jmp p[855 * 4];
	}
}

// XLATEOBJ_cGetPalette
extern "C" __declspec(naked) void __stdcall __E__856__()
{
	PROXY(XLATEOBJ_cGetPalette)
		__asm
	{
		jmp p[856 * 4];
	}
}

// XLATEOBJ_hGetColorTransform
extern "C" __declspec(naked) void __stdcall __E__857__()
{
	PROXY(XLATEOBJ_hGetColorTransform)
		__asm
	{
		jmp p[857 * 4];
	}
}

// XLATEOBJ_iXlate
extern "C" __declspec(naked) void __stdcall __E__858__()
{
	PROXY(XLATEOBJ_iXlate)
		__asm
	{
		jmp p[858 * 4];
	}
}

// XLATEOBJ_piVector
extern "C" __declspec(naked) void __stdcall __E__859__()
{
	PROXY(XLATEOBJ_piVector)
		__asm
	{
		jmp p[859 * 4];
	}
}

// bInitSystemAndFontsDirectoriesW
extern "C" __declspec(naked) void __stdcall __E__860__()
{
	PROXY(bInitSystemAndFontsDirectoriesW)
		__asm
	{
		jmp p[860 * 4];
	}
}

// bMakePathNameW
extern "C" __declspec(naked) void __stdcall __E__861__()
{
	PROXY(bMakePathNameW)
		__asm
	{
		jmp p[861 * 4];
	}
}

// cGetTTFFromFOT
extern "C" __declspec(naked) void __stdcall __E__862__()
{
	PROXY(cGetTTFFromFOT)
		__asm
	{
		jmp p[862 * 4];
	}
}

// ftsWordBreak
extern "C" __declspec(naked) void __stdcall __E__863__()
{
	PROXY(ftsWordBreak)
		__asm
	{
		jmp p[863 * 4];
	}
}

// gdiPlaySpoolStream
extern "C" __declspec(naked) void __stdcall __E__864__()
{
	PROXY(gdiPlaySpoolStream)
		__asm
	{
		jmp p[864 * 4];
	}
}

// ___XXX___866
extern "C" __declspec(naked) void __stdcall __E__865__()
{
	PROXY(___XXX___866)
		__asm
	{
		jmp p[865 * 4];
	}
}

// ___XXX___867
extern "C" __declspec(naked) void __stdcall __E__866__()
{
	PROXY(___XXX___867)
		__asm
	{
		jmp p[866 * 4];
	}
}

// ___XXX___868
extern "C" __declspec(naked) void __stdcall __E__867__()
{
	PROXY(___XXX___868)
		__asm
	{
		jmp p[867 * 4];
	}
}

// ___XXX___869
extern "C" __declspec(naked) void __stdcall __E__868__()
{
	PROXY(___XXX___869)
		__asm
	{
		jmp p[868 * 4];
	}
}

// ___XXX___870
extern "C" __declspec(naked) void __stdcall __E__869__()
{
	PROXY(___XXX___870)
		__asm
	{
		jmp p[869 * 4];
	}
}

// ___XXX___871
extern "C" __declspec(naked) void __stdcall __E__870__()
{
	PROXY(___XXX___871)
		__asm
	{
		jmp p[870 * 4];
	}
}

// ___XXX___872
extern "C" __declspec(naked) void __stdcall __E__871__()
{
	PROXY(___XXX___872)
		__asm
	{
		jmp p[871 * 4];
	}
}

// ___XXX___873
extern "C" __declspec(naked) void __stdcall __E__872__()
{
	PROXY(___XXX___873)
		__asm
	{
		jmp p[872 * 4];
	}
}

// ___XXX___874
extern "C" __declspec(naked) void __stdcall __E__873__()
{
	PROXY(___XXX___874)
		__asm
	{
		jmp p[873 * 4];
	}
}

// ___XXX___875
extern "C" __declspec(naked) void __stdcall __E__874__()
{
	PROXY(___XXX___875)
		__asm
	{
		jmp p[874 * 4];
	}
}

// ___XXX___876
extern "C" __declspec(naked) void __stdcall __E__875__()
{
	PROXY(___XXX___876)
		__asm
	{
		jmp p[875 * 4];
	}
}

// ___XXX___877
extern "C" __declspec(naked) void __stdcall __E__876__()
{
	PROXY(___XXX___877)
		__asm
	{
		jmp p[876 * 4];
	}
}

// ___XXX___878
extern "C" __declspec(naked) void __stdcall __E__877__()
{
	PROXY(___XXX___878)
		__asm
	{
		jmp p[877 * 4];
	}
}

// ___XXX___879
extern "C" __declspec(naked) void __stdcall __E__878__()
{
	PROXY(___XXX___879)
		__asm
	{
		jmp p[878 * 4];
	}
}

