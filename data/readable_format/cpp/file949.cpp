#include <iostream>
#include <vector>

// Function declaration is now optional since we're defining the function in the same file
// before its first use.
void dmzsol(int kd, int mstar, int n, std::vector<std::vector<double>>& v, std::vector<double>& z, std::vector<std::vector<double>>& dmz);

int main() {
    int kd = 2;
    int mstar = 2;
    int n = 2;
    std::vector<std::vector<double>> v = {{1.0, 3.0}, {2.0, 4.0}}; // Corresponding to the Fortran V initialization
    std::vector<double> z = {2.0, 3.0}; // Corresponding to the Fortran Z initialization
    std::vector<std::vector<double>> dmz(kd, std::vector<double>(n, 0.0)); // Initialized to zeros, similar to the Fortran DMZ initialization

    // Call the function
    dmzsol(kd, mstar, n, v, z, dmz);

    // Output the results
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < kd; ++j) {
            std::cout << "DMZ(" << j << "," << i << ") = " << dmz[j][i] << std::endl;
        }
    }

    return 0;
}

// Function definition
void dmzsol(int kd, int mstar, int n, std::vector<std::vector<double>>& v, std::vector<double>& z, std::vector<std::vector<double>>& dmz) {
    int jz = 0; // Adjusted for 0-indexing
    for (int i = 0; i < n; ++i) { // Adjusted loop indices for 0-indexing
        for (int j = 0; j < mstar; ++j) {
            double fact = z[jz];
            for (int l = 0; l < kd; ++l) {
                dmz[l][i] += fact * v[l][jz];
            }
            jz++;
        }
    }
}