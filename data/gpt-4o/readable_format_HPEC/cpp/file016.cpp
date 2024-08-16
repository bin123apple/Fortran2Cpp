#include <stdio.h>
#include <omp.h>
int main()
{
 int i, x, len;
 len = 10000;
#pragma omp parallel for private(i)
 for (i = 0; i < len; i++)
 {
     x = i;
 }
 printf("x = %d
", x);
 return 0;
}
