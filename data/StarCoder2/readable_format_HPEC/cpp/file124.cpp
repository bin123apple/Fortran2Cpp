#include <omp.h> // Include OpenMP header
// Assuming DRB083.h contains the declarations for functions or variables used in foo()
#include "DRB083.h"

// Declaration of foo() if it's not in DRB083.h
void foo();

int main() {
    #pragma omp parallel
    {
        foo();
    }
    return 0;
}
