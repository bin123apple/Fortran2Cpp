#include <iostream>
#include <cmath>

using namespace std;

void txinvr(int nx2, int ny2, int nz2, double* rho_i, double* us, double* vs, double* ws, double* speed, double* rhs, double c2, double bt) {
    if (timeron) {
        timer_start(t_txinvr);
    }

    for (int k = 1; k <= nz2; k++) {
        for (int j = 1; j <= ny2; j++) {
            for (int i = 1; i <= nx2; i++) {
                double ru1 = rho_i[i + j*nx2 + k*nz2*nx2];
                double uu = us[i + j*nx2 + k*nz2*nx2];
                double vv = vs[i + j*nx2 + k*nz2*nx2];
                double ww = ws[i + j*nx2 + k*nz2*nx2];
                double ac = speed[i + j*nx2 + k*nz2*nx2];
                double ac2inv = ac*ac;

                double r1 = rhs[0 + i + j*nx2 + k*nz2*nx2*5];
                double r2 = rhs[1 + i + j*nx2 + k*nz2*nx2*5];
                double r3 = rhs[2 + i + j*nx2 + k*nz2*nx2*5];
                double r4 = rhs[3 + i + j*nx2 + k*nz2*nx2*5];
                double r5 = rhs[4 + i + j*nx2 + k*nz2*nx2*5];

                double t1 = c2 / ac2inv * ( rho_i[i + j*nx2 + k*nz2*nx2]*r1 - uu*r2 - vv*r3 - ww*r4 + r5 );
                double t2 = bt * ru1 * ( uu * r1 - r2 );
                double t3 = ( bt * ru1 * ac ) * t1;

                rhs[0 + i + j*nx2 + k*nz2*nx2*5] = r1 - t1;
                rhs[1 + i + j*nx2 + k*nz2*nx2*5] = - ru1 * ( ww*r1 - r4 );
                rhs[2 + i + j*nx2 + k*nz2*nx2*5] = ru1 * ( vv*r1 - r3 );
                rhs[3 + i + j*nx2 + k*nz2*nx2*5] = - t2 + t3;
                rhs[4 + i + j*nx2 + k*nz2*nx2*5] = t2 + t3;
            }
        }
    }

    if (timeron) {
        timer_stop(t_txinvr);
    }
}
