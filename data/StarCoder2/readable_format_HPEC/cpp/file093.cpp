#include <iostream>
#include <omp.h>

int main() {
    int len = 1000;
    int* a = new int[len];

    a[0] = 2; // Adjusted for 0-based indexing

    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] = a[i] + a[0];
    }

    std::cout << "a[500] = " << a[500] << std::endl; // Adjusted for 0-based indexing

    delete[] a; // Deallocate memory
    return 0;
}
