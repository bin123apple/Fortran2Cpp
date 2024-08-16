#include <iostream>
#include <iomanip>
#include <string>

// Assuming the existence of a global structure similar to the Fortran module 'mg_data'
struct MGData {
    double nx[100]; // Example size, adjust as needed
    double ny[100]; // Example size, adjust as needed
    double nz[100]; // Example size, adjust as needed
};

// Assuming the definition of norm2u3 function
void norm2u3(double u[], int n1, int n2, int n3, double& rnm2, double& rnmu, double nx, double ny, double nz);

void rep_nrm(double u[][[]][], int n1, int n2, int n3, const std::string& title, int kk) {
    double rnm2, rnmu;
    norm2u3(u, n1, n2, n3, rnm2, rnmu, MGData::nx[kk-1], MGData::ny[kk-1], MGData::nz[kk-1]);
    std::cout << std::setw(2) << kk << " in " << title << ": norms = "
              << std::scientific << std::setprecision(14) << rnm2 << " " << rnmu << std::endl;
}

int main() {
    // Example usage
    double u[10][10][10]; // Example dimensions, adjust as needed
    int n1 = 10, n2 = 10, n3 = 10, kk = 1;
    std::string title = "ExampleTitle";

    // Initialize MGData::nx, MGData::ny, MGData::nz as needed
    // For example:
    MGData::nx[0] = 1.0;
    MGData::ny[0] = 2.0;
    MGData::nz[0] = 3.0;

    rep_nrm(u, n1, n2, n3, title, kk);

    return 0;
}
