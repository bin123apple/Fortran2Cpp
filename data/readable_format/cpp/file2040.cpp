#include <iostream>

// Function declaration
bool active(int e11);

int main() {
    // Test cases
    if (active(5)) {
        std::cout << "Test 1 passed: 5 is positive." << std::endl;
    } else {
        std::cout << "Test 1 failed: 5 is not positive." << std::endl;
    }

    if (!active(-3)) {
        std::cout << "Test 2 passed: -3 is not positive." << std::endl;
    } else {
        std::cout << "Test 2 failed: -3 is positive." << std::endl;
    }

    if (!active(0)) {
        std::cout << "Test 3 passed: 0 is not positive." << std::endl;
    } else {
        std::cout << "Test 3 failed: 0 is positive." << std::endl;
    }

    return 0;
}

// Function definition
bool active(int e11) {
    return e11 > 0;
}