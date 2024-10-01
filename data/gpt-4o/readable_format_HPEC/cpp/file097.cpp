#include <stdio.h>
#include <omp.h>

int main()
{
 int var = 0;

#pragma omp target map(tofrom:var) device(0)
#pragma omp teams distribute parallel for
 for (int i = 0; i <= 100; i++)
 {
#pragma omp atomic
 var += 1;
#pragma omp atomic
 var -= 2;
 }

 printf("%d\n", var);
 return 0;
}
