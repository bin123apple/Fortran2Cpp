#include <cstdint>
#include <complex>
#include <vector>
#include <cmath>
#include <gtest/gtest.h>

// Assuming the nrtype definitions based on the previous translation

namespace nrtype {

// Integer kinds
using ikind = int32_t;
using lkind = int64_t;

// Floating-point kinds
using rkind = float; // Assuming single precision
using dkind = double; // Assuming double precision

// Complex kinds
using c_single = std::complex<rkind>;
using c_double = std::complex<dkind>;

// Logical
using log_var = bool;

// Constants
constexpr rkind pi = 3.1415927f;
constexpr dkind dpi = 3.14159265358979323846;

// Derived types for sparse matrices
struct sparse_single {
    ikind rows, cols;
    std::vector<rkind> values;
    std::vector<ikind> rowIndex, colIndex;
};

struct sparse_double {
    ikind rows, cols;
    std::vector<dkind> values;
    std::vector<ikind> rowIndex, colIndex;
};

} // namespace nrtype

// Unit tests

TEST(NrtypeTest, IntegerKinds) {
    EXPECT_EQ(sizeof(nrtype::ikind), 4);
    EXPECT_EQ(sizeof(nrtype::lkind), 8);
}

TEST(NrtypeTest, FloatingPointKinds) {
    EXPECT_TRUE((std::is_same<float, nrtype::rkind>::value));
    EXPECT_TRUE((std::is_same<double, nrtype::dkind>::value));
}

TEST(NrtypeTest, Constants) {
    EXPECT_FLOAT_EQ(nrtype::pi, 3.1415927f);
    EXPECT_DOUBLE_EQ(nrtype::dpi, 3.14159265358979323846);
}

TEST(NrtypeTest, DerivedTypes) {
    nrtype::sparse_single ss;
    ss.rows = 2;
    ss.cols = 3;
    EXPECT_EQ(ss.rows, 2);
    EXPECT_EQ(ss.cols, 3);

    nrtype::sparse_double sd;
    sd.rows = 4;
    sd.cols = 5;
    EXPECT_EQ(sd.rows, 4);
    EXPECT_EQ(sd.cols, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}