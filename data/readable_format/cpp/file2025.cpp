#include <iostream>
#include <vector>

void daat(const std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& X, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            double R = 0.0;
            for (int k = 0; k < N; ++k) {
                R += A[i][k] * A[k][j]; // Correcting the multiply operation for A by A^T
            }
            X[i][j] = R;
        }
    }
}

void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Test 1: 2x2 Matrix
    std::vector<std::vector<double>> A1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> X1(2, std::vector<double>(2));
    daat(A1, X1, 2);
    std::cout << "Test 1: 2x2 Matrix" << std::endl;
    printMatrix(X1);

    // Test 2: 3x3 Matrix
    std::vector<std::vector<double>> A2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<double>> X2(3, std::vector<double>(3));
    daat(A2, X2, 3);
    std::cout << "Test 2: 3x3 Matrix" << std::endl;
    printMatrix(X2);

    return 0;
}