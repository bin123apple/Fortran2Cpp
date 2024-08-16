#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int b = 5;
    int len = 1000;
    std::vector<int> a(len);
    int error;

    // Initialize array a
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
    }

    // Parallel region with shared variables b and error
    #pragma omp parallel shared(b, error)
    {
        // Another parallel region
        #pragma omp parallel for
        for (int i = 0; i < len; ++i) {
            a[i] = b + a[i] * 5;
        }

        // Single region to update error
        #pragma omp single
        {
            error = a[9] + 1; // Note: C++ uses 0-based indexing
        }
    }

    // Print error
    std::cout << "error = " << error << std::endl;

    return 0;
}
