#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len), b(len), c(len);

    // Initialize vectors b and c for demonstration purposes
    for (int i = 0; i < len; ++i) {
        b[i] = i; // Example initialization
        c[i] = i * 2; // Example initialization
    }

    #pragma omp simd
    for (int i = 0; i < len; ++i) {
        a[i] = b[i] + c[i];
    }

    // Optional: Print the results to verify correctness
    // for (int i = 0; i < len; ++i) {
    //     std::cout << "a[" << i << "] = " << a[i] << std::endl;
    // }

    return 0;
}
