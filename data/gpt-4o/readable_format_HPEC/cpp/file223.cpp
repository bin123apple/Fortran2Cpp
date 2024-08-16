#include <stdio.h>
#define DATA_TYPE double
#define _PB_N 100
DATA_TYPE a[_PB_N][_PB_N];
DATA_TYPE u1[_PB_N];
DATA_TYPE u2[_PB_N];
DATA_TYPE v1[_PB_N];
DATA_TYPE v2[_PB_N];
DATA_TYPE w[_PB_N];
DATA_TYPE x[_PB_N];
DATA_TYPE y[_PB_N];
DATA_TYPE z[_PB_N];
DATA_TYPE alpha, beta;

void kernel_gemver()
{
 int i, j;
 for (i=0;i<_PB_N;i++)
 for (j=0;j<_PB_N;j++)
 a[j][i] = a[j][i] + (u1[i] * v1[j]) + (u2[i] * v2[j]);
 for (i=0;i<_PB_N;i++)
 for (j=0;j<_PB_N;j++)
 x[i] = x[i] + (beta * a[i][j] * y[j]);
 for (i=0;i<_PB_N;i++)
 x[i] = x[i] + z[i];
 for (i=0;i<_PB_N;i++)
 for (j=0;j<_PB_N;j++)
 w[i] = w[i] + (alpha * a[j][i] * x[j]);
}
