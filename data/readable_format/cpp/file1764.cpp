#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using Matrix = std::vector<std::vector<double>>;

Matrix matmul(const Matrix& a, const Matrix& b) {
    size_t rows_a = a.size();
    size_t cols_a = a[0].size();
    size_t rows_b = b.size();
    size_t cols_b = b[0].size();
    if (cols_a != rows_b) {
        throw std::invalid_argument("Matrix dimensions do not match for multiplication.");
    }
    Matrix result(rows_a, std::vector<double>(cols_b, 0.0));
    for (size_t i = 0; i < rows_a; ++i) {
        for (size_t j = 0; j < cols_b; ++j) {
            for (size_t k = 0; k < cols_a; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

Matrix transpose(const Matrix& m) {
    size_t rows = m.size();
    size_t cols = m[0].size();
    Matrix trans(cols, std::vector<double>(rows));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            trans[j][i] = m[i][j];
        }
    }
    return trans;
}

bool approxEqual(const Matrix& a, const Matrix& b, double eps = 1e-9) {
    if (a.size() != b.size() || a[0].size() != b[0].size()) {
        return false;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[0].size(); ++j) {
            if (std::abs(a[i][j] - b[i][j]) > eps) {
                return false;
            }
        }
    }
    return true;
}

void mass_matrix(Matrix& MM1) {
    const double m1 = 1.0;
    const Matrix A1 = {{1.0, 0.0}, {0.0, 1.0}, {0.0, 0.0}};
    const Matrix Mel = {{1.0/3.0, 0.0}, {0.0, 1.0/3.0}};
    
    MM1 = matmul(A1, matmul(Mel, transpose(A1)));
    for (size_t i = 0; i < MM1.size(); ++i)
        for (size_t j = 0; j < MM1[0].size(); ++j)
            MM1[i][j] *= m1;
}

// Simple testing mechanism
void run_tests() {
    // Test matmul
    {
        Matrix A = {{1, 2}, {3, 4}};
        Matrix B = {{2, 0}, {1, 2}};
        Matrix expected = {{4, 4}, {10, 8}};
        if (!approxEqual(matmul(A, B), expected)) {
            std::cerr << "matmul test failed" << std::endl;
            return;
        }
    }
    // Test transpose
    {
        Matrix A = {{1, 2}, {3, 4}, {5, 6}};
        Matrix expected = {{1, 3, 5}, {2, 4, 6}};
        if (!approxEqual(transpose(A), expected)) {
            std::cerr << "transpose test failed" << std::endl;
            return;
        }
    }
    // Test mass_matrix
    {
        Matrix MM1;
        mass_matrix(MM1);
        Matrix expected = {{1.0/3.0, 0.0, 0.0}, {0.0, 1.0/3.0, 0.0}, {0.0, 0.0, 0.0}};
        if (!approxEqual(MM1, expected)) {
            std::cerr << "mass_matrix test failed" << std::endl;
            return;
        }
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}