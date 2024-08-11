#include <cmath> // For std::sqrt

double ZABS(double ZR, double ZI) {
    double U, V, Q, S;
    U = std::abs(ZR);
    V = std::abs(ZI);
    S = U + V;
    S = S * 1.0; // This line essentially has no effect in C++, included for direct translation

    if (S == 0.0) {
        return 0.0;
    }
    
    if (U > V) {
        Q = U / V;
        return V * std::sqrt(1.0 + Q * Q);
    } else {
        Q = V / U;
        return U * std::sqrt(1.0 + Q * Q);
    }
}

// Example usage
#include <iostream>

int main() {
    double realPart = 3.0;
    double imagPart = 4.0;
    std::cout << "The absolute value of the complex number is: " << ZABS(realPart, imagPart) << std::endl;
    return 0;
}