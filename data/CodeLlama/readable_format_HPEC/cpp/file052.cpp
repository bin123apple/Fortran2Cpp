#include <omp.h>
#include <iostream>

// Equivalent to the Fortran module
class DRB127 {
public:
    static int tp; // Equivalent to the Fortran integer :: tp

    static void foo() {
        // OpenMP task directive
        #pragma omp task
        {
            tp = 1;
            #pragma omp task
            {
                // This task does not modify tp, so it inherits the value from the parent task
                int var = tp; // var can be 1 or 2, depending on the parent task's value
                #pragma omp task
                {
                    tp = 2;
                }
            }
        }
    }
};

// Definition of the static member variable
int DRB127::tp = 0;

int main() {
    // Call the foo function
    DRB127::foo();

    return 0;
}
