#include <iostream>
#include <vector>
#include <openacc.h>

int main() {
    const int n = 1024;
    std::vector<int> a(n), b(n), c(n);

    // Enter data region for a
    #pragma acc enter data create(a[0:n])
    // Parallel loop to populate array a
    #pragma acc kernels present(a[0:n])
    for (int i = 0; i < n; ++i) {
        a[i] = i * 2;
    }
    #pragma acc end kernels
    // Exit data region for a
    #pragma acc exit data copyout(a[0:n])

    // Enter data region for b
    #pragma acc enter data create(b[0:n])
    // Parallel loop to populate array b
    #pragma acc kernels present(b[0:n])
    for (int i = 0; i < n; ++i) {
        b[i] = i * 4;
    }
    #pragma acc end kernels
    // Exit data region for b
    #pragma acc exit data copyout(b[0:n])

    // Enter data region for c, with a and b as inputs
    #pragma acc enter data copyin(a[0:n],b[0:n]) create(c[0:n])
    // Parallel loop to compute c = a + b
    #pragma acc kernels present(a[0:n],b[0:n],c[0:n])
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] + b[i];
    }
    #pragma acc end kernels
    // Exit data region for c
    #pragma acc exit data copyout(c[0:n])

    // Verification loop
    for (int i = 0; i < n; ++i) {
        if (c[i] != a[i] + b[i]) {
            std::cerr << "Mismatch at index " << i << std::endl;
            return 1;
        }
    }

    return 0;
}