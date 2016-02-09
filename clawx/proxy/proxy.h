#pragma once
#include "log.h"

#include <windows.h>
#include <ddraw.h>

#ifdef PROXY_EXPORTS
#define PROXY_EXPORTS __declspec(dllexport)
#else
#define PROXY_EXPORTS __declspec(dllimport)
#endif

PROXY_EXPORTS IDirectDraw *DirectDrawProxyCreate(IDirectDraw *);

PROXY_EXPORTS void *ProxyLog();
