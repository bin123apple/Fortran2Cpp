#include <iostream>
#include <string>

// Function declaration
void add_integers(int a, int b, int& result);

// A simple test function
void test_add_integers();

int main() {
    // Run the test
    test_add_integers();

    return 0;
}

// Function definition
void add_integers(int a, int b, int& result) {
    result = a + b;
}

// A very simple test "framework"
void test_add_integers() {
    int result;
    add_integers(2, 3, result);
    if (result == 5) {
        std::cout << "Test passed: 2 + 3 = " << result << std::endl;
    } else {
        std::cout << "Test failed: 2 + 3 did not equal " << result << std::endl;
    }
}