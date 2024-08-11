#include <cstdlib> // For abort()

int main() {
    int x[13]; // Array of 13 integers, equivalent to Fortran's x(0:12)
    for (int i = 0; i <= 12; ++i) {
        x[i] = i; // Initialize array elements
    }

    // In C++, pointers can be used to achieve similar semantics to Fortran's pointers.
    // Here, z is a pointer to the first element of x, essentially pointing to the whole array.
    int* z = &x[0]; // or simply, z = x;

    for (int i = 0; i <= 12; ++i) {
        // In C++, array indexing and pointer arithmetic provide similar capabilities to Fortran's array and pointer semantics.
        // The condition checks if the value at the current index or the value pointed by z (which is incremented) is not equal to i.
        if (x[i] != i || z[i] != i) {
            abort(); // Terminate the program if the condition is true.
        }
    }

    return 0; // Successful execution
}