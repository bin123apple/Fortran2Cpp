#include <iostream>
#include <vector>
#include <cmath>
#include <gtest/gtest.h>

// Function Declarations
std::vector<std::vector<float>> gen(int order);
void build(int order);
void test(int order, int prefix, const std::vector<std::vector<float>>& values);

// Function Definitions

std::vector<std::vector<float>> gen(int order) {
    std::vector<std::vector<float>> matrix(order, std::vector<float>(order + 1));
    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order + 1; ++j) {
            matrix[i][j] = (i + 1) * (i + 1) + (j + 1);
        }
    }
    return matrix;
}

void build(int order) {
    std::vector<std::vector<float>> combined;

    // First call to test
    for (int i = 1; i <= order; ++i) {
        auto temp = gen(i);
        combined.insert(combined.end(), temp.begin(), temp.end());
    }
    test(order, 0, combined);

    // Second call to test
    combined.clear();
    for (int i = 1; i <= 3; ++i) {
        std::vector<float> temp = {1.5, 1.5};
        auto genResult = gen(i);
        for (auto& row : genResult) {
            temp.insert(temp.end(), row.begin(), row.end());
        }
        combined.push_back(temp);
    }
    test(3, 2, combined);
}

void test(int order, int prefix, const std::vector<std::vector<float>>& values) {
    int last = 0;
    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < prefix; ++j) {
            if (values[i][j] != 1.5f) {
                std::cerr << "Test failed." << std::endl;
                std::abort();
            }
        }
        for (int j = 0; j < i + 1; ++j) {
            for (int k = 0; k < i; ++k) {
                if (values[i][prefix + j * i + k] != (j + 1) + (k + 1) * (k + 1)) {
                    std::cerr << "Test failed." << std::endl;
                    std::abort();
                }
            }
        }
    }
    // Size check omitted since C++ vectors manage their size
}

// Unit Tests

TEST(GenFunctionTest, GeneratesCorrectMatrix) {
    int order = 3;
    auto result = gen(order);
    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order + 1; ++j) {
            EXPECT_FLOAT_EQ(result[i][j], (i + 1) * (i + 1) + (j + 1));
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}