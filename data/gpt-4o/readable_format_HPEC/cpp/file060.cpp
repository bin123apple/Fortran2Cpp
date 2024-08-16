#include <stdio.h>
#include <omp.h>
int main()
{
 int var = 0;
#pragma omp target map(tofrom:var) device(0)
#pragma omp teams distribute parallel for reduction(+:var)
 for (int i = 0; i < 200; i++)
 {
  if (var<101)
  {
   var = var+1;
  }
 }
 return 0;
}
