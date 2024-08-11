#include <iostream>
#include <vector>
#include <cmath>

// Define the ComAux structure within the same file for simplicity
struct ComAux {
    double rho1, amu1, alam1, rho2, amu2, alam2, rho3, amu3, alam3;
};

// Include the qinit function directly in this file
void qinit(int meqn, int mbc, int mx, int my, double xlower, double ylower, double dx, double dy, std::vector<std::vector<std::vector<double>>>& q, int maux, std::vector<std::vector<std::vector<double>>>& aux, ComAux& comaux) {
    double cp2 = sqrt((comaux.alam2 + 2.0 * comaux.amu2) / comaux.rho2);
    
    for (int i = 0; i < mx; ++i) {
        double xi = xlower + (i + 0.5) * dx;
        for (int j = 0; j < my; ++j) {
            double yj = ylower + (j + 0.5) * dy;
            // Adjusting indices for 0-based indexing
            q[0][i + mbc][j + mbc] = 0.0;
            q[1][i + mbc][j + mbc] = 0.0;
            q[2][i + mbc][j + mbc] = 0.0;
            q[3][i + mbc][j + mbc] = 0.0;
            q[4][i + mbc][j + mbc] = 0.0;
        }
    }
}

// Main program for testing
int main() {
    int meqn = 5, mbc = 2, mx = 3, my = 3, maux = 0;
    double xlower = 0.0, ylower = 0.0, dx = 1.0, dy = 1.0;
    ComAux comaux; // Initialize the common variables if needed

    // Initialize q and aux with the correct dimensions
    std::vector<std::vector<std::vector<double>>> q(meqn, std::vector<std::vector<double>>(mx + 2*mbc, std::vector<double>(my + 2*mbc, 0)));
    std::vector<std::vector<std::vector<double>>> aux(maux); // Assuming aux is not used in this test

    // Call the function
    qinit(meqn, mbc, mx, my, xlower, ylower, dx, dy, q, maux, aux, comaux);

    // Print results for comparison
    std::cout << "q values:" << std::endl;
    for (int i = 0; i < mx; ++i) {
        for (int j = 0; j < my; ++j) {
            std::cout << "(" << i + 1 << "," << j + 1 << "):"; // +1 to match Fortran's 1-based indexing in the output
            for (int k = 0; k < meqn; ++k) {
                std::cout << " " << q[k][i + mbc][j + mbc];
            }
            std::cout << std::endl;
        }
    }

    return 0;
}