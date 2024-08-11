// intern.cpp
#include <vector>
#include <cmath>
#include <cassert>
#include <iostream>

void intern(int j, const std::vector<std::vector<std::vector<double>>>& c,
            const std::vector<int>& mb, const std::vector<int>& nb,
            std::vector<std::vector<double>>& r,
            std::vector<std::vector<std::vector<std::vector<double>>>>& dr,
            int nbond) {
    for (int i = 0; i < nbond; ++i) {
        double dx = c[j][mb[i]-1][0] - c[j][nb[i]-1][0];
        double dy = c[j][mb[i]-1][1] - c[j][nb[i]-1][1];
        double dz = c[j][mb[i]-1][2] - c[j][nb[i]-1][2];
        r[j][i] = sqrt(dx*dx + dy*dy + dz*dz);
        dr[j][i][mb[i]-1][0] = dx / r[j][i];
        dr[j][i][mb[i]-1][1] = dy / r[j][i];
        dr[j][i][mb[i]-1][2] = dz / r[j][i];
        dr[j][i][nb[i]-1][0] = -dx / r[j][i];
        dr[j][i][nb[i]-1][1] = -dy / r[j][i];
        dr[j][i][nb[i]-1][2] = -dz / r[j][i];
    }
}

int main() {
    const int n = 1;
    const int nbond = 2;
    std::vector<std::vector<std::vector<double>>> c(n, std::vector<std::vector<double>>(4, std::vector<double>(3, 0.0)));
    std::vector<int> mb = {1, 2}; // Adjusted for 1-based indexing in Fortran
    std::vector<int> nb = {3, 4}; // Same here
    std::vector<std::vector<double>> r(n, std::vector<double>(nbond, 0.0));
    std::vector<std::vector<std::vector<std::vector<double>>>> dr(n, std::vector<std::vector<std::vector<double>>>(nbond, std::vector<std::vector<double>>(4, std::vector<double>(3, 0.0))));

    // Initialize matrix c with some values for testing
    c[0][0][0] = 0.0; c[0][1][0] = 1.0; c[0][2][0] = 1.0; c[0][3][0] = 0.0;
    c[0][2][1] = 1.0; c[0][3][1] = 1.0;

    intern(0, c, mb, nb, r, dr, nbond);

    // Assertions for testing the correctness of the intern function
    assert(std::abs(r[0][0] - std::sqrt(2.0)) < 1e-6);
    assert(std::abs(r[0][1] - std::sqrt(2.0)) < 1e-6);

    std::cout << "C++ Test assertions passed." << std::endl;

    return 0;
}