#include <iostream>
#include <omp.h>

// Assuming the existence of a function foo(int64_t i) in a separate module or file.
extern void foo(int64_t i);

int main() {
    int len = 1000;
    int64_t sum = 0;
    int64_t sum1 = 0;

    #pragma omp parallel
    {
        int64_t sum0 = 0;
        #pragma omp for
        for (int64_t i = 1; i <= len; ++i) {
            foo(i);
        }

        #pragma omp critical
        {
            sum += sum0;
        }
    }

    for (int64_t i = 1; i <= len; ++i) {
        sum1 += i;
    }

    std::cout << "sum = " << sum << " sum1 = " << sum1 << std::endl;

    return 0;
}
