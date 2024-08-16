#include <iostream>
#include <omp.h>

int main() {
    const int len = 100;
    int a[len][len];

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskloop
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < len; ++j) {
                    a[i][j] = a[i][j] + 1;
                }
            }
        }
    }

    std::cout << "a[50][50] = " << a[50][50] << std::endl;

    return 0;
}
