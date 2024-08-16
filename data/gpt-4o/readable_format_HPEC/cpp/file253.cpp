#include <stdio.h>
#define DATA_TYPE double
#define _PB_N 100
DATA_TYPE a[_PB_N][_PB_N];
DATA_TYPE b[_PB_N][_PB_N];
DATA_TYPE x[_PB_N], y[_PB_N], tmp[_PB_N];
DATA_TYPE alpha, beta;
int n;
int main()
{
 int i, j;

 for (i = 0; i < _PB_N; i++)
 {
 tmp[i] = 0.0;
 y[i] = 0.0;
 for (j = 0; j < _PB_N; j++)
 {
 tmp[i] = (a[j][i] * x[j]) + tmp[i];
 y[i] = (b[j][i] * x[j]) + y[i];
 }
 y[i] = (alpha * tmp[i]) + (beta * y[i]);
 }

 return 0;
}
