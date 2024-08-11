#include <complex>
#include <cmath>

float SCABS1(std::complex<float> z) {
    return std::abs(z.real()) + std::abs(z.imag());
}