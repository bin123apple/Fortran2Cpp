#include <vector>
#include <iostream>
#include <gtest/gtest.h>

class MoColumn {
public:
    void computeColumn(int nz, std::vector<std::vector<double>>& q, std::vector<std::vector<double>>& t, int nproma) {
        for (int k = 0; k < nz; ++k) {
            for (int proma = 0; proma < nproma; ++proma) {
                if (t[proma][k] > 0.0) {
                    q[proma][k] /= t[proma][k];
                }
            }
        }
    }
};

TEST(MoColumnTest, ComputesCorrectly) {
    MoColumn moColumn;
    int nz = 2;
    int nproma = 2;
    std::vector<std::vector<double>> t = {{1.0, -1.0}, {2.0, 4.0}};
    std::vector<std::vector<double>> q = {{2.0, 2.0}, {4.0, 8.0}};

    moColumn.computeColumn(nz, q, t, nproma);

    EXPECT_DOUBLE_EQ(q[0][0], 2.0);
    EXPECT_DOUBLE_EQ(q[0][1], 2.0);
    EXPECT_DOUBLE_EQ(q[1][0], 2.0);
    EXPECT_DOUBLE_EQ(q[1][1], 2.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}