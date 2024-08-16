#include "bt_data.h" // Assuming this header file contains the necessary data structures and functions

void add() {
    int i, j, k, m;

    if (timeron) timer_start(t_add);
    for (k = 0; k < grid_points[2] - 2; ++k) {
        for (j = 0; j < grid_points[1] - 2; ++j) {
            for (i = 0; i < grid_points[0] - 2; ++i) {
                for (m = 0; m < 5; ++m) {
                    u[m][i][j][k] = u[m][i][j][k] + rhs[m][i][j][k];
                }
            }
        }
    }
    if (timeron) timer_stop(t_add);
}
