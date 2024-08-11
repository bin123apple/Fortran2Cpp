#include <cmath>
#include <vector>

void DDAWTS(int NEQ, int IWT, const std::vector<double>& RTOL, const std::vector<double>& ATOL, const std::vector<double>& Y, std::vector<double>& WT, const std::vector<double>& RPAR, const std::vector<int>& IPAR) {
    double RTOLI = RTOL[0];
    double ATOLI = ATOL[0];

    for (int I = 0; I < NEQ; ++I) {
        if (IWT != 0) {
            RTOLI = RTOL[I];
            ATOLI = ATOL[I];
        }
        WT[I] = RTOLI * std::abs(Y[I]) + ATOLI;
    }
}