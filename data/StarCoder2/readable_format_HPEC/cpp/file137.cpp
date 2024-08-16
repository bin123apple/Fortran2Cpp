#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    int sum1 = 0;
    int sum2 = 0;

    #pragma omp parallel reduction(+: var)
    {
        #pragma omp for schedule(static) reduction(+: sum1)
        for (int i = 1; i <= 5; ++i) {
            sum1 += i;
        }

        #pragma omp for schedule(static) reduction(+: sum2)
        for (int i = 1; i <= 5; ++i) {
            sum2 += i;
        }

        var = sum1 + sum2;
    }

    std::cout << "var = " << var << std::endl;

    return 0;
}
