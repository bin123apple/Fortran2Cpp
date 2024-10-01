#include <stdio.h>
#include <omp.h>

int main() 
{
 int count = 0;

#pragma omp parallel shared(count)
 {
#pragma omp single
 count += 1;
 }
 printf("count = %d\n", count);
 return 0;
}
