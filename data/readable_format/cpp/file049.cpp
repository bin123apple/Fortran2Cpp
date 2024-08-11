#include <iostream>
#include <array>

int main() {
    std::array<int, 5> P;

    // Fill the array with squares of numbers 1 through 5.
    for (int i = 0; i < 5; ++i) {
        P[i] = (i + 1) * (i + 1);
    }

    // Print the elements of the array.
    for (int i = 0; i < 5; ++i) {
        std::cout.width(3); // To mimic the Fortran format '5I3'
        std::cout << P[i];
    }

    return 0;
}