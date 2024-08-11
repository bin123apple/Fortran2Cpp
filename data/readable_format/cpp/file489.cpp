#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib> // For std::exit()

int test_foo() {
    float x;
    double y;

    x = std::numeric_limits<float>::signaling_NaN();
    if (!std::isnan(x)) return 1;
    x = std::numeric_limits<float>::quiet_NaN();
    if (!std::isnan(x)) return 2;

    x = std::numeric_limits<float>::infinity();
    if (std::isfinite(x)) return 3;
    x = -std::numeric_limits<float>::infinity();
    if (std::isfinite(x)) return 4;

    y = std::numeric_limits<double>::signaling_NaN();
    if (!std::isnan(y)) return 5;
    y = std::numeric_limits<double>::quiet_NaN();
    if (!std::isnan(y)) return 6;

    y = std::numeric_limits<double>::infinity();
    if (std::isfinite(y)) return 7;
    y = -std::numeric_limits<double>::infinity();
    if (std::isfinite(y)) return 8;

    return 0; // All tests passed
}

int main() {
    int result = test_foo();
    if (result != 0) {
        std::cerr << "Test failed with code: " << result << std::endl;
        std::exit(result); // Optionally exit with a non-zero status to indicate failure
    } else {
        std::cout << "All tests passed." << std::endl;
    }
    return 0; // Indicates success
}