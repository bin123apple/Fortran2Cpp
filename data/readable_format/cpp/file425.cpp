#include <complex>
#include <iostream>
#include <cassert>

// Forward declaration of the function to be tested
int ILAZLC(int M, int N, const std::complex<double>* A, int LDA);

// Declaration of the test function
void TestILAZLC();

int main() {
    TestILAZLC();
    return 0;
}

// Function implementation
int ILAZLC(int M, int N, const std::complex<double>* A, int LDA) {
    std::complex<double> zero(0.0, 0.0);

    if (N == 0) return 0;

    for (int col = N; col >= 1; --col) {
        for (int row = 0; row < M; ++row) {
            if (A[(col-1)*LDA + row] != zero) {
                return col;
            }
        }
    }
    return 0; // If all elements are zero
}

// Test function implementation
void TestILAZLC() {
    const int M = 10;
    const int N = 10;
    std::complex<double> A[M * N] = {}; // Initialize all to zero

    // Test Case 1: All zero matrix
    assert(ILAZLC(M, N, A, M) == 0);
    std::cout << "Test Case 1 passed." << std::endl;

    // Test Case 2: Last column has a non-zero element
    A[(N-1)*M + 4] = std::complex<double>(1.0, 0.0); // A[5, 10] in 1-indexing
    assert(ILAZLC(M, N, A, M) == 10);
    std::cout << "Test Case 2 passed." << std::endl;

    // Test Case 3: 5th column is the last with a non-zero element
    A[(N-1)*M + 4] = std::complex<double>(0.0, 0.0); // Reset to zero
    A[(5-1)*M + 2] = std::complex<double>(1.0, 0.0); // A[3, 5] in 1-indexing
    assert(ILAZLC(M, N, A, M) == 5);
    std::cout << "Test Case 3 passed." << std::endl;
}