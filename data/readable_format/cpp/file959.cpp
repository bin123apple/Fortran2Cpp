#include <vector>
#include <algorithm> // for std::max and std::min
#include <cmath>     // for std::abs
#include <gtest/gtest.h>

// Function Declaration
double dla_gbrpvgrw(int n, int kl, int ku, int ncols, const std::vector<std::vector<double>>& ab,
                    int ldab, const std::vector<std::vector<double>>& afb, int ldafb);

// Function Definition
double dla_gbrpvgrw(int n, int kl, int ku, int ncols, const std::vector<std::vector<double>>& ab,
                    int ldab, const std::vector<std::vector<double>>& afb, int ldafb) {
    double rpvgrw = 1.0;
    int kd = ku + 1;

    for (int j = 0; j < ncols; ++j) {
        double amax = 0.0;
        double umax = 0.0;

        for (int i = std::max(j - ku, 0); i < std::min(j + kl + 1, n); ++i) {
            amax = std::max(std::abs(ab[kd + i - j - 1][j]), amax);
        }

        for (int i = std::max(j - ku, 0); i <= j; ++i) {
            umax = std::max(std::abs(afb[kd + i - j - 1][j]), umax);
        }

        if (umax != 0.0) {
            rpvgrw = std::min(amax / umax, rpvgrw);
        }
    }

    return rpvgrw;
}

// Unit Test
TEST(DLA_GBRPVGRWTest, BasicTest) {
    int n = 3, kl = 1, ku = 1, ncols = 3, ldab = 3, ldafb = 3;
    std::vector<std::vector<double>> ab = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    std::vector<std::vector<double>> afb = {{1, 3.5, 6.5}, {1.5, 4.5, 7.5}, {2.5, 5.5, 8.5}};

    double result = dla_gbrpvgrw(n, kl, ku, ncols, ab, ldab, afb, ldafb);

    EXPECT_NEAR(result, 1.0, 1e-9); // Adjust the expected result and tolerance as necessary
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}