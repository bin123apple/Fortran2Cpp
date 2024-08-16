#include <stdio.h>
#include <omp.h>
int main()
{
 int i = 0;
 int sum = 0;
#pragma omp parallel for reduction(+:sum) num_threads(10) private(i)
 for (i = 0; i < 10; i++) {
 f1(i);
 sum += i;
 }
 if (sum != 10)
 printf("sum = %d
", sum);
 return 0;
}
