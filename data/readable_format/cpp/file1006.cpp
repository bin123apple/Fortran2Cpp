#include <iostream>
#include <vector>

void transposeMatrix(std::vector<std::vector<int>>& V) {
    int N = V.size(); // Assuming V is a square matrix
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            std::swap(V[i][j], V[j][i]);
        }
    }
}

bool testTransposeFunction() {
    const int N = 10;
    std::vector<std::vector<int>> A(N, std::vector<int>(N));
    
    // Initialize the matrix A
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = (i + 1) * 10 + (j + 1);
        }
    }

    transposeMatrix(A);

    // Check the result
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] != (j + 1) * 10 + (i + 1)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    if (testTransposeFunction()) {
        std::cout << "C++ Test passed." << std::endl;
    } else {
        std::cout << "C++ Test failed." << std::endl;
    }
    return 0;
}