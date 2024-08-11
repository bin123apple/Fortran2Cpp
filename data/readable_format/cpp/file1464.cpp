#include <iostream>
#include <vector>

std::vector<int> fun(int n);

int main() {
    std::vector<int> b(2); // Vector of size 2, equivalent to dimension(2) in Fortran
    b = fun(b.size()); // Populate b using the fun function
    
    // Check the condition as in the Fortran code
    if (b[0] != 1 || b[1] != 2) {
        std::cerr << "Error condition met, stopping." << std::endl;
        exit(1); // Equivalent to STOP 1 in Fortran
    }
    
    return 0;
}

// Translating the pure function fun from Fortran
std::vector<int> fun(int n) {
    std::vector<int> result(n); // Result vector of size n
    
    // Populate the result vector
    for (int i = 0; i < n; ++i) {
        result[i] = i + 1; // Note: C++ uses 0-based indexing, hence i + 1
    }
    
    return result;
}