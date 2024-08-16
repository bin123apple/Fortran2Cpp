#include <iostream>
#include <omp.h>

int main() {
    int i, len;
    int a[1000];

    len = 1000;

    for (i = 1; i <= len; i++) {
        a[i-1] = i; // Fortran arrays are 1-indexed, C++ arrays are 0-indexed
    }

    #pragma omp parallel for
    for (i = 1; i <= len-1; i++) {
        a[i-1] = a[i] + 1;
    }

    std::cout << "a(500) = " << a[499] << std::endl; // Fortran arrays are 1-indexed, C++ arrays are 0-indexed

    return 0;
}
