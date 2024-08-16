#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len), b(len);
    int tmp, tmp2;

    // Initialize arrays a and b
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
        b[i] = i + 1;
    }

    // Parallel region for array a
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < len; ++i) {
            tmp = a[i] + (i + 1); // Adjust for 0-based indexing
            a[i] = tmp;
        }
    }

    // Parallel region for array b
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < len; ++i) {
            tmp2 = b[i] + (i + 1); // Adjust for 0-based indexing
            b[i] = tmp2;
        }
    }

    // Print values of a and b at index 50 (equivalent to 50 in Fortran)
    std::cout << a[49] << " " << b[49] << std::endl; // Adjust for 0-based indexing

    return 0;
}
