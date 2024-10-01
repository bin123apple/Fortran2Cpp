#include <stdio.h>
int a[100];
int b[100];
int main()
{
 int i;
 for (i=0;i<100;i++)
 {
 a[i] = i+1;
 b[i] = i+2;
 }
#pragma omp simd
 for (i=0;i<99;i++)
 a[i+1] = a[i] + b[i];

 printf ("a[50]=%d\n", a[49]);
 return 0;
}
