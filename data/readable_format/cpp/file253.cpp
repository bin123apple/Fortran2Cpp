#include <iostream>
#include <complex>
#include <algorithm>

double cabs1(std::complex<double> z) {
    return std::abs(real(z)) + std::abs(imag(z));
}

double zla_gbrpvgrw(int n, int kl, int ku, int ncols, std::complex<double>** ab, int ldab, std::complex<double>** afb, int ldafb) {
    int i, j, kd;
    double amax, umax, rpvgrw = 1.0;

    kd = ku + 1;
    for (j = 0; j < ncols; ++j) { // Adjusted for 0-based indexing
        amax = 0.0;
        umax = 0.0;
        for (i = std::max(j - ku, 0); i < std::min(j + kl, n); ++i) { // Adjusted for 0-based indexing
            amax = std::max(cabs1(ab[kd + i - j][j]), amax);
        }
        for (i = std::max(j - ku, 0); i <= j; ++i) { // Adjusted for 0-based indexing
            umax = std::max(cabs1(afb[kd + i - j][j]), umax);
        }
        if (umax != 0.0) {
            rpvgrw = std::min(amax / umax, rpvgrw);
        }
    }
    return rpvgrw;
}

std::complex<double>** allocateMatrix(int rows, int cols) {
    std::complex<double>** matrix = new std::complex<double>*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new std::complex<double>[cols];
    }
    return matrix;
}

void deallocateMatrix(std::complex<double>** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int n = 4;
    int kl = 1;
    int ku = 1;
    int ncols = 4;
    int ldab = 3;
    int ldafb = 3;

    // Allocate and initialize AB and AFB
    auto AB = allocateMatrix(ldab, ncols);
    auto AFB = allocateMatrix(ldafb, ncols);

    for (int i = 0; i < ldab; ++i) {
        for (int j = 0; j < ncols; ++j) {
            AB[i][j] = std::complex<double>(1.0, 0.0); // Example values
        }
    }

    for (int i = 0; i < ldafb; ++i) {
        for (int j = 0; j < ncols; ++j) {
            AFB[i][j] = std::complex<double>(1.0, 0.0); // Example values
        }
    }

    // Call the function
    double result = zla_gbrpvgrw(n, kl, ku, ncols, AB, ldab, AFB, ldafb);

    std::cout << "Result: " << result << std::endl;

    // Cleanup
    deallocateMatrix(AB, ldab);
    deallocateMatrix(AFB, ldafb);

    return 0;
}