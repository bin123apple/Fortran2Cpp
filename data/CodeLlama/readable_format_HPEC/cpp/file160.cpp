#include <iostream>
#include <vector>

// Assuming the existence of a header file for the sp_data module
#include "sp_data.h"

// Function prototype
void pinvr();

// Global variables (assuming they are defined in the sp_data module)
extern double bt;
extern int nx2, ny2, nz2;
extern std::vector<std::vector<std::vector<double>>> rhs;

void pinvr() {
    int i, j, k;
    double r1, r2, r3, r4, r5, t1, t2;

    // Start timer (if timeron is true)
    if (timeron) timer_start(t_pinvr);

    for (k = 1; k <= nz2; ++k) {
        for (j = 1; j <= ny2; ++j) {
            for (i = 1; i <= nx2; ++i) {
                r1 = rhs[0][i][j][k]; // Adjusted for 0-based indexing
                r2 = rhs[1][i][j][k];
                r3 = rhs[2][i][j][k];
                r4 = rhs[3][i][j][k];
                r5 = rhs[4][i][j][k];

                t1 = bt * r1;
                t2 = 0.5 * (r4 + r5);

                rhs[0][i][j][k] = bt * (r4 - r5);
                rhs[1][i][j][k] = -r3;
                rhs[2][i][j][k] = r2;
                rhs[3][i][j][k] = -t1 + t2;
                rhs[4][i][j][k] = t1 + t2;
            }
        }
    }

    // Stop timer (if timeron is true)
    if (timeron) timer_stop(t_pinvr);
}

// Note: The timer_start and timer_stop functions, and the global variables (timeron, t_pinvr, nx2, ny2, nz2, and rhs)
// are assumed to be defined elsewhere, similar to the Fortran module 'sp_data'.
