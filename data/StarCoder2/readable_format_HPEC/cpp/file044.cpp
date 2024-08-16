#include <iostream>
#include <omp.h>

int main() {
    const int N = 8;
    int b[N], c[N], temp[N];
    int a = 2;
    int val = 0;

    // Initialize arrays
    for (int i = 0; i < N; ++i) {
        b[i] = 0;
        c[i] = 2;
        temp[i] = 0;
    }

    // OpenMP target directive
    #pragma omp target map(tofrom:b) map(to:c,temp,a) device(0)
    {
        // OpenMP parallel directive
        #pragma omp parallel
        {
            for (int i = 0; i < 100; ++i) {
                // OpenMP for directive
                #pragma omp for
                for (int j = 0; j < N; ++j) {
                    temp[j] = b[j] + c[j];
                }

                // OpenMP for directive
                #pragma omp for
                for (int j = N-1; j >= 0; --j) {
                    b[j] = temp[j] * a;
                }
            }
        }
    }

    // Another loop outside the target directive
    for (int i = 0; i < 100; ++i) {
        val += 2;
        val *= 2;
    }

    // Check results
    for (int i = 0; i < N; ++i) {
        if (val!= b[i]) {
            std::cout << b[i] << " " << val << std::endl;
        }
    }

    return 0;
}
