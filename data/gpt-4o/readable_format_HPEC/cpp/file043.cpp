#include <stdio.h>
#if (_OPENMP<201511)
#error "An OpenMP 4.5 compiler is needed to compile this test."
#endif

#include <omp.h>
int var[16];
int main()
{
 int i, j;
 for (i = 0; i < 16; i++)
 var[i] = 0;

#pragma omp target map(tofrom:var) device(0)
#pragma omp teams distribute parallel for reduction(+:var)
 for (i = 0; i < 20; i++)
 {
#pragma omp simd
 for (j = 0; j < 16; j++)
 var[j] += 1;
 }

 for (i = 0; i < 16; i++)
 if (var[i] != 20)
 printf ("%d %d\n", var[i], i);

 return 0;
}
