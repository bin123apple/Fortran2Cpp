#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len;
    std::vector<int> a;

    // Allocate memory for the vector
    std::cout << "Enter the length of the vector: ";
    std::cin >> len;
    a.resize(len);

    // Initialize the vector
    for (int i = 0; i < len; i++) {
        a[i] = i + 1; // Note: Fortran uses 1-based indexing
    }

    // OpenMP target directive
    #pragma omp target teams distribute
    {
        // OpenMP parallel do directive
        #pragma omp parallel for
        for (int i = 0; i < len; i++) {
            a[i] += 1;
        }
    }

    // Deallocate memory
    a.clear();

    return 0;
}
