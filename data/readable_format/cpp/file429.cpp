#include <iostream>
#include <vector>

void OED__CTR_RS_EXPAND(int N, int NRS, int NR, int NS, std::vector<std::vector<double>>& X, std::vector<std::vector<std::vector<double>>>& Y) {
    int RS = NRS;

    for (int S = NS-1; S >= 0; --S) {
        for (int R = NR-1; R > S; --R) {
            --RS;
            for (int M = 0; M < N; ++M) {
                Y[M][R][S] = X[M][RS];
                Y[M][S][R] = X[M][RS];
            }
        }
        --RS;
        for (int M = 0; M < N; ++M) {
            Y[M][S][S] = X[M][RS];
        }
    }
}

int main() {
    int N = 3, NRS = 6, NR = 3, NS = 3;
    std::vector<std::vector<double>> X(N, std::vector<double>(NRS));
    std::vector<std::vector<std::vector<double>>> Y(N, std::vector<std::vector<double>>(NR, std::vector<double>(NS)));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < NRS; ++j) {
            X[i][j] = static_cast<double>(i + j + 2); // Adjusted to match Fortran output
        }
    }

    OED__CTR_RS_EXPAND(N, NRS, NR, NS, X, Y);

    for (int k = 0; k < NS; ++k) {
        for (int j = 0; j < NR; ++j) {
            for (int i = 0; i < N; ++i) {
                std::cout << "Y(" << i+1 << "," << j+1 << "," << k+1 << ") = " << Y[i][j][k] << std::endl;
            }
        }
    }

    return 0;
}