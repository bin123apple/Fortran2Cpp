#include <iostream>
#include <omp.h>

int main() {
    omp_lock_t lck;
    int var = 0;

    omp_init_lock(&lck);

    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams distribute reduction(+:var)
    for (int i = 1; i <= 100; ++i) {
        omp_set_lock(&lck);
        var = var + 1;
        omp_unset_lock(&lck);
    }

    omp_destroy_lock(&lck);

    std::cout << var << std::endl;

    return 0;
}
