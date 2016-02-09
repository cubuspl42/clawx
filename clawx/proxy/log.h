#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <stack>
#include <vector>

unsigned short thread_number;
thread_local unsigned short thread_index;

bool contains(std::string str, std::string substr) {
	return str.find(substr) != std::string::npos;
}

std::string read_file(const char *path) {
	std::ifstream t(path);
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());
	return str;
}

const std::string current_time() {
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
	os << GetCurrentThreadId() << '/' << current_time() << ' ';
	log_r(os, std::forward<Args>(args)...);
}

template<typename... Args>
void proxy_log(Args&&... args) {
	log(*((std::ofstream*)ProxyLog()), std::forward<Args>(args)...);
}

void proxy_log_unimplemented() {
	proxy_log(DLL_NAME, "<unimplemented>");
}

#define PROXY(symbol) proxy_log(DLL_NAME, #symbol);

#define PROXY_UNIMPLEMENTED() (proxy_log_unimplemented(), 0)
