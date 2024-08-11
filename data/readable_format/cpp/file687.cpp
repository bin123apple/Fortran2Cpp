#include <iostream>
#include <complex>
using namespace std;

int main() {
    int I;
    complex<double> Z;
    bool L;
    int B[2];

    // Assuming you've initialized I, Z, L, and B somewhere in your code

    // Translate the arithmetic IF for I
    if (I > 0) {
        // Corresponds to label 300 in Fortran
    } else if (I == 0) {
        // Corresponds to label 200 in Fortran
    } else {
        // Corresponds to label 100 in Fortran
    }

    // Translate the arithmetic IF for Z
    // Check if Z is non-zero for "true"
    if (real(Z) != 0 || imag(Z) != 0) {
        // Assuming a non-zero complex number is treated as positive
        // Corresponds to label 301 in Fortran
    } else {
        // Corresponds to label 201 in Fortran
        // Note: There's no direct negative condition for complex numbers in this context
    }

    // Translate the arithmetic IF for L
    if (L) {
        // Corresponds to label 302 in Fortran
    } else {
        // Corresponds to label 202 in Fortran
    }

    // Since direct array condition checks are not possible in the same way as Fortran,
    // we assume checking if any element is non-zero.
    bool anyNonZero = B[0] != 0 || B[1] != 0;
    if (anyNonZero) {
        // Corresponds to label 303 in Fortran
    } else {
        // Corresponds to label 203 in Fortran
    }

    return 0;
}