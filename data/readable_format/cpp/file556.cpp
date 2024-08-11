// op.cpp
#include <vector>
#include <iostream>

void op(int n, const std::vector<double>& x, std::vector<double>& y, const std::vector<double>& ad, const std::vector<double>& au, const std::vector<int>& jq, const std::vector<int>& irow) {
    for (int i = 0; i < n; ++i) {
        y[i] = ad[i] * x[i];
    }
    for (int j = 0; j < n; ++j) {
        for (int l = jq[j] - 1; l < jq[j + 1] - 1; ++l) {
            int i = irow[l] - 1; // Adjusting for zero-based indexing
            y[i] += au[l] * x[j];
            y[j] += au[l] * x[i];
        }
    }
}

// main.cpp
#include <gtest/gtest.h>

TEST(OpTest, HandlesPositiveAndNegativeNumbers) {
    const int n = 4;
    std::vector<double> x = {1.0, -2.0, 3.0, -4.0};
    std::vector<double> y(n, 0.0);
    std::vector<double> ad = {1.0, 2.0, 3.0, 4.0};
    std::vector<double> au = {5.0, 6.0, 7.0, 8.0, 9.0};
    std::vector<int> jq = {1, 3, 4, 5, 6};
    std::vector<int> irow = {2, 4, 1, 3, 2};

    op(n, x, y, ad, au, jq, irow);

    std::vector<double> expected_y = {-47.0, -28.0, 57.0, -28.0};
    for (size_t i = 0; i < n; ++i) {
        EXPECT_NEAR(y[i], expected_y[i], 1e-6);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}