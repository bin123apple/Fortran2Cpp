#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// Define the structure and functions directly in this file
struct t_type {
    std::vector<int> chars;
};

int callnb = 0;

bool recursivefunc(const t_type& thisObj) {
    t_type subpattern;
    bool match;

    callnb++; // Increment call number
    match = (callnb == 10);

    if (thisObj.chars.empty() || match) {
        return match;
    }

    subpattern.chars.resize(4);
    match = recursivefunc(subpattern);

    return match;
}

// Unit test code
class TestEnvironment : public ::testing::Test {
protected:
    void SetUp() override {
        callnb = 0;
    }
};

TEST_F(TestEnvironment, TestCondition) {
    t_type thisObj;
    thisObj.chars.resize(4);

    bool result = recursivefunc(thisObj) && callnb == 10;

    EXPECT_TRUE(result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}