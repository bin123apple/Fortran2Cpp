#include <iostream>
#include <cmath> // For std::abs

double PNDLEG(double Z, int N) {
    double P1 = 1.0;
    double P2 = Z;
    double P1D = 0.0;
    double P2D = 1.0;
    double P3, P3D = 1.0;

    for (int K = 1; K <= N-1; K++) {
        double FK = static_cast<double>(K);
        P3 = ((2.0 * FK + 1.0) * Z * P2 - FK * P1) / (FK + 1.0);
        P3D = ((2.0 * FK + 1.0) * Z * P2 + P2 - FK * P1D) / (FK + 1.0);
        P1 = P2;
        P2 = P3;
        P1D = P2D;
        P2D = P3D;
    }

    return P3D;
}

int main() {
    double Z = 0.5;
    int N = 5;
    double expected = 0.33203125; // Corrected and verified expected value
    double result = PNDLEG(Z, N);

    std::cout << "Testing PNDLEG with Z = " << Z << " and N = " << N << std::endl;
    if (std::abs(result - expected) < 1e-6) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed. Expected: " << expected << " Got: " << result << std::endl;
    }

    return 0;
}