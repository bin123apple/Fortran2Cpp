#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 2000;
    std::vector<int> a(len);

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
    }

    #pragma omp parallel for
    for (int i = 0; i < 1000; ++i) {
        a[2 * i] = a[i] + 1;
    }

    std::cout << "a[1001] = " << a[1001] << std::endl; // Adjusted index for 0-based array

    return 0;
}
