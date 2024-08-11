#include <cmath> // For std::abs, std::sqrt
#include <iostream> // For std::cout
#include <cassert> // For assert

double dlapy2(double x, double y) {
    const double ZERO = 0.0;
    const double ONE = 1.0;

    double w, xabs, yabs, z;

    xabs = std::abs(x);
    yabs = std::abs(y);
    w = std::max(xabs, yabs);
    z = std::min(xabs, yabs);

    if (z == ZERO) {
        return w;
    } else {
        return w * std::sqrt(ONE + (z / w) * (z / w));
    }
}

int main() {
    // Set a tolerance for floating point comparisons
    const double tol = 1e-9;

    // Test case 1
    assert(std::abs(dlapy2(3.0, 4.0) - 5.0) < tol);

    // Test case 2
    assert(std::abs(dlapy2(5.0, 12.0) - 13.0) < tol);

    // Test case 3
    assert(std::abs(dlapy2(8.0, 0.0) - 8.0) < tol);

    // Test case 4
    assert(std::abs(dlapy2(0.0, 0.0)) < tol);

    std::cout << "All tests passed successfully!";

    return 0;
}