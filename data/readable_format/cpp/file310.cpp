#include <gtest/gtest.h>
#include <vector>
#include <limits>
#include <cmath> // Include this for std::isnan

// Assuming the findMax function is defined as follows
double findMax(const std::vector<double>& A) {
    if (A.empty()) return std::numeric_limits<double>::quiet_NaN(); // Handling empty array case
    double BIGA = A[0];
    for (size_t i = 1; i < A.size(); ++i) {
        if (BIGA < A[i]) {
            BIGA = A[i];
        }
    }
    return BIGA;
}

// Unit tests
TEST(FindMaxTest, HandlesEmptyArray) {
    std::vector<double> A = {};
    EXPECT_TRUE(std::isnan(findMax(A))); // Fixed to use std::isnan correctly
}

TEST(FindMaxTest, HandlesIdenticalElements) {
    std::vector<double> A = {1, 1, 1, 1};
    EXPECT_DOUBLE_EQ(findMax(A), 1);
}

TEST(FindMaxTest, HandlesDistinctElements) {
    std::vector<double> A = {-2, -1, 0, 1, 2};
    EXPECT_DOUBLE_EQ(findMax(A), 2);
}

TEST(FindMaxTest, HandlesAllNegativeNumbers) {
    std::vector<double> A = {-10, -20, -30, -40};
    EXPECT_DOUBLE_EQ(findMax(A), -10);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}