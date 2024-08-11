#include <iostream>
#include <vector>

void COMBAK(int NM, int LOW, int IGH, std::vector<std::vector<float>>& AR, std::vector<std::vector<float>>& AI, std::vector<int>& INT, int M, std::vector<std::vector<float>>& ZR, std::vector<std::vector<float>>& ZI) {
    int I, J, LA, MM, MP, KP1, MP1;
    float XR, XI;

    if (M == 0) {
        return;
    }

    LA = IGH - 1;
    KP1 = LOW + 1;
    if (LA < KP1) {
        return;
    }

    for (MM = KP1; MM <= LA; ++MM) {
        MP = LOW + IGH - MM;
        MP1 = MP + 1;
        for (I = MP1; I <= IGH; ++I) {
            XR = AR[I-1][MP-1];
            XI = AI[I-1][MP-1];
            if (XR == 0.0f && XI == 0.0f) {
                continue;
            }
            for (J = 1; J <= M; ++J) {
                ZR[I-1][J-1] = ZR[I-1][J-1] + XR * ZR[MP-1][J-1] - XI * ZI[MP-1][J-1];
                ZI[I-1][J-1] = ZI[I-1][J-1] + XR * ZI[MP-1][J-1] + XI * ZR[MP-1][J-1];
            }
        }
        I = INT[MP-1];
        if (I == MP) {
            continue;
        }
        for (J = 1; J <= M; ++J) {
            XR = ZR[I-1][J-1];
            ZR[I-1][J-1] = ZR[MP-1][J-1];
            ZR[MP-1][J-1] = XR;
            XI = ZI[I-1][J-1];
            ZI[I-1][J-1] = ZI[MP-1][J-1];
            ZI[MP-1][J-1] = XI;
        }
    }
}

void printMatrix(const std::vector<std::vector<float>>& mat) {
    for (const auto& row : mat) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int NM = 5, M = 2, LOW = 1, IGH = 5;
    std::vector<std::vector<float>> AR(NM, std::vector<float>(NM, 1.0f)); // Initialize to test values
    std::vector<std::vector<float>> AI(NM, std::vector<float>(NM, 1.0f)); // Initialize to test values
    std::vector<std::vector<float>> ZR(NM, std::vector<float>(M, 1.0f));  // Initialize to test values
    std::vector<std::vector<float>> ZI(NM, std::vector<float>(M, 1.0f));  // Initialize to test values
    std::vector<int> INT = {1, 2, 3, 4, 5}; // Example values

    COMBAK(NM, LOW, IGH, AR, AI, INT, M, ZR, ZI);

    std::cout << "ZR:" << std::endl;
    printMatrix(ZR);

    std::cout << "ZI:" << std::endl;
    printMatrix(ZI);

    return 0;
}