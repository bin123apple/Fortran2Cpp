#include <cmath>
#include <iostream>
#include <array>

// Assuming the existence of a function 'exact' that takes the same parameters as in the Fortran code
void exact(int i, int j, int k, std::array<double, 5>& u000ijk);

// Assuming 'u' is a 4D array that is accessible in a similar way as in the Fortran code
extern std::array<std::array<std::array<std::array<double, 5>, 3>, 3>, 3> u;

// Assuming 'errnm' is a global array of size 5
std::array<double, 5> errnm;

// Assuming 'nx0', 'ny0', 'nz0', 'ist', 'iend', 'jst', 'jend' are defined globally or passed as parameters
extern int nx0, ny0, nz0, ist, iend, jst, jend;

void error() {
    // Initialize errnm to 0
    for (int m = 0; m < 5; ++m) {
        errnm[m] = 0.0;
    }

    // Loop over k, j, i as in the Fortran code
    for (int k = 1; k < nz0 - 1; ++k) {
        for (int j = jst; j <= jend; ++j) {
            for (int i = ist; i <= iend; ++i) {
                std::array<double, 5> u000ijk;
                exact(i, j, k, u000ijk);
                for (int m = 0; m < 5; ++m) {
                    double tmp = (u000ijk[m] - u[m][i][j][k]);
                    errnm[m] += tmp * tmp;
                }
            }
        }
    }

    // Compute RMS-norm of error as in the Fortran code
    for (int m = 0; m < 5; ++m) {
        errnm[m] = std::sqrt(errnm[m] / ((nx0 - 2) * (ny0 - 2) * (nz0 - 2)));
    }

    // Print RMS-norm of error
    std::cout << std::fixed << std::setprecision(5);
    for (int m = 0; m < 5; ++m) {
        std::cout << "RMS-norm of error in soln. to " << m + 1 << " pde = " << errnm[m] << std::endl;
    }
}

int main() {
    // Example usage of the error function
    error();
    return 0;
}
