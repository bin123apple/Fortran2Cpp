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
#pragma omp end task
   var = tp; // value of var can be 1 or 2
 }
#pragma omp end task
 tp = 2;
 }
#pragma omp end task
}

int main()
{
    foo();
    return 0;
}
