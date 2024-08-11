#include <iostream>
#include <cassert>

// Function to be tested
int add(int a, int b) {
    return a + b;
}

// Test function
void testAdd() {
    assert(add(1, 2) == 3);
    assert(add(-1, -2) == -3);
    assert(add(-5, 5) == 0);

    // Add more tests as needed
    std::cout << "All tests passed." << std::endl;
}

int main() {
    testAdd();
    return 0;
}