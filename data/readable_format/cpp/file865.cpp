#include <iostream>
#include <cstdint>

// Define the subroutine and global variable with C linkage
extern "C" {
    // Global variable with C linkage
    int32_t my_global_var = 0;

    // Subroutine with C linkage
    void my_f90_sub() {
        my_global_var += 10;
    }
}

// Main function for testing
int main() {
    std::cout << "Initial my_global_var: " << my_global_var << std::endl;

    // Call the subroutine
    my_f90_sub();

    // Test after calling my_f90_sub
    if (my_global_var != 10) {
        std::cerr << "Test failed: Expected my_global_var = 10, got " << my_global_var << std::endl;
        return 1; // Indicate an error
    } else {
        std::cout << "Test passed: my_global_var = " << my_global_var << std::endl;
    }

    return 0; // Success
}