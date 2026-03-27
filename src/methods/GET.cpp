#include "methods.hpp"

std::string	get_method(const std::string &file_path, bool is_dir) {
	if (is_dir) {
		std::ostringstream ss;
		for (const auto & entry : std::filesystem::directory_iterator(file_path))
			ss << entry.path() << "\n";
		return ss.str();
	}

	std::ifstream file(file_path);

	if (!file.is_open()) {
		return "";
	}

	std::stringstream ss;
	ss << file.rdbuf();
	file.close();

	return ss.str();
}
