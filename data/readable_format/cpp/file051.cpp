#include <iostream>

// Example functionality to be tested
int get_number() {
    return 42;
}

// Simple test function
void test_get_number() {
    int result = get_number();
    if (result == 42) {
        std::cout << "Test passed: get_number() returned " << result << std::endl;
    } else {
        std::cout << "Test failed: get_number() returned " << result << " instead of 42" << std::endl;
    }
}

// Main function to run the test
int main() {
    std::cout << "Testing get_number function..." << std::endl;
    test_get_number();
    return 0;
}