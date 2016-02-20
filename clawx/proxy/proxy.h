#pragma once

#include "proxy_exports.h"

#include "json.hpp"

#include <windows.h>
#include <ddraw.h>

using DirectDrawCreatePtr = decltype(&DirectDrawCreate);

class IProxy {
public:
	virtual ~IProxy() {}

	using CreateWindowExA_type = decltype(CreateWindowExA);

	virtual HWND CreateWindowExA(
		CreateWindowExA_type _CreateWindowExA,
		DWORD     dwExStyle,
		LPCTSTR   lpClassName,
		LPCTSTR   lpWindowName,
		DWORD     dwStyle,
		int       x,
		int       y,
		int       nWidth,
		int       nHeight,
		HWND      hWndParent,
		HMENU     hMenu,
		HINSTANCE hInstance,
		LPVOID    lpParam
	) = 0;

	virtual HRESULT DirectDrawProxyCreate(
		DirectDrawCreatePtr _DirectDrawCreate,
		GUID *lpGUID,
		LPDIRECTDRAW *lplpDD,
		IUnknown     *pUnkOuter
	) = 0;

	virtual void Log(std::string s) = 0;
};

PROXY_EXPORTS IProxy *GetProxy();