#pragma once

#include <string>
#include <vector>

class LocationConfig {
	public:
		std::string path;

		std::string root;
		std::vector<Methods> methods;

		bool        cgiEnabled;
		std::string cgiExtensions;
		std::string cgiPath;

		std::string	index;
		bool		auto_index;

		std::string uploadDir;
		LocationConfig() : cgiEnabled(false) {}
};