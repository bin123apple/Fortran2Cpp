#include <iostream>
#include <vector>
#include <omp.h>

void foo(std::vector<int>& a) {
    #pragma omp parallel for
    for(int i = 0; i < 30; ++i) {
        if ((i + 1) % 2 == 0) { // Fortran is 1-based index
            a[i] = 5;
        } else if (i + 1 <= 15) { // Adjusting condition to match Fortran's 1-based indexing
            a[i] = 2;
        } else {
            a[i] = 1;
        }
    }
}

int main() {
    std::vector<int> a(30); // Initialize array
  
    foo(a);
  
    std::cout << "C++ Stdout: Testing array modifications." << std::endl;
    for(int i = 0; i < 30; ++i) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    return 0;
}