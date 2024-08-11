#include <gtest/gtest.h>
#include <vector>

// Define the dscal function directly in this file
void dscal(int n, double da, std::vector<double>& dx, int incx) {
    if (n <= 0 || incx <= 0) return;

    if (incx == 1) {
        int m = n % 5;
        if (m != 0) {
            for (int i = 0; i < m; ++i) {
                dx[i] = da * dx[i];
            }
            if (n < 5) return;
        }
        for (int i = m; i < n; i += 5) {
            dx[i] = da * dx[i];
            dx[i + 1] = da * dx[i + 1];
            dx[i + 2] = da * dx[i + 2];
            dx[i + 3] = da * dx[i + 3];
            dx[i + 4] = da * dx[i + 4];
        }
    } else {
        int nincx = n * incx;
        for (int i = 0; i < nincx; i += incx) {
            dx[i] = da * dx[i];
        }
    }
}

// Test Cases
TEST(DscalTest, PositiveScaling) {
    std::vector<double> dx = {1.0, 2.0, 3.0, 4.0, 5.0};
    double da = 2.0;
    int incx = 1;
    dscal(5, da, dx, incx);
    std::vector<double> expected = {2.0, 4.0, 6.0, 8.0, 10.0};
    EXPECT_EQ(dx, expected);
}

TEST(DscalTest, NonContiguousAccess) {
    std::vector<double> dx = {1.0, 1.0, 2.0, 2.0, 3.0, 3.0};
    double da = 3.0;
    int incx = 2;
    dscal(3, da, dx, incx);
    std::vector<double> expected = {3.0, 1.0, 6.0, 2.0, 9.0, 3.0};
    EXPECT_EQ(dx, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}