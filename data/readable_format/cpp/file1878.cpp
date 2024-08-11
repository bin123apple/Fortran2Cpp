#include <cmath>
#include <iostream>
#include <limits>
#include <cfenv>
#include <algorithm>

// Hypotenuse calculation function
double hypot_cpp(double x, double y) {
    std::feclearexcept(FE_ALL_EXCEPT);
    double result = std::hypot(x, y);

    if (std::fetestexcept(FE_OVERFLOW) || std::fetestexcept(FE_UNDERFLOW)) {
        std::feclearexcept(FE_OVERFLOW | FE_UNDERFLOW);
        if (x == 0.0 || y == 0.0) {
            result = std::abs(x) + std::abs(y);
        } else {
            int expX = std::ilogb(x);
            int expY = std::ilogb(y);
            if (2 * std::abs(expX - expY) > std::numeric_limits<double>::digits + 1) {
                result = std::max(std::abs(x), std::abs(y));
            } else {
                double scaledX = std::scalbn(x, -expX);
                double scaledY = std::scalbn(y, -expY);
                double scaledResult = std::sqrt(scaledX * scaledX + scaledY * scaledY);
                result = std::scalbn(scaledResult, expX);
            }
        }
    }

    return result;
}

// Simple test function
void test_hypot_cpp(double x, double y, double expected) {
    double result = hypot_cpp(x, y);
    if (std::abs(result - expected) < 1e-6) {
        std::cout << "PASS: hypot_cpp(" << x << ", " << y << ") = " << result << std::endl;
    } else {
        std::cout << "FAIL: hypot_cpp(" << x << ", " << y << ") = " << result << " (Expected: " << expected << ")" << std::endl;
    }
}

int main() {
    // Normal case
    test_hypot_cpp(3.0, 4.0, 5.0);

    // Overflow case (behavior may vary based on the platform and implementation)
    // test_hypot_cpp(1.0E+150, 1.0E+150, expected_value_for_overflow);

    // Underflow case (behavior may vary based on the platform and implementation)
    // test_hypot_cpp(1.0E-200, 1.0E-200, expected_value_for_underflow);

    // Large and small values
    // test_hypot_cpp(1.0E+150, 1.0E-150, expected_value_for_mixed_magnitude);

    return 0;
}