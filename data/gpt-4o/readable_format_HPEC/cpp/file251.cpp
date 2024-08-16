#include <cmath>
#define EPS 0.1
#define _PB_M 100
#define _PB_N 100
#define DATA_TYPE double

void kernel_correlation(int m, int n, DATA_TYPE float_n, DATA_TYPE dat[_PB_N][_PB_M], DATA_TYPE symmat[_PB_M][_PB_M], DATA_TYPE mean[_PB_M], DATA_TYPE stddev[_PB_M])
{
    int i, j, j1, j2;

    for (j = 0; j < _PB_M; j++) {
        mean[j] = 0.0;
        for (i = 0; i < _PB_N; i++) {
            mean[j] += dat[i][j];
        }
        mean[j] /= float_n;
    }

    for (j = 0; j < _PB_M; j++) {
        stddev[j] = 0.0;
        for (i = 0; i < _PB_N; i++) {
            stddev[j] += (dat[i][j] - mean[j]) * (dat[i][j] - mean[j]);
        }
        stddev[j] /= float_n;
        stddev[j] = sqrt(stddev[j]);
        if (stddev[j] <= EPS) {
            stddev[j] = 1.0;
        }
    }

    for (i = 0; i < _PB_N; i++) {
        for (j = 0; j < _PB_M; j++) {
            dat[i][j] -= mean[j];
            dat[i][j] /= (sqrt(float_n) * stddev[j]);
        }
    }

    for (j1 = 0; j1 < _PB_M - 1; j1++) {
        symmat[j1][j1] = 1.0;
        for (j2 = j1 + 1; j2 < _PB_M; j2++) {
            symmat[j2][j1] = 0.0;
            for (i = 0; i < _PB_N; i++) {
                symmat[j2][j1] += dat[i][j1] * dat[i][j2];
            }
            symmat[j1][j2] = symmat[j2][j1];
        }
    }
    symmat[_PB_M - 1][_PB_M - 1] = 1.0;
}
