#include <stdio.h>
#include <omp.h>

long long sum = 0;
long long sum1 = 0;
void foo(long long i);

int main()
{
 #pragma omp parallel
 {
  #pragma omp for
  for (long long i=1; i<1002; i++)
  {
   foo(i);
  }
  #pragma omp critical
  sum += sum0;
 }
 for (long long i=1; i<1002; i++)
 {
  sum1 += i;
 }
 printf("sum = %lld, sum1 = %lld
", sum, sum1);
 return 0;
}

void foo(long long i)
{
 #pragma omp threadprivate(sum0)
 sum0 += i;
}
