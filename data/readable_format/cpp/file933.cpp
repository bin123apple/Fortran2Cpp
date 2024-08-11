#include <iostream>
#include <cassert>

// Function declaration and definition
float addNumbers(float number1, float number2) {
    return number1 + number2;
}

// A simple test function
void testAddNumbers() {
    // Test case 1: Positive numbers
    assert(addNumbers(5.0, 3.0) == 8.0);
    std::cout << "Test Case 1 Passed: 5.0 + 3.0 = 8.0" << std::endl;

    // Test case 2: Negative numbers
    assert(addNumbers(-2.0, -3.0) == -5.0);
    std::cout << "Test Case 2 Passed: -2.0 + -3.0 = -5.0" << std::endl;

    // Test case 3: Mixed numbers
    assert(addNumbers(-5.0, 10.0) == 5.0);
    std::cout << "Test Case 3 Passed: -5.0 + 10.0 = 5.0" << std::endl;
}

int main() {
    // Running the test function to validate addNumbers
    testAddNumbers();

    // Additional demonstration of addNumbers function
    float num1, num2;
    std::cout << "Enter two numbers to add: ";
    std::cin >> num1 >> num2;
    std::cout << "The sum is: " << addNumbers(num1, num2) << std::endl;

    return 0;
}