#include <iostream>
#include <cstdlib> // For std::abort()

#define N 1024

int main() {
    int a[N], b[N], c[N];

    // Initialize arrays a and b
    for (int i = 0; i < N; ++i) {
        a[i] = i * 2;
    }

    for (int i = 0; i < N; ++i) {
        b[i] = i * 4;
    }

    // Parallel section for computing c = a + b
    #pragma acc kernels copyin(a[0:N-1],b[0:N-1]) copyout(c[0:N-1])
    for (int ii = 0; ii < N; ++ii) {
        c[ii] = a[ii] + b[ii];
    }
    // End of parallel section

    // Verification
    for (int i = 0; i < N; ++i) {
        if (c[i] != a[i] + b[i]) {
            std::abort(); // Abort if any element doesn't match the expected result
        }
    }

    return 0;
}