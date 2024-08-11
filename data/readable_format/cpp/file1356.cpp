#include <iostream>

// Function declaration
int functionExample(int x);

// Subroutine equivalent in C++
void subroutineExample();

int main() {
    // Using the subroutine equivalent
    subroutineExample();

    // Using the function
    std::cout << "Result from functionExample: " << functionExample(5) << std::endl;

    return 0;
}

// Function definition
int functionExample(int x) {
    return 2 * x;
}

// Subroutine equivalent in C++
void subroutineExample() {
    std::cout << "Hello from subroutineExample!" << std::endl;
}