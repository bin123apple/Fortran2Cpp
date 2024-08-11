#include <vector>
#include <iostream>
#include <gtest/gtest.h>

// Implementation of pbm_cut directly in this file
void pbm_cut(std::vector<std::vector<int>>& ks, int kstart, int kend, int nthds) {
    int kend0 = kend;
    int kstart0 = kstart;
    int ithds = 0;

    while (ithds < nthds - 1) {
        int nn = kend0 - kstart0 + 1;
        int nblk = nn / (nthds - ithds);
        nblk = std::max(nblk, 0); // Ensure nblk is not negative

        if (nblk % 2 == 1) {
            nblk += 1;
        }

        ks[0][ithds] = kstart0;
        ks[1][ithds] = kstart0 + nblk - 1;
        kstart0 += nblk;
        ithds++;
    }

    int nn = kend0 - kstart0 + 1;
    int nblk = nn;
    nblk = std::max(nblk, 0); // Ensure nblk is not negative

    ks[0][ithds] = kstart0;
    ks[1][ithds] = kstart0 + nblk - 1;
}

// Unit tests for pbm_cut function using Google Test
TEST(PbmCutTest, HandlesEqualDivision) {
    int kstart = 1;
    int kend = 100;
    int nthds = 10;
    std::vector<std::vector<int>> ks(2, std::vector<int>(nthds, 0));
    pbm_cut(ks, kstart, kend, nthds);

    EXPECT_EQ(ks[0][0], 1);
    EXPECT_EQ(ks[1][nthds-1], 100);
}

TEST(PbmCutTest, HandlesOddNumberOfElements) {
    int kstart = 1;
    int kend = 101;
    int nthds = 10;
    std::vector<std::vector<int>> ks(2, std::vector<int>(nthds, 0));
    pbm_cut(ks, kstart, kend, nthds);

    EXPECT_EQ(ks[0][0], 1);
    EXPECT_EQ(ks[1][nthds-1], 101);
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}