#include <iostream>
#include <vector>
#include <complex>

void claswp(int N, std::complex<double>* A, int LDA, int K1, int K2, int* IPIV, int INCX) {
    for (int j = 0; j < N; ++j) {
        for (int i = K1 - 1; i < K2; ++i) {
            int IP = IPIV[i] - 1;
            if (IP != i) {
                for (int k = 0; k < LDA; ++k) {
                    std::swap(A[k + i * LDA], A[k + IP * LDA]);
                }
            }
        }
    }
}

int main() {
    int N = 5;
    int LDA = 5;
    int K1 = 1;
    int K2 = 5;
    int INCX = 1;
    std::vector<std::complex<double>> A(N * LDA);
    std::vector<int> IPIV(K2);

    // Initialize A and IPIV
    for (int i = 0; i < LDA; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i + j * LDA] = std::complex<double>(i + 1, j + 1);
        }
    }
    for (int i = K1 - 1; i < K2; ++i) {
        IPIV[i] = K2 - i;
    }

    std::cout << "Before CLASWP:" << std::endl;
    for (int i = 0; i < LDA; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << A[i + j * LDA] << " ";
        }
        std::cout << std::endl;
    }

    claswp(N, A.data(), LDA, K1, K2, IPIV.data(), INCX);

    std::cout << "After CLASWP:" << std::endl;
    for (int i = 0; i < LDA; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << A[i + j * LDA] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}