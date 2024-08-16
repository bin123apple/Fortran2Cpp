#include <iostream>
#include <vector>

using namespace std;

void setiv(double* nu, double* ue_1jk, double* ue_nx0jk, double* ue_i1k, double* ue_iny0k, double* ue_ij1, double* ue_ijnz, int nx0, int ny0, int nz) {
    for (int k = 2; k < nz; k++) {
        for (int j = 2; j < ny0; j++) {
            double zeta = (k - 1) / (nz - 1);
            double eta = (j - 1) / (ny0 - 1);
            for (int i = 2; i < nx0; i++) {
                double xi = (i - 1) / (nx0 - 1);
                double pxi, peta, pzeta;
                for (int m = 0; m < 5; m++) {
                    pxi = (1.0 - xi) * ue_1jk[m] + xi * ue_nx0jk[m];
                    peta = (1.0 - eta) * ue_i1k[m] + eta * ue_iny0k[m];
                    pzeta = (1.0 - zeta) * ue_ij1[m] + zeta * ue_ijnz[m];
                    nu[m * nx0 * ny0 * nz + i * ny0 * nz + j * nz + k] = pxi + peta + pzeta
                        - pxi * peta - peta * pzeta - pzeta * pxi
                        + pxi * peta * pzeta;
                }
            }
        }
    }
}
