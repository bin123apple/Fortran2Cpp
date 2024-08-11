#include <array>

double r3dot(const std::array<double, 3>& x, const std::array<double, 3>& y) {
    return x[0] * y[0] + x[1] * y[1] + x[2] * y[2];
}