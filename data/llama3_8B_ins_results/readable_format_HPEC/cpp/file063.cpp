#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 1000;
    std::vector<int> a(len);

    for (int i = 0; i < len; i++) {
        a[i] = i + 1; // equivalent to Fortran's a(i) = i
    }

    #pragma omp target teams distribute
    {
        #pragma omp parallel for
        for (int i = 1; i < len; i++) {
            a[i - 1] = a[i] + 1; // equivalent to Fortran's a(i) = a(i+1) + 1
        }
    }

    for (int i = 0; i < len; i++) {
        std::cout << "Values for i and a(i) are: " << i << " " << a[i] << std::endl;
    }

    return 0;
}
