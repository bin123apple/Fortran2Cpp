#include "lu_data.h"
#include <math.h>

void error() {
    double tmp;
    double u000ijk[5];

    for (int m = 0; m < 5; m++)
        errnm[m] = 0.0;

    for (int k = 1; k < nz - 1; k++)
        for (int j = jst - 1; j < jend; j++)
            for (int i = ist - 1; i < iend; i++) {
                exact(i + 1, j + 1, k + 1, u000ijk);
                for (int m = 0; m < 5; m++) {
                    tmp = (u000ijk[m] - u[m][i][j][k]);
                    errnm[m] += tmp * tmp;
                }
            }

    for (int m = 0; m < 5; m++)
        errnm[m] = sqrt(errnm[m] / ((double)(nx0 - 2)*(ny0 - 2)*(nz0 - 2)));

    printf("
 RMS-norm of error in soln. to first pde  = %.5e"
        "
 RMS-norm of error in soln. to second pde = %.5e"
        "
 RMS-norm of error in soln. to third pde  = %.5e"
        "
 RMS-norm of error in soln. to fourth pde = %.5e"
        "
 RMS-norm of error in soln. to fifth pde  = %.5e
",
        errnm[0], errnm[1], errnm[2], errnm[3], errnm[4]);
}
