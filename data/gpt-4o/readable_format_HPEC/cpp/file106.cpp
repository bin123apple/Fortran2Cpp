#include <stdio.h>
#include <omp.h>
int var[100];
int main()
{
 for (int i=0;i<100;i++)
 var[i] = 1;
#pragma omp target map(tofrom:var) device(0)
 {
#pragma omp parallel for ordered
 for (int i = 1; i < 100; i++)
 {
 #pragma omp ordered
 var[i] = var[i-1]+1;
 }
 }
 for (int i=0;i<100;i++)
 if (var[i]!=i+1) 
 printf("Data Race Present
");
 return 0;
}
