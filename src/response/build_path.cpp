#include "response.hpp"
#include "Config/LocationConfig.hpp"

std::string buildRealPath(const LocationConfig *loc) {
	// TODO: Add logic for index files, auto-index, etc.
	return loc->root;
}
