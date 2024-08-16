#include <stdio.h>
#if (_OPENMP<201511)
#error "An OpenMP 4.5 compiler is needed to compile this test."
#endif

int var[16];
int main()
{
 for (int i = 0; i < 16; i++)
 var[i] = 0;

#pragma omp target map(tofrom:var) device(0)
#pragma omp teams distribute parallel for
 for (int i = 0; i < 20; i++)
 {
#pragma omp simd
 for (int j = 0; j < 16; j++)
 var[j]+=1;
 }

 printf ("%d
", var[15]);
 return 0;
}
