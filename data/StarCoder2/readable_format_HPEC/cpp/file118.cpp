#include <iostream>
#include <omp.h>

int main() {
    const int len = 100;
    int a[len][len];

    #pragma omp parallel for ordered(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + 1;
            #pragma omp ordered depend(sink:i-1,j) depend(sink:i,j-1)
            std::cout << "test i = " << i+1 << "  j = " << j+1 << std::endl;
            #pragma omp ordered depend(source)
        }
    }

    return 0;
}
