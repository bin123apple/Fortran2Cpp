#include <iostream>
#include <string>

// Assuming great_rsd simply adds two numbers for demonstration purposes
template<typename T>
T great_rsd(T a, T b) {
    return a + b;
}

// A simple assert function for testing
template<typename T>
void assert_equals(T expected, T actual, const std::string& test_name) {
    if (expected == actual) {
        std::cout << test_name << " passed." << std::endl;
    } else {
        std::cout << test_name << " failed. Expected: " << expected << " Got: " << actual << std::endl;
    }
}

int main() {
    // Test cases for great_rsd
    assert_equals(8, great_rsd(5, 3), "Test 1: Adding positive numbers");
    assert_equals(0, great_rsd(-1, 1), "Test 2: Adding negative and positive numbers");
    assert_equals(-15, great_rsd(-5, -10), "Test 3: Adding negative numbers");

    return 0;
}