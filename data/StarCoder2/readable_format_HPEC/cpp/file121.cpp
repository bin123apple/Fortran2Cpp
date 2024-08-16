#include <iostream>
#include <omp.h>

// Assuming DRB048 contains relevant declarations or definitions
// #include "DRB048.h"

// Prototype for the foo function
void foo(int* a, int size, int value);

int main() {
    const int size = 100;
    int* a = new int[size];

    foo(a, size, 7);

    std::cout << a[50] << std::endl;

    delete[] a;
    return 0;
}

// Translated foo function
void foo(int* a, int size, int value) {
    // Assuming the intent is to initialize all elements of a to value
    for (int i = 0; i < size; ++i) {
        a[i] = value;
    }
}
