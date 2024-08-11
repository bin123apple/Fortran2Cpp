#include <iostream>
#include <cstdbool>

// Equivalent of the Fortran FUNCTION L()
extern "C" bool L() {
    return false;
}

// Equivalent of the Fortran FUNCTION L2()
bool L2() {
    return false;
}

// Equivalent of the Fortran SUBROUTINE S()
void S() {
    while (L()) {
        // Do something if L() is true
    }

    while (L2()) {
        // Do something if L2() is true
    }
}

int main() {
    S();
    return 0;
}