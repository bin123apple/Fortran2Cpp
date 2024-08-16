#include <stdio.h>
#include <omp.h>

int main()
{
 int var=0;
#pragma omp parallel sections
 {
#pragma omp section
 for (int i = 0; i < 10; i++)
 {
#pragma omp task shared(var)
 var+=1;
 }
 }
 printf ("var=%d
", var);
 return 0;
}
