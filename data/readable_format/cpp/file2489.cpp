#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void H12(int MDE, int LPIVOT, int L1, int M, std::vector<std::vector<double>>& U, int IUE, double& UP, std::vector<double>& C, int ICE, int ICV, int NCV) {
    const double ONE = 1.0;
    if (0 >= LPIVOT || LPIVOT >= L1 || L1 > M) return;

    double CL = std::abs(U[0][LPIVOT - 1]);
    if (MDE == 2) {
        // The original logic for MDE == 2 was to skip to processing that is done after calculating CL.
        // Since there's no additional logic for this case in the provided code snippet, it simply continues to the next block.
    }

    for (int J = L1 - 1; J < M; ++J) {
        CL = std::max(std::abs(U[0][J]), CL);
    }

    if (CL == 0) return;

    double CLINV = ONE / CL;
    double SM = std::pow(U[0][LPIVOT - 1] * CLINV, 2);
    for (int J = L1 - 1; J < M; ++J) {
        SM += std::pow(U[0][J] * CLINV, 2);
    }
    double SM1 = SM;
    CL *= std::sqrt(SM1);
    if (U[0][LPIVOT - 1] > 0) CL = -CL;

    UP = U[0][LPIVOT - 1] - CL;
    U[0][LPIVOT - 1] = CL;

    if (NCV <= 0) return;

    double B = UP * U[0][LPIVOT - 1];
    if (B == 0) return;

    B = ONE / B;
    int I2 = 1 - ICV + ICE * (LPIVOT - 1);
    int INCR = ICE * (L1 - LPIVOT);

    for (int J = 1; J <= NCV; ++J) {
        I2 += ICV;
        int I3 = I2 + INCR;
        int I4 = I3;
        double SM = C[I2 - 1] * UP; // Adjusted index for C++ 0-based indexing
        for (int I = L1 - 1; I < M; ++I) {
            SM += C[I3 - 1] * U[0][I]; // Adjusted index for C++ 0-based indexing
            I3 += ICE;
        }
        if (SM != 0) {
            SM *= B;
            C[I2 - 1] += SM * UP; // Adjusted index for C++ 0-based indexing
            for (int I = L1 - 1; I < M; ++I) {
                C[I4 - 1] += SM * U[0][I]; // Adjusted index for C++ 0-based indexing
                I4 += ICE;
            }
        }
    }
}

int main() {
    int MDE = 1;
    int LPIVOT = 1;
    int L1 = 2;
    int M = 3;
    std::vector<std::vector<double>> U = {{0.0, 1.0, 2.0, 3.0}};
    int IUE = 1;
    double UP;
    std::vector<double> C = {0.0, 1.0, 2.0, 3.0};
    int ICE = 1;
    int ICV = 1;
    int NCV = 1;

    H12(MDE, LPIVOT, L1, M, U, IUE, UP, C, ICE, ICV, NCV);

    std::cout << "UP: " << UP << std::endl;
    std::cout << "C: ";
    for (auto val : C) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}