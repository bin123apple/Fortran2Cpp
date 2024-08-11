#include <iostream>
#include <cmath>
#include <cassert>

// Declaration and initialization of global variables
double GAMMA = 1.0;
double XT = 0.75;

// The SOLUTN function translated from Fortran to C++
void SOLUTN(double X, double Z[], double DMVAL[]) {
    double CONS = GAMMA * X * (1.0 - 0.5 * X * X);
    double DCONS = GAMMA * (1.0 - 1.5 * X * X);
    double D2CONS = -3.0 * GAMMA * X;

    if (X > XT) {
        Z[0] = 0.0;
        Z[1] = 0.0;
        Z[2] = -CONS;
        Z[3] = -DCONS;
        DMVAL[1] = -D2CONS;
    } else {
        Z[0] = 2.0 * X;
        Z[1] = 2.0;
        Z[2] = -2.0 * X + CONS;
        Z[3] = -2.0 + DCONS;
        DMVAL[1] = D2CONS;
    }
    DMVAL[0] = 0.0;
}

// Test function for SOLUTN
void testSolutn() {
    double Z[4], DMVAL[2];
    double X = 0.5; // Test value for X

    SOLUTN(X, Z, DMVAL);

    std::cout << "Z: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << Z[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "DMVAL: ";
    for (int i = 0; i < 2; ++i) {
        std::cout << DMVAL[i] << " ";
    }
    std::cout << std::endl;

    // Automated checks
    assert(std::abs(Z[0] - (2.0 * X)) < 1e-6);
    assert(std::abs(Z[1] - 2.0) < 1e-6);
    assert(std::abs(DMVAL[0]) < 1e-6); // DMVAL[0] should be 0.0 according to SOLUTN logic
    // Note: More comprehensive tests might be necessary for real-world applications
}

int main() {
    testSolutn();
    return 0;
}