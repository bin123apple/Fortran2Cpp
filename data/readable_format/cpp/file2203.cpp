#include <vector>
#include <stdexcept>
#include <gtest/gtest.h>

// Function equivalent to floop13_F90
void floop13_F90(int N, std::vector<float> &y, std::vector<float> &x, const std::vector<float> &a, const std::vector<float> &b, const std::vector<float> &c, const std::vector<float> &d, float u) {
    if (y.size() != N || x.size() != N || a.size() != N || b.size() != N || c.size() != N || d.size() != N) {
        throw std::invalid_argument("Vector sizes do not match the specified size N");
    }

    for (int i = 0; i < N; ++i) {
        x[i] = a[i] + b[i] + c[i] + d[i];
        y[i] = u + d[i];
    }
}

// Function equivalent to floop13_F90Overhead
void floop13_F90Overhead(int N, std::vector<float> &y, std::vector<float> &x, const std::vector<float> &a, const std::vector<float> &b, const std::vector<float> &c, const std::vector<float> &d, float u) {
    // This function intentionally does nothing, just like the Fortran subroutine
}

// Test cases
TEST(Floop13Tests, BasicTest) {
    int N = 5;
    std::vector<float> y(N), x(N), a(N, 1.0), b(N, 2.0), c(N, 3.0), d(N, 4.0);
    float u = 5.0;

    floop13_F90(N, y, x, a, b, c, d, u);

    for (int i = 0; i < N; ++i) {
        EXPECT_FLOAT_EQ(x[i], a[i] + b[i] + c[i] + d[i]);
        EXPECT_FLOAT_EQ(y[i], u + d[i]);
    }
}

TEST(Floop13Tests, OverheadTest) {
    int N = 5;
    std::vector<float> y(N), x(N), a(N, 1.0), b(N, 2.0), c(N, 3.0), d(N, 4.0);
    float u = 5.0;

    floop13_F90(N, y, x, a, b, c, d, u);
    floop13_F90Overhead(N, y, x, a, b, c, d, u);

    for (int i = 0; i < N; ++i) {
        EXPECT_FLOAT_EQ(x[i], a[i] + b[i] + c[i] + d[i]);
        EXPECT_FLOAT_EQ(y[i], u + d[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}