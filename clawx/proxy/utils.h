#pragma once

#include <cstdio>
#include <string>

static const std::string DUMP_DIR = "Data/";

template<typename T>
inline void Dump(std::string name, const T *ptr) {
	std::string filename = DUMP_DIR + name;
	if (ptr) {
		FILE *f = fopen(filename.c_str(), "wb");
		fwrite(ptr, sizeof(T), 1, f);
		fclose(f);
	}
	else {
		filename += "_nullptr";
		FILE *f = fopen(filename.c_str(), "wb");
		fclose(f);
	}
}

template<typename T>
inline void Load(std::string name, T *ptr) {
	std::string filename = DUMP_DIR + name;
	FILE *f = fopen(filename.c_str(), "rb");
	fread(ptr, sizeof(T), 1, f);
	fclose(f);
}