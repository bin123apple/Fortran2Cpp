#include <iostream>
#include <omp.h>

int main() {
    int i, j, k;
    double a = 2.0;
    double b[8] = {0.0};
    double c[8] = {2.0};
    double temp[8] = {0.0};
    double val = 0.0;

    // Initialize arrays
    for (i = 0; i < 8; i++) {
        b[i] = 0.0;
        c[i] = 2.0;
        temp[i] = 0.0;
    }

    // OpenMP target region
    #pragma omp target teams distribute device(0)
    {
        // Map variables to device
        #pragma omp parallel
        {
            #pragma omp for
            for (i = 0; i < 100; i++) {
                // Compute temp array
                for (j = 0; j < 8; j++) {
                    temp[j] = b[j] + c[j];
                }

                // Compute b array
                for (j = 7; j >= 0; j--) {
                    b[j] = temp[j] * a;
                }
            }
        }
    }

    // Compute val
    for (i = 0; i < 100; i++) {
        val = val + 2.0;
        val = val * 2.0;
    }

    // Check if val matches b array
    for (i = 0; i < 8; i++) {
        if (val!= b[i]) {
            std::cout << b[i] << " " << val << std::endl;
        }
    }

    return 0;
}
