#include <iostream>
#include <array>
#include <cmath>

// Function to calculate the axis vector from a rotation matrix
void sla_DM2AV(const std::array<std::array<double, 3>, 3>& RMAT, std::array<double, 3>& AXVEC) {
    double X, Y, Z, S2, C2, PHI, F;

    X = RMAT[1][2] - RMAT[2][1];
    Y = RMAT[2][0] - RMAT[0][2];
    Z = RMAT[0][1] - RMAT[1][0];
    S2 = std::sqrt(X*X + Y*Y + Z*Z);
    
    if (S2 != 0.0) {
        C2 = RMAT[0][0] + RMAT[1][1] + RMAT[2][2] - 1.0;
        PHI = std::atan2(S2, C2);
        F = PHI / S2;
        
        AXVEC[0] = X * F;
        AXVEC[1] = Y * F;
        AXVEC[2] = Z * F;
    } else {
        AXVEC[0] = 0.0;
        AXVEC[1] = 0.0;
        AXVEC[2] = 0.0;
    }
}

// Main function for the unit test
int main() {
    std::array<std::array<double, 3>, 3> RMAT = {{
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0}
    }};
    std::array<double, 3> AXVEC;
    const double TOL = 1.0E-12;

    // Call the sla_DM2AV function
    sla_DM2AV(RMAT, AXVEC);

    // Check the result
    bool testPassed = true;
    for (int i = 0; i < 3; ++i) {
        if (std::abs(AXVEC[i]) > TOL) {
            std::cerr << "Test failed for element " << i << " Value: " << AXVEC[i] << std::endl;
            testPassed = false;
            break;
        }
    }

    if (testPassed) {
        std::cout << "C++ test passed successfully." << std::endl;
    } else {
        std::cerr << "C++ test failed." << std::endl;
    }

    return testPassed ? 0 : 1;
}