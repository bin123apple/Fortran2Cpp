#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len);

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjusted to match Fortran's 1-based indexing
    }

    #pragma omp parallel for
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + 1;
    }

    std::cout << "a[50-1]=" << a[50-1] << std::endl; // Adjusted to 0-based indexing for C++

    return 0;
}
