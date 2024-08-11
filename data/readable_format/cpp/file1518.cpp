#include <iostream>
#include <cmath> // for std::abs

int main() {
    // Assuming the use of float for 'real' equivalence. If you need double precision, change float to double.
    float a[2]; // Arrays in C++ are 0-indexed
    float b[2];
    
    // Assuming some values for a as your Fortran code does not initialize 'a'. 
    // You can assign values to 'a' as per your need.
    a[0] = -3.5f; 
    a[1] = 4.5f;

    for (int i = 0; i < 2; i++) {
        b[i] = std::abs(a[i]);
    }

    // Optional: Printing the contents of array b to verify results
    for (int i = 0; i < 2; i++) {
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }

    return 0;
}