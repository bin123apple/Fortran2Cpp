#include <iostream>

// Declaration of the function
int doubleValue(int x);

int main() {
    // Test the doubleValue function
    int result = doubleValue(5);
    if (result == 10) {
        std::cout << "C++ Test Passed: The result is: " << result << std::endl;
    } else {
        std::cout << "C++ Test Failed." << std::endl;
    }
    return 0;
}

// Definition of the function
int doubleValue(int x) {
    return x * 2;
}