#include <iostream>
#include <omp.h>

// Equivalent to the Fortran module DRB086
class DRB086 {
public:
    // Equivalent to the Fortran derived type A
    class A {
    public:
        static int counter;
        static int pcounter;

        A() : counter(0), pcounter(0) {}
    };

    // Equivalent to the Fortran subroutine foo
    static void foo() {
        #pragma omp atomic
        A::counter += 1;
        #pragma omp atomic
        A::pcounter += 1;
    }
};

// Initialize static members of class A
int DRB086::A::counter = 0;
int DRB086::A::pcounter = 0;

int main() {
    // Equivalent to the Fortran variable c
    DRB086::A c;

    // Parallel region
    #pragma omp parallel
    {
        DRB086::foo();
    }

    // Print the values of static members
    std::cout << DRB086::A::counter << " " << DRB086::A::pcounter << std::endl;

    return 0;
}
