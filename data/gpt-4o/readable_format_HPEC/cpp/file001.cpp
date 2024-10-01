#include <stdio.h>
#if (_OPENMP<201511)
#error "An OpenMP 4.5 compiler is needed to compile this test."
#endif

#include <stdio.h>
int a[100][100];
int main()
{
 int i, j;
#pragma omp parallel
 {
#pragma omp single
 {
#pragma omp taskloop collapse(2)
 for (i = 0; i < 100; i++)
 for (j = 0; j < 100; j++)
 a[i][j]+=1; 
 }
 }
 printf ("a[50][50]=%d\n", a[50][50]);
 return 0;
}
