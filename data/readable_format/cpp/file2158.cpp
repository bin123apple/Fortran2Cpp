#include <iostream>
#include <vector>
#include <cmath>

// Global variables simulating Fortran COMMON blocks
std::vector<double> WEIGHT(100);
int IWEIGHT;
std::vector<double> Y1(100), X1(100), X2(100), Y2(100);
int IPASS, IMAP;

void REGISY(int M, int N, const std::vector<double>& XC, std::vector<double>& RC, bool IFL) {
    for (int I = 0; I < M; ++I) {
        double Y2MY1 = Y2[I] - Y1[I];
        double XX2 = X1[I] * X1[I];
        double YY2 = Y1[I] * Y1[I];
        double RCSIMP = Y2MY1 - (XC[0] + XC[1] * X1[I] + XC[2] * Y1[I]);
        RC[I] = RCSIMP;

        if (IPASS == 1) continue;

        RC[I] -= (XC[3] * XX2 + XC[4] * Y1[I] * X1[I] + XC[5] * YY2);
        if (IPASS == 2) continue;

        RC[I] -= (XC[6] * Y1[I] * (XX2 + YY2) + XC[7] * Y1[I] * std::pow((XX2 + YY2), 2));
        if (IWEIGHT == 1) RC[I] *= WEIGHT[I];
    }
}

int main() {
    int M = 5;
    int N = 8;
    std::vector<double> XC = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    std::vector<double> RC(M);

    IWEIGHT = 1;
    IPASS = 3;
    
    for (int I = 0; I < M; ++I) {
        X1[I] = (I + 1) * 2.0;
        Y1[I] = (I + 1) * 1.0;
        Y2[I] = (I + 1) * 3.0;
        WEIGHT[I] = (I + 1) * 0.5;
    }

    bool IFL = true;
    REGISY(M, N, XC, RC, IFL);

    std::cout << "C++ Results:" << std::endl;
    for (int I = 0; I < M; ++I) {
        std::cout << "RC[" << I << "] = " << RC[I] << std::endl;
    }

    return 0;
}