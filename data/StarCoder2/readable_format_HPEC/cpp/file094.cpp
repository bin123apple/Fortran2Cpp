#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len), b(len);

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
        b[i] = i + 2;
    }

    #pragma omp simd
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + b[i];
    }

    std::cout << "a[50] = " << a[50] << std::endl;

    return 0;
}
