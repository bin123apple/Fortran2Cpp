#include <complex>
#include <cmath>

double DCABS1(const std::complex<double>& z) {
    return std::abs(z.real()) + std::abs(z.imag());
}