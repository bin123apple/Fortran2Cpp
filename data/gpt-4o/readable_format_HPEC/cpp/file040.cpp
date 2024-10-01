#include <stdio.h>
#include <omp.h>
int main()
{
 int var = 0;
 int i;
#pragma omp parallel sections
 {
 for (i = 0; i < 10; i++)
 {
#pragma omp task shared(var) if(0)
 var++;
 }
 }
 printf ("var = %d\n", var);
 return 0;
}
