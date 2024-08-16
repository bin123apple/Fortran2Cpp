#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len);

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
    }

    // Parallel loop to increment elements
    #pragma omp parallel for
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + 1; // Increment the next element
    }

    // Print the value of a[50] (equivalent to a(50) in Fortran)
    std::cout << "a[50]= " << a[50] << std::endl;

    return 0;
}
