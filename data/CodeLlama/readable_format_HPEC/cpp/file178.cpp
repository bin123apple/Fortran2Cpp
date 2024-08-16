#include <complex>
#include <vector>
#include "ft_data.h" // Assuming this header file contains necessary declarations

void compute_initial_conditions(std::vector<std::vector<std::vector<std::complex<double>>> &u0, int d1, int d2, int d3) {
    double start, an, dummy;
    std::vector<double> starts(nz); // Assuming nz is defined somewhere
    
    start = seed;
    ipow46(a, 0, an);
    dummy = randlc(start, an);
    ipow46(a, 2*nx*ny, an);
    
    starts[0] = start;
    for (int k = 1; k < dims[2]; ++k) { // Adjusted for zero-based indexing
        dummy = randlc(start, an);
        starts[k] = start;
    }
    
    for (int k = 0; k < dims[2]; ++k) { // Adjusted for zero-based indexing
        double x0 = starts[k];
        for (int j = 0; j < dims[1]; ++j) { // Adjusted for zero-based indexing
            vranlc(2*nx, x0, a, u0[0][j][k]); // Adjusted for zero-based indexing
        }
    }
}
