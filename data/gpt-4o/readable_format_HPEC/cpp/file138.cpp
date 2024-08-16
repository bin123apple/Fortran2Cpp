#include <stdio.h>
#include <omp.h>

int main()
{
 int len = 1000;
 double a[len];
 double b[len];
 double x;
 for (int i=0;i<len;i++)
 {
  a[i] = i/2.0;
  b[i] = 0.0;
 }
 x = foo(a,b,len);
 printf ("b[50] = %f
", b[50]);
 return 0;
}
