#include <gtest/gtest.h>
#include <complex>
#include <cmath>

// Define the kind_types class directly in this file
class kind_types {
public:
    static const int MaxParticles = 9;

    using intkind1 = int;
    using intkind2 = int;

    using dp = double;
    using qp = long double;

    static const std::complex<dp> cI_dp;
    static const std::complex<qp> cI_qp;

    static std::complex<dp> cmplx_dp(dp re, dp im = 0.0) {
        return std::complex<dp>(re, im);
    }

    static std::complex<qp> cmplx_qp(qp re, qp im = 0.0) {
        return std::complex<qp>(re, im);
    }
};

// Initialize the static constants
const std::complex<kind_types::dp> kind_types::cI_dp = std::complex<kind_types::dp>(0.0, 1.0);
const std::complex<kind_types::qp> kind_types::cI_qp = std::complex<kind_types::qp>(0.0, 1.0);

// Unit tests
TEST(kind_typesTest, cmplx_dp_with_imag) {
    std::complex<kind_types::dp> result = kind_types::cmplx_dp(1.0, 1.0);
    EXPECT_NEAR(result.real(), 1.0, 1e-10);
    EXPECT_NEAR(result.imag(), 1.0, 1e-10);
}

TEST(kind_typesTest, cmplx_dp_without_imag) {
    std::complex<kind_types::dp> result = kind_types::cmplx_dp(1.0);
    EXPECT_NEAR(result.real(), 1.0, 1e-10);
    EXPECT_NEAR(result.imag(), 0.0, 1e-10);
}

TEST(kind_typesTest, cmplx_qp_with_imag) {
    std::complex<kind_types::qp> result = kind_types::cmplx_qp(1.0L, 1.0L);
    EXPECT_NEAR(result.real(), 1.0L, 1e-10);
    EXPECT_NEAR(result.imag(), 1.0L, 1e-10);
}

TEST(kind_typesTest, cmplx_qp_without_imag) {
    std::complex<kind_types::qp> result = kind_types::cmplx_qp(1.0L);
    EXPECT_NEAR(result.real(), 1.0L, 1e-10);
    EXPECT_NEAR(result.imag(), 0.0L, 1e-10);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}