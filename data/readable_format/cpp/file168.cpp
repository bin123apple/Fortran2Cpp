#include <gtest/gtest.h>
#include <vector>
#include <cstdint>
#include <iostream>

// Global variables for simplicity
std::vector<int64_t> foo(2);
std::vector<int64_t> bar(2, 42); // Initialize bar with 42
int64_t lb = 4294967296;
int64_t ub = 4294967297;

// Function to mimic the Fortran behavior in C++
void initializeAndCopy() {
    // Copy values from bar to foo
    foo = bar;
}

// Test fixture for Google Test
class FooBarTest : public ::testing::Test {
protected:
    void SetUp() override {
        initializeAndCopy();
    }
};

TEST_F(FooBarTest, Initialization) {
    // Test if bar is initialized correctly
    for (auto& val : bar) {
        EXPECT_EQ(val, 42);
    }
}

TEST_F(FooBarTest, Copy) {
    // Test if values are copied from bar to foo correctly
    EXPECT_EQ(foo.size(), bar.size());
    for (std::size_t i = 0; i < foo.size(); ++i) {
        EXPECT_EQ(foo[i], bar[i]);
    }
}

TEST_F(FooBarTest, Bounds) {
    // Test bounds of foo
    EXPECT_EQ(lb, 4294967296);
    EXPECT_EQ(ub, 4294967297);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}