#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <stack>
#include <vector>

#include <windows.h>

inline bool contains(std::string str, std::string substr) {
	return str.find(substr) != std::string::npos;
}

inline std::string read_file(const char *path) {
	std::ifstream t(path);
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());
	return str;
}

inline const std::string current_time() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%X", &tstruct);
	return buf;
}

template<typename T>
void log_r(std::ofstream &os, T head) {
	os << head << std::endl;
}

template<typename T, typename... Tail>
void log_r(std::ofstream &os, T head, Tail&&... tail) {
	os << head << ' ';
	log_r(os, std::forward<Tail>(tail)...);
}

template<typename... Args>
void log_t(std::ofstream &os, Args&&... args) {
	os << current_time() << ' ';
	log_r(os, std::forward<Args>(args)...);
}

template<typename... Args>
void log(Args&&... args) {
	return;
	log_t(*((std::ofstream*)ProxyLog()), std::forward<Args>(args)...);
}

inline void log_unimplemented() {
	log(DLL_NAME, "<unimplemented>");
}

inline void log_hresult(HRESULT r) {
	switch (r) {
	case S_OK: log("r = S_OK"); break;
	default: log("r =", r); break;
	}
}

template<typename... Args>
void log_in(Args&&... args) {
	log(">", std::forward<Args>(args)...);
}

template<typename... Args>
void log_out(Args&&... args) {
	log("<", std::forward<Args>(args)...);
}

inline void log_flags(std::string fn, std::vector<std::pair<unsigned, std::string>> fdef, unsigned f) {
	fn += " = ";
	int i = 0;
	for (auto &p : fdef) {
		if (f & p.first) {
			if (i) {
				fn += " | ";
			}
			fn += p.second;
			++i;
		}
	}
	log(fn);
}

#define FLAG(flag) {flag, #flag}

#define PROXY(symbol) log(DLL_NAME, #symbol);

#define PROXY_UNIMPLEMENTED() (log_unimplemented(), 0)

