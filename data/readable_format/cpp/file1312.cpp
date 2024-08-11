#include <iostream>
#include <cmath>

// Definition of the DLADIV function goes here
void DLADIV(double A, double B, double C, double D, double& P, double& Q) {
    double E, F;

    if (std::abs(D) < std::abs(C)) {
        E = D / C;
        F = C + D * E;
        P = (A + B * E) / F;
        Q = (B - A * E) / F;
    } else {
        E = C / D;
        F = D + C * E;
        P = (B + A * E) / F;
        Q = (-A + B * E) / F;
    }
}

int main() {
    double P, Q;

    // Test case 1: ABS(D) < ABS(C)
    DLADIV(1.0, 2.0, 3.0, 1.0, P, Q);
    std::cout << "Test 1: P = " << P << ", Q = " << Q << std::endl;

    // Test case 2: ABS(D) >= ABS(C)
    DLADIV(2.0, 3.0, 1.0, 3.0, P, Q);
    std::cout << "Test 2: P = " << P << ", Q = " << Q << std::endl;

    return 0;
}