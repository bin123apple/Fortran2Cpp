#include <iostream>
#include <omp.h>

// Equivalent of the Fortran module 'DRB087'
namespace DRB087 {
    // Equivalent of the Fortran derived type 'A'
    struct A {
        int x;
        int y;

        // Constructor for initializing 'A'
        A(int x, int y) : x(x), y(y) {}
    };
}

// Global variables to mimic the static data member behavior in Fortran
int counter = 0;
int pcounter = 0;

int main() {
    DRB087::A c(0, 0); // Equivalent of 'type(A) :: c'

    #pragma omp parallel
    {
        // Incrementing the counters within the parallel region
        counter++;
        pcounter++;
    }

    // Printing the counters
    std::cout << counter << " " << pcounter << std::endl;

    return 0;
}
