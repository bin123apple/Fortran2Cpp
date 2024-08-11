#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <gtest/gtest.h>

// Function to calculate the product of elements in a 2D vector
int totalProduct(const std::vector<std::vector<int>>& a) {
    int total_product = 1;
    for (const auto& row : a) {
        total_product = std::accumulate(row.begin(), row.end(), total_product, std::multiplies<>());
    }
    return total_product;
}

// Test fixture for our product tests
class ProductTest : public ::testing::Test {
protected:
    std::vector<std::vector<int>> a{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
};

// Test case for the total product calculation
TEST_F(ProductTest, TotalProduct) {
    EXPECT_EQ(totalProduct(a), 362880) << "Total product should be 362880";
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}