#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<double> a(len), b(len), c(len);
    int i, j;

    // Initialization of arrays a, b, and c
    for (i = 0; i < len; ++i) {
        a[i] = static_cast<double>(i) / 2.0;
        b[i] = static_cast<double>(i) / 3.0;
        c[i] = static_cast<double>(i) / 7.0;
    }

    // Parallel loop with linear clause
    #pragma omp parallel for
    for (i = 0; i < len; ++i) {
        #pragma omp atomic
        c[j] += a[i] * b[i];
        j = (j + 1) % len; // Increment j and wrap around if necessary
    }

    // Print the value of c[49] (since C++ uses 0-based indexing)
    std::cout << "c[49] = " << c[49] << std::endl;

    return 0;
}
