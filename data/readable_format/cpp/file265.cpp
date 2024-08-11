#include <vector>
#include <iostream>
#include <cassert>

void rhofix_mat(int M, std::vector<std::vector<double>>& Matrix) {
    for (int ii = 0; ii < M; ++ii) {
        for (int jj = 0; jj < M; ++jj) {
            if (ii != jj) {
                Matrix[ii][jj] = Matrix[ii][jj] / 2.0;
            }
        }
    }
}

void rhofix_vec(int M, std::vector<double>& Vector) {
    int kk = 0;
    for (int ii = 0; ii < M; ++ii) {
        for (int jj = 0; jj <= ii; ++jj) {
            if (ii != jj) {
                Vector[kk] = Vector[kk] / 2.0;
            }
            kk++;
        }
    }
}

int main() {
    int M = 3;
    std::vector<std::vector<double>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<double> vec = {1, 2, 3, 4, 5, 6};

    rhofix_mat(M, matrix);
    rhofix_vec(M, vec);

    std::cout << "Modified Matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Modified Vector:" << std::endl;
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Verification (Assertions for C++ code)
    // Check matrix
    assert(matrix[0][1] == 1 && matrix[0][2] == 1.5);
    assert(matrix[1][0] == 2 && matrix[1][2] == 3);
    assert(matrix[2][0] == 3.5 && matrix[2][1] == 4);

    // Check vector
    assert(vec[0] == 1 && vec[1] == 1 && vec[3] == 2 && vec[4] == 2.5);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}