#include <gtest/gtest.h>

namespace magma_param {
    constexpr int sizeof_complex_16 = 16;
    constexpr int sizeof_complex = 8;
    constexpr int sizeof_double = 8;
    constexpr int sizeof_real = 4;
}

TEST(MagmaParamTest, SizeConstants) {
    EXPECT_EQ(magma_param::sizeof_complex_16, 16);
    EXPECT_EQ(magma_param::sizeof_complex, 8);
    EXPECT_EQ(magma_param::sizeof_double, 8);
    EXPECT_EQ(magma_param::sizeof_real, 4);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}