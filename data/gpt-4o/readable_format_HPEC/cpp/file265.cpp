#include <stdio.h>

#define DATA_TYPE double
#define _PB_N 100
#define _PB_TSTEPS 100

DATA_TYPE a[_PB_N][_PB_N];
DATA_TYPE b[_PB_N][_PB_N];

void kernel_jacobi_2d_imper(int tsteps, int n, DATA_TYPE a[_PB_N][_PB_N], DATA_TYPE b[_PB_N][_PB_N]) {
  int i, j, t;
  for (t = 1; t < _PB_TSTEPS; t++) {
    for (i = 2; i < _PB_N - 1; i++) {
      for (j = 2; j < _PB_N - 1; j++) {
        b[j][i] = 0.2 * (a[j][i] + a[j-1][i] + a[j+1][i] + a[j][i+1] + a[j][i-1]);
      }
    }
    for (i = 2; i < _PB_N - 1; i++) {
      for (j = 2; j < _PB_N - 1; j++) {
        a[j][i] = b[j][i];
      }
    }
  }
}
