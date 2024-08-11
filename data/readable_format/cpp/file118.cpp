#include <gtest/gtest.h>
#include <string>

// Function to trim trailing spaces from a string
void charln(std::string& text) {
    // Initialize the length of the text
    int klen = text.length();

    // Loop to trim trailing spaces
    while (klen > 0 && text[klen - 1] == ' ') {
        klen--;
    }

    // Resize the string to remove trailing spaces
    text.resize(klen);
}

// Test cases for the charln function
TEST(CharlnTest, TrailingSpaces) {
    std::string text = "Hello, World!   ";
    charln(text);
    EXPECT_EQ(text, "Hello, World!");
}

TEST(CharlnTest, NoTrailingSpaces) {
    std::string text = "C++";
    charln(text);
    EXPECT_EQ(text, "C++");
}

TEST(CharlnTest, EmptyString) {
    std::string text = "";
    charln(text);
    EXPECT_EQ(text, "");
}

// Main function for the test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}