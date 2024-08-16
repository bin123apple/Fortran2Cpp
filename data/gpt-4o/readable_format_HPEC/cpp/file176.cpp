#include "lu_data.h"
#include <cmath>

void setiv() {
    double xi, eta, zeta;
    double pxi, peta, pzeta;
    double ue_1jk[5], ue_nx0jk[5], ue_i1k[5], ue_iny0k[5], ue_ij1[5], ue_ijnz[5];

    for (int k = 1; k < nz - 1; k++) {
        for (int j = 1; j < ny - 1; j++) {
            zeta = static_cast<double>(k) / static_cast<double>(nz - 1);
            eta = static_cast<double>(j) / static_cast<double>(ny0 - 1);
            for (int i = 1; i < nx - 1; i++) {
                xi = static_cast<double>(i) / static_cast<double>(nx0 - 1);
                exact(1, j, k, ue_1jk);
                exact(nx0, j, k, ue_nx0jk);
                exact(i, 1, k, ue_i1k);
                exact(i, ny0, k, ue_iny0k);
                exact(i, j, 1, ue_ij1);
                exact(i, j, nz, ue_ijnz);
                for (int m = 0; m < 5; m++) {
                    pxi = (1.0 - xi) * ue_1jk[m] + xi * ue_nx0jk[m];
                    peta = (1.0 - eta) * ue_i1k[m] + eta * ue_iny0k[m];
                    pzeta = (1.0 - zeta) * ue_ij1[m] + zeta * ue_ijnz[m];
                    u[m][i][j][k] = pxi + peta + pzeta - pxi * peta - peta * pzeta - pzeta * pxi + pxi * peta * pzeta;
                }
            }
        }
    }
}
