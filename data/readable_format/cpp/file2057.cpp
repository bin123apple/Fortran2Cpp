#include <vector>
#include <cmath> // For std::abs
#include <gtest/gtest.h>

// Define the tag4refinement function directly in this file
void tag4refinement(int mx, int my, int mbc,
                    int meqn, double xlower, double ylower, double dx, double dy, int blockno,
                    const std::vector<std::vector<std::vector<double>>>& q, double tag_threshold, 
                    int& init_flag, int& tag_patch) {
    tag_patch = 0;

    for (int j = -mbc; j < my + mbc; ++j) {
        for (int i = -mbc; i < mx + mbc; ++i) {
            double qval = q[0][i + mbc][j + mbc]; // Assuming meqn=1 for simplicity
            if (std::abs(qval) > tag_threshold) {
                tag_patch = 1;
                return;
            }
        }
    }
}

// Unit tests for tag4refinement
TEST(Tag4RefinementTest, NoValuesExceedThreshold) {
    int mx = 2, my = 2, mbc = 1, meqn = 1;
    double xlower = 0, ylower = 0, dx = 1, dy = 1, tag_threshold = 1.0;
    int blockno = 0, init_flag = 0, tag_patch = 0;
    std::vector<std::vector<std::vector<double>>> q(meqn, std::vector<std::vector<double>>(mx + 2*mbc, std::vector<double>(my + 2*mbc, 0.0)));

    tag4refinement(mx, my, mbc, meqn, xlower, ylower, dx, dy, blockno, q, tag_threshold, init_flag, tag_patch);
    EXPECT_EQ(tag_patch, 0);
}

TEST(Tag4RefinementTest, ValuesExceedThreshold) {
    int mx = 2, my = 2, mbc = 1, meqn = 1;
    double xlower = 0, ylower = 0, dx = 1, dy = 1, tag_threshold = 1.5;
    int blockno = 0, init_flag = 0, tag_patch = 0;
    std::vector<std::vector<std::vector<double>>> q(meqn, std::vector<std::vector<double>>(mx + 2*mbc, std::vector<double>(my + 2*mbc, 0.0)));
    q[0][mbc][mbc] = 2.0; // Exceeds threshold

    tag4refinement(mx, my, mbc, meqn, xlower, ylower, dx, dy, blockno, q, tag_threshold, init_flag, tag_patch);
    EXPECT_EQ(tag_patch, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}