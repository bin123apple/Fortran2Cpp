#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <gtest/gtest.h>

class ModArrays {
public:
    static std::vector<float> reverse(const std::vector<float>& x) {
        std::vector<float> result(x.rbegin(), x.rend());
        return result;
    }

    static float average(const std::vector<float>& x) {
        float sum = std::accumulate(x.begin(), x.end(), 0.0f);
        return sum / x.size();
    }

    static float std(const std::vector<float>& x) {
        float avg = average(x);
        float sumSqDiff = std::accumulate(x.begin(), x.end(), 0.0f,
                                          [avg](float acc, float val) {
                                              return acc + (val - avg) * (val - avg);
                                          });
        return std::sqrt(sumSqDiff / x.size());
    }

    static std::vector<float> moving_average(const std::vector<float>& x, int window_size) {
        std::vector<float> ma(x.size());
        for (size_t i = 0; i < x.size(); ++i) {
            int lower_bound = std::max(static_cast<int>(i) - window_size + 1, 0);
            float avg = average(std::vector<float>(x.begin() + lower_bound, x.begin() + i + 1));
            ma[i] = avg;
        }
        return ma;
    }

    static std::vector<float> moving_std(const std::vector<float>& x, int window_size) {
        std::vector<float> ms(x.size());
        for (size_t i = 0; i < x.size(); ++i) {
            int lower_bound = std::max(static_cast<int>(i) - window_size + 1, 0);
            float standardDev = std(std::vector<float>(x.begin() + lower_bound, x.begin() + i + 1));
            ms[i] = standardDev;
        }
        return ms;
    }
};

// Unit tests

TEST(ModArraysTest, Reverse) {
    std::vector<float> input = {1, 2, 3, 4, 5};
    std::vector<float> expected = {5, 4, 3, 2, 1};
    EXPECT_EQ(ModArrays::reverse(input), expected);
}

TEST(ModArraysTest, Average) {
    std::vector<float> input = {1, 2, 3, 4, 5};
    float expected = 3;
    EXPECT_EQ(ModArrays::average(input), expected);
}

TEST(ModArraysTest, Std) {
    std::vector<float> input = {1, 2, 3, 4, 5};
    float expected = std::sqrt(2.0);
    EXPECT_NEAR(ModArrays::std(input), expected, 1e-6);
}

TEST(ModArraysTest, MovingAverage) {
    std::vector<float> input = {1, 2, 3, 4, 5};
    std::vector<float> expected = {1, 1.5, 2, 3, 4};
    EXPECT_EQ(ModArrays::moving_average(input, 3), expected);
}

TEST(ModArraysTest, MovingStd) {
    std::vector<float> input = {1, 2, 3, 4, 5};
    std::vector<float> expected = {0, std::sqrt(0.25), std::sqrt(0.666667), std::sqrt(0.666667), std::sqrt(0.666667)};
    auto result = ModArrays::moving_std(input, 3);
    for(size_t i = 0; i < expected.size(); ++i) {
        EXPECT_NEAR(result[i], expected[i], 1e-6);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}