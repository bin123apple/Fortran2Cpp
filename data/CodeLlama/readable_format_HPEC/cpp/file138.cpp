#include <iostream>
#include <vector>
#include <omp.h>

// Assuming the existence of a function foo similar to the Fortran version
double foo(const std::vector<double>& a, std::vector<double>& b, int len) {
    double sum = 0.0;
    for (int i = 0; i < len; ++i) {
        b[i] = a[i] / 2.0;
        sum += a[i];
    }
    return sum;
}

int main() {
    const int len = 1000;
    std::vector<double> a(len), b(len);

    // Initialize vectors a and b
    for (int i = 0; i < len; ++i) {
        a[i] = static_cast<double>(i + 1) / 2.0;
        b[i] = 0.0;
    }

    double x = foo(a, b, len);

    // Print the 50th element of b
    std::cout << "b(50) = " << b[49] << std::endl; // Note: C++ uses 0-based indexing

    return 0;
}
