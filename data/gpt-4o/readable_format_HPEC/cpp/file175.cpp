#include "ft_data.h"
#include <complex>

void compute_initial_conditions(std::complex<double> u0[], int d1, int d2, int d3) {
    int k, j;
    double x0, start, an, dummy;
    double starts[nz];

    start = seed;
    ipow46(a, 0, &an);
    dummy = randlc(&start, an);
    ipow46(a, 2*nx*ny, &an);

    starts[0] = start;
    for (k = 1; k < dims[2]; k++) {
        dummy = randlc(&start, an);
        starts[k] = start;
    }

    for (k = 0; k < dims[2]; k++) {
        x0 = starts[k];
        for (j = 0; j < dims[1]; j++) {
            vranlc(2*nx, &x0, a, &u0[j + d1*(k + d2*j)]);
        }
    }
}
