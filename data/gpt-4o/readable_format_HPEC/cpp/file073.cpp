#include <stdio.h>
#include <omp.h>

int main()
{
 int x=0;
 int i;
#pragma omp parallel for ordered
 for (i=0;i<100;i++)
 {
#pragma omp ordered
 x=x+1;
 }
 printf ("x = %d\n", x);
 return 0;
}
