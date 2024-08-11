#include <iostream>
#include <string>
#include <cstdlib> // for abort
#include <gtest/gtest.h>

// Declare the functions directly in this file
std::string foo(int i) {
    if (i < 0) {
        return "1234";
    } else {
        return "abcd";
    }
}

std::string bar(int i) {
    if (i < 0) {
        return "4567";
    } else {
        return foo(i);
    }
}

// Unit Tests
TEST(FooBarTest, FooPositive) {
    EXPECT_EQ(foo(1), "abcd");
}

TEST(FooBarTest, FooNegative) {
    EXPECT_EQ(foo(-1), "1234");
}

TEST(FooBarTest, BarPositive) {
    EXPECT_EQ(bar(1), "abcd");
}

TEST(FooBarTest, BarNegative) {
    EXPECT_EQ(bar(-1), "4567");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // Main program logic could go here if needed
    // For demonstration, we'll just run the tests
    return RUN_ALL_TESTS();
}