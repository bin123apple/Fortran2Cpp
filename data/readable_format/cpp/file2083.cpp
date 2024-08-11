#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

int main() {
    const int N = 1000;
    std::vector<int> a(N); // Using vector for dynamic array allocation
    
    // Filling the array
    for(int i = 0; i < N; ++i) {
        a[i] = i + 1; // Adjusting for 0-based indexing in C++
    }
    
    // Summing the array elements
    int s = 0;
    for(int i = 0; i < N; ++i) {
        s += a[i];
    }
    
    // Checking the sum and determining the result
    int result = 0;
    if(s != 500500) {
        result = -1;
    }
    
    // Outputting the result
    if(result == 0) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
        exit(1); // Exiting with an error code
    }
    
    // No need to explicitly deallocate 'a', as it will be automatically done by the vector destructor
    return 0;
}