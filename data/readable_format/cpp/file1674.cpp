// rffti1.cpp
#include <iostream>
#include <vector>
#include <cmath>

void RFFTI1(int N, std::vector<float>& WA, std::vector<float>& FAC) {
    const int NTRYH[4] = {4, 2, 3, 5};
    int NL = N, NF = 0, J = 0, NTRY = 0, NQ, NR;

    while (true) {
        J++;
        if (J <= 4) {
            NTRY = NTRYH[J-1];
        } else {
            NTRY += 2;
        }

        NQ = NL / NTRY;
        NR = NL - NTRY * NQ;

        if (NR != 0) continue;

        NF++;
        FAC[NF+1] = static_cast<float>(NTRY);
        NL = NQ;

        if (NL == 1) break;
    }

    FAC[0] = static_cast<float>(N);
    FAC[1] = static_cast<float>(NF);
}

int main() {
    const int N = 5;
    std::vector<float> WA(N, 0.0f), FAC(15, 0.0f);

    RFFTI1(N, WA, FAC);

    std::cout << "WA:" << std::endl;
    for (const auto& val : WA) {
        std::cout << val << std::endl;
    }

    std::cout << "FAC:" << std::endl;
    for (const auto& val : FAC) {
        std::cout << val << std::endl;
    }

    return 0;
}