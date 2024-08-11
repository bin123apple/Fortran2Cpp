#include <iostream>
#include <gtest/gtest.h>

// Mock functionality to test
namespace mo_kind {
    constexpr int pd = 12;
    constexpr int rd = 307;
    using dp = double; 
}

// Test case for the mo_kind namespace
TEST(MoKindTest, ConstantsCheck) {
    EXPECT_EQ(12, mo_kind::pd);
    EXPECT_EQ(307, mo_kind::rd);
    EXPECT_TRUE((std::is_same<double, mo_kind::dp>::value));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}