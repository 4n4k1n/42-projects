#include "response.hpp"
#include "Config/LocationConfig.hpp"
#include "color.hpp"
#include "GET.hpp"

std::string response(const http_request &request, const std::vector<LocationConfig> &locations) {
	const LocationConfig *loc = routeMatching(request.path, locations);

	if (checkMethod(request.method, loc) == false) {
		std::cerr << RED << "Error: method not allowed!" << RESET << std::endl;
		return "";
	}

	std::string file_path(buildRealPath(loc));

	if (checkFile(file_path, request.method) == -1) {
		std::cerr << RED << "Error: " <<
			"file does not exists or doesn't have the correct permissions"
			<< RESET << std::endl;
		return "";
	}

	std::string res = "";
	// TODO: execute method based on request.method

	// res = GET()

	return res;
}