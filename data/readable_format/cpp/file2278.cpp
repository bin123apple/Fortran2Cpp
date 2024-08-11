#include <iostream>

namespace h5global {
    // Declare global variables
    extern int h5p_default_f;
    extern int h5p_flags;

    // Ensure h5p_flags and h5p_default_f refer to the same memory location
    union {
        int h5p_flags;
        int h5p_default_f;
    } h5p_equiv;
}

// Define the global variables
int h5global::h5p_default_f;
int h5global::h5p_flags;

int main() {
    // Example usage
    h5global::h5p_equiv.h5p_default_f = 42;
    std::cout << "h5p_default_f: " << h5global::h5p_equiv.h5p_default_f << std::endl;
    std::cout << "h5p_flags: " << h5global::h5p_equiv.h5p_flags << std::endl;

    return 0;
}