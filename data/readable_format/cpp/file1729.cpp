#include <iostream>
#include <cassert>

// Function to swap two float values
void swap(float& x, float& y) {
    float aux = x;
    x = y;
    y = aux;
}

// Function to test the swap function
void test_swap() {
    float a = 2.0f;
    float b = 3.0f;
    float original_a = a;
    float original_b = b;

    // Call swap function
    swap(a, b);

    // Assert that the values have been swapped
    assert(a == original_b && b == original_a);

    if (a == original_b && b == original_a) {
        std::cout << "Test Passed: a and b were successfully swapped." << std::endl;
    } else {
        std::cerr << "Test Failed: a and b were not swapped correctly." << std::endl;
    }
}

int main() {
    // Calling the test function
    test_swap();

    return 0;
}