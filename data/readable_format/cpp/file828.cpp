#include <iostream>

// Function definition
void setValueTo2(int& a) {
    a = 2;
}

// Simple test function to verify setValueTo2
void testSetValueTo2() {
    int testVar = 0;
    setValueTo2(testVar);
    if (testVar == 2) {
        std::cout << "Test passed: testVar is 2." << std::endl;
    } else {
        std::cout << "Test failed: testVar is " << testVar << ", expected 2." << std::endl;
    }
}

int main() {
    // Call the test function within main
    testSetValueTo2();
    return 0;
}