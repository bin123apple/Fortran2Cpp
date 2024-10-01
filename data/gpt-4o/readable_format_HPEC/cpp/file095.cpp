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

void foo(){
 int x, y;
 x = 0;
 y = 2;

#pragma omp task shared(x)
 x = x+1;
#pragma omp task shared(y)
 y = y-1;
#pragma omp task depend(in: x) if(0)
 ;
 printf("x= %d\n", x);
#pragma omp taskwait
 printf("y= %d\n", y);
}
