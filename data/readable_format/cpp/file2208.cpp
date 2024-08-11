#include <iostream>
#include <vector>

void printArray(const std::vector<std::vector<int>>& arr) {
    std::cout << "Array Contents:" << std::endl;
    for (const auto& row : arr) {
        for (int elem : row) {
            std::cout.width(4); // Match Fortran output formatting
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int numRows = 10;
    const int numCols = 10;
    std::vector<std::vector<int>> im(numRows, std::vector<int>(numCols));

    // Initialize the array with some values
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            im[i][j] = (i + 1) * (j + 1); // Corrected to match Fortran's 1-based indexing
        }
    }

    // Mimic a "broadcast" by printing the array
    printArray(im);

    return 0;
}