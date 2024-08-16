#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    omp_lock_t lck;

    omp_init_lock(&lck);

    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams distribute parallel for
    for (int i = 1; i <= 10; ++i) {
        omp_set_lock(&lck);
        var = var + 1;
        omp_unset_lock(&lck);
    }

    omp_destroy_lock(&lck);

    std::cout << var << std::endl;

    return 0;
}
