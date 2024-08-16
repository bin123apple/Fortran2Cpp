#include <iostream>
#include <vector>
#include <cmath>

// Assuming the existence of a header file "sp_data.h" which contains necessary declarations
#include "sp_data.h"

// Function prototype
void ninvr();

void ninvr() {
    double r1, r2, r3, r4, r5, t1, t2;

    if (timeron) {
        timer_start(t_ninvr);
    }

    for (int k = 0; k < nz2; ++k) {
        for (int j = 0; j < ny2; ++j) {
            for (int i = 0; i < nx2; ++i) {
                r1 = rhs[0][i][j][k];
                r2 = rhs[1][i][j][k];
                r3 = rhs[2][i][j][k];
                r4 = rhs[3][i][j][k];
                r5 = rhs[4][i][j][k];

                t1 = bt * r3;
                t2 = 0.5 * (r4 + r5);

                rhs[0][i][j][k] = -r2;
                rhs[1][i][j][k] = r1;
                rhs[2][i][j][k] = bt * (r4 - r5);
                rhs[3][i][j][k] = -t1 + t2;
                rhs[4][i][j][k] = t1 + t2;
            }
        }
    }

    if (timeron) {
        timer_stop(t_ninvr);
    }
}

int main() {
    // Initialize necessary variables and data structures
    // Assuming "sp_data.h" provides necessary initializations

    // Call the function
    ninvr();

    return 0;
}
