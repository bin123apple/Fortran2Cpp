```C++
#include <cmath>
void error_norm(double rms[5]) {
    int i, j, k, m, d;
    double xi, eta, zeta, u_exact[5], add;
    for (m = 0; m < 5; m++)
        rms[m] = 0.0;
    for (k = 0; k < grid_points[3]; k++)
        for (j = 0; j < grid_points[2]; j++) {
            zeta = double(k) * dnzm1;
            eta = double(j) * dnym1;
            for (i = 0; i < grid_points[1]; i++) {
                xi = double(i) * dnxm1;
                exact_solution(xi, eta, zeta, u_exact);
                for (m = 0; m < 5; m++) {
                    add = u[m][i][j][k] - u_exact[m];
                    rms[m] += add * add;
                }
            }
        }
    for (m = 0; m < 5; m++)
        for (d = 0; d < 3; d++)
            rms[m] /= double(grid_points[d]-2);
    for (m = 0; m < 5; m++)
        rms[m] = sqrt(rms[m]);
}

void rhs_norm(double rms[5]) {
    int i, j, k, d, m;
    double add;
    for (m = 0; m < 5; m++)
        rms[m] = 0.0;
    for (k = 1; k < nz2; k++)
        for (j = 1; j < ny2; j++)
            for (i = 1; i < nx2; i++)
                for (m = 0; m < 5; m++) {
                    add = rhs[m][i][j][k];
                    rms[m] += add * add;
                }
    for (m = 0; m < 5; m++)
        for (d = 0; d < 3; d++)
            rms[m] /= double(grid_points[d]-2);
    for (m = 0; m < 5; m++)
        rms[m] = sqrt(rms[m]);
}
```
