#include <stdio.h>
#include <unistd.h>
#if (_OPENMP<201511)
#error "An OpenMP 4.5 compiler is needed to compile this test."
#endif
int main()
{
 int i = 0;
#pragma omp parallel
 {
#pragma omp single
 {
#pragma omp task depend(out: i)
 {
 sleep(3);
 i = 3;
 }
#pragma omp task depend(out: i)
 {
 i = 2;
 }
 }
 }
 if (i!=2) printf ("%d", i);
 return 0;
}
