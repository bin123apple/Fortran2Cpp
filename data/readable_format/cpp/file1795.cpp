#include <iostream>

// Declaration and definition of refer function
void refer() {
    std::cout << "Hello from refer" << std::endl;
}

// A simple test function that calls refer
void testRefer() {
    std::cout << "Testing refer function:" << std::endl;
    refer();
}

int main() {
    testRefer(); // Run our simple test
    return 0;
}