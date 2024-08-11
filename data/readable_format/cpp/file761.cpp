#include <vector>
#include <iostream>

template<typename T>
std::vector<std::vector<std::vector<T>>> create3DVector(int x, int y, int z, T value) {
    return std::vector<std::vector<std::vector<T>>>(x, std::vector<std::vector<T>>(y, std::vector<T>(z, value)));
}

template<typename T>
std::vector<std::vector<T>> create2DVector(int x, int y, T value) {
    return std::vector<std::vector<T>>(x, std::vector<T>(y, value));
}

void foo(std::vector<std::vector<int>>& array1, std::vector<std::vector<std::vector<float>>>& array2) {
    for (auto& row : array1) {
        for (auto& elem : row) {
            elem = 5;
        }
    }
    array1[0][0] = 30;

    for (auto& depth : array2) {
        for (auto& row : depth) {
            for (auto& elem : row) {
                elem = 3.0f;
            }
        }
    }
    array2[0][0][0] = 30.0f;
    array2[2][2][2] = 90.0f;
}

// C++ Unit Test Code using Google Test
// Save this part in a separate file, e.g., test_foo.cpp

#include <gtest/gtest.h>

TEST(FooBarTest, TestFoo) {
    std::vector<std::vector<int>> array1 = create2DVector<int>(3, 3, 0);
    std::vector<std::vector<std::vector<float>>> array2 = create3DVector<float>(3, 3, 3, 0.0);

    foo(array1, array2);

    EXPECT_EQ(array1[0][0], 30);
    EXPECT_EQ(array2[0][0][0], 30.0f);
    EXPECT_EQ(array2[2][2][2], 90.0f);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_EQ(array1[i][j], (i == 0 && j == 0) ? 30 : 5);
            for (int k = 0; k < 3; ++k) {
                float expectedValue = (i == 0 && j == 0 && k == 0) ? 30.0f : ((i == 2 && j == 2 && k == 2) ? 90.0f : 3.0f);
                EXPECT_EQ(array2[i][j][k], expectedValue);
            }
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}