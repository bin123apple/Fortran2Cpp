#include <iostream>

// Define global variables to mimic the Fortran COMMON block
namespace bar {
    int a;
    int b;
}

// Function to mimic the Fortran subroutine
void foo() {
    bar::a = 1;
    bar::b = 2;
}

int main() {
    foo();
    std::cout << "a = " << bar::a << ", b = " << bar::b << std::endl;
    return 0;
}