#pragma once

#include "proxy.h"

#include "json.hpp"

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

inline std::string img(std::string cssClass, std::string src) {
	return tag("img", {
		{ "class", cssClass },
		{ "src", src }
	});
}

inline void log(std::string s) {
	GetProxy()->Log(s);
}

inline std::string to_string(void *ptr) {
	std::stringstream ss;
	ss << ptr;
	return ss.str();
}

inline void log_call(std::string module, std::string fn, void *ptr) {
	using nlohmann::json;

	log(tag("div", json({
		{"class", "call"}
	}), tag("strong", {}, module) +
	tag("strong", {}, fn) +
	tag("span", { { "class", "ptr" } }, to_string(ptr))) + '\n');
}