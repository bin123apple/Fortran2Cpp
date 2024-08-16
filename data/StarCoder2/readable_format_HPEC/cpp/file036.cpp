#include <iostream>
#include <omp.h>

// Assuming DRB092.h or similar header file exists and contains necessary declarations
#include "DRB092.h"

int main() {
    int i, sum = 0, sum0 = 0, sum1 = 0;

    #pragma omp parallel
    {
        int sum0_private = 0;
        #pragma omp for
        for (i = 1; i <= 1001; ++i) {
            sum0_private += i;
        }
        #pragma omp critical
        sum += sum0_private;
    }

    for (i = 1; i <= 1001; ++i) {
        sum1 += i;
    }

    std::cout << "sum = " << sum << " sum1 = " << sum1 << std::endl;

    return 0;
}
