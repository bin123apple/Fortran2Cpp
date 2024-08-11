#include <iostream>
#include <complex>
#include <cmath> // For std::abs

void testConjugate(const std::complex<double>& original, const std::complex<double>& expectedConjugate) {
    auto conjugate = std::conj(original);
    // Check if the real parts are close enough
    bool realCheck = std::abs(conjugate.real() - expectedConjugate.real()) < 1e-6;
    // Check if the imaginary parts are close enough
    bool imagCheck = std::abs(conjugate.imag() - expectedConjugate.imag()) < 1e-6;

    if (realCheck && imagCheck) {
        std::cout << "Test passed for (" << original.real() << "+" << original.imag() << "i). "
                  << "Conjugate is (" << conjugate.real() << "+" << conjugate.imag() << "i)" << std::endl;
    } else {
        std::cout << "Test failed for (" << original.real() << "+" << original.imag() << "i). "
                  << "Expected conjugate is (" << expectedConjugate.real() << "+" << expectedConjugate.imag() << "i), "
                  << "but got (" << conjugate.real() << "+" << conjugate.imag() << "i)" << std::endl;
    }
}

int main() {
    std::complex<float> z(2.0, 3.0); // equivalent to Fortran's 'complex'
    std::complex<double> dz(2.71, -3.14); // equivalent to Fortran's 'complex(KIND=8)'

    // Taking the conjugate of the complex numbers
    z = std::conj(z);
    dz = std::conj(dz);

    // Print the complex numbers
    std::cout << "z = " << z.real() << (z.imag() >= 0 ? "+" : "") << z.imag() << "i" << std::endl;
    std::cout << "dz = " << dz.real() << (dz.imag() >= 0 ? "+" : "") << dz.imag() << "i" << std::endl;

    // Run tests
    testConjugate(std::complex<double>(2.0, 3.0), std::complex<double>(2.0, -3.0));
    testConjugate(std::complex<double>(2.71, -3.14), std::complex<double>(2.71, 3.14));

    return 0;
}