// TBKSB.cpp
#include <vector>
#include <iostream>

void TBKSB(const std::vector<double>& W, const std::vector<std::vector<double>>& V, int N, std::vector<double>& B, std::vector<double>& X) {
    double S, WTMP, VTMP, XTMP, BTMP;
    for (int i = 0; i < N; ++i) {
        X[i] = 0.0;
    }
    for (int K = 0; K < N; ++K) {
        if (W[K] != 0.0) {
            WTMP = 1.0 / W[K];
            for (int I = 0; I < N; ++I) {
                X[I] += V[I][K] * WTMP * V[I][K] * B[I];
            }
            for (int I = 0; I < N - 1; ++I) {
                XTMP = X[I];
                BTMP = B[I];
                VTMP = V[I][K];
                for (int J = I + 1; J < N; ++J) {
                    S = VTMP * WTMP * V[J][K];
                    XTMP += S * B[J];
                    X[J] += S * BTMP;
                }
                X[I] = XTMP;
            }
        }
    }
}

// Main.cpp
#include <gtest/gtest.h>

TEST(TBKSBTest, BasicTest) {
    const int N = 3;
    std::vector<double> W = {1.0, 2.0, 3.0};
    std::vector<std::vector<double>> V = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
    std::vector<double> B = {1.0, 2.0, 3.0};
    std::vector<double> X(N, 0.0); // Initialize X with zeros

    TBKSB(W, V, N, B, X);

    std::vector<double> expectedX = {1.0, 1.0, 1.0}; // Based on the Fortran output
    for (int i = 0; i < N; ++i) {
        EXPECT_NEAR(X[i], expectedX[i], 1e-9);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}