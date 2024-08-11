// test_t3dmix_mod.cpp
#include <gtest/gtest.h>

// Instead of including from "t3dmix_mod.hpp", define your class or namespace directly here.
namespace t3dmix_mod {
    // Example function to demonstrate testing.
    int add(int a, int b) {
        return a + b;
    }
}

// Test case for the add function
TEST(T3dmixModTest, AddFunction) {
    EXPECT_EQ(3, t3dmix_mod::add(1, 2));
    EXPECT_EQ(5, t3dmix_mod::add(2, 3));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}