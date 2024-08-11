#include <gtest/gtest.h>
#include <string>
#include <cctype> // For std::toupper

// Define the ppm_rc_uppercase function directly in this file
void ppm_rc_uppercase(std::string& record) {
    for (char& c : record) {
        if (c >= 'a' && c <= 'z') {
            c = std::toupper(c);
        }
    }
}

// Unit tests
TEST(PpmRcUppercaseTest, ConvertsLowercaseToUppercase) {
    std::string test_string = "hello, world!";
    ppm_rc_uppercase(test_string);
    EXPECT_EQ(test_string, "HELLO, WORLD!");
}

TEST(PpmRcUppercaseTest, HandlesMixedCase) {
    std::string test_string = "FoRtRaN 77";
    ppm_rc_uppercase(test_string);
    EXPECT_EQ(test_string, "FORTRAN 77");
}

TEST(PpmRcUppercaseTest, HandlesNumbersAndPunctuation) {
    std::string test_string = "123abc!@#";
    ppm_rc_uppercase(test_string);
    EXPECT_EQ(test_string, "123ABC!@#");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}