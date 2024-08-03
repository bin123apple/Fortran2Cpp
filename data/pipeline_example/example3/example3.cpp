#include <cmath>
#include <cassert>
#include <iostream>

// Function definition
float PGCT01(int RGB, int CI, int CIMIN, int CIMAX) {
    const int R = 1;
    const int G = 2;
    const int B = 3;

    float X = static_cast<float>(CI - CIMIN) / static_cast<float>(CIMAX - CIMIN);

    if (RGB == R) {
        return std::pow(std::sin(X * 3.0f), 2);
    } else if (RGB == G) {
        return std::pow(std::sin(X * 5.0f), 2);
    } else if (RGB == B) {
        return std::pow(std::sin(X * 7.0f), 2);
    }

    return 0.0f;  // Return a default value if none of the conditions match
}

int main() {
    // Unit tests
    assert(std::abs(PGCT01(1, 1, 0, 10) - std::pow(std::sin(1.0 / 10.0 * 3.0), 2)) < 1E-6 && "Test case 1 failed");
    assert(std::abs(PGCT01(2, 5, 0, 10) - std::pow(std::sin(5.0 / 10.0 * 5.0), 2)) < 1E-6 && "Test case 2 failed");
    assert(std::abs(PGCT01(3, 7, 0, 10) - std::pow(std::sin(7.0 / 10.0 * 7.0), 2)) < 1E-6 && "Test case 3 failed");

    std::cout << "All test cases passed." << std::endl;

    return 0;
}