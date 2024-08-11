#include <cstdint>
#include <cassert>
#include <iostream>

// The function to be tested
void C(int32_t* X) {
    *X = (*X) << 8;
}

// A simple test function
void testC() {
    int32_t testValue = 1; // Initialize test value
    C(&testValue); // Apply the shift operation
    
    // Assert that the result is as expected
    assert(testValue == 256);
    
    // If the program hasn't exited, the test passed
    std::cout << "Test passed: 1 shifted left by 8 bits is " << testValue << std::endl;
}

int main() {
    // Run the test
    testC();
    
    return 0;
}