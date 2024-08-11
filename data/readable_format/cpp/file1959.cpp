#include <iostream>

// Function Declaration and Definition
void F1() {
    // Body of F1
}

// Test Function
void testF1() {
    try {
        F1(); // Attempt to call F1
        std::cout << "F1 executed successfully." << std::endl;
    } catch (...) {
        std::cout << "F1 execution failed with an exception." << std::endl;
    }
}

int main() {
    testF1(); // Execute test
    return 0;
}