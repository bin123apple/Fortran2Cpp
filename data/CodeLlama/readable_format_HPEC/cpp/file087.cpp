#include <iostream>
#include <vector>
#include <omp.h>

// Assuming the existence of a function gen_task(int i) which is not defined here.
// You might need to adjust the implementation based on the original Fortran code.
void gen_task(int i) {
    // Placeholder implementation
    // This function should be defined based on what it's supposed to do in the original Fortran code.
}

int main() {
    std::vector<int> a(100); // Dynamic array allocation with 100 elements

    #pragma omp parallel
    {
        #pragma omp single
        for (int i = 0; i < 100; ++i) {
            gen_task(i); // Assuming gen_task modifies the array or does something with the index
        }
    }

    for (int i = 0; i < 100; ++i) {
        if (a[i] != i + 1) {
            std::cout << "warning: a(" << i << ") = " << a[i] << " not expected " << i + 1 << std::endl;
        }
        // Uncomment the following line if you need to print the values for debugging
        // std::cout << a[i] << " " << i + 1 << std::endl;
    }

    return 0;
}
