#include <iostream>
#include <vector>

// Function prototype is now followed by its definition in the same file.

int ILADLC(int M, int N, double *A, int LDA) {
    const double ZERO = 0.0;
    if (N == 0) {
        return N;
    } else if (*(A + (N-1) * LDA) != ZERO || *(A + (M-1) + (N-1) * LDA) != ZERO) {
        return N;
    } else {
        for (int j = N; j > 0; --j) {
            for (int i = 0; i < M; ++i) {
                if (*(A + i + (j-1) * LDA) != ZERO) {
                    return j;
                }
            }
        }
    }
    return 0; // This should never be reached unless N <= 0
}

void runTest(const std::string& testName, int M, int N, const std::vector<double>& matrix, int LDA) {
    std::cout << testName << ": ";
    if (N > 0) {
        int result = ILADLC(M, N, const_cast<double*>(matrix.data()), LDA);
        std::cout << result << std::endl;
    } else {
        std::cout << "Skipped (empty matrix)" << std::endl;
    }
}

int main() {
    // Test 1: Empty matrix (0x0)
    runTest("Test 1 (Empty Matrix)", 0, 0, {}, 0);

    // Test 2: Matrix with all elements zero
    std::vector<double> allZeros(3 * 4, 0.0);
    runTest("Test 2 (All Zeros)", 3, 4, allZeros, 3);

    // Test 3: Non-zero element at different positions
    std::vector<double> nonZeroAt31(3 * 4, 0.0);
    nonZeroAt31[2] = 1.0; // Non-zero at A[3][1] in 1-based indexing (A[2] in 0-based)
    runTest("Test 3 (Non-zero at A(3,1))", 3, 4, nonZeroAt31, 3);

    std::vector<double> nonZeroAt14(3 * 4, 0.0);
    nonZeroAt14[9] = 1.0; // Non-zero at A[1][4] in 1-based indexing (A[9] in 0-based)
    runTest("Test 4 (Non-zero at A(1,4))", 3, 4, nonZeroAt14, 3);

    return 0;
}