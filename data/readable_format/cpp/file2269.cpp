#include <gtest/gtest.h>
#include <vector>
#include <cmath> // Include for std::pow

double sqdist(double x1, double y1, double z1, double x2, double y2, double z2, int ind, int MAXROT, const std::vector<std::vector<std::vector<double>>>& rotmat) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    double dz = z1 - z2;
    double sqdist = 0.0;

    for (int i = 0; i < 3; ++i) {
        double cont = rotmat[ind][i][0] * dx
                    + rotmat[ind][i][1] * dy
                    + rotmat[ind][i][2] * dz;
        sqdist += cont * cont;
    }

    return sqdist;
}

TEST(SqDistTest, BasicTest) {
    double x1 = 1.0, y1 = 2.0, z1 = 3.0;
    double x2 = 4.0, y2 = 5.0, z2 = 6.0;
    int ind = 0;
    int MAXROT = 3;

    std::vector<std::vector<std::vector<double>>> rotmat(MAXROT, std::vector<std::vector<double>>(3, std::vector<double>(3, 0.0)));

    // Initialize the rotation matrix
    rotmat[0][0][0] = 1.0; rotmat[0][0][1] = 0.0; rotmat[0][0][2] = 0.0;
    rotmat[0][1][0] = 0.0; rotmat[0][1][1] = 1.0; rotmat[0][1][2] = 0.0;
    rotmat[0][2][0] = 0.0; rotmat[0][2][1] = 0.0; rotmat[0][2][2] = 1.0;

    double result = sqdist(x1, y1, z1, x2, y2, z2, ind, MAXROT, rotmat);

    // Expected result calculation
    double expected = std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2) + std::pow(z1 - z2, 2);

    EXPECT_DOUBLE_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}