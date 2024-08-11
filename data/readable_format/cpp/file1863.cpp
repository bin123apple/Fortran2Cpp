#include <iostream>
#include <gtest/gtest.h>

// Define the dummy_subroutine function in this file
void dummy_subroutine() {
    for (int i = 1; i <= 10; ++i) {
        std::cout << "First loop body: " << i << std::endl;
    }

    for (int i = 1; i <= 10; ++i) {
        std::cout << "Second loop body: " << i << std::endl;
    }
}

// Unit Test
namespace {
    TEST(DummySubroutineTest, LoopTest) {
        // Here, we are simply calling the function to ensure it executes.
        // In a more complex scenario, you could mock std::cout to verify the output.
        EXPECT_NO_THROW(dummy_subroutine());
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}