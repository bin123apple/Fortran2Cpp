#include <stdio.h>
#include <omp.h>

int main()
{
    int var = 0;
    omp_lock_t lck;
    omp_init_lock(&lck);
    
    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams distribute parallel for
    for (int i = 0; i < 10; i++)
    {
        omp_set_lock(&lck);
        var += 1;
        omp_unset_lock(&lck);
    }
    
    omp_destroy_lock(&lck);
    
    printf("%d\n", var);

    return 0;
}
