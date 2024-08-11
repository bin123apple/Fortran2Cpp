#include <iostream>
#include <iomanip> // for std::setprecision

int main() {
    // Equivalent of dimension and initialization of nums and data
    int nums[] = {12, 34};
    float data[] = {1.2f, 3.4f};

    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(1);

    // Writing data array with format equivalent to Fortran's (f3.1,x,f3.1)
    std::cout << data[0] << " " << data[1] << std::endl;

    // Writing nums array with format equivalent to Fortran's (i3,x,i3)
    // Note: C++ does not have a direct equivalent for Fortran's format specifiers,
    // especially for numeric field width and error handling in I/O operations.
    // Error handling (e.g., for output operations failing) is also generally
    // handled differently in C++ and would typically involve exceptions or
    // checking stream state flags rather than a goto-style error label.
    std::cout << std::setw(3) << nums[0] << " " << std::setw(3) << nums[1] << std::endl;

    return 0;
}