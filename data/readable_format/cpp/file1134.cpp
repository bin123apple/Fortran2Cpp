#include <omp.h>
#include <iostream>

void compute(int* u, const int* v, const int* w, int size) {
    #pragma omp parallel for
    for(int i = 0; i < size; ++i) {
        u[i] = v[i] + w[i];
    }
}

int main() {
    const int size = 1024;
    int u[size], v[size], w[size];

    // Initialize arrays
    for(int i = 0; i < size; ++i) {
        v[i] = i + 1; // Adjust for 1-based equivalent values in Fortran
        w[i] = 2 * (i + 1); // Adjust for 1-based equivalent values in Fortran
    }

    // Call the computation function
    compute(u, v, w, size);

    // Test results
    for(int i = 0; i < size; ++i) {
        if(u[i] != 3 * (i + 1)) { // Check if the computation is correct
            std::cerr << "Test failed at index: " << i << std::endl;
            return 1;
        }
    }

    std::cout << "C++ test passed." << std::endl;
    return 0;
}