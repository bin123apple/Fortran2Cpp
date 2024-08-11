#include <iostream>

// Namespace equivalent functionality directly in the global scope
int add_two_numbers(int a, int b) {
    return a + b;
}

// A very basic "test framework" to simulate what a unit test might do
void test_add_two_numbers() {
    int result = add_two_numbers(2, 3);
    if (result == 5) {
        std::cout << "Test passed: add_two_numbers(2, 3) == 5" << std::endl;
    } else {
        std::cout << "Test failed: add_two_numbers(2, 3) != 5, got " << result << std::endl;
    }
}

int main() {
    // Run our basic test
    test_add_two_numbers();
    
    return 0;
}