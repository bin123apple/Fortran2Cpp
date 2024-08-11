#include <gtest/gtest.h>
#include <string>
#include <algorithm>
#include <cctype>

// Up function definition
std::string Up(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) -> unsigned char { return std::toupper(c); });
    return result;
}

// Unit tests for the Up function
TEST(UpFunctionTest, ConvertsToUppercase) {
    EXPECT_EQ(Up("hello"), "HELLO");
    EXPECT_EQ(Up("world"), "WORLD");
    EXPECT_EQ(Up("TestString"), "TESTSTRING");
}

// Unit tests for the main logic
TEST(MainLogicTest, MatchesTargetString) {
    std::string input = "AbCdEfGhIjKlM";
    std::string target = "ABCDEFGHIJKLM";
    std::string converted = Up(input);
    EXPECT_EQ(converted, target);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}