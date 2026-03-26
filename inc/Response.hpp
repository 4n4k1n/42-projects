#pragma once

#include <sstream>
#include <unistd.h>
#include <vector>
#include <map>
#include "Config/LocationConfig.hpp"

struct http_request {
	std::string 						method;			// GET, POST, DELETE, etc.
	std::string 						path;			// /api/users
	std::string 						http_version;	// HTTP/1.1
	std::map<std::string, std::string>	headers;		// Host, Content-Type, etc.
	std::string 						body;			// Request body content
};

const LocationConfig	*routeMatching(const std::string &uri, const std::vector<LocationConfig> &locations);
bool	checkMethod(const std::string &method, const LocationConfig *location);
std::string buildRealPath(const LocationConfig *loc, const std::string &request_path);
int	checkFile(std::string file_path, std::string method);
std::string response(const http_request &request, const std::vector<LocationConfig> &locations);

std::string	errorResponse(const int error_code);
