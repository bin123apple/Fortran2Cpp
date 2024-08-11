#include <gtest/gtest.h>
#include <string>

// Function definition directly in this file
void ALPCLR(const std::string& DEV1) {
    // Function body. Currently, it does nothing.
}

// Test case for the ALPCLR function
TEST(ALPCLRTest, DoesNothingTest) {
    std::string dev1 = "ABC";
    ALPCLR(dev1);
    // Since ALPCLR does nothing, we check if dev1 remains unchanged.
    EXPECT_EQ(dev1, "ABC");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}