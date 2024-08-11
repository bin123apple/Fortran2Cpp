#include <gtest/gtest.h>
#include <string>
#include <vector>

// Function to convert a vector of characters to a string
std::string charArray2String(const std::vector<char>& charArray) {
    std::string text;
    for (const char& c : charArray) {
        text += c;
    }
    return text;
}

// Test for charArray2String function
TEST(CharArray2StringTest, ConvertsCorrectly) {
    std::vector<char> testArray = {'A', 'B', 'C', 'D'};
    std::string result = charArray2String(testArray);
    ASSERT_EQ(result, "ABCD");
}

// Test for the entire program logic
TEST(ProgramTest, GeneratesCorrectString) {
    // Generate the character array
    std::vector<char> charArr;
    for (int i = 1; i <= 26; ++i) {
        charArr.push_back(char(i + 64)); // Uppercase letters
        charArr.push_back(char(i + 96)); // Lowercase letters
    }

    // Convert to string and compare
    std::string txt = charArray2String(charArr);
    ASSERT_EQ(txt, "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}