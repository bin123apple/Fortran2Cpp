#include <iostream>
#include <vector>

int main() {
    // Vector for single dimension array (equivalent to integer, allocatable :: i(:))
    std::vector<int> i;

    // Vector of vectors for two-dimensional array (equivalent to integer, allocatable :: j(:,:))
    std::vector<std::vector<int>> j;

    // Check if 'j' vector (2D array) is allocated (actually, if it's empty or not)
    // In C++, an empty vector has been allocated, but has no elements.
    // There's no direct equivalent to Fortran's allocated function for memory allocation check,
    // but we can check if the vector is empty as a proxy.
    std::cout << std::boolalpha << j.empty() << std::endl;

    return 0;
}