#include <iostream>
#include <cassert>
#include <cmath>

// Function to allocate memory for a matrix of size rows x cols
float** allocateMatrix(int rows, int cols) {
    float** matrix = new float*[rows];
    for(int i = 0; i < rows; ++i) {
        matrix[i] = new float[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0.0f; // Initialize with 0
        }
    }
    return matrix;
}

// Function to deallocate memory for a matrix
void deallocateMatrix(float** matrix, int rows) {
    for(int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Function to perform matrix multiplication
float** matrixMultiply(float** a, int aRows, int aCols, float** b, int bRows, int bCols) {
    if (aCols != bRows) {
        // Matrix multiplication is not defined if the number of columns in A is not equal to the number of rows in B
        return nullptr;
    }

    float** result = allocateMatrix(aRows, bCols);
    for (int i = 0; i < aRows; ++i) {
        for (int j = 0; j < bCols; ++j) {
            result[i][j] = 0.0f;
            for (int k = 0; k < aCols; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

int main() {
    // Initialize matrices a and b
    float** a = allocateMatrix(3, 2);
    float** b = allocateMatrix(2, 3);

    // Fill matrices a and b with values
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 2; ++j) {
            a[i][j] = 1.0f; // Fill with 1.0
        }
    }
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 3; ++j) {
            b[i][j] = 2.3f; // Fill with 2.3
        }
    }

    // Perform matrix multiplication
    float** ret = matrixMultiply(a, 3, 2, b, 2, 3);

    // Assertions to verify the correctness of the result
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            assert(std::fabs(ret[i][j] - 4.6) < 0.001);
        }
    }

    std::cout << "All tests passed." << std::endl;

    // Clean up
    deallocateMatrix(ret, 3);
    deallocateMatrix(a, 3);
    deallocateMatrix(b, 2);

    return 0;
}