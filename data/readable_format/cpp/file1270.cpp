#include <iostream>
#include <cmath>
#include <cassert>
#include <string>

void iau_RV2M(const double W[3], double R[3][3]) {
    double X, Y, Z, PHI, S, C, F;
    X = W[0];
    Y = W[1];
    Z = W[2];
    PHI = std::sqrt(X*X + Y*Y + Z*Z);
    S = std::sin(PHI);
    C = std::cos(PHI);
    F = 1.0 - C;
    if (PHI > 0.0) {
        X = X / PHI;
        Y = Y / PHI;
        Z = Z / PHI;
    }
    R[0][0] = X*X*F + C;
    R[0][1] = X*Y*F + Z*S;
    R[0][2] = X*Z*F - Y*S;
    R[1][0] = Y*X*F - Z*S;
    R[1][1] = Y*Y*F + C;
    R[1][2] = Y*Z*F + X*S;
    R[2][0] = Z*X*F + Y*S;
    R[2][1] = Z*Y*F - X*S;
    R[2][2] = Z*Z*F + C;
}

void AssertMatrixEqual(const double A[3][3], const double B[3][3], const std::string& message) {
    const double Tolerance = 1e-10;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(std::fabs(A[i][j] - B[i][j]) < Tolerance && message.c_str());
        }
    }
    std::cout << message << ": Passed" << std::endl;
}

void IdentityMatrix(double Mat[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Mat[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

int main() {
    // Test 1: Zero vector
    double W[3] = {0.0, 0.0, 0.0};
    double R[3][3];
    double Expected[3][3];

    iau_RV2M(W, R);
    IdentityMatrix(Expected);
    AssertMatrixEqual(R, Expected, "Test 1: Zero vector");

    // Feel free to add more tests here...

    return 0;
}