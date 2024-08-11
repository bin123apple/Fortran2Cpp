#include <iostream>
#include <cstring> // For strlen
#include <cstdlib> // For abort

// Forward declaration of the subroutine
void T(char A[], char B[], int lenA, int lenB);

int main() {
    char A[11]; // In C++, arrays are 0-indexed, and for a 10 character string, we need space for the null terminator
    char B[9];  // Similarly, for an 8 character string
    strcpy(A, "gfortran  "); // Copying the strings into the character arrays
    strcpy(B, "rocks!");    // Note: Unlike Fortran, C++ automatically appends the null terminator
    
    T(A, B, 10, 8); // Passing the strings and their intended fixed lengths to the subroutine
    
    return 0;
}

void T(char A[], char B[], int lenA, int lenB) {
    // Checking the length of the strings against their intended fixed lengths
    // Note: strlen returns the length of the string up to the first null terminator, not including it
    if(strlen(A) != lenA) abort();
    if(strlen(B) != lenB) abort();
}