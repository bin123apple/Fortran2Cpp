#include <gtest/gtest.h>
#include <stdexcept>

// Mock-up implementations for the purposes of the test
const int STAT_STOPPED_IMAGE = 1; // Assuming this is the stopped status constant

// Mock implementation of the image_status function
int image_status(int image_id) {
    // Mock-up implementation to simulate the behavior.
    switch (image_id) {
        case 1: return 0; // OK
        case 2: // Fallthrough
        case 3: return STAT_STOPPED_IMAGE; // Stopped, example constant
        default: return -1; // Unknown status for simplicity
    }
}

// Unit Tests
TEST(ImageStatusTest, Image1ShouldReportOK) {
    EXPECT_EQ(image_status(1), 0);
}

TEST(ImageStatusTest, Image2ShouldBeStopped) {
    EXPECT_EQ(image_status(2), STAT_STOPPED_IMAGE);
}

TEST(ImageStatusTest, Image3ShouldBeStopped) {
    EXPECT_EQ(image_status(3), STAT_STOPPED_IMAGE);
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}