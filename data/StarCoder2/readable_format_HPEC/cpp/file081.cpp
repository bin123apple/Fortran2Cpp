#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int i, error, len, b;
    std::vector<int> a;

    len = 1000;
    b = 5;
    a.resize(len);

    for (i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
    }

    #pragma omp parallel shared(b, error)
    {
        #pragma omp for nowait
        for (i = 0; i < len; ++i) {
            a[i] = b + a[i] * 5;
        }
    }

    #pragma omp barrier
    #pragma omp single
    error = a[8] + 1; // Adjusting index for 0-based array

    std::cout << "error = " << error << std::endl;

    return 0;
}
