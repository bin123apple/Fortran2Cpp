#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

// Assuming Google Test is set up in your environment

// Translated function from Fortran to C++
void floop12_F90(int N, std::vector<float>& y, std::vector<float>& x, const std::vector<float>& a, const std::vector<float>& b, const std::vector<float>& c, const std::vector<float>& d, float u) {
    std::transform(a.begin(), a.end(), y.begin(), [u](float ai) { return u + ai; });
    for (int i = 0; i < N; ++i) {
        x[i] = a[i] + b[i] + c[i] + d[i];
    }
}

void floop12_F90Overhead(int N, std::vector<float>& y, std::vector<float>& x, const std::vector<float>& a, const std::vector<float>& b, const std::vector<float>& c, const std::vector<float>& d, float u) {
    // This function intentionally left blank
}

// Test case for the function
TEST(Floop12Test, Correctness) {
    const int N = 4;
    std::vector<float> a = {1.0, 2.0, 3.0, 4.0};
    std::vector<float> b = {2.0, 3.0, 4.0, 5.0};
    std::vector<float> c = {3.0, 4.0, 5.0, 6.0};
    std::vector<float> d = {4.0, 5.0, 6.0, 7.0};
    std::vector<float> y(N), x(N);
    float u = 1.5;

    floop12_F90(N, y, x, a, b, c, d, u);

    std::vector<float> expected_y = {2.5, 3.5, 4.5, 5.5};
    std::vector<float> expected_x = {10.0, 14.0, 18.0, 22.0};

    for (int i = 0; i < N; ++i) {
        EXPECT_FLOAT_EQ(y[i], expected_y[i]);
        EXPECT_FLOAT_EQ(x[i], expected_x[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}