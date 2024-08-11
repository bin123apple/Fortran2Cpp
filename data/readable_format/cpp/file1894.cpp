#include <iostream>
#include <cmath>

// Define your class or struct here
struct TypeParamReal {
    double example_real; // Assuming double precision is needed
};

// Simple test function that does not rely on any external framework
void test_example_real() {
    TypeParamReal obj;
    obj.example_real = 1.2; // Setting up test case

    // Simple test condition
    if (std::abs(obj.example_real - 1.2) < 1e-6) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
}

// Main function to run tests
int main() {
    std::cout << "Running tests..." << std::endl;
    test_example_real();
    return 0;
}