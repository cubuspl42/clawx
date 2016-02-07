#pragma once

#include <fstream>

// #define PROXY_LOG

#ifdef PROXY_LOG

std::ofstream proxy_log;

int proxy_init() {
	proxy_log.open("log.txt");
	return 0;
}

void proxy(const char *symbol) {
	proxy_log << symbol << '\n';
}

int _ = proxy_init();

#define PROXY(symbol) proxy(#symbol);

#else

#define PROXY(symbol)

#endif