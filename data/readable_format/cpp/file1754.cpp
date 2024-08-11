#include <iostream>
#include <complex>

int main() {
    // Using double for the complex number's type, equivalent to COMPLEX(KIND=8) in Fortran
    std::complex<double> K;

    // Assuming K is initialized somehow, otherwise it will just be (0,0)
    // For demonstration, let's assign a value to K
    K = std::complex<double>(3.0, 4.0); // Example value

    // Printing the complex conjugate of K
    std::cout << std::conj(K) << std::endl;

    // Printing the imaginary part of K
    std::cout << imag(K) << std::endl;

    return 0;
}