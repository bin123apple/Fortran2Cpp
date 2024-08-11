#include <iostream>
#include <vector>

// Function to test
void foo(const std::vector<int>& x) {
    int sum = 0;
    for (int num : x) {
        sum += num;
    }
    std::cout << "Sum = " << sum << std::endl;
}

// Basic testing function
void testFooFunction() {
    std::vector<int> testVector = {1, 2, 3, 4, 5};
    std::cout << "Testing foo with input {1, 2, 3, 4, 5}..." << std::endl;
    foo(testVector); // This should output: Sum = 15
}

int main() {
    testFooFunction(); // Run our basic test
    return 0;
}