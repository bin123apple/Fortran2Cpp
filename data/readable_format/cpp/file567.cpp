#include <iostream>
#include <string>
#include <cstdlib>

// Define the namespace and function within the same file
namespace para {
    std::string bobo(int n) {
        std::string original = "1234567890";
        return original.substr(0, n);
    }
}

// Simple function to test the expected value of bobo against the actual value
void test_bobo(int testNum, int n, const std::string& expected) {
    std::string result = para::bobo(n);
    if (result != expected) {
        std::cerr << "Test " << testNum << " failed: Expected \"" << expected << "\", got \"" << result << "\"" << std::endl;
        std::exit(EXIT_FAILURE);
    } else {
        std::cout << "Test " << testNum << " passed." << std::endl;
    }
}

int main() {
    // Run tests
    test_bobo(1, 10, "1234567890");
    test_bobo(2, 5, "12345");
    test_bobo(3, 0, "");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}