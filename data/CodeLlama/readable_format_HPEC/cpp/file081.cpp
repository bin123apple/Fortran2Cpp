#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 1000;
    int b = 5;
    std::vector<int> a(len);

    // Initialize array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
    }

    // Parallel region with shared variables
    #pragma omp parallel shared(b, a)
    {
        // Parallel for loop
        #pragma omp for
        for (int i = 0; i < len; ++i) {
            a[i] = b + a[i] * 5;
        }

        // Nowait to ensure the single region is not blocked by the for loop
        #pragma omp for nowait
        for (int i = 0; i < len; ++i) {
            a[i] = b + a[i] * 5;
        }
    }

    // Barrier to synchronize all threads
    #pragma omp barrier

    // Single region to compute error
    #pragma omp single
    {
        int error = a[8] + 1; // Arrays in C++ are 0-indexed, so a[9] in Fortran is a[8] in C++
        std::cout << "error = " << error << std::endl;
    }

    return 0;
}
