#include <stdio.h>
#include <omp.h>

int main() {
 int k;
 #pragma omp parallel
 {
  #pragma omp master
  {
   k = omp_get_num_threads();
   printf("Number of threads requested = %d\n", k);
  }
 }
 return 0;
}
