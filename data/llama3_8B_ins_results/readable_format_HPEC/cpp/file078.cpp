#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    omp_lock_t lck;

    omp_init_lock(&lck);

    #pragma omp target teams distribute parallel do
    for (int i = 1; i <= 10; i++) {
        #pragma omp critical
        {
            omp_set_lock(&lck);
            var++;
            omp_unset_lock(&lck);
        }
    }

    #pragma omp end target

    omp_destroy_lock(&lck);

    std::cout << var << std::endl;

    return 0;
}
