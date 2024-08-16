#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len;
    std::vector<int> a;

    // Assuming len is initialized somewhere
    // For demonstration, let's say len = 10
    len = 10;

    // Allocate and initialize the vector
    a.resize(len);
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-indexed, C++ arrays are 0-indexed
    }

    // OpenMP target directive
    #pragma omp target map(a[0:len])
    {
        // OpenMP parallel for directive
        #pragma omp parallel for
        for (int i = 0; i < len; ++i) {
            a[i] = a[i] + 1;
        }
    }

    // Deallocate the vector
    a.clear();

    return 0;
}
