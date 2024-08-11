#include <iostream>
#include <cassert>

// Define the namespace to keep the utility functions organized
namespace Utilities {
    // Template function to swap two values of any type
    template<typename T>
    void swap(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }
}

// Define test functions to verify the swap functionality
void testSwapInteger() {
    int i1 = 1, i2 = 2;
    Utilities::swap(i1, i2);
    assert(i1 == 2 && i2 == 1);
    std::cout << "testSwapInteger: Passed" << std::endl; // Corrected line
}

void testSwapReal() {
    float r1 = 1.0f, r2 = 2.0f;
    Utilities::swap(r1, r2);
    assert(r1 == 2.0f && r2 == 1.0f);
    std::cout << "testSwapReal: Passed" << std::endl; // Corrected line
}

int main() {
    // Demonstration of swapping
    int i1 = 1, i2 = 3;
    float r1 = 9.2f, r2 = 5.6f;
    
    std::cout << "Initial state: "
              << "i1 = " << i1 << ", i2 = " << i2 << ", r1 = " << r1 << ", r2 = " << r2 << std::endl;
    
    Utilities::swap(i1, i2);
    Utilities::swap(r1, r2);
    
    std::cout << "State after swaps: "
              << "i1 = " << i1 << ", i2 = " << i2 << ", r1 = " << r1 << ", r2 = " << r2 << std::endl;

    // Running test cases
    testSwapInteger();
    testSwapReal();
    
    return 0;
}