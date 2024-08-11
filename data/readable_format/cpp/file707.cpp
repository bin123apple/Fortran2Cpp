#include <iostream>
#include <vector>
#include <omp.h>

// Function prototype is optional since the definition is before main in this case.
int foo(const std::vector<int>& a, std::vector<int>& b, int n);

int main() {
    int n = 5; // Example size
    std::vector<int> a = {1, 2, 3, 4, 5}; // Example input
    std::vector<int> b(n); // Output vector
    
    int result = foo(a, b, n);
    
    std::cout << "Sum: " << result << std::endl;
    std::cout << "B: ";
    for (int i : b) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

// Definition of the foo function.
int foo(const std::vector<int>& a, std::vector<int>& b, int n) {
    int r = 0;
    
    #pragma omp parallel for reduction(+:r) default(none) shared(a, n)
    for (int i = 0; i < n; ++i) {
        r += a[i];
    }
    
    b[0] = a[0];
    for (int i = 1; i < n; ++i) {
        b[i] = b[i - 1] + a[i];
    }
    
    return r;
}