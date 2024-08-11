#include <iostream>

// Declaration of function pointer type
using Subroutine = void (*)(int);

// Forward declaration of sub2 to be used in sub1
void sub2(int num);

// Equivalent to subroutine sub1 in Fortran
void sub1(Subroutine sub) {
    sub(1); // Calling the passed function with argument 1
}

// Equivalent to subroutine sub2 in Fortran
void sub2(int num) {
    std::cout << num << std::endl;
}

// Equivalent to the main program in Fortran
int main() {
    sub1(sub2); // Passing sub2 as an argument to sub1
    return 0;
}