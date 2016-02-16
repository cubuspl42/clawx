#pragma once

#include "proxy.h"

#include "json.hpp"
#include "stb_image_write.h"

#include <string>

inline std::string tag(std::string tagName, nlohmann::json attrs, std::string innerHtml = "") {
	using nlohmann::json;

	std::string html = "<" + tagName + (attrs.empty() ? "" : " ");

	if (!attrs.empty()) {
		for (json::iterator it = attrs.begin(); it != attrs.end(); ++it) {
			html += it.key() + "=" + '"' + it.value().get<std::string>() + '"';
		}
	}

	html += ">";
	html += innerHtml;
	html += "</" + tagName + ">";

	return html;
}

inline std::string to_string(void *ptr) {
	std::stringstream ss;
	ss << ptr;
	return ss.str();
}

inline std::string img(std::string cssClass, std::string src) {
	return tag("img", {
		{ "class", cssClass },
		{ "src", src }
	});
}

inline std::string img_dump(int w, int h, const byte *data) {
	static int i = 0;
	std::string filename = "img/" + std::to_string(i++) + ".png";
	stbi_write_png(filename.c_str(), w, h, 1, data, w);
	return img("dump", filename);
}

inline std::string json_dump(nlohmann::json j) {
	return tag("data", { {"class", "json"} }, j.dump(2));
}

inline std::string ptr(void *ptr) {
	return tag("span", { { "class", "ptr" } }, to_string(ptr));
}

inline void log(std::string s) {
	GetProxy()->Log(s);
}

inline void log_call(std::string module, std::string fn, void *p) {
	using nlohmann::json;

	log(
		tag("div", json({
			{"class", "call"}
		}),
			tag("strong", {}, module) +
			tag("strong", {}, fn) +
			ptr(p) + '\n'
		)
	);
}