#include <iostream>

// Function declaration
void greet();
int addNumbers(int a, int b);

int main() {
    greet();
    std::cout << "The sum of 5 and 10 is: " << addNumbers(5, 10) << std::endl;
    return 0;
}

// Function definitions
void greet() {
    std::cout << "Hello, World!" << std::endl;
}

int addNumbers(int a, int b) {
    return a + b;
}