#include <gtest/gtest.h>
#include <type_traits> // For type checking

// Define the SMConstants directly in this file
struct SMConstants {
    // Constants for precision digits
    static constexpr int DOUBLE_DIGITS = 15;
    static constexpr int SINGLE_DIGITS = 6;
    
    // Floating-point types
    using RP = double;
    using SP = float;
    using CP = double;

    // Prevent instantiation of this struct since it's meant to be a constants container
    SMConstants() = delete;
};

// Definitions for the static constexpr members
constexpr int SMConstants::DOUBLE_DIGITS;
constexpr int SMConstants::SINGLE_DIGITS;

// Unit tests for SMConstants
TEST(SMConstantsTest, Constants) {
    EXPECT_EQ(SMConstants::DOUBLE_DIGITS, 15);
    EXPECT_EQ(SMConstants::SINGLE_DIGITS, 6);
}

TEST(SMConstantsTest, Types) {
    EXPECT_TRUE((std::is_same<SMConstants::RP, double>::value));
    EXPECT_TRUE((std::is_same<SMConstants::SP, float>::value));
    EXPECT_TRUE((std::is_same<SMConstants::CP, double>::value));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}