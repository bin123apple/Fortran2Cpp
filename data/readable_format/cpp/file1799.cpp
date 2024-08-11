#include <iostream>
#include <vector>
#include <string>

int main() {
    int n = 5;

    { // Equivalent to myblock: BLOCK
        std::vector<int> arr(n); // Dynamic array of int with size n

        { // Nested BLOCK
            std::vector<int> arr(2 * n); // Shadows the outer arr
            // This array is only accessible within this block
        } // End of nested BLOCK
        // The inner arr is destroyed here
    } // End of myblock

    { // BLOCK for dynamic allocation
        std::vector<int> alloc_arr(n); // Dynamic array, auto deallocated
    } // End of BLOCK

    { // BLOCK for string manipulation
        std::string str = "123456789";
        str.resize(n); // Resize string to match the character length n
        // Note: The original Fortran code would have a string of length n filled with spaces or truncated to fit,
        // which is why we resize here to mimic setting a length limit on the string.
    } // End of BLOCK

    return 0;
}