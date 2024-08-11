#include <iostream>
#include <vector>
#include <iomanip>

// Function declaration
void calcrhoelcomp(
    int nef,
    std::vector<std::vector<double>>& vel,
    const std::vector<std::vector<std::vector<double>>>& shcon,
    const std::vector<std::vector<int>>& ielmatf,
    int ntmat_,
    const std::vector<int>& mi,
    int nefa,
    int nefb) 
{
    for (int i = nefa - 1; i < nefb; ++i) {
        double t1l = vel[i][0];
        int imat = ielmatf[0][i] - 1; // Correction for 0-based indexing in C++
        vel[i][5] = vel[i][4] / (shcon[3][0][imat] * t1l); // Corrected indices
    }
}

int main() {
    const int nef = 5, ntmat_ = 2;
    std::vector<int> mi = {nef, 0, 1};
    std::vector<std::vector<double>> vel(nef, std::vector<double>(8, 0.0));
    std::vector<std::vector<std::vector<double>>> shcon(4, std::vector<std::vector<double>>(ntmat_, std::vector<double>(1, 0.0)));
    std::vector<std::vector<int>> ielmatf(1, std::vector<int>(nef, 1)); // Correct initialization for 1-based index
    
    // Initialize test data
    for(int i = 0; i < nef; ++i) {
        vel[i][0] = static_cast<double>(i + 1);
        vel[i][4] = static_cast<double>((i + 1) * 10);
    }
    shcon[3][0][0] = 2.0; // Corrected for 0-based indexing

    int nefa = 1, nefb = nef;
    // Call the function
    calcrhoelcomp(nef, vel, shcon, ielmatf, ntmat_, mi, nefa, nefb);

    // Output result for verification
    std::cout << "vel[:,5] after calcrhoelcomp:" << std::endl;
    for (int i = 0; i < nef; ++i) {
        std::cout << std::fixed << std::setprecision(2) << vel[i][5] << std::endl;
    }

    return 0;
}