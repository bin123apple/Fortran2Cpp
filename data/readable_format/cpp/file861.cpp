#include <gtest/gtest.h>
#include <vector>
#include <iostream>

// Define the ice6_s template function directly in this file.
template<typename T>
int ice6_s(const T& a) {
    if (a.empty()) {
        return -1; // Mimics the case where the Fortran array's first dimension lower bound is not as expected.
    } else {
        return 0; // Placeholder for successful check.
    }
}

// Overload for a vector of vectors (2D array).
template<typename T>
int ice6_s(const std::vector<std::vector<T>>& a) {
    return ice6_s(a.empty() ? std::vector<T>{} : a.front());
}

// Test cases
TEST(Ice6STest, Test1DVector) {
    std::vector<int> vec1D = {1, 2, 3};
    EXPECT_EQ(ice6_s(vec1D), 0);
}

TEST(Ice6STest, TestEmpty1DVector) {
    std::vector<int> vec1D = {};
    EXPECT_EQ(ice6_s(vec1D), -1);
}

TEST(Ice6STest, Test2DVector) {
    std::vector<std::vector<int>> vec2D = {{1, 2}, {3, 4}};
    EXPECT_EQ(ice6_s(vec2D), 0);
}

TEST(Ice6STest, TestEmpty2DVector) {
    std::vector<std::vector<int>> vec2D = {};
    EXPECT_EQ(ice6_s(vec2D), -1);
}

// Main function
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}