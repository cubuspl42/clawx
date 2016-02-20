#pragma once

#ifdef PROXY_EXPORTS
#define PROXY_EXPORTS __declspec(dllexport)
#else
#define PROXY_EXPORTS __declspec(dllimport)
#endif
