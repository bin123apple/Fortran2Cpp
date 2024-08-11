#include <iostream>

// Declaration in a header-like fashion for clarity.
void printNumber();

int main() {
    printNumber();
    return 0;
}

// Definition
void printNumber() {
    std::cout << 42 << std::endl;
}