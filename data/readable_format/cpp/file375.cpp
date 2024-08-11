#include <iostream>
#include <omp.h>

int main() {
    const int size = 16;
    int* a = new int[size];
    
    // Initialize array elements to 0
    for (int i = 0; i < size; ++i) {
        a[i] = 0;
    }
    
    #pragma omp parallel
    {
        // OpenMP parallel sections with reduction on array 'a'
        #pragma omp sections reduction(+:a[:size])
        {
            #pragma omp section
            {
                for (int i = 0; i < size; ++i) {
                    a[i] = a[i] + 1;  // Equivalent to "a = a + 1" in Fortran
                }
            }
            #pragma omp section
            {
                for (int i = 0; i < size; ++i) {
                    a[i] = a[i] + 2;  // Equivalent to "a = a + 2" in Fortran
                }
            }
        }
    }

    // Check if all elements are equal to 3
    bool valid = true;
    for (int i = 0; i < size; ++i) {
        if (a[i] != 3) {
            valid = false;
            break;
        }
    }
    
    if (!valid) {
        std::cerr << "Validation failed: not all elements are 3." << std::endl;
        delete[] a;  // Deallocate memory
        return 1;  // Non-zero return value indicates failure
    }

    delete[] a;  // Deallocate memory
    return 0;  // Success
}