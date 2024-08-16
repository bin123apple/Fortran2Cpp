#include <stdio.h>
#include <omp.h>
int main()
{
 int numThreads = 0;
#pragma omp parallel
 {
  if (omp_get_thread_num() == 0) {
    numThreads = omp_get_num_threads();
  }
  else {
    printf("numThreads = %d
", numThreads);
  }
 }
 return 0;
}
