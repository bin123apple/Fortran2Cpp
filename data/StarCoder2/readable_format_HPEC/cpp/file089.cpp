#include <iostream>
#include <omp.h>

int main() {
    int b[8], c[8], temp[8];
    int a, val;

    // Initialize arrays and variables
    for (int i = 0; i < 8; ++i) {
        b[i] = 0;
        c[i] = 2;
        temp[i] = 0;
    }

    a = 2;
    val = 0;

    // OpenMP target directive with maps
    #pragma omp target map(tofrom:b) map(to:c,temp,a) device(0)
    {
        // OpenMP teams directive
        #pragma omp teams
        {
            for (int i = 0; i < 100; ++i) {
                // OpenMP distribute directive for the first loop
                #pragma omp distribute
                for (int j = 0; j < 8; ++j) {
                    temp[j] = b[j] + c[j];
                }

                // OpenMP distribute directive for the second loop
                #pragma omp distribute
                for (int j = 7; j >= 0; --j) {
                    b[j] = temp[j] * a;
                }
            }
        }
    }

    // Additional computation outside the target region
    for (int i = 0; i < 100; ++i) {
        val = val + 2;
        val = val * 2;
    }

    // Verification
    for (int i = 0; i < 8; ++i) {
        if (val!= b[i]) {
            std::cout << b[i] << " " << val << std::endl;
        }
    }

    return 0;
}
