#include <iostream>
#include <string>

void rep_nrm(double*** u, int n1, int n2, int n3, std::string title, int kk) {
    double rnm2, rnmu;

    norm2u3(u, n1, n2, n3, rnm2, rnmu, kk);

    std::cout << "Level " << kk << " in " << title << ": norms = " << rnm2 << " " << rnmu << std::endl;
}

// Assuming norm2u3 is a separate function that calculates the norms
void norm2u3(double*** u, int n1, int n2, int n3, double& rnm2, double& rnmu, int nx, int ny, int nz) {
    // implementation of norm2u3
}
