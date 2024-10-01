#include <stdio.h>
#include <omp.h>
int a[100];
void gen_task(int i)
{
#pragma omp task depend(out:a[i])
 a[i] = a[i] + 1;
}
int main()
{
 int i;
 for (i = 0; i < 100; i++)
 a[i] = i;
#pragma omp parallel
 {
#pragma omp single
 for (i = 0; i < 100; i++)
 gen_task(i);
 }
 for (i = 0; i < 100; i++)
 if (a[i] != i + 1)
 printf("warning: a[%d] = %d not expected %d\n", i, a[i], i + 1);
 return 0;
}
