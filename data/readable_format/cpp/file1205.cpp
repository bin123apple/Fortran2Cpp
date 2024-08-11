#include <iostream>

// Function declaration
void test(int& a, int& b, int& d);

// Simple testing function that does not rely on external libraries
void runTest() {
    int a = 2, b = 3, d = 0;
    test(a, b, d);
    if (d == 5) {
        std::cout << "Test Passed: d is " << d << std::endl;
    } else {
        std::cout << "Test Failed: d is " << d << ", expected 5" << std::endl;
    }
}

// Main function
int main() {
    runTest();
    return 0;
}

// Function definition
void test(int& a, int& b, int& d) {
    d = a + b;
}