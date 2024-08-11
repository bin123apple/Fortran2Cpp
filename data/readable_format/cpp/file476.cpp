#include <iostream>

// Function to perform the bit shift
int shiftRight(int value, int positions) {
    return value >> positions;
}

// Simple test function
void testShiftRight(int value, int positions, int expected) {
    int result = shiftRight(value, positions);
    if (result == expected) {
        std::cout << "Test passed: " << value << " >> " << positions << " = " << result << std::endl;
    } else {
        std::cout << "Test failed: " << value << " >> " << positions << " = " << result << " (Expected: " << expected << ")" << std::endl;
    }
}

int main() {
    // Test case: shifting 1 to the right by 3 positions should result in 0
    testShiftRight(1, 3, 0);

    return 0;
}