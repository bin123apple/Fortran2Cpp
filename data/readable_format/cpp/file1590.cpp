// calculation_module.cpp
#include <iostream>

void compute_values(int& i, int& j) {
    i = i + 2 + 3; // Assuming i is initialized before calling this function
    j = 1 + 2 * 3;
    i = (i + 1) * 2;
}

int main() {
    int i = 0; // Initialize i here for consistency with Fortran example
    int j;
    compute_values(i, j);
    
    if (i == 10 && j == 7) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed. i: " << i << " j: " << j << std::endl;
    }
    
    return 0;
}