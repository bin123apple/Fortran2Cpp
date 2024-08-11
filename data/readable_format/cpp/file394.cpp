// hello.cpp
#include <iostream>

// Declaration of functions
void greet();
void performCalculation();

int main() {
    greet();
    performCalculation();
    return 0;
}

// Definition of functions
void greet() {
    std::cout << "Hello, World!" << std::endl;
}

void performCalculation() {
    int result = 3 + 4;
    std::cout << "The sum of 3 and 4 is " << result << "." << std::endl;
}