#include <iostream>
#include <vector>
#include <cmath> // For fabs

// Function to fill the matrix
void fillMatrix(std::vector<std::vector<float>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = 10 * (i + 1) + (j + 1);
        }
    }
}

// Simple test function to verify matrix values
bool testMatrix(const std::vector<std::vector<float>>& matrix) {
    bool isCorrect = true;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            float expectedValue = 10 * (i + 1) + (j + 1);
            if (std::fabs(matrix[i][j] - expectedValue) > 0.001) {
                std::cerr << "Test Failed at [" << i << "][" << j << "]: Expected " << expectedValue << ", got " << matrix[i][j] << std::endl;
                isCorrect = false;
            }
        }
    }
    return isCorrect;
}

int main() {
    const int rows = 2;
    const int cols = 3;
    std::vector<std::vector<float>> a(rows, std::vector<float>(cols));

    fillMatrix(a);

    if (testMatrix(a)) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    // If needed, manual output for verification
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}