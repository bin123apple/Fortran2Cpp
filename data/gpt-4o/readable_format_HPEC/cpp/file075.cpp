#include <stdio.h>
#include <omp.h>
int main()
{
 int var = 0;
#pragma omp parallel shared(var)
 {
#pragma omp single
 {
 var+=1;
 }
#pragma omp barrier
#pragma omp single
 {
 var+=1;
 }
 }
 printf ("var = %d\n", var);
 return 0;
}
