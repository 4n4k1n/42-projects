#pragma once

#include "webserv.hpp"
#include "Config/Config.hpp"

class HttpRequest {
	public:
	enum Methods {GET, POST, DELETE, UNKNOWN = -1};

	Methods		method;
	std::string target;
	std::string path;
	std::string query;
	std::string version;

	std::map<std::string, std::string> headers;

	std::string body;

	size_t contentLength;
	bool keepAlive;

	void parseReqline(HttpRequest& req, const std::string& rawReq);
	void parseHeaders(HttpRequest& req, const std::string& rawReq);
	HttpRequest parseRequest(const std::string& rawReq);
	void print() const;
};
