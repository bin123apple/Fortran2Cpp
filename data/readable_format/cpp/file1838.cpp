#include <iostream>
#include <cstdint> // For fixed-width integers, if needed.

int main() {
    // Assuming i1 represents a kind that can be mapped to a standard int.
    // In C++, we don't usually have to define the "kind" of an integer this way.
    const int i1 = sizeof(int); // Mimicking the kind functionality as size, for demonstration.

    // Mimicking Fortran array with a kind type, but in C++ this is somewhat artificial.
    const int i2[1] = {i1};

    // Variable i3 with the "kind" specified by i2(1).
    int i3; // Directly using int here, assuming i1's kind maps to int.

    // Assigning and printing i3 with the kind from i1.
    i3 = static_cast<int>(0); // Using static_cast for type conversion, though not needed here.
    std::cout << i3 << std::endl;

    // Assigning and printing i3 with the kind from i2(1).
    i3 = static_cast<int>(0); // Again, static_cast not needed, but shown for consistency.
    std::cout << i3 << std::endl;

    return 0;
}