#include <iostream>

// Assuming this is the content that would be in init_flag_1.h
constexpr bool is_initialized = true;

// A simple function to test is_initialized
void testIsInitialized() {
    if (is_initialized) {
        std::cout << "Test Passed: is_initialized is true." << std::endl;
    } else {
        std::cout << "Test Failed: is_initialized is not true." << std::endl;
    }
}

int main() {
    // Call the test function
    testIsInitialized();

    // Main program functionality here
    // For demonstration, it just prints the value of is_initialized
    std::cout << "Main Functionality: The value of is_initialized is " << (is_initialized ? "true" : "false") << std::endl;

    return 0;
}