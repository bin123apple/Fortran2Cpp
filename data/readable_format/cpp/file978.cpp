#include <iostream>
#include <cstring> // For memcpy
#include <cstdlib> // For abort

int main() {
    float x = 1.0f;
    float y = x;
    int ix, iy;

    // Using memcpy to replicate Fortran's transfer behavior
    std::memcpy(&ix, &x, sizeof(x));
    std::memcpy(&iy, &y, sizeof(y));

    // Printing the integer representations in hexadecimal format
    std::cout << std::hex << ix << " " << iy << std::endl;

    if (ix != iy) {
        std::abort(); // Aborting if ix and iy are not equal
    }

    return 0;
}