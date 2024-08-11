#include <iostream>
#include <gtest/gtest.h>

// Assuming these were previously missing or external.
bool isFinalized = false; // Global variable to track finalization status.

void ROMS_finalize() {
    // Simulate some finalization logic.
    std::cout << "ROMS_finalize called, environment finalized." << std::endl;
    isFinalized = true;
}

// The test case for the ROMS_finalize function.
TEST(AbortFunctionTest, TestROMSFinalize) {
    // Before calling ROMS_finalize, isFinalized should be false.
    ASSERT_FALSE(isFinalized);

    // Call the function we want to test.
    ROMS_finalize();
    
    // Check if ROMS_finalize did its job by setting isFinalized to true.
    EXPECT_TRUE(isFinalized);
}

int main(int argc, char **argv) {
    // Initializes Google Test.
    ::testing::InitGoogleTest(&argc, argv);
    // Runs all tests and returns the result.
    return RUN_ALL_TESTS();
}