#include <iostream>

int main() {
    int i, j;

    // Equivalent of the first DO loop in Fortran
    for (i = 1; i <= 10; ++i) {
        j = i;
    }

    j = 20;

    // Equivalent of the second DO loop with IF condition in Fortran
    for (i = 1; i <= 10; ++i) {
        if (j < 15) {
            j = i;
            std::cout << "HERE" << std::endl;
        }
    }

    return 0;
}