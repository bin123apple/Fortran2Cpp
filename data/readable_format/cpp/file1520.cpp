#include <omp.h>
#include <iostream>
#include <cstdlib>

int main() {
    omp_nest_lock_t lock;
    bool l = false;

    omp_init_nest_lock(&lock);

    if (omp_test_nest_lock(&lock) != 1) std::abort();
    if (omp_test_nest_lock(&lock) != 2) std::abort();

    #pragma omp parallel if(false) reduction(|:l)
    {
        if (omp_test_nest_lock(&lock) != 0) l = true;
    }

    if (l) std::abort();
    if (omp_test_nest_lock(&lock) != 3) std::abort();

    omp_unset_nest_lock(&lock);
    omp_unset_nest_lock(&lock);
    omp_unset_nest_lock(&lock);

    omp_destroy_nest_lock(&lock);

    return 0;
}