#include <openacc.h>
#include <vector>
#include <iostream>
#include <stdbool.h>

int main() {
    int i;
    int a[10];
    int b[3]; // Note: Adjusted to 0-based indexing, so b(5:7) becomes b[0:2] in C++
    const int acc_async_noval = -1;
    const int acc_async_sync = -2;
    bool l;

    // Example 1: Asynchronous operations with variable i
    #pragma acc kernels async(i)
    #pragma acc end kernels
    #pragma acc parallel async(i)
    #pragma acc end parallel

    // Example 2: Asynchronous operations without specifying queue
    #pragma acc kernels async
    #pragma acc end kernels
    #pragma acc parallel async
    #pragma acc end parallel

    // Example 3: Asynchronous operations with predefined constants
    #pragma acc kernels async(acc_async_noval)
    #pragma acc end kernels
    #pragma acc parallel async(acc_async_noval)
    #pragma acc end parallel

    #pragma acc kernels async(acc_async_sync)
    #pragma acc end kernels
    #pragma acc parallel async(acc_async_sync)
    #pragma acc end parallel

    // Example 4: Default(none) to specify no default scoping
    #pragma acc kernels default(none)
    #pragma acc end kernels
    #pragma acc parallel default(none)
    #pragma acc end parallel

    // Wait clauses with various conditions
    #pragma acc kernels wait(l)
    #pragma acc end kernels
    #pragma acc kernels wait(true)
    #pragma acc end kernels
    #pragma acc kernels wait(i, 1)
    #pragma acc end kernels
    #pragma acc kernels wait(a)
    #pragma acc end kernels
    #pragma acc kernels wait(b[0], b[1]) // Adjusted for 0-based indexing
    #pragma acc end kernels

    #pragma acc parallel wait(l)
    #pragma acc end parallel
    #pragma acc parallel wait(true)
    #pragma acc end parallel
    #pragma acc parallel wait(i, 1)
    #pragma acc end parallel
    #pragma acc parallel wait(a)
    #pragma acc end parallel
    #pragma acc parallel wait(b[0], b[1]) // Adjusted for 0-based indexing
    #pragma acc end parallel

    return 0;
}