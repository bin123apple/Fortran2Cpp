#include <iostream>
#include <vector>
#include <cassert>

// Matrix class definition
class Matrix {
public:
    int rows;
    int columns;
    std::vector<std::vector<double>> data; // Assuming the data type is double. Adjust if necessary.

    Matrix(int r, int c) : rows(r), columns(c), data(r, std::vector<double>(c, 0.0)) {
        // The matrix is now initialized with 0.0 for each element
    }
};

// Simple test function to verify matrix initialization
void testMatrixInitialization() {
    int rows = 5;
    int columns = 10;
    Matrix m(rows, columns);

    assert(m.rows == rows);
    assert(m.columns == columns);
    assert(m.data.size() == static_cast<size_t>(rows));
    assert(m.data[0].size() == static_cast<size_t>(columns));

    std::cout << "Test passed: Matrix initialized correctly with dimensions (" << rows << ", " << columns << ")." << std::endl;
}

int main() {
    testMatrixInitialization();
    // Add more tests as needed
    return 0;
}