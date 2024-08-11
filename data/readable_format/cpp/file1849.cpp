#include <iostream>
#include <cstdlib> // For std::abort

// Assuming we are simulating the Fortran modules 'm' and 'n' and their variables a and b

// Variables previously in m.h and n.h
extern "C" {
    int a = 5; // Simulate module m's variable a
    int b = -5; // Simulate module n's variable a (renamed to b in the original program)
}

int main() {
    std::cout << a << " " << b << std::endl; // Print values of 'a' and 'b'
    if (a != 5 || b != -5) {
        std::abort(); // Check condition and call abort if necessary
    }

    return 0;
}