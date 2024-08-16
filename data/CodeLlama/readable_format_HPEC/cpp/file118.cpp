#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len, 0)); // Initialize a 2D vector with size len x len

    #pragma omp parallel for collapse(2) ordered(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + 1;
            #pragma omp ordered depend(sink:i-1,j) depend(sink:i,j-1)
            std::cout << "test i = " << i+1 << "  j = " << j+1 << std::endl; // +1 to match Fortran's 1-based indexing
            #pragma omp ordered depend(source)
        }
    }

    return 0;
}
