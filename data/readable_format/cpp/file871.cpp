#include <iostream>

// Function prototype
void sub(int* a, int n);

int main() {
    const int n = 10;
    int a[n];

    std::cout << "This is a test." << std::endl;

    sub(a, n); // Call the function to modify the array

    // Print the modified array
    for(int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

// Function definition
void sub(int* a, int n) {
    for(int i = 0; i < n; i++) {
        a[i] = i + 1; // +1 to match Fortran's 1-based indexing
    }
}