#include <iostream>
#include <omp.h>

// Assuming the definition of the A type from the Fortran code is as follows:
class A {
public:
    int x, y;
    A(int x = 0, int y = 0) : x(x), y(y) {} // Constructor with default values
};

// Global variables to mimic the static data members in the Fortran code
int counter = 0;
int pcounter = 0;

int main() {
    A c(0, 0); // Instance of A with default values

    #pragma omp parallel
    {
        #pragma omp atomic // Ensure atomic increment for counter and pcounter
        counter += 1;
        #pragma omp atomic
        pcounter += 1;
    }

    std::cout << counter << " " << pcounter << std::endl;

    return 0;
}
