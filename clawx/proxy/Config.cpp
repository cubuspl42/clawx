#include "Config.h"

#include <fstream>

static std::string CONFIG_PATH = "config.json";
static std::string DEBUG_CONFIG_PATH = "configd.json";

Config::Config(std::string path)
	: path(path)
{
	Reload();
}

Config::~Config()
{
}

const nlohmann::json & Config::Dict()
{
	return dict;
}

void Config::Reload()
{
	std::ifstream file;
	file.open(path);
	assert(file.good());
	dict << file;
}

PROXY_EXPORTS Config * GetConfig()
{
	static Config * config = nullptr;
	if (!config) {
		config = new Config(CONFIG_PATH);
	}
	return config;
}

PROXY_EXPORTS Config * GetDebugConfig()
{
	static Config * configd = nullptr;
	if (!configd) {
		configd = new Config(DEBUG_CONFIG_PATH);
	}
	return configd;
}
