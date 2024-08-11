#include <gtest/gtest.h>
#include <array>

// Define the equivalent structure to COMMON/RAND2/
struct RAND2 {
    int IY = 0;
    int IFF = 0; // Initialized as per DATA statement
    std::array<int, 97> IR = {}; // Default initialized to 0
};

// Define the equivalent structure to COMMON/ICPU0/
struct ICPU0 {
    int ICPU = 0; // Initialized as per DATA statement
};

// Global instances
RAND2 rand2;
ICPU0 icpu0;

// Initialization function, equivalent to BLOCK DATA BLOCK
void initializeBlock() {
    rand2.IFF = 0; // Explicit initialization, if needed
    icpu0.ICPU = 0; // Explicit initialization, if needed
    // No need to initialize rand2.IY and rand2.IR as they are already default initialized to 0.
}

// Unit test code
TEST(BlockDataTest, InitializationTest) {
    initializeBlock(); // Call the initialization

    // Verify that the global variables are initialized correctly
    EXPECT_EQ(rand2.IFF, 0);
    EXPECT_EQ(icpu0.ICPU, 0);
    // You can also test the initialization of rand2.IR array elements if needed
    EXPECT_EQ(rand2.IR[0], 0); // Just an example, testing the first element
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}