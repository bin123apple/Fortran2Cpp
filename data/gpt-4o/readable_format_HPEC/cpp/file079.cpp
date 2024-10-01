#include <stdio.h>
#ifdef _OPENMP
#include <omp.h>
#endif

int main()
{
 int var[8];
 int i, j;

 for (i = 0; i < 8; i++)
 var[i] = 0;

#pragma omp target map(tofrom:var) device(0)
#pragma omp teams num_teams(1) thread_limit(1048)
#pragma omp distribute parallel for
 for (i = 0; i < 20; i++)
 {
#pragma omp simd
 for (j = 0; j < 8; j++)
 var[j]++;
 }
 printf("%d\n", var[7]);
 return 0;
}
