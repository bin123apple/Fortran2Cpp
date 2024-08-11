// main_program.cpp
#include <iostream>
#include <vector>
#include <cmath>

void updateVectors(std::vector<double>& yv1, std::vector<double>& yv2,
                   const std::vector<double>& tiltc, const std::vector<double>& tilts,
                   const std::vector<std::vector<double>>& aaiv,
                   const std::vector<std::vector<double>>& bbiv,
                   const std::vector<double>& moidpsv) {
    size_t n = yv1.size();
    for (size_t j = 0; j < n; ++j) {
        for (size_t i = 0; i < n; ++i) {
            yv1[j] = yv1[j] + (tiltc[i] * bbiv[0][i] - tilts[i] * aaiv[0][i]) * moidpsv[j];
            yv2[j] = yv2[j] + (tiltc[i] * aaiv[0][i] + tilts[i] * bbiv[0][i]) * moidpsv[j];
        }
    }
}

void assertAlmostEqual(double a, double b, double tol = 1e-6) {
    if (std::fabs(a - b) > tol) {
        std::cerr << "Assertion failed: " << a << " is not approximately equal to " << b << std::endl;
        std::exit(1);
    }
}

void testUpdateVectors() {
    std::vector<double> yv1(5, 0.0), yv2(5, 0.0);
    std::vector<double> tiltc = {0.1, 0.2, 0.3, 0.4, 0.5};
    std::vector<double> tilts = {0.05, 0.1, 0.15, 0.2, 0.25};
    std::vector<std::vector<double>> aaiv = {{0.2, 0.4, 0.6, 0.8, 1.0}};
    std::vector<std::vector<double>> bbiv = {{0.3, 0.6, 0.9, 1.2, 1.5}};
    std::vector<double> moidpsv = {1.0, 2.0, 3.0, 4.0, 5.0};

    updateVectors(yv1, yv2, tiltc, tilts, aaiv, bbiv, moidpsv);

    // Assertions based on expected results
    assertAlmostEqual(yv1[0], 1.1); // Example assertions based on the Fortran output
    assertAlmostEqual(yv2[0], 1.925);
    // Add more assertions as needed
    std::cout << "All tests passed." << std::endl;
}

int main() {
    testUpdateVectors();
    return 0;
}