#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<int> a(len), b(len + len * len), c(len, 0);

    // Initialization of a and b
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            b[j + i * len] = 1;
        }
        a[i] = 1;
    }

    // Parallel computation using OpenMP
    #pragma omp target map(to:a,b) map(tofrom:c) device(0)
    {
        #pragma omp teams distribute parallel for
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                c[i] += a[j] * b[j + i * len];
            }
        }
    }

    // Check and print results
    for (int i = 0; i < len; ++i) {
        if (c[i] != len) {
            std::cout << c[i] << std::endl;
        }
    }

    return 0;
}
