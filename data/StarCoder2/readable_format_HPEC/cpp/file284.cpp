#include "sp_data.h" // Assuming sp_data.h contains relevant declarations

void add() {
    int i, j, k, m;

    if (timeron) timer_start(t_add);
    for (k = 1; k <= nz2; ++k) {
        for (j = 1; j <= ny2; ++j) {
            for (i = 1; i <= nx2; ++i) {
                for (m = 1; m <= 5; ++m) {
                    u[m][i][j][k] = u[m][i][j][k] + rhs[m][i][j][k];
                }
            }
        }
    }
    if (timeron) timer_stop(t_add);
}
