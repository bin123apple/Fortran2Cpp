#include <stdio.h>
#include <omp.h>

int a[100];
int main()
{
 int len, i, x;

 len = 100;
 x = 10;

#pragma omp parallel for
 for (i = 0; i < len; i++)
 {
  a[i] = x;
  x = i;
 }
 printf ("x = %d
", x);
 return 0;
}
