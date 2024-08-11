#include <iostream>
#include <vector>
#include <cmath>

// Declaration of the DDANRM function modified to accept const double* for input arrays
double DDANRM(int NEQ, const double* V, const double* WT, const double* RPAR, const int* IPAR) {
    double SUM = 0.0, VMAX = 0.0;
    for (int I = 0; I < NEQ; ++I) {
        double temp = std::abs(V[I] / WT[I]);
        if (temp > VMAX) VMAX = temp;
    }
    if (VMAX > 0.0) {
        for (int I = 0; I < NEQ; ++I) {
            SUM += std::pow((V[I] / WT[I]) / VMAX, 2);
        }
        return VMAX * std::sqrt(SUM / NEQ);
    }
    return 0.0;
}

void testDDANRM(const std::vector<double>& V, const std::vector<double>& WT, double expected) {
    int NEQ = V.size();
    double result = DDANRM(NEQ, V.data(), WT.data(), nullptr, nullptr);
    std::cout << "Test Result: " << result;
    if (std::abs(result - expected) < 1e-6) {
        std::cout << " - Passed" << std::endl;
    } else {
        std::cout << " - Failed" << std::endl;
    }
}

int main() {
    // Example test case
    std::vector<double> V = {1.0, 2.0, 3.0};
    std::vector<double> WT = {1.0, 2.0, 3.0};
    
    // The expected value should be calculated based on your specific test case
    // For demonstration, let's assume an expected value of 1.0
    // Note: This is a placeholder and may not correspond to the actual expected value for the given inputs
    double expected = 1.0;
    
    testDDANRM(V, WT, expected);

    // Add more tests as needed with different V, WT, and expected values

    return 0;
}