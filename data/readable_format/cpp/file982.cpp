#include <iostream>
#include <complex>
#include <cmath>
#include <cassert>

// Helper function to compare floating-point numbers
bool nearlyEqual(float a, float b, float epsilon = 1e-5) {
    return std::fabs(a - b) < epsilon;
}

int main() {
    const std::complex<float> C1(-3.4, 0);
    const std::complex<float> C2(-3, 0);

    const float F1 = -3;
    const float F2 = -3.4;

    // Unit Tests
    assert(C1 == std::complex<float>(-3.4, 0) && "Test C1 Failed");
    assert(C2 == std::complex<float>(-3, 0) && "Test C2 Failed");
    assert(F1 == -3 && "Test F1 Failed");
    assert(nearlyEqual(F2, -3.4) && "Test F2 Failed"); // Using nearlyEqual for floating-point comparison

    std::cout << "All tests passed." << std::endl;

    return 0;
}