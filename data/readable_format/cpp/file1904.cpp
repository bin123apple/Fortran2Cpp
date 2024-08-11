#include <iostream>
#include <cassert>

void foo(int x[3], int& sum) {
    sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += x[i];
    }
}

int main() {
    int a[3][3];
    
    // Corrected initialization to match Fortran's results
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            a[i][j] = (i + 1) + (j + 1); // Adjusted to match Fortran's 1-based indexing
        }
    }
    
    int sum = 0;
    // Pass the first row of 'a' to 'foo' and calculate sum
    foo(a[0], sum);
    
    std::cout << "Sum of array slice in C++: " << sum << std::endl;
    
    // Unit Test: Verify the sum of the first row of 'a'
    int expected_sum = 9; // For the given initialization, the sum of the first row should be 9.
    assert(sum == expected_sum);

    std::cout << "Test passed: Sum of array slice in C++ is correct." << std::endl;
    
    return 0;
}