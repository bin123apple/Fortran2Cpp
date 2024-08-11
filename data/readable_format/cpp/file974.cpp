#include <cstdlib> // For abort()
#include <cstring> // For strcmp()
#include <iostream>

int main() {
    // Equivalent to INTEGER(KIND=8) in Fortran
    long long arr[3];

    // Equivalent to CHARACTER(len=6) in Fortran
    char carr[3][7]; // Extra space for null terminator in C-style strings

    // Array initializations
    arr[0] = 4; arr[1] = 42; arr[2] = 12;
    if (arr[0] != 4 || arr[1] != 42 || arr[2] != 12) std::abort();
    
    arr[0] = 4; arr[1] = 42; arr[2] = 12;
    if (arr[0] != 4 || arr[1] != 42 || arr[2] != 12) std::abort();
    
    arr[0] = 4; arr[1] = 42; arr[2] = 12;
    if (arr[0] != 4 || arr[1] != 42 || arr[2] != 12) std::abort();

    arr[0] = 4; arr[1] = 42; arr[2] = 12;
    if (arr[0] != 4 || arr[1] != 42 || arr[2] != 12) std::abort();

    // Character array initialization
    strncpy(carr[0], "foo", 6); carr[0][6] = '\0'; // Ensure null termination
    strncpy(carr[1], "foob", 6); carr[1][6] = '\0'; // Truncating "foobar" to "foob" to fit 6 characters including null terminator
    strncpy(carr[2], "xyz", 6); carr[2][6] = '\0';

    // Character array checks
    if (strcmp(carr[0], "foo") != 0 || strcmp(carr[1], "foob") != 0 || strcmp(carr[2], "xyz") != 0) {
        std::abort();
    }

    return 0;
}