#include "lu_data.h"
void exact(int i, int j, int k, double u000ijk[5]){
    double xi, eta, zeta;

    xi = double(i - 1) / (nx0 - 1);
    eta = double(j - 1) / (ny0 - 1);
    zeta = double(k - 1) / (nz - 1);

    for(int m = 0; m < 5; m++)
        u000ijk[m] = ce[m][0] + (ce[m][1] + (ce[m][4] + (ce[m][7] + ce[m][10] * xi) * xi) * xi) * xi +
                     (ce[m][2] + (ce[m][5] + (ce[m][8] + ce[m][11] * eta) * eta) * eta) * eta +
                     (ce[m][3] + (ce[m][6] + (ce[m][9] + ce[m][12] * zeta) * zeta) * zeta) * zeta;
}
