#include <iostream>
#include <cstdlib> // For abort()

void foo(int* v) {
    v[0] = 2; // Arrays in C++ are 0-based
}

int main() {
    int i[1];
    i[0] = 1; // Initialize the first (and only) element of the array
    
    // The 'associate' construct does not have a direct equivalent in C++.
    // We directly pass the array to the function.
    foo(i);
    
    // Check the condition and call abort if it is true
    if (i[0] != 2) {
        std::abort();
    }
    
    return 0;
}