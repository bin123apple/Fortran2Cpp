// great.cpp
#include <iostream>

void great(int a, int b) {
    if (a > b) {
        std::cout << a << " is greater than " << b << std::endl;
    } else {
        std::cout << a << " is not greater than " << b << std::endl;
    }
}

// Simple test function
void testGreat(int a, int b, bool expectedResult) {
    if ((a > b) == expectedResult) {
        std::cout << "Test passed for: " << a << " and " << b << std::endl;
    } else {
        std::cout << "Test failed for: " << a << " and " << b << std::endl;
    }
}

int main() {
    // Direct calls
    great(5, 3);
    great(2, 4);
    
    // Unit tests
    testGreat(5, 3, true);
    testGreat(2, 4, false);
    
    return 0;
}