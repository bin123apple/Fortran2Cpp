#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

// Declaration of the radresult function
void radresult(int ntr, std::vector<std::vector<double>>& xloadact,
               std::vector<double>& bcr, std::vector<int>& nloadtr,
               std::vector<double>& tarea, std::vector<double>& tenv,
               std::vector<double>& physcon, std::vector<double>& erad,
               std::vector<double>& auview, std::vector<double>& fenv,
               std::vector<int>& irowrad, std::vector<int>& jqrad,
               int nzsrad, std::vector<double>& q) {
    for (int i = 0; i < ntr; ++i) {
        q[i] = bcr[i];
    }

    for (int i = 0; i < ntr; ++i) {
        for (int j = jqrad[i] - 1; j < jqrad[i + 1] - 1; ++j) { // Adjusted for 0-based indexing
            int k = irowrad[j] - 1; // Adjusted for 0-based indexing
            q[k] -= auview[j] * bcr[i];
            q[i] -= auview[nzsrad + j] * bcr[k];
        }
    }

    for (int i = 0; i < ntr; ++i) {
        int j = nloadtr[i] - 1; // Adjusted for 0-based indexing
        q[i] -= fenv[i] * physcon[1] * std::pow(tenv[i], 4);
        xloadact[1][j] = std::max(std::pow(tarea[i], 4) - q[i] / (erad[i] * physcon[1]), 0.0);
        xloadact[1][j] = std::pow(xloadact[1][j], 0.25) + physcon[0];
    }
}

int main() {
    const int ntr = 3;
    std::vector<std::vector<double>> xloadact(2, std::vector<double>(ntr));
    std::vector<double> bcr = {1, 2, 3};
    std::vector<int> nloadtr = {1, 2, 3};
    std::vector<double> tarea = {1.0, 1.0, 1.0};
    std::vector<double> tenv = {300.0, 300.0, 300.0};
    std::vector<double> physcon = {273.15, 5.67E-8};
    std::vector<double> erad = {5.67E-8, 5.67E-8, 5.67E-8};
    std::vector<double> auview = {0.1, 0.2, 0.3, 0.2, 0.4, 0.6};
    std::vector<double> fenv = {0.5, 0.5, 0.5};
    std::vector<int> irowrad = {1, 2, 3, 1, 2, 3};
    std::vector<int> jqrad = {1, 2, 3, 4};
    int nzsrad = ntr;
    std::vector<double> q(ntr);

    radresult(ntr, xloadact, bcr, nloadtr, tarea, tenv, physcon, erad, auview, fenv, irowrad, jqrad, nzsrad, q);

    // Print results for verification
    for (int i = 0; i < ntr; ++i) {
        std::cout << "q(" << i << ") = " << q[i] << std::endl;
        std::cout << "xloadact(2," << i << ") = " << std::setprecision(6) << xloadact[1][i] << std::endl;
    }

    return 0;
}