// update_y.cpp
#include <iostream>
#include <vector>
#include <cmath> // For std::abs

// Function to update Y values based on the original Fortran code
void updateY(std::vector<double>& Y, const std::vector<double>& TILTS, const std::vector<double>& TILTC, double EKK, int I) {
    Y[0] = Y[0] - EKK * TILTS[I - 1];
    Y[1] = Y[1] + EKK * TILTC[I - 1];
}

// Simple function to test the updateY function
bool testUpdateY() {
    std::vector<double> Y = {1.0, 1.0};
    std::vector<double> TILTS = {0.5};
    std::vector<double> TILTC = {0.3};
    double EKK = 2.0;
    int I = 1;

    updateY(Y, TILTS, TILTC, EKK, I);

    // Check the results with a tolerance for floating-point comparison
    const double tolerance = 1e-7;
    bool test1 = std::abs(Y[0] + 0.0) < tolerance; // Corrected expected value
    bool test2 = std::abs(Y[1] - 1.6) < tolerance;

    return test1 && test2;
}

int main() {
    if (testUpdateY()) {
        std::cout << "C++ Test passed." << std::endl;
    } else {
        std::cout << "C++ Test failed." << std::endl;
    }

    return 0;
}