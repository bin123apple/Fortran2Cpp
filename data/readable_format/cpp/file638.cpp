#include <iostream>
#include <cmath> // For fabs

// Define the interp_trilinear function
void interp_trilinear(double di, double dj, double dk, float var[2][2][2], double &velp) {
    double i1, i2, i3, i4, j1, j2;

    i1 = (var[1][0][0] - var[0][0][0]) * di + var[0][0][0];
    i2 = (var[1][0][1] - var[0][0][1]) * di + var[0][0][1];
    i3 = (var[1][1][1] - var[0][1][1]) * di + var[0][1][1];
    i4 = (var[1][1][0] - var[0][1][0]) * di + var[0][1][0];

    j1 = (i3 - i2) * dj + i2;
    j2 = (i4 - i1) * dj + i1;

    velp = (j1 - j2) * dk + j2;
}

// Define a function to run a test case
void runTest(double di, double dj, double dk, float var[2][2][2], double expected) {
    double velp;
    interp_trilinear(di, dj, dk, var, velp);

    std::cout << "Test with di=" << di << ", dj=" << dj << ", dk=" << dk;
    if (fabs(velp - expected) < 1e-6) {
        std::cout << " - Passed" << std::endl;
    } else {
        std::cout << " - Failed (Expected: " << expected << ", Got: " << velp << ")" << std::endl;
    }
}

// Main function to run the tests
int main() {
    float var[2][2][2] = {
        {{1.0f, 2.0f}, {3.0f, 4.0f}},
        {{5.0f, 6.0f}, {7.0f, 8.0f}}
    };

    // Test Case 1
    runTest(0.5, 0.5, 0.5, var, 4.5); // The expected value should match the interpolation result

    // You can add more test cases with different di, dj, dk, var, and expected values

    return 0;
}