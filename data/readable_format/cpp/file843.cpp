#include <iostream>
#include <complex>
#include <cstdlib> // for std::abort

void foo(std::complex<double> p[10]) {
    for (int i = 0; i < 10; ++i) {
        if (p[i] != std::complex<double>(-0.2, 0.1)) {
            std::abort();
        }
    }
}

int main() {
    std::complex<double> p[10];
    
    // Initialize the array elements
    for (int i = 0; i < 10; ++i) {
        p[i] = std::complex<double>(0.1, 0.2);
    }
    
    // Perform the complex multiplication
    std::complex<double> multiplier(0.0, 1.0);
    for (int i = 0; i < 10; ++i) {
        p[i] *= multiplier;
    }
    
    foo(p);
    
    return 0;
}