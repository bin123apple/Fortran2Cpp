#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len, 0));

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp for collapse(2)
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    a[i][j]++;
                }
            }
        }
    }

    std::cout << "a(50,50) = " << a[50][50] << std::endl;

    return 0;
}
