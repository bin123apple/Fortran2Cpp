#include <iostream>
#include <omp.h>

// Global variables to mimic the behavior of the Fortran module
long long sum0 = 0;
long long sum1 = 0;

// Function prototype
void foo(long long i);

int main() {
    long long sum = 0;

    #pragma omp parallel
    {
        #pragma omp for
        for (long long i = 1; i <= 1001; ++i) {
            foo(i);
        }

        #pragma omp critical
        {
            sum += sum0;
        }
    }

    for (long long i = 1; i <= 1001; ++i) {
        sum1 += i;
    }

    std::cout << "sum = " << sum << " sum1 = " << sum1 << std::endl;

    return 0;
}

void foo(long long i) {
    #pragma omp critical
    {
        sum0 += i;
    }
}
