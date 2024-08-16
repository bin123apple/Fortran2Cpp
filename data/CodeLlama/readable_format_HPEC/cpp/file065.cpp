#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<int> a(len), b(len), c(len);

    // Initialize vectors b and c with some values
    for (int i = 0; i < len; ++i) {
        b[i] = i;
        c[i] = i * 2;
    }

    // Parallel SIMD operation to compute a = b + c
    #pragma omp simd
    for (int i = 0; i < len; ++i) {
        a[i] = b[i] + c[i];
    }

    // Optional: Print the results to verify
    for (int i = 0; i < len; ++i) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    return 0;
}
