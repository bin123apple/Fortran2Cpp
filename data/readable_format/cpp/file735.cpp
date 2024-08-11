#include <iostream>
#include <cstdlib> // for std::abort()

// Declaration of the kernel function
void kernel(int lo, int hi, float a[], float b[], float c[]);

int main() {
    const int n = 20;
    float a[n], b[n], c[n];

    // Initialize arrays a, b, and c
    for (int i = 0; i < n; i++) {
        a[i] = 1.0f;
        b[i] = 2.0f;
        c[i] = 3.0f;
    }

    // Call the kernel function
    kernel(0, n, a, b, c); // Note: Arrays in C++ are 0-based, adjusted indices accordingly

    // Check if all elements of c are equal to 1
    for (int i = 0; i < n; i++) {
        if (c[i] != 1.0f) {
            std::abort();
        }
    }

    return 0; // Success
}

// Definition of the kernel function
void kernel(int lo, int hi, float a[], float b[], float c[]) {
    // Copy elements from a to b
    for (int i = lo; i < hi; i++) {
        b[i] = a[i];
    }
    // Copy elements from b to c
    for (int i = lo; i < hi; i++) {
        c[i] = b[i];
    }
}