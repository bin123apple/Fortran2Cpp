#include <iostream>
#include <omp.h>

int tp, var;

#pragma omp threadprivate(tp)

void foo()
{
 #pragma omp task
 {
 #pragma omp task
 {
 tp = 1;
 #pragma omp task
 {
 var = tp;
 }
 }
 }
}

int main()
{
 foo();
 std::cout << var << std::endl;
 return 0;
}
