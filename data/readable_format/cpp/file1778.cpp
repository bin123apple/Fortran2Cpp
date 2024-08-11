#include <vector>
#include <iostream>
#include <gtest/gtest.h>

// Array2D definition
template<typename T>
struct Array2D {
    size_t rows, cols;
    std::vector<T> data;

    Array2D(size_t rows, size_t cols, T initial_value = T()) : rows(rows), cols(cols), data(rows * cols, initial_value) {}

    T& operator()(size_t row, size_t col) { // Fortran-style 1-based indexing
        return data[(row - 1) * cols + (col - 1)];
    }

    const T& operator()(size_t row, size_t col) const { // Const version for read-only access
        return data[(row - 1) * cols + (col - 1)];
    }

    void print() const { // Simple print function for demonstration
        for (size_t i = 1; i <= rows; ++i) {
            for (size_t j = 1; j <= cols; ++j) {
                std::cout << (*this)(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Unit Tests
TEST(Array2DTest, NonEmptyInitialization) {
    Array2D<int> non_empty(2, 2, 1); // Initialize with 1
    non_empty(1, 2) = 2; // Adjust values to mimic PAD effect
    non_empty(2, 1) = 2;
    non_empty(2, 2) = 2;

    // Check the initialization and manual adjustments
    EXPECT_EQ(non_empty(1, 1), 1);
    EXPECT_EQ(non_empty(1, 2), 2);
    EXPECT_EQ(non_empty(2, 1), 2);
    EXPECT_EQ(non_empty(2, 2), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}