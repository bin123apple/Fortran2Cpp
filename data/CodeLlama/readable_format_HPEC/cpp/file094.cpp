#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<int> a(len), b(len);

    // Initialize arrays a and b
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjusted for 0-based indexing in C++
        b[i] = i + 2; // Adjusted for 0-based indexing in C++
    }

    // SIMD operation
    #pragma omp simd
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + b[i];
    }

    // Print the result
    std::cout << "a[49] = " << a[49] << std::endl; // Adjusted for 0-based indexing in C++

    return 0;
}
