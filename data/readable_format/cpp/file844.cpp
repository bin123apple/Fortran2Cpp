#include <iostream>
#include <string>
#include <cstdlib> // For abort()

// Equivalent to the Fortran module 'z'
namespace z {
    std::string a[2] = {"main  ", "main  "}; // Initialized as per the Fortran code
    std::string b[2] = {"abcd  ", "efghij"};
}

// Simple test utility functions
namespace test_utils {
    void assert_equals(const std::string& expected, const std::string& actual, const std::string& message) {
        if (expected != actual) {
            std::cerr << "Assertion failed: " << message << " - Expected: " << expected << ", Actual: " << actual << std::endl;
            std::abort();
        }
    }

    void run_tests() {
        using namespace z;
        assert_equals("main  ", a[0], "a[0] initialization");
        assert_equals("main  ", a[1], "a[1] initialization");
        assert_equals("abcd  ", b[0], "b[0] initialization");
        assert_equals("efghij", b[1], "b[1] initialization");
        
        std::cout << "All tests passed." << std::endl;
    }
}

int main() {
    test_utils::run_tests();
    return 0;
}