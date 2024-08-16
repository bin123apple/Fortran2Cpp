#include <stdio.h>
#if (_OPENMP<201511)
#error "An OpenMP 4.5 compiler is needed to compile this test."
#endif

int main()
{
 int i=0;
#pragma omp parallel
 {
#pragma omp single
 {
#pragma omp task
 i=1;
#pragma omp task
 i=2;
 }
 }
 printf ("i=%d
", i);
 return 0;
}
