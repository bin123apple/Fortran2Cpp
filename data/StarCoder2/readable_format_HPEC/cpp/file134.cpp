#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len), b(len);
    static int tmp;
    int tmp2;

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjusting for 1-based indexing in Fortran
        b[i] = i + 1; // Adjusting for 1-based indexing in Fortran
    }

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < len; ++i) {
            tmp = a[i] + i + 1; // Adjusting for 1-based indexing in Fortran
            a[i] = tmp;
        }
    }

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < len; ++i) {
            tmp2 = b[i] + i + 1; // Adjusting for 1-based indexing in Fortran
            b[i] = tmp2;
        }
    }

    std::cout << a[49] << " " << b[49] << std::endl; // Adjusting for 0-based indexing in C++

    return 0;
}
