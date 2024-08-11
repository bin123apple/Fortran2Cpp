// cscal.cpp
#include <iostream>
#include <complex>
#include <vector>

void CSCAL(int N, std::complex<float> CA, std::complex<float>* CX, int INCX) {
    if (N <= 0 || INCX <= 0) return;

    if (INCX == 1) {
        for (int I = 0; I < N; ++I) {
            CX[I] = CA * CX[I];
        }
    } else {
        for (int I = 0; I < N; I += INCX) {
            CX[I] = CA * CX[I];
        }
    }
}

// test_cscal.cpp
#include <gtest/gtest.h>

TEST(CSCALTest, Test1) {
    int N = 5;
    std::complex<float> CA(2, 3);
    std::vector<std::complex<float>> CX(N, std::complex<float>(1, 1));
    CSCAL(N, CA, CX.data(), 1);
    for (const auto& val : CX) {
        EXPECT_EQ(val, std::complex<float>(-1, 5));
    }
}

TEST(CSCALTest, Test2) {
    int N = 4;
    std::complex<float> CA(0.5, 0.5);
    std::vector<std::complex<float>> CX(N, std::complex<float>(2, 2));
    CSCAL(N, CA, CX.data(), 2);
    EXPECT_EQ(CX[0], std::complex<float>(0, 2));
    EXPECT_EQ(CX[2], std::complex<float>(0, 2));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}