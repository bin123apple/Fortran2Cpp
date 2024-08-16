#include <iostream>
#include <omp.h>

int main() {
    const int len = 100;
    int a[len], b[len];

    // Initialize arrays a and b
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjusted for 0-based indexing
        b[i] = i + 2; // Adjusted for 0-based indexing
    }

    // Parallel SIMD operation
    #pragma omp simd
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + b[i]; // Adjusted for 0-based indexing
    }

    // Print the results
    for (int i = 0; i < len; ++i) {
        std::cout << "Values for i and a[i] are: " << i + 1 << " " << a[i] << std::endl; // Adjusted for 0-based indexing and output
    }

    return 0;
}
