#include <iostream>
#include <complex>
#include <cmath>

// Declare the external DLAEV2 function prototype
extern "C" {
    void DLAEV2(double a, double b, double c, double &rt1, double &rt2, double &cs1, double &t);
}

// Define the ZLAEV2 function
void ZLAEV2(std::complex<double> A, std::complex<double> B, std::complex<double> C, 
            double &RT1, double &RT2, double &CS1, std::complex<double> &SN1) {
    const double ZERO = 0.0;
    const double ONE = 1.0;
    double T;
    std::complex<double> W;

    if (std::abs(B) == ZERO) {
        W = ONE;
    } else {
        W = std::conj(B) / std::abs(B);
    }

    // Assuming DLAEV2 is a mock or external function provided elsewhere
    DLAEV2(std::real(A), std::abs(B), std::real(C), RT1, RT2, CS1, T);

    SN1 = W * T;
}

// Mock implementation of DLAEV2
extern "C" void DLAEV2(double a, double b, double c, double &rt1, double &rt2, double &cs1, double &t) {
    // Simplified operation for demonstration
    rt1 = a + c;
    rt2 = a - c;
    cs1 = b;
    t = 1.0;
}

// Main function to test ZLAEV2
int main() {
    std::complex<double> A(1.0, 2.0), B(2.0, 3.0), C(1.5, -0.5), SN1;
    double RT1, RT2, CS1;

    // Test case 1: Basic functionality
    ZLAEV2(A, B, C, RT1, RT2, CS1, SN1);
    std::cout << "Test 1 Results: " << RT1 << " " << RT2 << " " << CS1 << " " << SN1 << std::endl;

    // Test case 2: B is zero
    B = std::complex<double>(0.0, 0.0);
    ZLAEV2(A, B, C, RT1, RT2, CS1, SN1);
    std::cout << "Test 2 Results: " << RT1 << " " << RT2 << " " << CS1 << " " << SN1 << std::endl;

    return 0;
}