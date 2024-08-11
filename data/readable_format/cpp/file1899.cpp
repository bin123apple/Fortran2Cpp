#include <iostream>

// Simple function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Main function to test the add function
int main() {
    int result = add(2, 3);
    
    if (result == 5) {
        std::cout << "Test passed: 2 + 3 = " << result << std::endl;
    } else {
        std::cout << "Test failed: 2 + 3 did not equal " << result << std::endl;
    }

    return 0;
}