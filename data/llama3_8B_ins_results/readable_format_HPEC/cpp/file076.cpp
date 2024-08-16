#include <iostream>
#include <omp.h>

int main() {
    int i, j, len;
    double a[20][20];

    len = 20;

    for (i = 1; i <= len; i++) {
        for (j = 1; j <= len; j++) {
            a[i-1][j-1] = 0.5; // Note: Fortran uses 1-based indexing, C++ uses 0-based indexing
        }
    }

    #pragma omp parallel for private(j)
    for (i = 1; i < len; i++) {
        for (j = 1; j <= len; j++) {
            a[i-1][j-1] += a[i][j-1];
        }
    }

    std::cout << "a(10,10) = " << a[9][9] << std::endl;

    return 0;
}
