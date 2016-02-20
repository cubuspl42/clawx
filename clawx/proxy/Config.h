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

	const nlohmann::json & Dict();

	void Reload();

};

PROXY_EXPORTS Config * GetConfig();

PROXY_EXPORTS Config * GetDebugConfig();

inline const nlohmann::json & config(Config *cfg, std::string key) {
	const auto &j = cfg->Dict();
	if (j.find(key) != j.end()) {
		return j[key];
	}
	else {
		std::string message = "Key '" + key + "' not found in config! Aborting.";
		MessageBox(0, message.c_str(), "Error", MB_ICONEXCLAMATION);
		std::exit(1);
	}
}

inline const nlohmann::json & config(std::string key) {
	return config(GetConfig(), key);
}

inline const nlohmann::json & configd(std::string key) {
	return config(GetDebugConfig(), key);
}
