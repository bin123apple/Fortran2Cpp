#include <iostream>

// Function declaration
int f() {
    return 88;
}

// Simple test function
void testF() {
    int expected = 88;
    int result = f();
    if (result == expected) {
        std::cout << "Test passed: f() = " << result << std::endl;
    } else {
        std::cout << "Test failed: f() = " << result << ", expected: " << expected << std::endl;
    }
}

int main() {
    // Run the test
    testF();
    return 0;
}