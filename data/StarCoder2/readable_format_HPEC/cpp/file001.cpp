#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len, 0)); // Initialize a 2D vector with size len x len, all elements set to 0

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskloop collapse(2)
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < len; ++j) {
                    a[i][j] = a[i][j] + 1;
                }
            }
        }
    }

    // Print the value of a[50][50] (remembering C++ uses 0-based indexing)
    std::cout << "a[50][50] = " << a[50][50] << std::endl;

    return 0;
}
