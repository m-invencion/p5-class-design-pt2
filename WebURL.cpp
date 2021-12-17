#include "WebURL.h"
#include <string>
#include <iostream>
#include <ostream>

WebURL::WebURL(std::string userURL)
	:	URL{ userURL },
		// Using similar from project 2 to initialize scheme, authority, and path.
		scheme{ userURL.substr(0, userURL.find("//")) },
		authority{ userURL.substr(scheme.length(), userURL.substr(scheme.length() + 2).find_first_of("/") + 2) },
		path{ userURL.substr(scheme.length() + authority.length()) }
	{ }

// Getter functions.
std::string WebURL::getURL() const {
	return URL;
}

std::string WebURL::getURLScheme() const {
	return scheme;
}

std::string WebURL::getURLAuthority() const {
	return authority;
}

std::string WebURL::getURLPath() const {
	return path;
}

// Output stream overload.
std::ostream& operator<<(std::ostream& out, const WebURL& URL) {
	out << "URL: " << URL.getURL() << "\n" <<
		"    SCHEME: " << URL.getURLScheme() << "\n" <<
		"    AUTHORITY: " << URL.getURLAuthority() << "\n" <<
		"    PATH: " << URL.getURLPath() << "\n";
	return out;
}