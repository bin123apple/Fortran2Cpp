#include <iostream>
#include <string>
#include <stdexcept>
#include <gtest/gtest.h>

// Function declarations
void test();
void sub(std::string& str, int j);

// Main test function
void test() {
    int i = 5;
    std::string s1;
    sub(s1, i); // Call the sub function

    if (s1.length() != 5) throw std::runtime_error("Length check failed");
    if (s1 != "ZZZZZ") throw std::runtime_error("String check failed");
}

// Sub function definition
void sub(std::string& str, int j) {
    str = std::string(j, 'Z'); // Repeat 'Z' j times

    if (str.length() != 5) throw std::runtime_error("Length check failed");
    if (str != "ZZZZZ") throw std::runtime_error("String check failed");
}

// Unit Tests using Google Test Framework
TEST(MainFunctionalityTest, StringManipulations) {
    EXPECT_NO_THROW({
        std::string s = std::string(2, 'x');
        EXPECT_EQ(s.length(), 2);
        EXPECT_EQ(s, "xx");
        EXPECT_EQ(std::string(2, ' ').length(), 2);
        EXPECT_EQ(std::string(2, 'y'), "yy");
    });
}

TEST(TestFunction, StringManipulations) {
    EXPECT_NO_THROW({
        test();  // Testing the 'test' function
    });
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}