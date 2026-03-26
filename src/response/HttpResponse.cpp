#include "HttpResponse.hpp"
#include "status.hpp"
#include "Config/LocationConfig.hpp"
#include "color.hpp"
#include "methods.hpp"
#include <sstream>

HttpResponse::HttpResponse(int s) : status(s) {}

HttpResponse::HttpResponse(const HttpResponse &other) {
	if (this != &other)
		*this = other;
}

HttpResponse &HttpResponse::operator=(const HttpResponse &other) {
	if (this != &other) 
		*this = other;
	return *this;
}


void HttpResponse::setHeader(const std::string &key, const std::string &value) {
	this->headers[key] = value;
}

void HttpResponse::setStandardHeader(void) {
	if (headers.find("Server") == headers.end())
		headers["Server"] = "Webserv/1.0";
	if (headers.find("Connection") == headers.end())
		headers["Connection"] = "close";
	if (!body.empty() && headers.find("Content-Lenght") == headers.end())
		headers["Content-Lenght"] = std::to_string(body.size());
}

std::string HttpResponse::build(void) {
	setStandardHeader();

	std::ostringstream ss;
	ss << "HTTP/1.1 " << status << " " << HTTP_STATUS_MESSAGES.at(status) << "\r\n";

	for (std::map<std::string, std::string>::const_iterator i = headers.begin();
	i != headers.end(); ++i) {
		ss << i->first << ": " << i->second << "\r\n";
	}

	ss << "\r\n";

	if (!body.empty())
		ss << body;

	return ss.str();
}

std::string response(const http_request &request, const std::vector<LocationConfig> &locations) {
	const LocationConfig *loc = routeMatching(request.path, locations);
	int status = 200;
	std::stringstream ss;

	if (checkMethod(request.method, loc) == false) {
		return errorResponse(405);
	}

	std::string file_path(buildRealPath(loc, request.path));

	if (request.method == "GET" || request.method == "DELETE") {
		status = checkFile(file_path, request.method);
		if (status != 200) {
				return errorResponse(status);
		}
	}

	std::string res;

	if (request.method == "GET") {
		std::string content = GET(file_path);

		ss << "HTTP/1.1 200 OK\r\n";
		ss << "Content-Type: text/html\r\n";
		ss << "Content-Length: " << content.size() << "\r\n";
		ss << "\r\n";
		ss << content;
		res = ss.str();
	}
	else if (request.method == "POST") {
		status = POST(file_path, request.body);
		ss << "HTTP/1.1 " << status << " " << HTTP_STATUS_MESSAGES.at(status) << "\r\n";
		res = ss.str();
	}
	else if (request.method == "DELETE") {
		status = DELETE(file_path);
		ss << "HTTP/1.1 " << status << " " << HTTP_STATUS_MESSAGES.at(status) << "\r\n";
		res = ss.str();
	}

	return res;
}