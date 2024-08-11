#include <iostream>
#include <cstdint> // For int64_t

void phi1_2d_mat(const double x[2], double phi[3], double mat_grad[2][3]) {
    double x0, y0;
    int64_t inode; // Using int64_t as an equivalent to Fortran's integer*8

    x0 = x[0]; // Note the shift from 1-based to 0-based indexing
    y0 = x[1];
    inode = 0; // Changed to 0-based indexing
    phi[inode] = 1 - x0 - y0;
    mat_grad[0][inode] = -1;
    mat_grad[1][inode] = -1;

    inode = 1;
    phi[inode] = x0;
    mat_grad[0][inode] = 1;
    mat_grad[1][inode] = 0;

    inode = 2;
    phi[inode] = y0;
    mat_grad[0][inode] = 0;
    mat_grad[1][inode] = 1;
}

int main() {
    // Example usage
    double x[] = {0.5, 0.25};
    double phi[3];
    double mat_grad[2][3];

    phi1_2d_mat(x, phi, mat_grad);

    // Optionally, print the results to verify
    for (int i = 0; i < 3; ++i) {
        std::cout << "phi[" << i << "] = " << phi[i] << std::endl;
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "mat_grad[" << i << "][" << j << "] = " << mat_grad[i][j] << std::endl;
        }
    }

    return 0;
}