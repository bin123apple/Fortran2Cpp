#include <gtest/gtest.h>
#include <limits>

// Directly include the type definitions in this file, replacing the need for gsw_mod_kinds.h
typedef float r4;
typedef double r8;

TEST(KindsTest, Precision) {
    // Test precision
    r4 var_r4 = 1.234567f; // Suffix 'f' to ensure float literal
    r8 var_r8 = 1.23456789012345; // Double precision by default

    EXPECT_FLOAT_EQ(1.234567f, var_r4);
    EXPECT_DOUBLE_EQ(1.23456789012345, var_r8);
}

TEST(KindsTest, Range) {
    // Test range
    r4 var_r4 = std::numeric_limits<r4>::max();
    r8 var_r8 = std::numeric_limits<r8>::max();

    EXPECT_GT(var_r4, 1.0E30f);
    EXPECT_GT(var_r8, 1.0E300);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}