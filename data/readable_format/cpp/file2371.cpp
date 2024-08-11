#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint> // For int16_t

void BININT(const std::vector<std::vector<int16_t>>& IA, int NPIX, int NLINES, int INVAL, int IDX, int IDY,
            std::vector<double>& X, std::vector<double>& Y, std::vector<double>& Z, std::vector<double>& W, int& NBIN) {
    NBIN = 0;
    for (int JMIN = 1; JMIN <= NLINES; JMIN += IDY) { // Adjust loop to start from 1
        int JMAX = std::min(JMIN + IDY - 1, NLINES);
        for (int IMIN = 1; IMIN <= NPIX; IMIN += IDX) { // Adjust loop to start from 1
            int IMAX = std::min(IMIN + IDX - 1, NPIX);
            double SUM = 0.0;
            int NPT = 0;
            int IX = 0;
            int IY = 0;
            for (int J = JMIN; J <= JMAX; ++J) {
                for (int I = IMIN; I <= IMAX; ++I) {
                    if (IA[I-1][J-1] != INVAL) { // Adjust for zero-based indexing
                        SUM += IA[I-1][J-1];
                        NPT += 1;
                        IX += I;
                        IY += J;
                    }
                }
            }
            if (NPT >= 1) {
                NBIN += 1;
                X.push_back(static_cast<double>(IX) / NPT);
                Y.push_back(static_cast<double>(IY) / NPT);
                Z.push_back(SUM / NPT);
                W.push_back(std::sqrt(static_cast<double>(NPT)));
            }
        }
    }
}

int main() {
    int NPIX = 10;
    int NLINES = 10;
    int INVAL = 0; // Adjust INVAL to match Fortran code
    int IDX = 2;
    int IDY = 2;

    std::vector<std::vector<int16_t>> IA(NPIX, std::vector<int16_t>(NLINES, 0));

    // Initialize IA with some data
    for (int i = 0; i < NPIX; ++i) {
        for (int j = 0; j < NLINES; ++j) {
            IA[i][j] = i + j + 2; // Adjust for the one-based indexing comparison
        }
    }

    std::vector<double> X, Y, Z, W;
    int NBIN = 0;

    BININT(IA, NPIX, NLINES, INVAL, IDX, IDY, X, Y, Z, W, NBIN);

    std::cout << "NBIN = " << NBIN << std::endl;
    for (int i = 0; i < NBIN; ++i) {
        std::cout << "X[" << i << "] = " << X[i] << ", Y[" << i << "] = " << Y[i] << ", Z[" << i << "] = " << Z[i] << ", W[" << i << "] = " << W[i] << std::endl;
    }

    return 0;
}