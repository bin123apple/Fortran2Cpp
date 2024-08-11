#include <iostream>
#include <cassert>

// Function to add two numbers
int addTwoNumbers(int a, int b) {
    return a + b;
}

// Unit test for the addTwoNumbers function
void testAddTwoNumbers() {
    assert(addTwoNumbers(2, 3) == 5);
    std::cout << "Test passed: addTwoNumbers test";
}

int main() {
    testAddTwoNumbers();
    return 0;
}