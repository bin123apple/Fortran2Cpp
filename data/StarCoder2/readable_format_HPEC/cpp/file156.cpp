#include "sp_data.h" // Assuming sp_data.h contains necessary declarations

void tzetar() {
    double t1, t2, t3, ac, xvel, yvel, zvel, r1, r2, r3, r4, r5, btuz, ac2u, uzik1;

    if (timeron) timer_start(t_tzetar);

    for (int k = 1; k <= nz2; ++k) {
        for (int j = 1; j <= ny2; ++j) {
            for (int i = 1; i <= nx2; ++i) {

                xvel = us[i-1][j-1][k-1]; // Adjusted for 0-based indexing
                yvel = vs[i-1][j-1][k-1]; // Adjusted for 0-based indexing
                zvel = ws[i-1][j-1][k-1]; // Adjusted for 0-based indexing
                ac = speed[i-1][j-1][k-1]; // Adjusted for 0-based indexing

                ac2u = ac * ac;

                r1 = rhs[0][i-1][j-1][k-1]; // Adjusted for 0-based indexing
                r2 = rhs[1][i-1][j-1][k-1]; // Adjusted for 0-based indexing
                r3 = rhs[2][i-1][j-1][k-1]; // Adjusted for 0-based indexing
                r4 = rhs[3][i-1][j-1][k-1]; // Adjusted for 0-based indexing
                r5 = rhs[4][i-1][j-1][k-1]; // Adjusted for 0-based indexing

                uzik1 = u[0][i-1][j-1][k-1]; // Adjusted for 0-based indexing
                btuz = bt * uzik1;

                t1 = btuz / ac * (r4 + r5);
                t2 = r3 + t1;
                t3 = btuz * (r4 - r5);

                rhs[0][i-1][j-1][k-1] = t2;
                rhs[1][i-1][j-1][k-1] = -uzik1 * r2 + xvel * t2;
                rhs[2][i-1][j-1][k-1] = uzik1 * r1 + yvel * t2;
                rhs[3][i-1][j-1][k-1] = zvel * t2 + t3;
                rhs[4][i-1][j-1][k-1] = uzik1 * (-xvel * r2 + yvel * r1) + qs[i-1][j-1][k-1] * t2 + c2iv * ac2u * t1 + zvel * t3;
            }
        }
    }

    if (timeron) timer_stop(t_tzetar);
}
