#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    omp_lock_t lck;

    omp_init_lock(&lck);

    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams distribute reduction(+:var)
    for (int i = 1; i <= 100; i++) {
        #pragma omp critical
        {
            omp_set_lock(&lck);
            var++;
            omp_unset_lock(&lck);
        }
    }
    #pragma omp end teams distribute
    #pragma omp end target

    omp_destroy_lock(&lck);

    std::cout << var << std::endl;

    return 0;
}
