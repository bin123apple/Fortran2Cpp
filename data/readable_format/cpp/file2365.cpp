#include <vector>
#include <iostream>
#include <gtest/gtest.h>

double computeD1(const std::vector<double>& Y, double H, int N, bool isDN) {
    const double C1 = -21.0;
    const double C2 = 13.0;
    const double C3 = 17.0;
    const double C4 = -9.0;
    const double R20 = 0.05;

    int I, IP;
    double SIGN;

    if (isDN) {
        I = -1;
        IP = N - 3; // Adjust for 0-based indexing and reverse order
        SIGN = -1.0;
    } else {
        I = 1;
        IP = 0; // Adjust for 0-based indexing
        SIGN = 1.0;
    }

    return SIGN * (C1 * Y[IP] + C2 * Y[IP + I] + C3 * Y[IP + 2 * I] + C4 * Y[IP + 3 * I]) * R20 / H;
}

double D1(const std::vector<double>& Y, double H, int N) {
    return computeD1(Y, H, N, false);
}

double DN(const std::vector<double>& Y, double H, int N) {
    return computeD1(Y, H, N, true);
}

TEST(D1DNTest, TestD1) {
    std::vector<double> Y = {1.0, 2.0, 3.0, 4.0, 5.0};
    double H = 1.0;
    int N = 5;
    
    double resultD1 = D1(Y, H, N);
    double expectedD1 = (-21.0*1.0 + 13.0*2.0 + 17.0*3.0 - 9.0*4.0) * 0.05 / H;
    ASSERT_NEAR(resultD1, expectedD1, 1e-6);
}

TEST(D1DNTest, TestDN) {
    std::vector<double> Y = {1.0, 2.0, 3.0, 4.0, 5.0};
    double H = 1.0;
    int N = 5;
    
    double resultDN = DN(Y, H, N);
    double expectedDN = (-21.0*5.0 + 13.0*4.0 + 17.0*3.0 - 9.0*2.0) * 0.05 * -1.0 / H;
    ASSERT_NEAR(resultDN, expectedDN, 1e-6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}