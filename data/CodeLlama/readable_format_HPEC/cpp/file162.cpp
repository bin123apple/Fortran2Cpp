#include <cmath>
#include <iostream>

// Assuming the existence of a function 'exact' that matches the Fortran subroutine's signature.
void exact(int i, int j, int k, double u000ijk[5]);

void error() {
    int i, j, k, m;
    double tmp;
    double u000ijk[5];

    // Initialize errnm to 0.0
    for (m = 0; m < 5; ++m) {
        errnm[m] = 0.0;
    }

    // Loop over k, j, i as in the Fortran code
    for (k = 1; k < nz - 1; ++k) { // Adjusted for 0-based indexing
        for (j = jst; j <= jend; ++j) { // Adjusted for 0-based indexing
            for (i = ist; i <= iend; ++i) { // Adjusted for 0-based indexing
                exact(i, j, k, u000ijk);
                for (m = 0; m < 5; ++m) {
                    tmp = (u000ijk[m] - u[m][i][j][k]); // Adjusted array access for 0-based indexing
                    errnm[m] += tmp * tmp;
                }
            }
        }
    }

    // Calculate the RMS norm
    for (m = 0; m < 5; ++m) {
        errnm[m] = sqrt(errnm[m] / (double(nx0 - 2) * (ny0 - 2) * (nz0 - 2)));
    }

    // Print the RMS norms
    std::cout << "RMS-norm of error in soln. to first pde = " << errnm[0] << std::endl;
    std::cout << "RMS-norm of error in soln. to second pde = " << errnm[1] << std::endl;
    std::cout << "RMS-norm of error in soln. to third pde = " << errnm[2] << std::endl;
    std::cout << "RMS-norm of error in soln. to fourth pde = " << errnm[3] << std::endl;
    std::cout << "RMS-norm of error in soln. to fifth pde = " << errnm[4] << std::endl;
}

// The 'exact' function needs to be defined according to the Fortran subroutine's logic.
