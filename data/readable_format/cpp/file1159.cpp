#include <iostream>
#include <cassert>
#include <cstddef>

// Instead of a namespace, we'll directly define everything in the global scope for simplicity

class myF90Derived {
public:
    void* my_c_ptr; // Equivalent to type(c_ptr)

    myF90Derived() : my_c_ptr(nullptr) {} // Constructor initializes my_c_ptr to null
};

// Equivalent to the Fortran subroutine, a function in C++
extern "C" void sub0() {
    myF90Derived my_f90_type;
    myF90Derived* my_f90_type_ptr = nullptr;

    my_f90_type.my_c_ptr = nullptr;
    std::cout << "my_f90_type is: " << my_f90_type.my_c_ptr << std::endl;

    my_f90_type_ptr = &my_f90_type;
    std::cout << "my_f90_type_ptr is: " << my_f90_type_ptr->my_c_ptr << std::endl;
}

// Main function that also acts as a test driver
int main() {
    // Call sub0 directly, as it already contains print statements demonstrating functionality.
    sub0();

    // Perform a basic check to ensure pointers are initialized to nullptr.
    myF90Derived instance;
    assert(instance.my_c_ptr == nullptr);
    std::cout << "C++ Test passed: my_c_ptr is correctly initialized to nullptr." << std::endl;

    return 0;
}