#include <gtest/gtest.h>

// Assuming this is the content you might have in ppm_comp_pp_doring.hpp
// A simple example function to be tested
int add(int a, int b) {
    return a + b;
}

// Test case for the add function
TEST(PPMDoringTest, TestAdd) {
    EXPECT_EQ(5, add(2, 3));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}