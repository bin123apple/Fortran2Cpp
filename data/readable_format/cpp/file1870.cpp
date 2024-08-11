#include <gtest/gtest.h>
#include <cmath>

// Defining the namespace directly in this file instead of using a separate header.
namespace current_kind {
    constexpr double Zero = 0.0;
    constexpr double One = 1.0;
    constexpr double Quarter = 0.25;
    constexpr double Four = 4.0;
    constexpr double Half = 0.5;
    constexpr double Eighth = 0.125;
    constexpr double Two = 2.0;
    constexpr double Third = 1.0 / 3.0;
}

// Unit tests for the constants
TEST(CurrentKindTest, Constants) {
    EXPECT_DOUBLE_EQ(current_kind::Zero, 0.0);
    EXPECT_DOUBLE_EQ(current_kind::One, 1.0);
    EXPECT_NEAR(current_kind::Quarter, 0.25, 1e-9);
    EXPECT_DOUBLE_EQ(current_kind::Four, 4.0);
    EXPECT_NEAR(current_kind::Half, 0.5, 1e-9);
    EXPECT_NEAR(current_kind::Eighth, 0.125, 1e-9);
    EXPECT_DOUBLE_EQ(current_kind::Two, 2.0);
    EXPECT_NEAR(current_kind::Third, 1.0 / 3.0, 1e-9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}