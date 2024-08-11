#include <iostream>
#include <vector>
#include <algorithm> // For std::max

// Declaration and definition of the ILADLR function
int ILADLR(int M, int N, double** A, int LDA) {
    const double ZERO = 0.0;

    if (M == 0) {
        return M;
    } else if (A[M-1][0] != ZERO || A[M-1][N-1] != ZERO) {
        return M;
    } else {
        int result = 0;
        for (int J = 0; J < N; ++J) {
            int I = M;
            while ((A[std::max(I-1, 0)][J] == ZERO) && (I >= 1)) {
                --I;
            }
            result = std::max(result, I);
        }
        return result;
    }
}

// Test program
int main() {
    int M = 4, N = 3, LDA = 4;
    std::vector<std::vector<double>> matrix(M, std::vector<double>(N, 0.0));

    // Initialize matrix
    matrix[0][0] = 1.0;
    matrix[1][2] = 2.0;
    matrix[2][1] = 3.0;
    // The last row is all zeros

    // Convert to double pointer for ILADLR function
    double** A = new double*[LDA];
    for (int i = 0; i < LDA; ++i) {
        A[i] = matrix[i].data();
    }

    int result = ILADLR(M, N, A, LDA);
    std::cout << "The last non-zero row is: " << result << std::endl;

    // Clean up
    delete[] A;

    return 0;
}