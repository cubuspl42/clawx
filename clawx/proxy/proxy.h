#pragma once

#include "log.h"

#include "json.hpp"

#include <windows.h>
#include <ddraw.h>

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

PROXY_EXPORTS void *ProxyLog();

PROXY_EXPORTS void *Config();

#define config (*((nlohmann::json*)Config()))