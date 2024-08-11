#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

// Define a simple assertion function for testing
void assert(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "Assertion failed: " << message << std::endl;
        std::exit(EXIT_FAILURE);
    } else {
        std::cout << "Test passed: " << message << std::endl;
    }
}

// Check if a file exists
bool fileExists(const std::string& filename) {
    std::ifstream file(filename.c_str());
    return file.good();
}

// Main function to run tests
int main() {
    std::string filename = "tmpfile";
    
    // Test file creation
    {
        std::ofstream file(filename, std::ios::out);
        assert(file.is_open(), "File should be open after creation");
        file.close();
        assert(fileExists(filename), "File should exist after creation");
    }

    // Test file deletion
    {
        assert(std::remove(filename.c_str()) == 0, "File should be removed successfully");
        assert(!fileExists(filename), "File should not exist after deletion");
    }

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}