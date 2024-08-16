#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len);
    std::vector<int> b(len);

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjusted for 0-based indexing
        b[i] = i + 2; // Adjusted for 0-based indexing
    }

    #pragma omp simd
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + b[i];
    }

    for (int i = 0; i < len; ++i) {
        std::cout << "Values for i and a[i] are: " << i + 1 << " " << a[i] << std::endl; // Adjusted for 1-based indexing for consistency with Fortran output
    }

    return 0;
}
