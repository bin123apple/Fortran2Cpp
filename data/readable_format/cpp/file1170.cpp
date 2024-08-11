#include <gtest/gtest.h>
#include <iostream>

// Assuming this is the content of runProgram() which was your main program logic.
// For demonstration, it simply returns 0 indicating success.
int runProgram() {
    // Your original program logic here.
    std::cout << "Original program logic runs here."; // Keep the string in one line
    return 0; // Example return value to indicate success.
}

// Test case definition.
TEST(MainProgramTest, NormalCondition) {
    EXPECT_EQ(runProgram(), 0) << "The program should exit with code 0 under normal conditions.";
}

// Main function to run all tests.
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}