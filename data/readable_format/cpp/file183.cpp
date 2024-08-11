#include <iostream>
#include <vector>

// Function prototype
void sub(std::vector<int>& a, int n);

int main() {
    // Declare a vector with 10 elements
    std::vector<int> a(10);

    // Print the initial message
    std::cout << "This is a test." << std::endl;

    // Call the subroutine
    sub(a, 10);

    // Print the modified vector elements
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    // Terminate the program
    return 0;
}

// The subroutine that modifies the vector
void sub(std::vector<int>& a, int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based, hence i+1
    }
}