#include <stdio.h>
#include <omp.h>

double a[100], b[100], c[100];
int main() 
{
 int i, j = 0;
 for (i = 0; i < 100; i++) 
 {
 a[i] = (double)i/2.0;
 b[i] = (double)i/3.0;
 c[i] = (double)i/7.0;
 }

#pragma omp parallel for
 for (i = 0; i < 100; i++) 
 {
 c[j] = c[j] + a[i]*b[i];
 j = j + 1;
 }

 printf("c[50] = %f\n", c[50]);

 return 0;
}
