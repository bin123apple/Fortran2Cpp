#include <string>
#include <gtest/gtest.h>

// Define the ST_LCUC function directly in this file
void ST_LCUC(const std::string& string, std::string& outstr, int& iret) {
    iret = 0; // Assuming iret is used to indicate success/failure, keeping it 0 as the original code doesn't modify it.
    outstr = string; // Copy input string to output string.
    int isize = outstr.length(); // Get the length of the string.

    for (int i = 0; i < isize; ++i) {
        if (outstr[i] >= 'a' && outstr[i] <= 'z') { // Check if the character is lowercase.
            outstr[i] = outstr[i] - 32; // Convert to uppercase (ASCII manipulation).
        }
    }
}

// Test cases
TEST(STLCUCTest, EmptyString) {
    std::string input = "";
    std::string output;
    int iret;
    ST_LCUC(input, output, iret);
    EXPECT_EQ(output, "");
}

TEST(STLCUCTest, OnlyUppercaseLetters) {
    std::string input = "HELLO";
    std::string output;
    int iret;
    ST_LCUC(input, output, iret);
    EXPECT_EQ(output, "HELLO");
}

TEST(STLCUCTest, OnlyLowercaseLetters) {
    std::string input = "world";
    std::string output;
    int iret;
    ST_LCUC(input, output, iret);
    EXPECT_EQ(output, "WORLD");
}

TEST(STLCUCTest, MixedCharacters) {
    std::string input = "HeLlO 123!";
    std::string output;
    int iret;
    ST_LCUC(input, output, iret);
    EXPECT_EQ(output, "HELLO 123!");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}