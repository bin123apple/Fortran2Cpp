#include <iostream>
#include <omp.h>

// Assuming the content of DRB085 is relevant, include its C++ equivalent here
// #include "DRB085.h"

// Assuming sum0 and sum1 are defined globally or in a namespace
extern int sum0;
extern int sum1;

// Assuming foo is a function that modifies sum0 in some way
void foo(int i) {
    // Placeholder for the actual implementation
    sum0 += i;
}

int main() {
    const int len = 1000;
    int64_t sum = 0;

    // Initialize sum0 and sum1 if necessary
    sum0 = 0;
    sum1 = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int64_t i = 1; i <= len; ++i) {
        foo(i);
    }

    for (int64_t i = 1; i <= len; ++i) {
        sum1 += i;
    }

    std::cout << "sum = " << sum << " sum1 = " << sum1 << std::endl;

    return 0;
}
