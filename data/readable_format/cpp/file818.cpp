#include <iostream>
#include <vector>

void DLASWP(int N, std::vector<std::vector<double>>& A, int LDA, int K1, int K2, std::vector<int>& IPIV, int INCX) {
    int IP, K;
    double TEMP;

    for (int J = 0; J < N; ++J) {
        for (int I = K1 - 1; I < K2; ++I) { // Adjust for 0-based indexing
            IP = IPIV[I] - 1; // Adjust for 0-based indexing
            if (IP != I) {
                for (K = 0; K < LDA; ++K) {
                    TEMP = A[K][I];
                    A[K][I] = A[K][IP];
                    A[K][IP] = TEMP;
                }
            }
        }
    }
}

void printMatrix(const std::vector<std::vector<double>>& A) {
    for (const auto& row : A) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int n = 4;
    std::vector<std::vector<double>> A = {
        {1, 5, 9, 13},
        {2, 6, 10, 14},
        {3, 7, 11, 15},
        {4, 8, 12, 16}
    };
    std::vector<int> IPIV = {2, 1, 4, 3}; // 1-based indexing

    DLASWP(n, A, n, 1, 4, IPIV, 1);

    std::cout << "Resulting Matrix A after DLASWP:" << std::endl;
    printMatrix(A);

    return 0;
}