#include <stdio.h>
#include <omp.h>
int main()
{
 int len = 100;
 int a[len], b[len], c[len];
#pragma omp simd
 for (int i = 0; i < len; i++)
 a[i] = b[i] + c[i];
 return 0;
}
