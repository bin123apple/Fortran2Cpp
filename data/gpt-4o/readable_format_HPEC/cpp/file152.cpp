#include "sp_data.h"

void ninvr() 
{
    int i, j, k;
    double r1, r2, r3, r4, r5, t1, t2;

    if (timeron) timer_start(t_ninvr);

    for (k = 0; k < nz2; k++)
    for (j = 0; j < ny2; j++)
    for (i = 0; i < nx2; i++) {

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

    if (timeron) timer_stop(t_ninvr);
}
