#include <stdio.h>
#include <math.h>
#include <omp.h>

#define MSIZE 200
#define dp 1.0
#define mits 1000
#define tol 0.0000000001
#define relax 1.0
#define alpha 0.0543

double u[MSIZE][MSIZE], f[MSIZE][MSIZE], uold[MSIZE][MSIZE];
double dx, dy;

void initialize() {
    int i, j;
    double xx, yy;

    dx = 2.0 / (MSIZE-1);
    dy = 2.0 / (MSIZE-1);

    for (i = 0; i < MSIZE; i++) {
        for (j = 0; j < MSIZE; j++) {
            xx = -1.0 + dx * i;
            yy = -1.0 + dy * i;
            u[i][j] = 0.0;
            f[i][j] = -1.0 * alpha * (1.0-xx*xx) * (1.0-yy*yy) - 2.0* (1.0-xx*xx) -2.0 * (1.0-yy*yy);
        }
    }
}

void jacobi() {
    double omega;
    int i, j, k;
    double error, resid, ax, ay, b;

    omega = relax;
    dx = 2.0 / (MSIZE-1);
    dy = 2.0 / (MSIZE-1);

    ax = 1.0 / (dx * dx);
    ay = 1.0 / (dy * dy);
    b = -2.0 / (dx * dx) - 2.0 / (dy * dy) - alpha;

    error = 10.0 * tol;
    k = 1;

    do {
        error = 0.0;

#pragma omp parallel
        {
#pragma omp for private(i,j)
            for (i = 0; i < MSIZE; i++)
                for (j = 0; j < MSIZE; j++)
                    uold[i][j] = u[i][j];

#pragma omp for private(i,j,resid) reduction(+:error)
            for (i = 1; i < MSIZE-1; i++)
                for (j = 1; j < MSIZE-1; j++) {
                    resid = (ax * (uold[i - 1][j] + uold[i + 1][j]) + ay * (uold[i][j - 1] + uold[i][j + 1]) + b * uold[i][j] - f[i][j]) / b;
                    u[i][j] = uold[i][j] - omega * resid;
                    error = error + resid * resid;
                }
        }

        error = sqrt(error)/(MSIZE*MSIZE);
        k++;
    } while (k <= mits);

    printf("Total number of iterations: %d
", k);
    printf("Residual: %.15f
", error);
}

int main() {
    initialize();
    jacobi();
    return 0;
}
