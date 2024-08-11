#include <iostream>
#include <cassert>
#include <cmath>

// Define a simple 2x2 matrix struct for demonstration
struct Matrix {
    float data[2][2];

    Matrix() {} // Default constructor

    // Constructor to initialize the matrix elements
    Matrix(float a, float b, float c, float d) {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    // Function to transpose the matrix
    Matrix transpose() const {
        return Matrix(data[0][0], data[1][0], data[0][1], data[1][1]);
    }

    // Function for matrix multiplication
    Matrix multiply(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < 2; ++k) {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Function to compare matrices
    bool isApprox(const Matrix& other, float epsilon = 1e-6) const {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (std::fabs(data[i][j] - other.data[i][j]) > epsilon) {
                    return false;
                }
            }
        }
        return true;
    }
};

// Test functions (assuming a simple test framework)
void testTranspose() {
    Matrix m(1, 2, 3, 4);
    Matrix transposed = m.transpose();
    Matrix expected(1, 3, 2, 4);
    assert(transposed.isApprox(expected));
    std::cout << "Transpose test passed." << std::endl;
}

void testMultiply() {
    Matrix m1(1, 2, 3, 4);
    Matrix m2(2, 0, 1, 2);
    Matrix result = m1.multiply(m2);
    Matrix expected(4, 4, 10, 8);
    assert(result.isApprox(expected));
    std::cout << "Multiply test passed." << std::endl;
}

int main() {
    testTranspose();
    testMultiply();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}