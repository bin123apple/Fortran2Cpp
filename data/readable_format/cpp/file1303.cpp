#include <cstddef> // for std::size_t

// Assuming we want to keep the function generic, we'll use a template.
// This function accepts a pointer to the first element of the array and its size.
// The size argument isn't used in this particular function, but it's included to demonstrate
// how you might pass array length information to a C++ function, analogous to Fortran's assumed-shape arrays.
template<typename T>
const void* f_loc(T* what, std::size_t size)
{
    // Simply return the address of the first element.
    // In C++, the array name or a pointer to its first element
    // can directly serve as the address.
    return static_cast<const void*>(what);
}

// Example usage
#include <iostream>

int main() {
    int array[] = {10, 20, 30, 40, 50};

    // Getting the address of the first element of the array
    const void* address = f_loc(array, 5);

    // Printing the address
    std::cout << "Address of the first element: " << address << std::endl;

    return 0;
}