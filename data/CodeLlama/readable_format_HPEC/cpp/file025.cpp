#include <iostream>
#include <omp.h>

class DRB128 {
public:
    static int tp;

    static void foo() {
        #pragma omp task
        {
            tp = 1;
        }

        #pragma omp task
        {
            // This task does nothing but demonstrates the use of task
        }

        #pragma omp task
        {
            // This task updates var using tp
            int var = tp;
        }
    }
};

int DRB128::tp = 0;

int main() {
    #pragma omp parallel
    {
        DRB128::foo();
    }

    // Print var to demonstrate that it has been updated
    std::cout << DRB128::tp << std::endl;

    return 0;
}
