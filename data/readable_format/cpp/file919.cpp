// CSGETNP.cpp
#include <iostream>
#include <vector>
#include <limits>

void CSGETNP(const std::vector<double>& X, const std::vector<double>& Y, const std::vector<double>& Z,
             const std::vector<int>& LIST, const std::vector<int>& LPTR, const std::vector<int>& LEND,
             std::vector<int>& NPTS, int L, double& DF, int& IER) {
    int LM1 = L - 1;
    if (LM1 < 1) {
        IER = 1;
        return;
    }
    IER = 0;
    DF = std::numeric_limits<double>::max();
    int NP = -1;
    int N1 = NPTS[0] - 1;
    double X1 = X[N1], Y1 = Y[N1], Z1 = Z[N1];

    for (int i = 0; i < LM1; ++i) {
        int NI = NPTS[i] - 1;
        for (int j = 0; j < L; ++j) {
            int NB = LIST[j] - 1;
            if (NB == NI) continue;
            double DNB = -(X[NB] * X1 + Y[NB] * Y1 + Z[NB] * Z1);
            if (DNB < DF) {
                DF = DNB;
                NP = NB;
            }
        }
    }

    if (NP != -1) {
        NPTS[L - 1] = NP + 1;
    } else {
        IER = 2;
    }
}

int main() {
    std::vector<double> X = {0.0, 1.0, 2.0, 3.0, 4.0};
    std::vector<double> Y = {0.0, 1.0, 0.0, 1.0, 0.0};
    std::vector<double> Z = {0.0, 0.0, 1.0, 1.0, 2.0};
    std::vector<int> LIST = {1, 2, 3, 4, 5};
    std::vector<int> LPTR = {1, 2, 3, 4, 5};
    std::vector<int> LEND = {1, 1, 1, 1, 1};
    std::vector<int> NPTS = {1, 2, 3, 4, 5};
    int L = NPTS.size();
    double DF;
    int IER;

    CSGETNP(X, Y, Z, LIST, LPTR, LEND, NPTS, L, DF, IER);

    if (IER == 0) {
        std::cout << "Success: DF = " << DF << std::endl;
        std::cout << "NPTS = ";
        for (const auto& npt : NPTS) {
            std::cout << npt << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "An error occurred: IER = " << IER << std::endl;
    }

    return 0;
}