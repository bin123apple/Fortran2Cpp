#include <iostream>

// Function to add two numbers
int addTwoNumbers(int a, int b) {
    return a + b;
}

// A simple test for the addTwoNumbers function
void testAddTwoNumbers() {
    int result = addTwoNumbers(2, 3);
    if (result == 5) {
        std::cout << "Test passed: 2 + 3 = " << result << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
}

int main() {
    // Run the test
    testAddTwoNumbers();

    return 0;
}