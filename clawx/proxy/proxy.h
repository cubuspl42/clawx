#pragma once

#include <windows.h>
#include <ddraw.h>

#include "json.hpp"

#define config (*((nlohmann::json*)Config()))

#include "log.h"

#ifdef PROXY_EXPORTS
#define PROXY_EXPORTS __declspec(dllexport)
#else
#define PROXY_EXPORTS __declspec(dllimport)
#endif

using DirectDrawCreatePtr = decltype(&DirectDrawCreate);

PROXY_EXPORTS HRESULT DirectDrawProxyCreate(
	DirectDrawCreatePtr _DirectDrawCreate,
	GUID *lpGUID,
	LPDIRECTDRAW *lplpDD,
	IUnknown     *pUnkOuter
);

PROXY_EXPORTS void SetHwnd(HWND hWnd);

PROXY_EXPORTS void *ProxyLog();

PROXY_EXPORTS void *Config();