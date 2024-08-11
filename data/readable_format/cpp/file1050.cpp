// Filename: slar2v.cpp

#include <vector>
#include <iostream>

void SLAR2V(int N, std::vector<float>& X, std::vector<float>& Y, std::vector<float>& Z, int INCX, const std::vector<float>& C, const std::vector<float>& S, int INCC) {
    int IX = 0;
    int IC = 0;
    for (int I = 0; I < N; ++I) {
        float XI = X[IX];
        float YI = Y[IX];
        float ZI = Z[IX];
        float CI = C[IC];
        float SI = S[IC];
        float T1 = SI * ZI;
        float T2 = CI * ZI;
        float T3 = T2 - SI * XI;
        float T4 = T2 + SI * YI;
        float T5 = CI * XI + T1;
        float T6 = CI * YI - T1;
        X[IX] = CI * T5 + SI * T4;
        Y[IX] = CI * T6 - SI * T3;
        Z[IX] = CI * T4 - SI * T5;
        IX += INCX;
        IC += INCC;
    }
}

int main() {
    int N = 3;
    int INCX = 1;
    int INCC = 1;
    std::vector<float> X = {1.0, 2.0, 3.0};
    std::vector<float> Y = {4.0, 5.0, 6.0};
    std::vector<float> Z = {7.0, 8.0, 9.0};
    std::vector<float> C = {0.5, 0.5, 0.5};
    std::vector<float> S = {0.5, 0.5, 0.5};

    SLAR2V(N, X, Y, Z, INCX, C, S, INCC);

    std::cout << "X:";
    for (const auto& val : X) std::cout << " " << val;
    std::cout << std::endl;

    std::cout << "Y:";
    for (const auto& val : Y) std::cout << " " << val;
    std::cout << std::endl;

    std::cout << "Z:";
    for (const auto& val : Z) std::cout << " " << val;
    std::cout << std::endl;

    return 0;
}