#include "mg_data.h"
#include <iostream>
#include <iomanip>

// Assuming norm2u3 is a function defined elsewhere in your code
extern void norm2u3(const double* u, int n1, int n2, int n3, double& rnm2, double& rnmu, int nx, int ny, int nz);

void rep_nrm(const double* u, int n1, int n2, int n3, const std::string& title, int kk) {
    double rnm2, rnmu;

    norm2u3(u, n1, n2, n3, rnm2, rnmu, nx[kk], ny[kk], nz[kk]);

    std::cout << " Level " << kk << " in " << title << ": norms = "
              << std::scientific << std::setprecision(14)
              << rnm2 << " " << rnmu << std::endl;
}
