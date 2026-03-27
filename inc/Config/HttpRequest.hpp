#pragma once

#include <string>
#include <map>

typedef enum {
	GET,
	POST,
	DELETE,
	UNKOWN = -1
} Methods;

class HttpRequest {
	public:

	Methods		method;
	std::string target;
	std::string path;
	std::string query;
	std::string version;

	std::map<std::string, std::string> headers;

	std::string body;

	size_t contentLength;
	bool keepAlive;


	HttpRequest parseRequest(const std::string& req);
	private:
};
