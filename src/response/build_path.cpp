#include "response.hpp"
#include "Config/LocationConfig.hpp"

std::string buildRealPath(const LocationConfig *loc, const std::string &request_path) {
	// Remove the location prefix from the request path
	std::string relative_path = request_path;
	if (request_path.find(loc->path) == 0) {
		relative_path = request_path.substr(loc->path.length());
	}

	// Combine root with the relative path
	std::string full_path = loc->root;

	// Ensure root ends with / and relative doesn't start with /
	if (!full_path.empty() && full_path[full_path.length() - 1] != '/') {
		full_path += '/';
	}
	if (!relative_path.empty() && relative_path[0] == '/') {
		relative_path = relative_path.substr(1);
	}

	full_path += relative_path;

	// TODO: Add logic for index files, auto-index, etc.
	return full_path;
}
