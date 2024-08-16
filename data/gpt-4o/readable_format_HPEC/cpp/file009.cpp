#include <stdio.h>
float b[4];
int main()
{
 int i, m, n;
 m = 2;
 n = 4;
#pragma omp simd safelen(2)
 for (i = m+1; i < n; i++)
 b[i] = b[i-m] - 1.0;
 printf("%f", b[3]);
 return 0;
}
