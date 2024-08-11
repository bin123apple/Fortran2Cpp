#include <iostream>

// Mimicking the Fortran module 'm' with a namespace
namespace m {
    int i = 3; // equivalent to "integer::i=3" in Fortran
    // 'j' is not included here since it's not used in the 't' program directly from 'm'
}

int main() {
    using namespace m; // Using the variables from namespace m, similar to 'use m,only:i'
    int j = 77; // equivalent to "integer::j=77" in Fortran

    // Printing values of 'i' and 'j', similar to Fortran's print statement
    std::cout << i << " " << j << std::endl;

    return 0;
}