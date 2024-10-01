#include <stdio.h>
#include <omp.h>
int main()
{
 int i = 0;
#pragma omp parallel sections
 {
#pragma omp section
 i=1;
#pragma omp section
 i=2;
 }
 printf ("i=%d\n", i);
 return 0;
}
