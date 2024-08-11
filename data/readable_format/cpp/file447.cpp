#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <iostream>

// Assuming the translated functions are as previously described:

void maxvalIJS2(const std::vector<int>& array, int& maxValue) {
    if (!array.empty()) {
        auto it = std::max_element(array.begin(), array.end());
        maxValue = *it;
    } else {
        maxValue = 0;
    }
}

void maxvalISS2(const std::vector<int>& array, int& maxValue) {
    if (!array.empty()) {
        auto it = std::max_element(array.begin(), array.end());
        maxValue = *it;
    } else {
        maxValue = 0;
    }
}

// Test cases
TEST(MaxValTest, TestMaxvalIJS2) {
    std::vector<int> testArray = {1, 5, 3, 7, 6};
    int maxValue;
    maxvalIJS2(testArray, maxValue);
    EXPECT_EQ(maxValue, 7) << "maxvalIJS2 should return the max value of 7";
}

TEST(MaxValTest, TestMaxvalISS2) {
    std::vector<int> testArray = {1, 5, 3, 7, 6};
    int maxValue;
    maxvalISS2(testArray, maxValue);
    EXPECT_EQ(maxValue, 7) << "maxvalISS2 should return the max value of 7";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}