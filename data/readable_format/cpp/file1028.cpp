#include <cmath>
#include <gtest/gtest.h>

// Function definition for dnrm2 - computes the Euclidean norm of a vector
double dnrm2(int n, const double* x, int incx) {
    const double zero = 0.0;
    const double one = 1.0;
    double norm, scale, ssq, absxi;
    
    if (n < 1 || incx < 1) {
        norm = zero;
    } else if (n == 1) {
        norm = std::abs(x[0]);
    } else {
        scale = zero;
        ssq = one;
        for (int ix = 0; ix < 1 + (n - 1) * incx; ix += incx) {
            if (x[ix] != zero) {
                absxi = std::abs(x[ix]);
                if (scale < absxi) {
                    ssq = one + ssq * (scale / absxi) * (scale / absxi);
                    scale = absxi;
                } else {
                    ssq += (absxi / scale) * (absxi / scale);
                }
            }
        }
        norm = scale * std::sqrt(ssq);
    }
    return norm;
}

// Unit tests for dnrm2 function
TEST(DNRM2Test, PositiveNumbers) {
    double testVec[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double result = dnrm2(5, testVec, 1);
    EXPECT_NEAR(result, std::sqrt(55), 1e-9);
}

TEST(DNRM2Test, SkipElements) {
    double testVec[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double result = dnrm2(3, testVec, 2);
    EXPECT_NEAR(result, std::sqrt(1*1 + 3*3 + 5*5), 1e-9);
}

TEST(DNRM2Test, ZeroVector) {
    double testVec[] = {0.0, 0.0, 0.0, 0.0, 0.0};
    double result = dnrm2(5, testVec, 1);
    EXPECT_DOUBLE_EQ(result, 0.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}