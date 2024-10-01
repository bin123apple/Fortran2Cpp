#include <stdio.h>
#include <omp.h>

int main()
{
 omp_lock_t lck;
 int var = 0;
 int i;

 omp_init_lock(&lck);

#pragma omp target map(tofrom:var) device(0)
#pragma omp teams distribute reduction(+:var)
 for (i = 0; i < 100; i++)
 {
  omp_set_lock(&lck);
  var = var+1;
  omp_unset_lock(&lck);
 }

 omp_destroy_lock(&lck);

 printf("%d\n", var);
 return 0;
}
