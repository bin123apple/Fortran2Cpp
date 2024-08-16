#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define dp 100

double a[dp][dp], b[dp][dp], c[dp][dp];

int main()
{
 int i, j;

 for (i=0; i<dp; i++)
 for (j=0; j<dp; j++)
 {
 a[i][j] = double(i)/2.0;
 b[i][j] = double(i)/3.0;
 c[i][j] = double(i)/7.0;
 }

#pragma omp simd collapse(2)
 for (i = 0; i < dp; i++)
 for (j = 0; j < dp; j++)
 c[i][j]=a[i][j]*b[i][j];

 printf("c[50][50] = %f
", c[50][50]);

 return 0;
}
