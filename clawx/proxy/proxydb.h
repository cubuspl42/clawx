#pragma once

#include <windows.h>

#include <cstdio>
#include <cassert>
#include <vector>
#include <map>

struct ProxyDb {
	std::map<unsigned, DWORD> dm;
	std::map<unsigned, std::vector<char>> sm;

	ProxyDb() {
		Load();
	}

	void SetDword(unsigned key, DWORD value) {
		dm[key] = value;
	}

	DWORD GetDword(unsigned key, DWORD value) {
		return dm[key];
	}

	template<typename T>
	void SetBuffer(unsigned key, const T *ptr) {
		auto &v = sm[key];
		unsigned n = sizeof(T);
		v.resize(n);
		char *vd = v.data();
		memcpy(vd, ptr, n);
	}

	template<typename T>
	void GetBuffer(unsigned key, T *ptr) {
		const auto &v = sm[key];
		const char *vd = v.data();
		unsigned n = v.size();
		assert(sizeof(T) == n);
		memcpy(ptr, vd, n);
	}

	void Save() {
		FILE *f = fopen("proxydb", "wb");
		int dmn = dm.size();
		int smn = sm.size();

		fwrite(&dmn, 4, 1, f);
		fwrite(&smn, 4, 1, f);

		for (const auto &p : dm) {
			fwrite(&p.first, 4, 1, f);
			fwrite(&p.second, 4, 1, f);
		}

		for (const auto &p : sm) {
			int n = p.second.size();
			const char *vd = p.second.data();
			fwrite(&p.first, 4, 1, f);
			fwrite(&n, 4, 1, f);
			fwrite(vd, 1, n, f);
		}
	}

	void Load() {
		FILE *f = fopen("proxydb", "rb");
		int dmn = 0;
		int smn = 0;

		fread(&dmn, 4, 1, f);
		fread(&smn, 4, 1, f);

		for (int i = 0; i < dmn; ++i) {
			int k;
			DWORD v;
			fread(&k, 4, 1, f);
			fread(&v, 4, 1, f);
			dm[k] = v;
		}

		for (int i = 0; i < smn; ++i) {
			int k;
			int n;
			std::vector<char> v;
			fread(&k, 4, 1, f);
			fread(&n, 4, 1, f);
			v.resize(n);
			fread(v.data(), 1, n, f);
		}
	}
};