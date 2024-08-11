#include <iostream>
#include <vector>
#include <complex>
#include <string>
#include <gtest/gtest.h>

// Define the checkMatrixSize template function within this file.
template<typename T>
void checkMatrixSize(int nsize1, int nsize2, const std::vector<std::vector<T>>& matrix, const std::string& matname, const std::string& subname) {
    if (matrix.size() != nsize1 || (nsize1 > 0 && matrix[0].size() != nsize2)) {
        throw std::runtime_error("Matrix " + matname + " has incorrect size in " + subname);
    }
    // For demonstration, we'll just print a success message. In actual use, you might do more.
    std::cout << "Matrix " << matname << " checked successfully in " << subname << "." << std::endl;
}

// Unit tests for the checkMatrixSize function
TEST(CheckMatrixSize, CorrectSizeInt) {
    std::vector<std::vector<int>> intMatrix = {{1, 2}, {3, 4}};
    EXPECT_NO_THROW(checkMatrixSize(2, 2, intMatrix, "intMatrix", "CorrectSizeInt"));
}

TEST(CheckMatrixSize, IncorrectSizeInt) {
    std::vector<std::vector<int>> intMatrix = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_ANY_THROW(checkMatrixSize(2, 2, intMatrix, "intMatrix", "IncorrectSizeInt"));
}

TEST(CheckMatrixSize, CorrectSizeFloat) {
    std::vector<std::vector<float>> floatMatrix = {{1.0f, 2.0f}, {3.0f, 4.0f}};
    EXPECT_NO_THROW(checkMatrixSize(2, 2, floatMatrix, "floatMatrix", "CorrectSizeFloat"));
}

TEST(CheckMatrixSize, CorrectSizeComplexDouble) {
    std::vector<std::vector<std::complex<double>>> complexDoubleMatrix = {{{1.0, 2.0}, {3.0, 4.0}}};
    EXPECT_NO_THROW(checkMatrixSize(1, 2, complexDoubleMatrix, "complexDoubleMatrix", "CorrectSizeComplexDouble"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}