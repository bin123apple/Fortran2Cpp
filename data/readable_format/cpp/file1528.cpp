#include <iostream>
#include <vector>
#include <cmath>

// Function Prototype
void NEWPR(int Nz, std::vector<double>& PzNew, const std::vector<double>& PZOLD, const std::vector<double>& CORR, double SCALAR);

int main() {
    const int maxz = 5;
    std::vector<double> PzNew(maxz), PZOLD = {1.0, 2.0, 3.0, 4.0, 5.0}, CORR = {0.1, 0.2, 0.3, 0.4, 0.5};
    double SCALAR = 2.0;

    // Call the function to update the PzNew vector
    NEWPR(maxz, PzNew, PZOLD, CORR, SCALAR);

    // Expected PzNew values based on PZOLD, CORR, and SCALAR
    std::vector<double> expected = {1.2, 2.4, 3.6, 4.8, 6.0};

    bool testPassed = true;
    for (int i = 0; i < maxz; ++i) {
        if (std::fabs(PzNew[i] - expected[i]) > 1e-6) { // Comparing floating-point numbers
            testPassed = false;
            break;
        }
    }

    if (testPassed) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}

// Function Definition
void NEWPR(int Nz, std::vector<double>& PzNew, const std::vector<double>& PZOLD, const std::vector<double>& CORR, double SCALAR) {
    for (int I = 0; I < Nz; ++I) {
        PzNew[I] = PZOLD[I] + SCALAR * CORR[I];
    }
}