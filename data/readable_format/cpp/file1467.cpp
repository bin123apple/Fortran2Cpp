#include <iostream>
#include <vector>

// Define the reshape function
std::vector<std::vector<int>> reshape(const std::vector<int>& vect, int rows, int cols) {
    std::vector<std::vector<int>> reshaped(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            reshaped[i][j] = vect[i * cols + j];
        }
    }
    return reshaped;
}

// Simple function to test the reshape functionality
void testReshape() {
    int r = 2, nb = 4;
    std::vector<int> vect(nb * r, 1);  // Initialized with 1s
    std::vector<std::vector<int>> reshaped = reshape(vect, r, nb);
    bool isCorrect = true;

    // Check if all values in the reshaped array are 1
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < nb; ++j) {
            if (reshaped[i][j] != 1) {
                isCorrect = false;
                break;
            }
        }
        if (!isCorrect) break;
    }

    if (isCorrect) {
        std::cout << "Test passed: Reshape function works correctly." << std::endl;
    } else {
        std::cout << "Test failed: Reshape function does not work as expected." << std::endl;
    }
}

// Main function to run tests
int main() {
    testReshape();
    return 0;
}