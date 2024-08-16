#include <iostream>
#include <omp.h>

// Assuming globalArray.h defines a global array 'a'
#include "globalArray.h"

void useGlobalArray(int len) {
    // This function is supposed to do something with 'a', but the original Fortran code does not specify its functionality.
    // For demonstration, let's just ensure 'a' is correctly sized.
    if (a == nullptr) {
        a = new int[len]; // Dynamic allocation, assuming 'a' is a global pointer.
    }
}

int main() {
    int len = 100;
    int x = 10;

    useGlobalArray(len); // Ensure 'a' is allocated and ready.

    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] = x;
        x = i + 1; // Note: C++ uses 0-based indexing, hence i + 1.
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}
