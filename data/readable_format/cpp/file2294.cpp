#include <iostream>
#include <gtest/gtest.h>

// Mock implementations of dependencies
extern "C" void finalize_dyn() {
    std::cout << "finalize_dyn called" << std::endl;
    // Your mock implementation here
}

extern "C" void finalize_phy() {
    std::cout << "finalize_phy called" << std::endl;
    // Your mock implementation here
}

extern "C" void shtns_destroy() {
    std::cout << "shtns_destroy called" << std::endl;
    // Your mock implementation here
}

// The gfsFinalise function that calls the dependencies
extern "C" void gfsFinalise() {
    finalize_dyn();
    finalize_phy();
    shtns_destroy();
    std::cout << "gfsFinalise executed successfully." << std::endl;
}

// Test case for gfsFinalise function
TEST(FinalizeTest, BasicTest) {
    // Call the gfsFinalise function
    gfsFinalise();
    
    // If the function completes without throwing an error, the test passes
    EXPECT_TRUE(true); // This line is just to have an assertion. In real tests, replace it with actual checks.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}