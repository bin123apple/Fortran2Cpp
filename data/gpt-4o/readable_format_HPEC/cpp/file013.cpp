#include <stdio.h>
#include <omp.h>

int main()
{
 int i = 0;
 int sum = 0;
#pragma omp parallel reduction(+:sum) num_threads(10)
 {
    f1(&i);
    sum+=i;
 }
 if (sum != 10)
 printf ("sum=%d\n", sum);
 return 0;
}
