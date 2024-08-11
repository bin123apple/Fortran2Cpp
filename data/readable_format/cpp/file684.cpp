#include <iostream>
#include <cmath> // For std::exp and std::abs

// Function prototype is no longer necessary since the definition comes before main

// probKS Function Definition
double probKS(double alam) {
    const double EPS1 = 0.001;
    const double EPS2 = 1.E-8;
    double a2 = -2.0 * alam * alam;
    double fac = 2.0;
    double probKS = 0.0;
    double termbf = 0.0;
    
    for (int j = 1; j <= 100; ++j) {
        double term = fac * std::exp(a2 * j * j);
        probKS += term;
        if (std::abs(term) < EPS1 * termbf || std::abs(term) < EPS2 * probKS) {
            return probKS;
        }
        fac = -fac;
        termbf = std::abs(term);
    }
    
    probKS = 1.0;
    return probKS;
}

// Main function with test cases
int main() {
    double alam, result;

    alam = 0.5;
    result = probKS(alam);
    std::cout << "Test 1, ALAM = 0.5, PROBKS = " << result << std::endl;

    alam = 1.0;
    result = probKS(alam);
    std::cout << "Test 2, ALAM = 1.0, PROBKS = " << result << std::endl;

    return 0;
}