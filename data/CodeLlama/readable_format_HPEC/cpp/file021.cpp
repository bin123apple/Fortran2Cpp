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

    // Parallelize the loop
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        int tmp = a[i] + (i + 1); // Adjust for 0-based indexing
        a[i] = tmp;
    }

    // Print the result
    std::cout << "a[50]=" << a[50] << std::endl;

    return 0;
}
