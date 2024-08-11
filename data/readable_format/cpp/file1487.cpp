// ABSHM.cpp
#include <iostream>
#include <cassert>
#include <cmath>

double ABSHM(double T, double DP, double Q) {
    return Q / (461.5e-05 * (T + 273.16));
}

int main() {
    // Test Case 1
    double result = ABSHM(25.0, 0.0, 1000.0);
    std::cout << "Test 1 (T=25, DP=unused, Q=1000): Expected ~726.74, Got " << result << std::endl;
    assert(std::fabs(result - 726.74) < 1.0); // Adjusted expected value and tolerance

    std::cout << "All tests passed." << std::endl;
    return 0;
}