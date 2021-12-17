#pragma once
#include <string>
#include <ostream>

class WebURL {
public:
	WebURL(std::string userURL);

	// Getter functions.
	std::string getURL() const;
	std::string getURLScheme() const;
	std::string getURLAuthority() const;
	std::string getURLPath() const;

private:
	const std::string URL;
	const std::string scheme;
	const std::string authority;
	const std::string path;
};

// Output stream overload.
std::ostream& operator<<(std::ostream& out, const WebURL& URL);