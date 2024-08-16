#include <stdio.h>
#include <omp.h>

int main() {

    int i, sum = 0, sum0 = 0, sum1 = 0;

#pragma omp parallel private(sum0)
    {
#pragma omp for
        for (i = 0; i <= 1000; i++) {
            sum0 += i;
        }
#pragma omp critical
        sum += sum0;
    }

    for (i = 0; i <= 1000; i++) {
        sum1 += i;
    }

    printf("sum = %d, sum1 = %d
", sum, sum1);

    return 0;
}
