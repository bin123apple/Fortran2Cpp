#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// Define the sqzlgv function directly in this file
void sqzlgv(const std::vector<int>& iptims, const std::vector<bool>& whotim, const std::vector<float>& valin, 
            std::vector<float>& valout) {
    for (size_t i = 0; i < iptims.size(); ++i) {
        if (whotim[iptims[i] - 1]) {
            valout.push_back(valin[i]);
        }
    }
}

// Basic test using Google Test
TEST(SqzlgvTest, FiltersCorrectly) {
    std::vector<int> iptims = {1, 2, 3, 4, 5};
    std::vector<bool> whotim = {true, false, true, false, true};
    std::vector<float> valin = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::vector<float> valout;

    sqzlgv(iptims, whotim, valin, valout);

    std::vector<float> expected_valout = {1.0f, 3.0f, 5.0f};
    EXPECT_EQ(valout.size(), 3);
    EXPECT_EQ(valout, expected_valout);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}