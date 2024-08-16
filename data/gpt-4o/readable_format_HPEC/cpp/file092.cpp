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
 printf ("a=%d
", a);
 return 0;
}
