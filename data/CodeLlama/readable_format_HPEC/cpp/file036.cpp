#include <iostream>
#include <omp.h>

int main() {
    int sum = 0;
    int sum0 = 0;
    int sum1 = 0;

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 1; i <= 1001; ++i) {
            sum0 += i;
        }

        #pragma omp critical
        {
            sum += sum0;
        }
    }

    for (int i = 1; i <= 1001; ++i) {
        sum1 += i;
    }

    std::cout << "sum = " << sum << " sum1 = " << sum1 << std::endl;

    return 0;
}
