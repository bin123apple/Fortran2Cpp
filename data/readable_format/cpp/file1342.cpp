#include <iostream>
#include <complex>
#include <cmath>
#include <cassert>

// Definition of the ZEXP function.
void ZEXP(double AR, double AI, double& BR, double& BI) {
    std::complex<double> Z(AR, AI); // Construct complex number from real (AR) and imaginary (AI) parts
    std::complex<double> result = std::exp(Z); // Calculate the complex exponential

    BR = std::real(result); // Extract real part
    BI = std::imag(result); // Extract imaginary part
}

// Function prototype for test cases.
void test_case(double AR, double AI, double expectedBR, double expectedBI) {
    double BR, BI;
    ZEXP(AR, AI, BR, BI);

    // Asserting with a small delta to account for floating-point arithmetic inaccuracies.
    assert(std::abs(BR - expectedBR) < 1e-9);
    assert(std::abs(BI - expectedBI) < 1e-9);

    std::cout << "Test passed for input (" << AR << ", " << AI << ")."
              << " Result: (" << BR << ", " << BI << ")" << std::endl;
}

// Main function to execute test cases.
int main() {
    // Test case 1: e^(1.0 + 0.0i) = e^1.0
    test_case(1.0, 0.0, std::exp(1.0), 0.0);

    // Test case 2: e^(0.0 + 1.0i) = cos(1.0) + isin(1.0) (Euler's formula)
    test_case(0.0, 1.0, std::cos(1.0), std::sin(1.0));

    // Test case 3: e^(-1.0 - 1.0i)
    std::complex<double> expectedResult = std::exp(std::complex<double>(-1.0, -1.0));
    test_case(-1.0, -1.0, std::real(expectedResult), std::imag(expectedResult));

    // Test case 4: e^(0.5 + 0.5i)
    expectedResult = std::exp(std::complex<double>(0.5, 0.5));
    test_case(0.5, 0.5, std::real(expectedResult), std::imag(expectedResult));

    return 0;
}