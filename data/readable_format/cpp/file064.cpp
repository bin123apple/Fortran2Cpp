#include <iostream>
#include <algorithm> // For std::min

// Function prototype is no longer necessary since the definition is in the same file before main.

bool DGENND(int M, int N, double* A, int LDA) {
    const double ZERO = 0.0;
    int K = std::min(M, N);

    for (int I = 0; I < K; ++I) {
        if (*(A + I * LDA + I) < ZERO) { // Accessing A(I,I) considering Fortran's column-major vs. C++'s row-major
            return false;
        }
    }

    return true;
}

int main() {
    // Test case 1: Positive definite matrix
    double A1[] = {1.0, 0.0, 0.0, 1.0};
    std::cout << "Test 1 (Positive definite): " << std::boolalpha << DGENND(2, 2, A1, 2) << std::endl;

    // Test case 2: Matrix with a negative diagonal element
    double A2[] = {-1.0, 0.0, 0.0, 1.0};
    std::cout << "Test 2 (Negative diagonal element): " << std::boolalpha << DGENND(2, 2, A2, 2) << std::endl;

    // Test case 3: Rectangular matrix (more rows)
    double A3[] = {1.0, 0.0, 0.0, 1.0, 0.0, 0.0};
    std::cout << "Test 3 (Rectangular matrix): " << std::boolalpha << DGENND(3, 2, A3, 3) << std::endl;

    return 0;
}