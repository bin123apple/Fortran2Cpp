#include <iostream>

namespace CRASH_ModCaltz {
    int getValue() {
        return 42;
    }
}

// A simple function to test getValue
void testGetValue() {
    int expected = 42;
    int result = CRASH_ModCaltz::getValue();
    if (result == expected) {
        std::cout << "Test passed: Value is " << result << std::endl;
    } else {
        std::cout << "Test failed: Expected " << expected << ", got " << result << std::endl;
    }
}

int main() {
    // Run the test
    testGetValue();
    return 0;
}