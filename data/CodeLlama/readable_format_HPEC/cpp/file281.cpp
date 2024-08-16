#include <iostream>
#include <vector>
#include <omp.h>

// Assuming gen_task is a function that takes an integer and modifies the array in some way.
// Since the original Fortran code does not specify what gen_task does, we'll create a simple version of it.
void gen_task(int i) {
    // Assuming 'a' is a global or passed vector. For simplicity, we'll use a global vector.
    static std::vector<int> a(100); // Initialize with size 100
    a[i-1] = i + 1; // Adjust for 0-based indexing
}

int main() {
    // Parallel region
    #pragma omp parallel
    {
        #pragma omp single
        {
            for (int i = 1; i <= 100; ++i) {
                gen_task(i);
            }
        }
    }

    // Verification
    for (int i = 1; i <= 100; ++i) {
        if (a[i-1] != i + 1) { // Adjust for 0-based indexing
            std::cout << "warning: a(" << i << ") = " << a[i-1] << " not expected " << i + 1 << std::endl;
        }
        // std::cout << a[i-1] << " " << i + 1 << std::endl; // Uncomment to print values
    }

    return 0;
}
