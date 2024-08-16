#include <vector>

// Assuming DATA_TYPE is a typedef for double or float, depending on the precision needed.
// Adjust accordingly if DATA_TYPE is defined differently in your Fortran code.
typedef double DATA_TYPE;

void kernel_gesummv(int n, DATA_TYPE alpha, DATA_TYPE beta,
                   DATA_TYPE* a, DATA_TYPE* b, DATA_TYPE* tmp, DATA_TYPE* x, DATA_TYPE* y) {
    // Assuming a, b, x, y, tmp are all allocated and sized appropriately outside this function.
    // This function does not allocate memory for these arrays.

    // OpenMP pragma for scoping
    #pragma omp scop
    for (int i = 0; i < n; ++i) {
        tmp[i] = 0.0;
        y[i] = 0.0;
        for (int j = 0; j < n; ++j) {
            tmp[i] = (a[j + i*n] * x[j]) + tmp[i]; // Adjusted for column-major order
            y[i] = (b[j + i*n] * x[j]) + y[i]; // Adjusted for column-major order
        }
        y[i] = (alpha * tmp[i]) + (beta * y[i]);
    }
    #pragma omp endscop
}
