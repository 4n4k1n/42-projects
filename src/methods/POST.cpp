#include "methods.hpp"

int	post_method(const std::string &file_path, const std::string &content) {
	// Check if file exists to determine status code
	bool exists = std::filesystem::exists(file_path);

	std::ofstream file(file_path, std::ios::app);

	if (!file.is_open()) {
		return 500;
	}

	file << content;
	file.close();

	return exists ? 200 : 201;
}
