#include <iostream>
#include <omp.h>

// Assuming globalArray is defined elsewhere, similar to the Fortran module
extern void useGlobalArray(int len);

// Assuming 'a' is a global array defined elsewhere
extern int a[];

int main() {
    int len = 100;
    int x = 10;

    useGlobalArray(len);

    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] = x;
        x = i + 1; // Adjusted for 0-based indexing
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}
