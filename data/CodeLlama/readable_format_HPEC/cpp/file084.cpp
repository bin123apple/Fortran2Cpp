#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len;
    std::cout << "Enter the length of the array: ";
    std::cin >> len;

    std::vector<int> a(len); // Dynamic array allocation

    // Filling the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Arrays in C++ are 0-indexed
    }

    // OpenMP target parallel for directive
    #pragma omp target map(a[0:len])
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] = a[i] + 1; // Incrementing each element
    }

    // No need to explicitly deallocate 'a' as it will be automatically done by the vector destructor
    return 0;
}
