#include <gtest/gtest.h>
#include <vector>

// Function definition directly in this file
void loop18_F77(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, double u, double v) {
    for (int i = 0; i < N; ++i) {
        x[i] = (u + a[i]) * (v + b[i]);
    }
}

// Test case for the function
TEST(Loop18F77Test, CorrectnessTest) {
    int N = 5;
    std::vector<double> x(N), a(N, 1.0), b(N, 2.0), expected(N);
    double u = 3.0, v = 4.0;

    // Compute expected results for comparison
    for (int i = 0; i < N; ++i) {
        expected[i] = (u + a[i]) * (v + b[i]);
    }

    // Call the function
    loop18_F77(N, x, a, b, u, v);

    for (int i = 0; i < N; ++i) {
        EXPECT_DOUBLE_EQ(x[i], expected[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}