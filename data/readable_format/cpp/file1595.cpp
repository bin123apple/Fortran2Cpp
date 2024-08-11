#include <iostream>
#include <array>
#include <cmath>
#include <gtest/gtest.h>

class MNormal {
public:
    // Function to compute the normalized vector
    static std::array<double, 2> normal(const std::array<double, 2>& v) {
        std::array<double, 2> n;
        n[0] = v[1];
        n[1] = -v[0];
        double norm = std::sqrt(n[0] * n[0] + n[1] * n[1]);
        n[0] /= norm;
        n[1] /= norm;
        return n;
    }
};

TEST(NormalizeVectorTest, FirstQuadrant) {
    std::array<double, 2> a = {1.0, 1.0};
    std::array<double, 2> expected = {sqrt(0.5), -sqrt(0.5)};
    auto result = MNormal::normal(a);
    EXPECT_NEAR(expected[0], result[0], 1e-7);
    EXPECT_NEAR(expected[1], result[1], 1e-7);
}

TEST(NormalizeVectorTest, SecondQuadrant) {
    std::array<double, 2> a = {-1.0, 1.0};
    std::array<double, 2> expected = {sqrt(0.5), sqrt(0.5)};
    auto result = MNormal::normal(a);
    EXPECT_NEAR(expected[0], result[0], 1e-7);
    EXPECT_NEAR(expected[1], result[1], 1e-7);
}

TEST(NormalizeVectorTest, DifferentMagnitude) {
    std::array<double, 2> a = {3.0, 4.0};
    std::array<double, 2> expected = {0.8, -0.6};
    auto result = MNormal::normal(a);
    EXPECT_NEAR(expected[0], result[0], 1e-7);
    EXPECT_NEAR(expected[1], result[1], 1e-7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}