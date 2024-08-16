```cpp
#include "lu_data.h"
#include <cmath>

void pintgr() {
    int i, j, k;
    int ibeg, ifin, ifin1;
    int jbeg, jfin, jfin1;
    double frc1, frc2, frc3;

    ibeg = ii1;
    ifin = ii2;
    jbeg = ji1;
    jfin = ji2;
    ifin1 = ifin - 1;
    jfin1 = jfin - 1;

    for (j = jbeg; j <= jfin; j++) {
        for (i = ibeg; i <= ifin; i++) {
            k = ki1;
            phi1[i][j] = c2 * (u[5][i][j][k] - 0.5 * (pow(u[2][i][j][k], 2) + pow(u[3][i][j][k], 2) + pow(u[4][i][j][k], 2)) / u[1][i][j][k]);
            k = ki2;
            phi2[i][j] = c2 * (u[5][i][j][k] - 0.5 * (pow(u[2][i][j][k], 2) + pow(u[3][i][j][k], 2) + pow(u[4][i][j][k], 2)) / u[1][i][j][k]);
        }
    }

    frc1 = 0.0;
    for (j = jbeg; j <= jfin1; j++) {
        for (i = ibeg; i <= ifin1; i++) {
            frc1 += phi1[i][j] + phi1[i+1][j] + phi1[i][j+1] + phi1[i+1][j+1] + phi2[i][j] + phi2[i+1][j] + phi2[i][j+1] + phi2[i+1][j+1];
        }
    }
    frc1 = dxi * deta * frc1;

    // continue translating the rest of the code similarly...
}
```
