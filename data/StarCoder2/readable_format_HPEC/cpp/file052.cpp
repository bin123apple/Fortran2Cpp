#include <iostream>
#include <omp.h>

class DRB127 {
public:
    static int tp; // Equivalent to the Fortran module variable 'tp'

    static void foo() {
        // OpenMP task region with 'tp' as threadprivate
        #pragma omp task
        {
            #pragma omp task
            tp = 1;
            #pragma omp task
            {
                // 'tp' is private to this task, so it does not affect the outer 'tp'
            }
            // 'tp' is still 1 here due to the scope of the tasks
            var = tp; // This will assign 1 to 'var'
            #pragma omp task
            tp = 2;
            // 'tp' is now 2 here due to the scope of the tasks
        }
        // 'tp' is still 2 here due to the scope of the task region
    }

private:
    static int var; // Equivalent to the Fortran module variable 'var'
};

// Initialize static members
int DRB127::tp = 0;
int DRB127::var = 0;

int main() {
    DRB127::foo();
    // 'var' should be 1, as the last task sets 'tp' to 2, but 'var' is updated only once.
    std::cout << "var: " << DRB127::var << std::endl;
    return 0;
}
