#include <iostream>
#include <cassert>

// Function Prototype
bool notwin(double xw1, double xw2, double x);

int main() {
    // Test 1: x is within the range
    assert(notwin(1.0, 5.0, 3.0) == false);
    std::cout << "Test 1 passed." << std::endl;

    // Test 2: x is outside the range (greater than xw2)
    assert(notwin(1.0, 5.0, 6.0) == true);
    std::cout << "Test 2 passed." << std::endl;

    // Test 3: x is outside the range (less than xw1)
    assert(notwin(1.0, 5.0, 0.0) == true);
    std::cout << "Test 3 passed." << std::endl;

    // Test 4: xw1 is greater than xw2
    assert(notwin(5.0, 1.0, 3.0) == false);
    std::cout << "Test 4 passed." << std::endl;

    // Test 5: x is equal to xw1
    assert(notwin(1.0, 5.0, 1.0) == false);
    std::cout << "Test 5 passed." << std::endl;

    // Test 6: x is equal to xw2
    assert(notwin(1.0, 5.0, 5.0) == false);
    std::cout << "Test 6 passed." << std::endl;

    return 0;
}

// Function Definition
bool notwin(double xw1, double xw2, double x) {
    if (xw1 > xw2) {
        return false;
    } else {
        return x < xw1 || x > xw2;
    }
}