#include <iostream>
#include <vector>

class ModuleCells {
public:
    std::vector<std::vector<int>> cells;

    void allocate(int numRows, int numCols) {
        cells.resize(numRows);
        for (auto& row : cells) {
            row.resize(numCols, 0); // Initialize cells with 0
        }
    }
};

int main() {
    ModuleCells myCells;

    // Allocate a 5x10 array
    myCells.allocate(5, 10);

    // Set a value and perform a basic check
    myCells.cells[2][3] = 42;
    if (myCells.cells[2][3] == 42) {
        std::cout << "Test passed: cells[2][3] == 42" << std::endl;
    } else {
        std::cout << "Test failed: cells[2][3] != 42" << std::endl;
    }

    // Since we're not using Google Test or any other external testing framework,
    // there's no need for special setup or linking against other libraries.
    return 0;
}