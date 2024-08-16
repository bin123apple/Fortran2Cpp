#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<double> a(len), b(len), c(len);
    int i, j;

    // Initialize arrays a, b, and c
    for (i = 0; i < len; ++i) {
        a[i] = static_cast<double>(i) / 2.0;
        b[i] = static_cast<double>(i) / 3.0;
        c[i] = static_cast<double>(i) / 7.0;
    }

    // Parallel region to update c based on a and b
    #pragma omp parallel for
    for (i = 0; i < len; ++i) {
        c[i] = c[i] + a[i] * b[i];
    }

    // Print c[50]
    std::cout << "c[50] = " << c[50] << std::endl;

    return 0;
}
