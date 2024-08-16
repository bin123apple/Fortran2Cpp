#include "mg_data.h" // Assuming this header file provides necessary data structures and functions

void comm3(double*** u, int n1, int n2, int n3, int kk) {
    if (timeron) timer_start(T_comm3);

    for (int i3 = 1; i3 < n3 - 1; ++i3) { // Adjusted for 0-based indexing
        for (int i2 = 1; i2 < n2 - 1; ++i2) {
            u[0][i2][i3] = u[n1 - 2][i2][i3]; // Adjusted indices for 0-based indexing
            u[n1 - 1][i2][i3] = u[1][i2][i3];
        }

        for (int i1 = 0; i1 < n1; ++i1) {
            u[i1][0][i3] = u[i1][n2 - 2][i3];
            u[i1][n2 - 1][i3] = u[i1][1][i3];
        }
    }

    for (int i2 = 0; i2 < n2; ++i2) {
        for (int i1 = 0; i1 < n1; ++i1) {
            u[i1][i2][0] = u[i1][i2][n3 - 2];
            u[i1][i2][n3 - 1] = u[i1][i2][1];
        }
    }

    if (timeron) timer_stop(T_comm3);
}
