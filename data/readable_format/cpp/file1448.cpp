#include <array>
#include <gtest/gtest.h>

// Define the sizes namespace directly in this file, without using a separate header file.
namespace sizes {
    constexpr int Ndim = 3;
    constexpr std::array<int, Ndim> mesh = {100, 100, 100};
    constexpr int meshx = mesh[0];
    constexpr int meshy = mesh[1];
    constexpr int meshz = mesh[2];
}

// Test for Ndim
TEST(SizesTest, TestNdim) {
    EXPECT_EQ(sizes::Ndim, 3);
}

// Test for mesh array values
TEST(SizesTest, TestMeshArray) {
    EXPECT_EQ(sizes::mesh[0], 100);
    EXPECT_EQ(sizes::mesh[1], 100);
    EXPECT_EQ(sizes::mesh[2], 100);
}

// Test for meshx, meshy, meshz
TEST(SizesTest, TestMeshXYZ) {
    EXPECT_EQ(sizes::meshx, 100);
    EXPECT_EQ(sizes::meshy, 100);
    EXPECT_EQ(sizes::meshz, 100);
}

// The main function that runs all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}