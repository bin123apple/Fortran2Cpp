#include <iostream>
#include <vector>
#include <cmath> // For std::abs

// Function to perform matrix multiplication
void matrix_multiply(const std::vector<std::vector<double>>& a,
                     const std::vector<std::vector<double>>& b,
                     std::vector<std::vector<double>>& c,
                     int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0; // Initialize element to 0
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to test the matrix_multiply function
bool test_matrix_multiply() {
    std::vector<std::vector<double>> a = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> b = {{1, 0}, {0, 1}};
    std::vector<std::vector<double>> c = {{0, 0}, {0, 0}};
    std::vector<std::vector<double>> expected_c = {{1, 2}, {3, 4}};

    matrix_multiply(a, b, c, 2);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (std::abs(c[i][j] - expected_c[i][j]) > 1e-9) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    if (test_matrix_multiply()) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}