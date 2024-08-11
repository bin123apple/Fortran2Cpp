#include <iostream>
#include <iomanip> // For std::setprecision
#include <cmath>   // For std::abs()

// Function prototype is optional in this case since the definition is before main()
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
    double A, B, C, D, P, Q;

    // Test 1
    A = 1.0; B = 2.0; C = 3.0; D = 4.0;
    DLADIV(A, B, C, D, P, Q);
    std::cout << "Test 1: P = " << std::setprecision(10) << P << " Q = " << Q << std::endl;

    // Test 2
    A = 5.0; B = 6.0; C = 7.0; D = 8.0;
    DLADIV(A, B, C, D, P, Q);
    std::cout << "Test 2: P = " << std::setprecision(10) << P << " Q = " << Q << std::endl;

    // Add more tests as needed

    return 0;
}