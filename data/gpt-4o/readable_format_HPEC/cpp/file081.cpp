#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
 int len = 1000;
 int b = 5;
 int *a = (int*)malloc(len*sizeof(int));
 int i, error;

 for (i = 0; i < len; i++)
 a[i] = i;

#pragma omp parallel shared(b, error)
 {
#pragma omp for nowait
 for (i = 0; i < len; i++)
 a[i] = b + a[i] * 5;
 }

#pragma omp barrier
#pragma omp single
 error = a[8] + 1;

 printf("error = %d\n", error);

 free(a);
 return 0;
}
