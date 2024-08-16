#include <stdio.h>
#include <omp.h>

int main()
{
 int* counter = new int;
 *counter = 0;

#pragma omp parallel
 {
 #pragma omp atomic
 *counter = *counter + 1;
 }

 printf("%d
", *counter);

 delete counter;

 return 0;
}
