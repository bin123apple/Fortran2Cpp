#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int j = 0;
    std::vector<int> a(10, 10); // Initialize a vector of size 10 with all elements set to 10
    std::vector<int> b(10, 0);  // Initialize a vector of size 10 with all elements set to 0

    #pragma omp parallel
    {
        int j_private = 0;
        #pragma omp for
        for (int i = 0; i < 10; ++i) {
            j_private = j_private + 1;
            b[i] = a[i] * 2;
        }
        
        #pragma omp critical
        j += j_private;
    }

    std::cout << j << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}