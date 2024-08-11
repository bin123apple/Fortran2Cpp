#include <gtest/gtest.h>
#include <string>

// Define replaceCharacter directly in this file
void replaceCharacter(std::string& str, char oldChar, char newChar) {
    size_t length = str.length();
    for (size_t i = 0; i < length; ++i) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

// Unit tests
TEST(ReplaceCharacterTest, ReplaceAtVariousPositions) {
    std::string testString = "abcdeabcdeabcde";
    replaceCharacter(testString, 'a', 'z');
    EXPECT_EQ(testString, "zbcdezbcdezbcde");
}

TEST(ReplaceCharacterTest, OldCharDoesNotExist) {
    std::string testString = "abcdeabcdeabcde";
    replaceCharacter(testString, 'x', 'y');
    EXPECT_EQ(testString, "abcdeabcdeabcde");
}

TEST(ReplaceCharacterTest, MultipleInstancesOfOldChar) {
    std::string testString = "aaaaa";
    replaceCharacter(testString, 'a', 'b');
    EXPECT_EQ(testString, "bbbbb");
}

TEST(ReplaceCharacterTest, EmptyString) {
    std::string testString = "";
    replaceCharacter(testString, 'a', 'b');
    EXPECT_EQ(testString, "");
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}