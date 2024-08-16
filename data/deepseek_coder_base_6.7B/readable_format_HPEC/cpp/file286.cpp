Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>

// Assuming the use of a 4D array for u, and phi1 and phi2 are 2D arrays
// The dimensions of these arrays are not specified in the Fortran code, so we'll assume some reasonable sizes
// For demonstration, let's assume dimensions are:
// u: 6 x ii2 x ji2 x ki2
// phi1: ii2 x ji2
// phi2: ii2 x ji2

// Function prototypes
void pintgr(int ii1, int ii2, int ji1, int ji2, int ki1, int ki2, double c2, double dxi, double deta, double dzeta,
            std::vector<std::vector<std::vector<std::vector<double>>>>& u,
            std::vector<std::vector<double>>& phi1,
            std::vector<std::vector<double>>& phi2,
            double& frc);

int main() {
    // Example usage
    int ii1 = 1, ii2 = 10, ji1 = 1, ji2 = 10, ki1 = 1, ki2 = 2;
    double c2 = 1.0, dxi = 0.1, deta = 0.1, dzeta = 0.1;

    // Assuming dimensions for u, phi1, phi2
    std::vector<std::vector<std::vector<std::vector<double>>>> u(6, std::vector<std::vector<std::vector<double>>>(ii2, std::vector<std::vector<double>>(ji2, std::vector<double>(ki2, 0.0))));
    std::vector<std::vector<double>> phi1(ii2, std::vector<double>(ji2, 0.0));
    std::vector<std::vector<double>> phi2(ii2, std::vector<double>(ji2, 0.0));
    double frc = 0.0;

    // Call the subroutine
    pintgr(ii1, ii2, ji1, ji2, ki1, ki2, c2, dxi, deta, dzeta, u, phi1, phi2, frc);

    // Output results
    std::cout << "frc: " << frc << std::endl;

    return 0;
}

void pintgr(int ii1, int ii2, int ji1, int ji2, int ki1, int ki2, double c2, double dxi, double deta, double dzeta,
            std::vector<std::vector<std::vector<std::vector<double>>>>& u,
            std::vector<std::vector<double>>& phi1,
            std::vector<std::vector<double>>& phi2,
            double& frc) {
    int ibeg, ifin, ifin1;
    int jbeg, jfin, jfin1;
    double frc1, frc2, frc3;

    ibeg = ii1;
    ifin = ii2;
    jbeg = ji1;
    jfin = ji2;
    ifin1 = ifin - 1;
    jfin1 = jfin - 1;

    for (int j = jbeg; j <= jfin; ++j) {
        for (int i = ibeg; i <= ifin; ++i) {
            int k = ki1;
            phi1[i-1][j-1] = c2 * (u[4][i-1][j-1][k-1] - 0.5 * (u[1][i-1][j-1][k-1] * u[1][i-1][j-1][k-1] +
                                                            u[2][i-1][j-1][k-1] * u[2][i-1][j-1][k-1] +
                                                            u[3][i-1][j-1][k-1] * u[3][i-1][j-1][k-1])) / u[0][i-1][j-1][k-1];

            k = ki2;
            phi2[i-1][j-1] = c2 * (u[4][i-1][j-1][k-1] - 0.5 * (u[1][i-1][j-1][k-1] * u[1][i-1][j-1][k-1] +
                                                            u[2][i-1][j-1][k-1] * u[2][i-1][j-1][k-1] +
                                                            u[3][i-1][j-1][k-1] * u[3][i-1][j-1][k-1])) / u[0][i-1][j-1][k-1];
        }
    }

    frc1 = 0.0;
    for (int j = jbeg; j <= jfin1; ++j) {
        for (int i = ibeg; i <= ifin1; ++i) {
            frc1 += (phi1[i-1][j-1] + phi1[i][j-1] + phi1[i-1][j] + phi1[i][j] +
                     phi2[i-1][j-1] + phi2[i][j-1] + phi2[i-1][j] + phi2[i][j]);
        }
    }
    frc1 *= dxi * deta;

    for (int k = ki1; k <= ki2; ++k) {
        for (int i = ibeg; i <= ifin; ++i) {
            phi1[i-1][k-1] = c2 * (u[4][i-1][jbeg-1][k-1] - 0.5 * (u[1][i-1][jbeg-1][k-1] * u[1][i-1][jbeg-1][k-1] +
                                                                u[2][i-1][jbeg-1][k-1] * u[2][i-1][jbeg-1][k-1] +
                                                                u[3][i-1][jbeg-1][k-1] * u[3][i-1][jbeg-1][k-1])) / u[0][i-1][jbeg-1][k-1];
        }
    }

    for (int k = ki1; k <= ki2; ++k) {
        for (int i = ibeg; i <= ifin; ++i) {
            phi2[i-1][k-1] = c2 * (u[4][i-1][jfin-1][k-1] - 0.5 * (u[1][i-1][jfin-1][k-1] * u[1][i-1][jfin-1][k-1] +
                                                                u[2][i-1][jfin-1][k-1] * u[2][i-1][jfin-1][k-1] +
                                                                u[3][i-1][jfin-1][k-1] * u[3][i-1][jfin-1][k-1])) / u[0][i-1][jfin-1][k-1];
        }
    }

    frc2 = 0.0;
    for (int k = ki1; k <= ki2-1; ++k) {
        for (int i = ibeg; i <= ifin1; ++i) {
            frc2 += (phi1[i-1][k-1] + phi1[i][k-1] + phi1[i-1][k] + phi1[i][k] +
                     phi2[i-1][k-1] + phi2[i][k-1] + phi2[i-1][k] + phi2[i][k]);
        }
    }
    frc2 *= dxi * dzeta;

    for (int k = ki1; k <= ki2; ++k) {
        for (int j = jbeg; j <= jfin; ++j) {
            phi1[j-1][k-1] = c
