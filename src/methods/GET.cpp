#include "methods.hpp"

std::string	get_method(const std::string &file_path) {
	std::ifstream file(file_path);

	if (!file.is_open()) {
		return "";
	}

	std::stringstream ss;
	ss << file.rdbuf();
	file.close();

	return ss.str();
}
