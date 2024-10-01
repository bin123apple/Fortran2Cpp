#include <stdio.h>
#include <omp.h>
int main()
{
 int a = 0;
#pragma omp parallel
 {
#pragma omp atomic
 a+=1;
 }
 printf ("a=%d\n", a);
 return 0;
}
