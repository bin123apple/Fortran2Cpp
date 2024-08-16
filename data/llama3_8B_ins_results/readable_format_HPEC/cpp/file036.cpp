#include <iostream>
#include <omp.h>

int main() {
    int i, sum = 0, sum0 = 0, sum1 = 0;

    #pragma omp parallel
    {
        int sum0 = 0;
        #pragma omp for
        for (i = 1; i <= 1001; i++) {
            sum0 += i;
        }
        #pragma omp critical
        {
            sum += sum0;
        }
    }

    for (i = 1; i <= 1001; i++) {
        sum1 += i;
    }

    std::cout << "sum = " << sum << ", sum1 = " << sum1 << std::endl;

    return 0;
}
