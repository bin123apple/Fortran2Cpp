#include <iostream>
#include <omp.h>
#define len 1000

long long sum = 0;
long long sum0 = 0;
long long sum1 = 0;

void foo(long long i) 
{
#pragma omp threadprivate(sum0)
 sum0 += i;
}

int main()
{
#pragma omp parallel copyin(sum0)
{
#pragma omp for
 for (long long i = 0; i < len; i++)
 {
  foo(i);
 }
#pragma omp critical
 {
  sum += sum0;
 }
}
 for (long long i = 0; i < len; i++)
 {
  sum1 += i;
 }

 std::cout << "sum = " << sum << ", sum1 = " << sum1 << std::endl;
 return 0;
}
