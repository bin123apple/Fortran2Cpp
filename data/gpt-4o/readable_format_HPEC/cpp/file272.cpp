#include <stdio.h>
#include <omp.h>

void foo();

int main()
{
#pragma omp parallel
 {
#pragma omp single
 foo();
 }
 return 0;
}

void foo()
{
 int x = 0, y = 2;

#pragma omp task shared(x)
 x+=1; // 1st Child Task

#pragma omp task shared(y)
 y-=1; // 2nd Child Task

#pragma omp taskwait // 1st taskwait

 printf ("x=%d\n", x);
 printf ("y=%d\n", y);

#pragma omp taskwait // 2nd taskwait
}
