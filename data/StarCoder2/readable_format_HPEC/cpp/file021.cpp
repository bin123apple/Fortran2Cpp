#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len);

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-indexed, C++ arrays are 0-indexed
    }

    // Parallel processing with OpenMP
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        int tmp = a[i] + i + 1; // Adjust for 1-indexing
        a[i] = tmp;
    }

    // Print the result
    std::cout << "a[50-1]= " << a[50-1] << std::endl; // Adjust for 0-indexing

    return 0;
}
