#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

double a[100];
int main()
{
 int i, len = 100, rem, j;
 double u;

 for (i = 0; i < len; i++)
 {
  a[i] = i+1;
 }

 u = (double)rand() / RAND_MAX;
 j = floor(100*u);

#pragma omp parallel for if (j%2==0)
 for (i = 0; i < len-1; i++)
 {
  a[i+1] = a[i]+1;
 }

 printf("a[50] = %.f
",a[50]);

 return 0;
}
