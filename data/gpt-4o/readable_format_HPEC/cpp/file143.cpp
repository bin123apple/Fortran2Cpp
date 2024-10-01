#include <stdio.h>
#include <omp.h>
#define N 1000

float a[N][N];
float v[N];
float v_out[N];

int main()
{
 float sum;
 int i,j;
 for (i=0; i<N; i++)
 {
  sum = 0;
#pragma omp parallel for reduction(+:sum)
  for (j=0; j<N; j++)
  {
   sum += a[i][j]*v[j];
   printf("%f\n",sum);
  }
  v_out[i] = sum;
 }
 return 0;
}
