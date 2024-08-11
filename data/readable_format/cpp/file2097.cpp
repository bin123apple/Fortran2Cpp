#include <iostream>
#include <vector>

// Function prototype declaration
void sub(std::vector<int>& a, int n);

int main() {
    std::vector<int> a(10); // Vector initialized with 10 elements

    std::cout << "This is a test." << std::endl;

    // Call the subroutine equivalent in C++
    sub(a, 10);

    // Print the elements of the array
    for(int i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

// The subroutine 'sub' equivalent function in C++
void sub(std::vector<int>& a, int n) {
    for(int i = 0; i < n; i++) {
        a[i] = i + 1; // Adding 1 because Fortran arrays start at 1
    }
}