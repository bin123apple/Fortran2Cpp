#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 2000;
    std::vector<int> a(len); // Dynamic array with 2000 elements

    // Filling the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjusting for 1-based indexing in Fortran
    }

    // Parallel section to modify the array
    #pragma omp parallel for
    for (int i = 0; i < 1000; ++i) {
        a[2 * i] = a[i] + 1; // Adjusting for 0-based indexing in C++
    }

    // Printing the result
    std::cout << "a[1002-1] = " << a[1002 - 1] << std::endl; // Adjusting for 0-based indexing in C++

    return 0;
}
