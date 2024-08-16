#include <iostream>
#include <omp.h>

// Assuming the functionality of foo is similar to what's expected from the Fortran code
void foo(int* a, int size, int value) {
    #pragma omp parallel for firstprivate(value)
    for (int i = 0; i < size; ++i) {
        a[i] = value;
    }
}

int main() {
    const int size = 100;
    int* a = new int[size];

    foo(a, size, 7);

    // Print the 50th element to demonstrate the effect of the firstprivate clause
    std::cout << a[49] << std::endl;

    delete[] a;
    return 0;
}
