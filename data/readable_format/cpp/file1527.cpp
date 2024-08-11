#include <iostream>
#include <string>

// Functionality
const int num = 1;

int getNum() {
    return num;
}

// Simple test function
void testNum() {
    if (getNum() == 1) {
        std::cout << "Test passed: num is 1" << std::endl;
    } else {
        std::cout << "Test failed: num is not 1" << std::endl;
    }
}

int main() {
    // Run the test
    testNum();

    return 0;
}