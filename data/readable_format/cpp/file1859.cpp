#include <iostream>

// Define the namespace and function within the same file.
namespace hmixing_mod {
    int addNumbers(int a, int b) {
        return a + b;
    }
}

// A simple function to test addNumbers.
void testAddNumbers() {
    int result = hmixing_mod::addNumbers(2, 3);
    if (result == 5) {
        std::cout << "Test passed: 2 + 3 = " << result << std::endl;
    } else {
        std::cout << "Test failed: 2 + 3 did not equal 5, got " << result << std::endl;
    }
}

int main() {
    // Run the test.
    testAddNumbers();
    return 0;
}