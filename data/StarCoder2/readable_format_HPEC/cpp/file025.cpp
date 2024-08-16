#include <iostream>
#include <omp.h>

class DRB128 {
public:
    static int tp; // Equivalent to the Fortran module variable 'tp'

    static void foo() {
        // OpenMP task region
        #pragma omp task
        {
            // OpenMP task region
            #pragma omp task
            {
                tp = 1; // This operation is performed by the first task
            }
            // OpenMP task region
            #pragma omp task
            {
                // This task does not modify 'tp' but can access it
            }
        }
        // OpenMP task region
        #pragma omp task
        {
            // This task ensures 'var' is updated after all tasks have completed
            int var = tp; // This line is executed by the last task
            // Assuming 'var' needs to be accessed or used further, you might need to return it or pass it as an argument
            std::cout << var << std::endl;
        }
    }
};

// Initialize the static member 'tp' of class DRB128
int DRB128::tp = 0;

int main() {
    DRB128::foo(); // Call the static method 'foo' of class DRB128
    return 0;
}
