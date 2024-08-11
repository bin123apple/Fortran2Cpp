#include <iostream>

void foo0() {
    for (int j = 1; j <= 2; ++j) {
        if (true) {
            // The body of the if statement is empty, similar to the Fortran code
        }
    }
}

int main() {
    foo0();
    return 0;
}