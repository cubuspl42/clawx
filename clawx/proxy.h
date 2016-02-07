#pragma once

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
void _log(std::ofstream &os, T head) {
	os << head << std::endl;
}

template<typename T, typename... Tail>
void _log(std::ofstream &os, T head, Tail&&... tail) {
	os << head << ' ';
	_log(os, std::forward<Tail>(tail)...);
}

template<typename... Args>
void log(std::ofstream &os, Args&&... args) {
	os << thread_index << '.' << current_time() << ' ';
	_log(os, std::forward<Args>(args)...);
}

#define DLL_NAME_STR(name) #name

bool enable_proxy_log = false;

std::ofstream proxy_log_file;
std::ofstream stack_log_file;

int proxy_init() {
	std::string cfg = read_file("config.txt");
	enable_proxy_log = contains(cfg, DLL_NAME);
	proxy_log_file.open(DLL_NAME "_log.txt");
	stack_log_file.open(DLL_NAME "_stack_log.txt");
	proxy_log_file.rdbuf()->pubsetbuf(0, 0);
	stack_log_file.rdbuf()->pubsetbuf(0, 0);
	return 0;
}

template<typename... Args>
void proxy_log(Args&&... args) {
	if (enable_proxy_log) {
		log(proxy_log_file, std::forward<Args>(args)...);
	}
}

void proxy_log_symbol(const char *category, const char *symbol) {
	proxy_log(category, symbol);
}

void proxy_log_unimplemented() {
	proxy_log_symbol(DLL_NAME, "<unimplemented>");
}

int _ = proxy_init();

#define PROXY(symbol) proxy_log_symbol(DLL_NAME, #symbol);

#define PROXY_UNIMPLEMENTED() (proxy_log_unimplemented(), 0)

thread_local std::vector<std::string> stack;

void dump_stack() {
	stack_log_file << "[ ";
	for (auto symbol : stack) {
		stack_log_file << symbol << ' ';
	}
	stack_log_file << "]" << std::endl;
}

void stack_push(std::string symbol) {
	stack.push_back(symbol);
	dump_stack();
}

void stack_pop(std::string symbol) {
	if (stack.back() != symbol) {
		log(stack_log_file, stack.back(), "!=", symbol);
	}
	stack.pop_back();
	dump_stack();
}

#define STACK_PUSH(symbol) stack_push(#symbol)

#define STACK_POP(symbol) stack_pop(#symbol)
