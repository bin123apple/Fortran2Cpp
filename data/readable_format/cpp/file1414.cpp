#include <iostream>
#include <cstdlib> // For exit()

void checkv(int& ires, int a[][3], int rows, int cols, int opt1 = -1) {
    if (opt1 == -1) {
        // If opt1 is not provided, count all elements.
        ires = rows * cols;
    } else if (opt1 == 1) {
        // If opt1 is provided and equals 1, count rows (Fortran's first dimension).
        ires = rows;
    } else if (opt1 == 2) {
        // If opt1 is provided and equals 2, count columns (Fortran's second dimension).
        ires = cols;
    } else {
        // Handle unexpected dimension request.
        std::cerr << "Invalid dimension specified for size calculation." << std::endl;
        std::exit(1);
    }
}

int main() {
    int a[2][3]; // Equivalent to Fortran's 'integer :: a(2,3)'
    int ires;

    // Equivalent to Fortran's 'call checkv (ires, a)'
    checkv(ires, a, 2, 3);
    if (ires != 6) std::exit(1);

    // Equivalent to Fortran's 'call checkv (ires, a, 1)'
    checkv(ires, a, 2, 3, 1);
    if (ires != 2) std::exit(2);

    return 0;
}