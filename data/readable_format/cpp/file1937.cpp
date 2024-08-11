#include <iostream>

int main() {
    int i = 2;

    // In the original Fortran code, the select case goes directly to the default case.
    // We replicate this behavior in C++ with a switch statement, even though it's not necessary for this simple example.
    switch(i) {
        default:
            std::cout << i << std::endl;
            break;
    }

    return 0;
}