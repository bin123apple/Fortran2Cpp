#include <vector>
#include <cassert>
#include <iostream>

// Declaration of MXIDEN function
void MXIDEN(int N, std::vector<std::vector<float>>& MAT) {
    // Resize the vector to match dimensions N x N
    MAT.resize(N);
    for (int i = 0; i < N; ++i) {
        MAT[i].resize(N, 0.0f); // Initialize all elements to 0
    }

    if (N == 4) {
        // Explicitly setting elements for N = 4
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                MAT[i][j] = (i == j) ? 1.0f : 0.0f;
            }
        }
    } else {
        // Setting diagonal elements to 1 for N != 4
        for (int i = 0; i < N; ++i) {
            MAT[i][i] = 1.0f;
        }
    }
}

// Unit test function
void testMXIDEN(int N) {
    std::vector<std::vector<float>> MAT;
    MXIDEN(N, MAT);

    // Check if the matrix is an identity matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                assert(MAT[i][j] == 1.0f); // Diagonal elements should be 1
            } else {
                assert(MAT[i][j] == 0.0f); // Off-diagonal elements should be 0
            }
        }
    }

    std::cout << "Test with N = " << N << " passed." << std::endl;
}

int main() {
    // Test with N = 4
    testMXIDEN(4);

    // Test with N not equal to 4 (e.g., N = 5)
    testMXIDEN(5);

    return 0;
}