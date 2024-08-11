#include <iostream>
#include <utility> // For std::swap
#include <gtest/gtest.h> // Google Test Framework

namespace NumericKinds {
    
    // Assuming closest C++ types for real kinds
    using R_SP = float;       // Single Precision
    using R_DP = double;      // Double Precision
    using R_QP = long double; // Quadruple Precision
    
    using RK = R_DP; // Chosen real kind

    // Assuming closest C++ types for integer kinds
    using I1B = int8_t;
    using I2B = int16_t;
    using I3B = int32_t;
    using I4B = int64_t;

    using IK = I3B; // Chosen integer kind
    
    // Template function for swapping that works with both real and integer kinds
    template<typename T>
    void swap(T& a, T& b) {
        std::swap(a, b);
    }

    // Explicit instantiation for RK and IK
    template void swap<RK>(RK&, RK&);
    template void swap<IK>(IK&, IK&);
}

// Unit Tests
TEST(NumericKindsTest, SwapReal) {
    NumericKinds::RK a = 1.0, b = 2.0;
    NumericKinds::swap(a, b);
    EXPECT_EQ(a, 2.0);
    EXPECT_EQ(b, 1.0);
}

TEST(NumericKindsTest, SwapInteger) {
    NumericKinds::IK a = 1, b = 2;
    NumericKinds::swap(a, b);
    EXPECT_EQ(a, 2);
    EXPECT_EQ(b, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}