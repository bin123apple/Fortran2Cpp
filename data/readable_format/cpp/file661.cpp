#include <complex>
#include <cmath>

double DCABS1(const std::complex<double>& Z) {
    return std::abs(Z.real()) + std::abs(Z.imag());
}