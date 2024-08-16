#include <iostream>
#include <omp.h>

int main() {
    int len = 1000;
    int sum = 0;
    int sum0 = 0; // Equivalent to 'copyin' in Fortran
    int sum1 = 0; // Not in the original code, but needed for completeness

    #pragma omp parallel
    {
        #pragma omp single
        {
            for (int i = 1; i <= len; ++i) {
                sum0 += i;
            }

            #pragma omp critical
            {
                sum += sum0;
            }
        }
    }

    for (int i = 1; i <= len; ++i) {
        sum1 += i;
    }

    std::cout << "sum = " << sum << " sum1 = " << sum1 << std::endl;

    return 0;
}
