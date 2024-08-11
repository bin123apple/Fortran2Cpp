#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void MDIAN2(std::vector<double>& X, int N, double& XMED) {
    const double BIG = 1.E30;
    const double AFAC = 1.5;
    const double AMP = 1.5;
    double A = 0.5 * (X[0] + X[N - 1]);
    double EPS = std::abs(X[N - 1] - X[0]);
    double AP = BIG;
    double AM = -BIG;

    while (true) {
        double SUM = 0.0;
        double SUMX = 0.0;
        int NP = 0;
        int NM = 0;
        double XP = BIG;
        double XM = -BIG;
        for (int J = 0; J < N; ++J) {
            double XX = X[J];
            if (XX != A) {
                if (XX > A) {
                    NP++;
                    if (XX < XP) XP = XX;
                } else if (XX < A) {
                    NM++;
                    if (XX > XM) XM = XX;
                }
                double DUM = 1.0 / (EPS + std::abs(XX - A));
                SUM += DUM;
                SUMX += XX * DUM;
            }
        }

        if (NP - NM >= 2) {
            AM = A;
            double AA = XP + std::max(0.0, SUMX / SUM - A) * AMP;
            if (AA > AP) AA = 0.5 * (A + AP);
            EPS = AFAC * std::abs(AA - A);
            A = AA;
        } else if (NM - NP >= 2) {
            AP = A;
            double AA = XM + std::min(0.0, SUMX / SUM - A) * AMP;
            if (AA < AM) AA = 0.5 * (A + AM);
            EPS = AFAC * std::abs(AA - A);
            A = AA;
        } else {
            if (N % 2 == 0) {
                if (NP == NM) {
                    XMED = 0.5 * (XP + XM);
                } else if (NP > NM) {
                    XMED = 0.5 * (A + XP);
                } else {
                    XMED = 0.5 * (XM + A);
                }
            } else {
                if (NP == NM) {
                    XMED = A;
                } else if (NP > NM) {
                    XMED = XP;
                } else {
                    XMED = XM;
                }
            }
            break; // Exit the while loop after setting XMED
        }
    }
}

int main() {
    std::vector<double> X = {1.0, 3.0, 2.0, 5.0, 4.0};
    int N = X.size();
    double XMED;

    MDIAN2(X, N, XMED);
    std::cout << "Median is: " << XMED << std::endl;

    return 0;
}