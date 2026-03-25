#include "response.hpp"
#include "methods.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <filesystem>
#include <vector>

// ANSI color codes for test output
#define TEST_GREEN "\033[32m"
#define TEST_RED "\033[31m"
#define TEST_BLUE "\033[34m"
#define TEST_RESET "\033[0m"

// Test counter
static int g_tests_passed = 0;
static int g_tests_failed = 0;

// Helper: Print test result
void print_test_result(const std::string &test_name, bool passed) {
	if (passed) {
		std::cout << TEST_GREEN << "[PASS] " << TEST_RESET << test_name << std::endl;
		g_tests_passed++;
	} else {
		std::cout << TEST_RED << "[FAIL] " << TEST_RESET << test_name << std::endl;
		g_tests_failed++;
	}
}

// Helper: Create a test file with content
void create_test_file(const std::string &path, const std::string &content) {
	std::ofstream file(path);
	file << content;
	file.close();
}

// Helper: Remove test file if it exists
void cleanup_test_file(const std::string &path) {
	if (std::filesystem::exists(path)) {
		std::filesystem::remove(path);
	}
}

// Helper: Create a LocationConfig for testing
LocationConfig create_test_location(const std::string &path, const std::string &root,
									const std::vector<std::string> &methods) {
	LocationConfig loc;
	loc.path = path;
	loc.root = root;
	loc.methods = methods;
	loc.cgiEnabled = false;
	return loc;
}

// Helper: Create an http_request for testing
http_request create_test_request(const std::string &method, const std::string &path,
								 const std::string &body = "") {
	http_request req;
	req.method = method;
	req.path = path;
	req.http_version = "HTTP/1.1";
	req.body = body;
	return req;
}

// ============================================================================
// TEST CASES
// ============================================================================

// Test 1: GET method - successful file read
void test_get_success() {
	const std::string test_file = "/tmp/webserv_test_get.txt";
	const std::string test_content = "Hello, World!";

	// Setup
	create_test_file(test_file, test_content);

	std::vector<std::string> allowed_methods = {"GET", "POST", "DELETE"};
	LocationConfig loc = create_test_location("/", "/tmp/", allowed_methods);
	std::vector<LocationConfig> locations = {loc};

	http_request req = create_test_request("GET", "/webserv_test_get.txt");

	// Execute
	std::string result = response(req, locations);

	// Verify
	bool passed = !result.empty() && result.find(test_content) != std::string::npos;
	print_test_result("GET - successful file read", passed);

	// Cleanup
	cleanup_test_file(test_file);
}

// Test 2: GET method - file not found
void test_get_file_not_found() {
	const std::string test_file = "/tmp/webserv_test_nonexistent.txt";

	// Ensure file doesn't exist
	cleanup_test_file(test_file);

	std::vector<std::string> allowed_methods = {"GET", "POST", "DELETE"};
	LocationConfig loc = create_test_location("/", "/tmp/", allowed_methods);
	std::vector<LocationConfig> locations = {loc};

	http_request req = create_test_request("GET", "/webserv_test_nonexistent.txt");

	// Execute
	std::string result = response(req, locations);

	// Verify - should return empty string on error
	bool passed = result.empty();
	print_test_result("GET - file not found returns empty", passed);
}

// Test 3: POST method - create new file
void test_post_create_new_file() {
	const std::string test_file = "/tmp/webserv_test_post_new.txt";
	const std::string test_content = "New file content";

	// Setup - ensure file doesn't exist
	cleanup_test_file(test_file);

	std::vector<std::string> allowed_methods = {"GET", "POST", "DELETE"};
	LocationConfig loc = create_test_location("/", "/tmp/", allowed_methods);
	std::vector<LocationConfig> locations = {loc};

	http_request req = create_test_request("POST", "/webserv_test_post_new.txt", test_content);

	// Execute
	std::string result = response(req, locations);

	// Verify - should return 201 Created for new file
	bool passed = result.find("201") != std::string::npos &&
				  result.find("Created") != std::string::npos;
	print_test_result("POST - create new file returns 201", passed);

	// Cleanup
	cleanup_test_file(test_file);
}

// Test 4: POST method - append to existing file
void test_post_append_existing_file() {
	const std::string test_file = "/tmp/webserv_test_post_existing.txt";
	const std::string initial_content = "Initial content\n";
	const std::string new_content = "Appended content";

	// Setup - create existing file
	create_test_file(test_file, initial_content);

	std::vector<std::string> allowed_methods = {"GET", "POST", "DELETE"};
	LocationConfig loc = create_test_location("/", "/tmp/", allowed_methods);
	std::vector<LocationConfig> locations = {loc};

	http_request req = create_test_request("POST", "/webserv_test_post_existing.txt", new_content);

	// Execute
	std::string result = response(req, locations);

	// Verify - should return 200 OK for existing file
	bool passed = result.find("200") != std::string::npos &&
				  result.find("OK") != std::string::npos;
	print_test_result("POST - append to existing file returns 200", passed);

	// Cleanup
	cleanup_test_file(test_file);
}

// Test 5: DELETE method - successful deletion
void test_delete_success() {
	const std::string test_file = "/tmp/webserv_test_delete.txt";

	// Setup - create file to delete
	create_test_file(test_file, "To be deleted");

	std::vector<std::string> allowed_methods = {"GET", "POST", "DELETE"};
	LocationConfig loc = create_test_location("/", "/tmp/", allowed_methods);
	std::vector<LocationConfig> locations = {loc};

	http_request req = create_test_request("DELETE", "/webserv_test_delete.txt");

	// Execute
	std::string result = response(req, locations);

	// Verify - should return 204 No Content
	bool status_ok = result.find("204") != std::string::npos &&
					 result.find("No Content") != std::string::npos;
	bool file_deleted = !std::filesystem::exists(test_file);
	bool passed = status_ok && file_deleted;

	print_test_result("DELETE - successful deletion returns 204", passed);

	// Cleanup (if test failed)
	cleanup_test_file(test_file);
}

// Test 6: DELETE method - file not found
void test_delete_file_not_found() {
	const std::string test_file = "/tmp/webserv_test_delete_nonexistent.txt";

	// Setup - ensure file doesn't exist
	cleanup_test_file(test_file);

	std::vector<std::string> allowed_methods = {"GET", "POST", "DELETE"};
	LocationConfig loc = create_test_location("/", "/tmp/", allowed_methods);
	std::vector<LocationConfig> locations = {loc};

	http_request req = create_test_request("DELETE", "/webserv_test_delete_nonexistent.txt");

	// Execute
	std::string result = response(req, locations);

	// Verify - should return empty (file check fails before DELETE is called)
	bool passed = result.empty();
	print_test_result("DELETE - file not found returns empty", passed);
}

// Test 7: Method not allowed
void test_method_not_allowed() {
	std::vector<std::string> allowed_methods = {"GET"};  // Only GET allowed
	LocationConfig loc = create_test_location("/", "/tmp/", allowed_methods);
	std::vector<LocationConfig> locations = {loc};

	http_request req = create_test_request("POST", "/test.txt", "content");

	// Execute
	std::string result = response(req, locations);

	// Verify - should return empty string when method not allowed
	bool passed = result.empty();
	print_test_result("Method not allowed returns empty", passed);
}

// Test 8: Multiple locations - correct route matching
void test_multiple_locations() {
	const std::string test_file = "/tmp/api/webserv_test_api.txt";
	const std::string test_content = "API response";

	// Setup - create directory and file
	std::filesystem::create_directories("/tmp/api");
	create_test_file(test_file, test_content);

	std::vector<std::string> methods1 = {"GET"};
	std::vector<std::string> methods2 = {"GET", "POST"};

	LocationConfig loc1 = create_test_location("/", "/tmp/", methods1);
	LocationConfig loc2 = create_test_location("/api/", "/tmp/api/", methods2);
	std::vector<LocationConfig> locations = {loc1, loc2};

	http_request req = create_test_request("GET", "/api/webserv_test_api.txt");

	// Execute
	std::string result = response(req, locations);

	// Verify - should successfully read file from /api/ location
	bool passed = !result.empty() && result.find(test_content) != std::string::npos;
	print_test_result("Multiple locations - correct route matching", passed);

	// Cleanup
	cleanup_test_file(test_file);
	std::filesystem::remove("/tmp/api");
}

// Test 9: GET with empty file
void test_get_empty_file() {
	const std::string test_file = "/tmp/webserv_test_empty.txt";

	// Setup - create empty file
	create_test_file(test_file, "");

	std::vector<std::string> allowed_methods = {"GET"};
	LocationConfig loc = create_test_location("/", "/tmp/", allowed_methods);
	std::vector<LocationConfig> locations = {loc};

	http_request req = create_test_request("GET", "/webserv_test_empty.txt");

	// Execute
	std::string result = response(req, locations);

	// Verify - GET returns file content, so empty file returns empty string
	// This is expected behavior - the HTTP headers are added elsewhere
	bool passed = result.empty();
	print_test_result("GET - empty file returns empty content", passed);

	// Cleanup
	cleanup_test_file(test_file);
}

// Test 10: POST with empty body
void test_post_empty_body() {
	const std::string test_file = "/tmp/webserv_test_post_empty.txt";

	// Setup - ensure file doesn't exist
	cleanup_test_file(test_file);

	std::vector<std::string> allowed_methods = {"POST"};
	LocationConfig loc = create_test_location("/", "/tmp/", allowed_methods);
	std::vector<LocationConfig> locations = {loc};

	http_request req = create_test_request("POST", "/webserv_test_post_empty.txt", "");

	// Execute
	std::string result = response(req, locations);

	// Verify - should return 201 Created
	bool passed = result.find("201") != std::string::npos;
	print_test_result("POST - empty body creates file with 201", passed);

	// Cleanup
	cleanup_test_file(test_file);
}

// ============================================================================
// MAIN TEST RUNNER
// ============================================================================

int main() {
	std::cout << TEST_BLUE << "========================================" << TEST_RESET << std::endl;
	std::cout << TEST_BLUE << "  Running response() Unit Tests" << TEST_RESET << std::endl;
	std::cout << TEST_BLUE << "========================================" << TEST_RESET << std::endl << std::endl;

	// Run all tests
	test_get_success();
	test_get_file_not_found();
	test_post_create_new_file();
	test_post_append_existing_file();
	test_delete_success();
	test_delete_file_not_found();
	test_method_not_allowed();
	test_multiple_locations();
	test_get_empty_file();
	test_post_empty_body();

	// Print summary
	std::cout << std::endl;
	std::cout << TEST_BLUE << "========================================" << TEST_RESET << std::endl;
	std::cout << TEST_BLUE << "  Test Summary" << TEST_RESET << std::endl;
	std::cout << TEST_BLUE << "========================================" << TEST_RESET << std::endl;
	std::cout << TEST_GREEN << "Passed: " << g_tests_passed << TEST_RESET << std::endl;
	std::cout << TEST_RED << "Failed: " << g_tests_failed << TEST_RESET << std::endl;
	std::cout << "Total:  " << (g_tests_passed + g_tests_failed) << std::endl;

	return g_tests_failed == 0 ? 0 : 1;
}
