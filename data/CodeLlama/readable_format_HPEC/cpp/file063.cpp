#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 1000;
    std::vector<int> a(len); // Dynamic array of integers

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Arrays in C++ are 0-indexed, unlike Fortran which is 1-indexed
    }

    // OpenMP target region with map clause for array 'a'
    #pragma omp target map(a[0:len])
    {
        // Parallel loop to update the array
        #pragma omp parallel for
        for (int i = 0; i < len - 1; ++i) {
            a[i] = a[i + 1] + 1;
        }
    }

    // Print the array values
    for (int i = 0; i < len; ++i) {
        std::cout << "Values for i and a[i] are: " << i + 1 << " " << a[i] << std::endl;
    }

    return 0;
}
