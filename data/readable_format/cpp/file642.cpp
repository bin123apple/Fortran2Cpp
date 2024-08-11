#include <gtest/gtest.h>

// The function to be tested
void whatever(bool& l1, const bool l2, const bool l3) {
    if ((l1 && l2) != l3) {
        l1 = true;
    } else {
        l1 = false;  // Ensure l1 is explicitly set to false when condition is not met
    }
}

// Test fixture for Whatever function
class WhateverTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code here, if needed
    }

    void TearDown() override {
        // Cleanup code here, if needed
    }
};

TEST_F(WhateverTest, Test1) {
    bool l1 = false;
    bool l2 = false;
    bool l3 = false;
    whatever(l1, l2, l3);
    EXPECT_FALSE(l1); // Corrected expectation based on the Fortran unit test results
}

TEST_F(WhateverTest, Test2) {
    bool l1 = false;
    bool l2 = true;
    bool l3 = true;
    whatever(l1, l2, l3);
    EXPECT_TRUE(l1); // Expect l1 to be true after the function call
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}