#include <iostream>
#include <complex>
#include <algorithm>

// CGENND function prototype
bool CGENND(int m, int n, std::complex<double>** A, int LDA);

// CGENND function definition
bool CGENND(int m, int n, std::complex<double>** A, int LDA) {
    const double ZERO = 0.0;
    int k = std::min(m, n);
    
    for (int i = 0; i < k; ++i) {
        std::complex<double> AII = A[i][i];
        if (std::real(AII) < ZERO || std::imag(AII) != ZERO) {
            return false;
        }
    }
    return true;
}

// Main function containing tests
int main() {
    // Test 1: 2x2 identity matrix
    int M = 2, N = 2, LDA = 2;
    std::complex<double>* A[2];
    A[0] = new std::complex<double>[2]{{1.0, 0.0}, {0.0, 0.0}};
    A[1] = new std::complex<double>[2]{{0.0, 0.0}, {1.0, 0.0}};
    std::cout << "Test 1 (Expect 1): " << CGENND(M, N, A, LDA) << std::endl;
    delete[] A[0];
    delete[] A[1];

    // Test 2: 2x2 matrix with a negative real part on the diagonal
    M = 2; N = 2; LDA = 2;
    std::complex<double>* B[2];
    B[0] = new std::complex<double>[2]{{-1.0, 0.0}, {0.0, 0.0}};
    B[1] = new std::complex<double>[2]{{0.0, 0.0}, {1.0, 0.0}};
    std::cout << "Test 2 (Expect 0): " << CGENND(M, N, B, LDA) << std::endl;
    delete[] B[0];
    delete[] B[1];

    return 0;
}