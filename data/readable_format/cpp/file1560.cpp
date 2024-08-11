#include <iostream>
#include <vector>

int ILADLC(size_t M, size_t N, const std::vector<std::vector<double>>& A) {
    const double ZERO = 0.0;
    if (N == 0) {
        return 0;
    } else if (A[0][N-1] != ZERO || A[M-1][N-1] != ZERO) {
        return N;
    } else {
        for (int col = N-1; col >= 0; --col) {
            for (size_t row = 0; row < M; ++row) {
                if (A[row][col] != ZERO) {
                    return col + 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    std::vector<std::vector<double>> A1 = {
        {0.0, 0.0, 0.0},
        {0.0, 2.0, 0.0},
        {0.0, 3.0, 0.0}
    };
    std::cout << "Test Case 1: Expected 2, Got " << ILADLC(3, 3, A1) << std::endl;

    std::vector<std::vector<double>> A2 = {
        {0.0, 0.0},
        {0.0, 0.0}
    };
    std::cout << "Test Case 2: Expected 0, Got " << ILADLC(2, 2, A2) << std::endl;

    return 0;
}