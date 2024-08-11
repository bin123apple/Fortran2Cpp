#include <gtest/gtest.h>
#include <vector>
#include <cmath> // for exp() and abs()

// Assuming global variable (from common /cqinit/ in Fortran)
double beta; 

// The qinit function translated from Fortran to C++
void qinit(int maxmx, int meqn, int mbc, int mx, double xlower, double dx, std::vector<std::vector<double>>& q, int maux, std::vector<std::vector<double>>& aux) {
    for (int i = 0; i < mx; ++i) {
        double xcell = xlower + (i + 0.5) * dx;
        q[i][0] = 0.5 * exp(-80.0 * xcell * xcell);
        if (std::abs(xcell + 0.2) < 0.1) {
            q[i][0] += 0.5;
        }
        q[i][1] = 0.0;
    }
}

// Unit test for qinit function
TEST(QinitTest, InitializesCorrectly) {
    int maxmx = 100, meqn = 2, mbc = 1, mx = 5;
    double xlower = 0.0, dx = 0.01;
    std::vector<std::vector<double>> q(mx, std::vector<double>(meqn, 0.0));
    int maux = 0; // Example value, adjust as needed
    std::vector<std::vector<double>> aux; // Assuming aux isn't used in this simplified example

    qinit(maxmx, meqn, mbc, mx, xlower, dx, q, maux, aux);

    // Check the first few values of q
    EXPECT_NEAR(0.5 * exp(-80.0 * (0.005 * 0.005)), q[0][0], 1e-5);
    EXPECT_DOUBLE_EQ(0.0, q[0][1]);
    // Add more checks as necessary
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}