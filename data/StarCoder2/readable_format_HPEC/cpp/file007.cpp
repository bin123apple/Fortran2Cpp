#include <iostream>
#include <omp.h>

// Assuming the DRB086 module contains the definition of class A and the foo function
// You need to include the header file where A and foo are defined
#include "DRB086.h"

// Global variables to mimic the static data member behavior in Fortran
int counter = 0;
int pcounter = 0;

// Mimicking the foo function from Fortran
void foo() {
    // Incrementing the global counter
    counter++;

    // This is a critical section to ensure pcounter is updated correctly
    #pragma omp critical
    {
        pcounter++;
    }
}

int main() {
    A c(0, 0); // Creating an instance of class A, equivalent to type(A) :: c in Fortran

    #pragma omp parallel
    {
        foo(); // Calling the foo function in parallel
    }

    // Printing the counters
    std::cout << counter << " " << pcounter << std::endl;

    return 0;
}
