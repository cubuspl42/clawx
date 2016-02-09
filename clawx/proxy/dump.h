#pragma once

#include <cstdio>
#include <string>

template<typename T>
void Dump(std::string name, const T *ptr) {
	if (ptr) {
		FILE *f = fopen(name.c_str(), "wb");
		fwrite(ptr, sizeof(T), 1, f);
		fclose(f);
	}
	else {
		name += "_nullptr";
		FILE *f = fopen(name.c_str(), "wb");
		fclose(f);
	}
}

template<typename T>
void Load(std::string name, T *ptr) {
	FILE *f = fopen(name.c_str(), "rb");
	fread(ptr, sizeof(T), 1, f);
	fclose(f);
}