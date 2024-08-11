#include <iostream>
#include <limits>
#include <cstddef> // For std::size_t
#include <gtest/gtest.h> // Ensure Google Test is properly linked

// Define the Precision namespace directly in this file
namespace Precision {

// Approximating Fortran's SELECTED_INT_KIND with C++ types
constexpr std::int16_t B1Ki = std::numeric_limits<std::int16_t>::max();
constexpr std::int32_t B2Ki = std::numeric_limits<std::int32_t>::max();
constexpr std::int32_t B4Ki = std::numeric_limits<std::int32_t>::max();
constexpr std::int64_t B8Ki = std::numeric_limits<std::int64_t>::max();

// Approximating Fortran's SELECTED_REAL_KIND with C++ types
using QuKi = long double; // Highest precision
using R8Ki = double;      // Double precision
using SiKi = float;       // Single precision

// Byte sizes of the types
constexpr std::size_t BYTES_IN_SiKi = sizeof(SiKi);
constexpr std::size_t BYTES_IN_R8Ki = sizeof(R8Ki);
constexpr std::size_t BYTES_IN_QuKi = sizeof(QuKi);

// Default integer kind and size
using IntKi = decltype(B4Ki);
constexpr std::size_t BYTES_IN_INT = sizeof(IntKi);

// Conditionally compile for different precision settings
// Note: You'll need to define DOUBLE_PRECISION before including this file
// if you want to test the double precision setting.
#ifndef DOUBLE_PRECISION
using ReKi = SiKi;
using DbKi = R8Ki;

constexpr std::size_t BYTES_IN_REAL = BYTES_IN_SiKi;
constexpr std::size_t BYTES_IN_DBL = BYTES_IN_R8Ki;
#else
using ReKi = R8Ki;
using DbKi = QuKi;

constexpr std::size_t BYTES_IN_REAL = BYTES_IN_R8Ki;
constexpr std::size_t BYTES_IN_DBL = BYTES_IN_QuKi;
#endif

} // Namespace Precision

// Unit Tests
TEST(PrecisionTest, IntegerTypes) {
    EXPECT_EQ(sizeof(std::int16_t), 2);
    EXPECT_EQ(sizeof(std::int32_t), 4);
    EXPECT_EQ(sizeof(std::int64_t), 8);
}

TEST(PrecisionTest, RealTypes) {
    EXPECT_EQ(sizeof(Precision::SiKi), 4);
    EXPECT_EQ(sizeof(Precision::R8Ki), 8);
    EXPECT_TRUE(sizeof(Precision::QuKi) == 16 || sizeof(Precision::QuKi) == 12); // Platform dependent
}

TEST(PrecisionTest, ConditionalCompilation) {
    #ifndef DOUBLE_PRECISION
    EXPECT_EQ(sizeof(Precision::ReKi), Precision::BYTES_IN_REAL);
    EXPECT_EQ(sizeof(Precision::DbKi), Precision::BYTES_IN_DBL);
    #else
    EXPECT_EQ(sizeof(Precision::ReKi), Precision::BYTES_IN_REAL);
    EXPECT_EQ(sizeof(Precision::DbKi), Precision::BYTES_IN_DBL);
    #endif
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}