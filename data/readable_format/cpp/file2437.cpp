#include <iostream>

// Function to be tested
int add(int a, int b) {
    return a + b;
}

// Test function
void testAdd() {
    int result = add(2, 3);
    if (result == 5) {
        std::cout << "Test passed: 2 + 3 = " << result << std::endl;
    } else {
        std::cout << "Test failed: 2 + 3 did not equal " << result << std::endl;
    }
}

int main() {
    // Main program logic (if any)
    std::cout << "Main program running..." << std::endl;

    // Call the test
    testAdd();

    return 0;
}