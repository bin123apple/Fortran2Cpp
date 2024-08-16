#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 1000;
    std::vector<int> a(len);

    a[0] = 2; // Arrays in C++ are 0-indexed

    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] = a[i] + a[0];
    }

    // Printing the 500th element (1-indexed in the original Fortran code)
    std::cout << "a[499] = " << a[499] << std::endl; // Adjusted for 0-indexing

    return 0;
}
