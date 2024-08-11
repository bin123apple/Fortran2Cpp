#include <iostream>
#include <cassert>

void extUray(double** U, double* Uray, int nd, int np, int iray) {
    iray -= 1; // Adjusting to 0-based indexing

    for (int L = 0; L < nd; ++L) {
        Uray[L] = U[L][iray];
    }
}

int main() {
    int nd = 4, np = 3;
    int iray = 2; // 1-based index for consistency with Fortran version

    // Dynamic allocation and initialization of U
    double** U = new double*[nd];
    for (int i = 0; i < nd; ++i) {
        U[i] = new double[np];
        for (int j = 0; j < np; ++j) {
            U[i][j] = i * np + j + 1; // Matches Fortran initialization
        }
    }

    // Allocate Uray
    double* Uray = new double[nd];

    // Call the function
    extUray(U, Uray, nd, np, iray);

    // Display results
    std::cout << "Extracted column (iray=" << iray << "):" << std::endl;
    for (int i = 0; i < nd; ++i) {
        std::cout << Uray[i] << " ";
    }
    std::cout << std::endl;

    // Cleanup
    for (int i = 0; i < nd; ++i) {
        delete[] U[i];
    }
    delete[] U;
    delete[] Uray;

    return 0;
}