#include <omp.h>
#include <iostream>

int main() {
    omp_lock_t lck;
    int var = 0;

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams num_teams(1)
        {
            #pragma omp distribute parallel for
            for (int i = 1; i <= 100; ++i) {
                omp_set_lock(&lck);
                var = var + 1;
                omp_unset_lock(&lck);
            }
        }
    }

    return 0;
}
