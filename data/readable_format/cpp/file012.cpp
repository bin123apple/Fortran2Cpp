#include <iostream>
#include <vector>
#include <cmath> // For atan
#include <gtest/gtest.h>

// Defining the namespace and its functions directly in this file
namespace bidon {
    int my_size(const std::vector<int>& t) {
        return t.size();
    }

    double get_pi() {
        return 4.0 * std::atan(1.0);
    }
}

// Unit tests for the functions in the bidon namespace
TEST(BidonTest, TestMySize) {
    std::vector<int> v = {1, 2, 3, 4};
    EXPECT_EQ(4, bidon::my_size(v));
}

TEST(BidonTest, TestGetPi) {
    double pi = bidon::get_pi();
    EXPECT_NEAR(pi, 3.14159265358979323846, 1e-5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}