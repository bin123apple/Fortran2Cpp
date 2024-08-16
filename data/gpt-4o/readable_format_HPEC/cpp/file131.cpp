#include <stdio.h>
#include <omp.h>

int main()
{
 int counter = 0;

#pragma omp parallel
 {
   foo(&counter);
 }
 printf("%d
", counter);

 return 0;
}

void foo(int *counter)
{
#pragma omp atomic
  *counter += 1;
}
