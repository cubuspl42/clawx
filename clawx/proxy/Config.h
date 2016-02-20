#pragma once

#include "proxy_exports.h"

#include "json.hpp"

#include <Windows.h>

class Config
{
	std::string path;
	nlohmann::json dict;

public:

	Config(std::string path);

	~Config();

	void ResetPath(std::string path);

	const nlohmann::json & Dict();

	void Reload();

};

PROXY_EXPORTS Config * GetConfig();

inline const nlohmann::json & config(std::string key) {
	const auto &j = GetConfig()->Dict();
	if (j.find(key) != j.end()) {
		return j[key];
	}
	else {
		std::string message = "Key '" + key + "' not found in config! Aborting.";
		MessageBox(0, message.c_str(), "Error", MB_ICONEXCLAMATION);
		std::exit(1);
	}
}
