#include <stdio.h>

#define DATA_TYPE double
#define _PB_NI ni
#define _PB_NJ nj

void kernel_symm(int ni, int nj, DATA_TYPE alpha, DATA_TYPE beta, DATA_TYPE c[100][100], DATA_TYPE a[100][100], DATA_TYPE b[100][100]) {
 DATA_TYPE acc;
 int i, j, k;

 for (i = 0; i < _PB_NI; i++)
 for (j = 0; j < _PB_NJ; j++) {
 acc = 0.0;
 for (k = 0; k < j; k++) {
 c[j][k] = c[j][k] + (alpha * a[i][k] * b[j][i]);
 acc = acc + (b[j][k] * a[i][k]);
 }
 c[j][i] = (beta * c[j][i]) + (alpha * a[i][i] * b[j][i]) + (alpha * acc);
 }
}
