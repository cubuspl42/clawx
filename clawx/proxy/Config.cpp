#include "Config.h"

#include <fstream>

static std::string CONFIG_PATH = "config.json";
static std::string DEBUG_CONFIG_PATH = "Data/configd.json";

Config::Config(std::string path)
	: path(path)
{
	Reload();
}

Config::~Config()
{
}

void Config::ResetPath(std::string path)
{
	this->path = path;
	Reload();
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
		const auto & j = config->Dict();
		if (j.find("debug") != j.end() && j["debug"]) {
			config->ResetPath(DEBUG_CONFIG_PATH);
		}
	}
	return config;
}
