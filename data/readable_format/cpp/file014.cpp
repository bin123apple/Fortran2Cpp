#include <iostream>
#include <vector>
#include <cmath>

void LAGZO(int N, std::vector<double>& X, std::vector<double>& W) {
    double HN = 1.0 / N;
    int IT, NR;
    double Z, Z0, P, F0, F1, PF, PD, FD, Q, WP, GD;

    for (NR = 1; NR <= N; ++NR) {
        if (NR == 1) Z = HN;
        if (NR > 1) Z = X[NR - 2] + HN * pow(NR, 1.27);

        IT = 0;

        do {
            ++IT;
            Z0 = Z;
            P = 1.0;

            for (int I = 1; I <= NR - 1; ++I) {
                P = P * (Z - X[I - 1]);
            }

            F0 = 1.0;
            F1 = 1.0 - Z;

            for (int K = 2; K <= N; ++K) {
                PF = ((2.0 * K - 1.0 - Z) * F1 - (K - 1.0) * F0) / K;
                PD = K / Z * (PF - F1);
                F0 = F1;
                F1 = PF;
            }

            FD = PF / P;
            Q = 0.0;

            for (int I = 1; I <= NR - 1; ++I) {
                WP = 1.0;

                for (int J = 1; J <= NR - 1; ++J) {
                    if (J != I) {
                        WP = WP * (Z - X[J - 1]);
                    }
                }

                Q += WP;
            }

            GD = (PD - Q * FD) / P;
            Z = Z - FD / GD;

        } while (IT <= 40 && std::abs((Z - Z0) / Z) > 1.0e-15);

        X[NR - 1] = Z;
        W[NR - 1] = 1.0 / (Z * PD * PD);
    }
}

int main() {
    const int N = 5;
    std::vector<double> X(N), W(N);

    LAGZO(N, X, W);

    std::cout << "X:" << std::endl;
    for (const auto& x : X) {
        std::cout << x << std::endl;
    }

    std::cout << "W:" << std::endl;
    for (const auto& w : W) {
        std::cout << w << std::endl;
    }

    return 0;
}