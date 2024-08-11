#include <iostream>
#include <cmath> // for std::abs

int main() {
    // Assuming floating-point numbers for `real` in Fortran, use `float` or `double` in C++
    float a[2]; // assuming 0-based indexing in C++
    float b[2];
    float x;

    // Note: In Fortran arrays are 1-based, but in C++ they are 0-based
    for (int i = 0; i < 2; ++i) {
        x = std::abs(a[i]); // using std::abs for absolute value
        b[i] = x;
    }

    return 0;
}