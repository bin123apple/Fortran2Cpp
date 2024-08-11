#include <vector>

void FPOLY(double x, std::vector<double>& p) {
    p[0] = 1.0; // Adjusted for 0-based indexing, equivalent to P(1)=1. in Fortran
    for (int j = 1; j < p.size(); ++j) { // Adjusted loop to start from 1, equivalent to J=2:N in Fortran
        p[j] = p[j - 1] * x; // Adjusted indexing, J-1 and J, for 0-based indexing
    }
}