#include <gtest/gtest.h>

// Assuming the use of a namespace for mod1
namespace mod1 {
    constexpr int modval1 = 1; // Replaced @ONE@ with 1
}

// Unit test code
TEST(Mod1Test, CheckModval1) {
    EXPECT_EQ(mod1::modval1, 1); // Ensures modval1 equals 1
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}