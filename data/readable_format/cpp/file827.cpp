#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <gtest/gtest.h>

// Function to check if a number is a palindrome
bool is_pal(int targ) {
    std::string targ_str = std::to_string(targ);
    std::string rev_str = targ_str;
    std::reverse(rev_str.begin(), rev_str.end());
    return targ_str == rev_str;
}

// Function to find the largest palindrome made from the product of two 3-digit numbers
int findMaxPalindrome() {
    const int max_val = 999;
    int max_pal = 1;
    for (int i = 1; i <= max_val; ++i) {
        for (int j = i; j <= max_val; ++j) {
            int prod = i * j;
            if (is_pal(prod)) {
                max_pal = std::max(prod, max_pal);
            }
        }
    }
    return max_pal;
}

// Test cases for is_pal function
TEST(PalindromeTest, IsPalindrome) {
    EXPECT_TRUE(is_pal(12321));
    EXPECT_FALSE(is_pal(12345));
}

// Test for finding the maximum palindrome product
TEST(PalindromeTest, MaxPalindromeProduct) {
    EXPECT_EQ(findMaxPalindrome(), 906609);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();
    std::cout << "The largest palindrome made from the product of two 3-digit numbers is: " 
              << findMaxPalindrome() << std::endl;
    return result;
}