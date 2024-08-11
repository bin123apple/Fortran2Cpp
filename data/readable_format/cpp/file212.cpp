// covsrt.cpp
#include <iostream>
#include <vector>
#include <iomanip>

void covsrt(std::vector<std::vector<double>>& covar, int ncvm, int ma, const std::vector<int>& lista, int mfit) {
    for (int j = 0; j < ma; ++j) {
        for (int i = 0; i < ma; ++i) {
            if (i == j) {
                covar[i][j] = 1.0;
            } else {
                covar[i][j] = 0.0;
            }
        }
    }
}

int main() {
    const int MA = 3, MFIT = 2, NCVM = 3;
    std::vector<std::vector<double>> COVAR(MA, std::vector<double>(NCVM, 0));
    std::vector<int> LISTA = {0, 2}; // Adjusted for 0-based indexing

    covsrt(COVAR, NCVM, MA, LISTA, MFIT);

    std::cout << "Modified COVAR:" << std::endl;
    for (const auto& row : COVAR) {
        for (const auto& elem : row) {
            std::cout << std::fixed << std::setprecision(3) << std::setw(8) << elem;
        }
        std::cout << std::endl;
    }

    return 0;
}