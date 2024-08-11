#include <iostream>
#include <cstdlib>  // For exit()

void foo() {
    int A[30];
    int* p = A;  // Pointer to the array A

    A[2] = 777;  // Arrays are 0-based in C++
    p[8] = 777;
    A[8] = 999;

    if (A[2] != 777 || A[8] != 999) {
        std::cerr << "Error: Values do not match expected results" << std::endl;
        std::exit(1);  // Equivalent to stop 1 in Fortran
    }
}

int main() {
    foo();
    return 0;
}