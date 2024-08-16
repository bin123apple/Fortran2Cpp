#include <iostream>
#include <vector>
#include <omp.h>

// Assuming the existence of a function `foo` similar to the Fortran version
double foo(const std::vector<double>& a, std::vector<double>& b, int len);

int main() {
    const int len = 1000;
    std::vector<double> a(len), b(len, 0.0); // Initialize b with 0.0

    // Parallel loop to populate vectors a and b
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] = static_cast<double>(i + 1) / 2.0;
    }

    double x = foo(a, b, len);
    std::cout << "b[49] = " << b[49] << std::endl; // Note: C++ uses 0-based indexing

    return 0;
}

// Dummy implementation of foo for demonstration. You should replace it with the actual logic.
double foo(const std::vector<double>& a, std::vector<double>& b, int len) {
    double sum = 0.0;
    for (int i = 0; i < len; ++i) {
        sum += a[i] * b[i];
    }
    return sum;
}
