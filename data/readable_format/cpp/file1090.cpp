#include <iostream>
#include <cstdint> // For std::intptr_t

struct descr {
    void* address; // Equivalent to type(C_PTR) in Fortran
};

int main() {
    double buf[1] = {0}; // Equivalent to double precision, target :: buf(1)
    descr DD;
    DD.address = static_cast<void*>(buf); // Equivalent to c_loc in Fortran
    
    // The `reinterpret_cast` is used for converting pointer types to integer types for comparison
    std::intptr_t i = reinterpret_cast<std::intptr_t>(DD.address);
    std::intptr_t j = reinterpret_cast<std::intptr_t>(buf);
    
    // In C++, there's no direct equivalent to Fortran's STOP. We use return with a non-zero value to indicate error.
    if (i == 0 || j == 0) {
        std::cerr << "Null pointer encountered." << std::endl;
        return 1;
    }

    if (i != j) {
        std::cerr << "Pointers do not match." << std::endl;
        return 2;
    }

    // If everything is okay, return 0.
    return 0;
}