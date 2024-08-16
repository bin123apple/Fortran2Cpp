#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    int sum1 = 0;
    int sum2 = 0;

    #pragma omp parallel reduction(+: var)
    {
        int sum1_local = 0;
        int sum2_local = 0;

        #pragma omp for schedule(static) reduction(+: sum1_local)
        for (int i = 1; i <= 5; i++) {
            sum1_local += i;
        }

        #pragma omp for schedule(static) reduction(+: sum2_local)
        for (int i = 1; i <= 5; i++) {
            sum2_local += i;
        }

        var = sum1_local + sum2_local;
    }

    std::cout << "var = " << var << std::endl;

    return 0;
}
