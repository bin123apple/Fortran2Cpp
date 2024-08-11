#include <gtest/gtest.h>

// Normally, this would be in n_layers.h
namespace NLayers {
    int calculateLayers(int x) {
        return x * 2; // Example functionality
    }
}

// Test cases
TEST(NLayersTest, CalculateLayers) {
    EXPECT_EQ(4, NLayers::calculateLayers(2));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}