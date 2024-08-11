#include <iostream>
#include <vector>
#include <cassert>

// Global variable declaration
double beta;

// qinit function definition
void qinit(int maxmx, int meqn, int mbc, int mx, double xlower, double dx, std::vector<std::vector<double>>& q, int maux, std::vector<std::vector<double>>& aux) {
    double ql = 0.13;
    double qr = 0.1;

    for (int i = 0; i < mx; ++i) {
        double xcell = xlower + (i + 0.5) * dx; // Adjusted for 0-based indexing
        if (xcell < 0.0) {
            q[i][0] = ql; // Adjusted for 0-based indexing in both dimensions
        } else {
            q[i][0] = qr; // Adjusted for 0-based indexing in both dimensions
        }
    }
}

// Main function containing the unit test code
int main() {
    int maxmx = 10, meqn = 1, mbc = 2, mx = 5, maux = 0;
    double xlower = -0.5, dx = 0.2;
    
    // Initialize q and aux with appropriate sizes
    std::vector<std::vector<double>> q(mx, std::vector<double>(meqn, 0.0));
    std::vector<std::vector<double>> aux; // Assuming aux is not used in this test
    
    // Call the qinit function
    qinit(maxmx, meqn, mbc, mx, xlower, dx, q, maux, aux);

    // Check the results
    for (int i = 0; i < mx; ++i) {
        if (i < 2) {
            assert(q[i][0] == 0.13);
        } else {
            assert(q[i][0] == 0.1);
        }
    }

    std::cout << "C++ test passed." << std::endl;

    return 0;
}