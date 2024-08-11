#include <iostream>
#include <cmath>
#include <cstdint>
#include <limits>
#include <gtest/gtest.h>

// Function approximating Fortran's selected_int_kind
int selected_int_kind(int r) {
    if (r <= std::log10(std::numeric_limits<int8_t>::max())) return 1;
    if (r <= std::log10(std::numeric_limits<int16_t>::max())) return 2;
    if (r <= std::log10(std::numeric_limits<int32_t>::max())) return 4;
    if (r <= std::log10(std::numeric_limits<int64_t>::max())) return 8;
    return -1;
}

// Tests
TEST(SelectedIntKindTest, HandlesInt8Max) {
    EXPECT_EQ(selected_int_kind(static_cast<int>(std::log10(std::numeric_limits<int8_t>::max()))), 1);
}

TEST(SelectedIntKindTest, HandlesInt16Max) {
    EXPECT_EQ(selected_int_kind(static_cast<int>(std::log10(std::numeric_limits<int16_t>::max()))), 2);
}

TEST(SelectedIntKindTest, HandlesInt32Max) {
    EXPECT_EQ(selected_int_kind(static_cast<int>(std::log10(std::numeric_limits<int32_t>::max()))), 4);
}

TEST(SelectedIntKindTest, HandlesInt64Max) {
    EXPECT_EQ(selected_int_kind(static_cast<int>(std::log10(std::numeric_limits<int64_t>::max()))), 8);
}

TEST(SelectedIntKindTest, HandlesSpecialCase) {
    int i4 = std::numeric_limits<int32_t>::max();
    EXPECT_EQ(selected_int_kind(i4), -1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}