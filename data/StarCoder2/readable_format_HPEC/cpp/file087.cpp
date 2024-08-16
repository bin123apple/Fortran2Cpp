#include <iostream>
#include <vector>
#include <omp.h>

// Assuming the existence of a function similar to gen_task in the DRB100 library
extern void gen_task(int i);

int main() {
    std::vector<int> a(100);

    #pragma omp parallel
    {
        #pragma omp single
        for (int i = 1; i <= 100; ++i) {
            gen_task(i);
        }
    }

    for (int i = 1; i <= 100; ++i) {
        if (a[i-1]!= i + 1) { // Adjusting index for 0-based array in C++
            std::cout << "warning: a(" << i << ") = " << a[i-1] << " not expected " << i + 1 << std::endl;
        }
//        std::cout << a[i-1] << " " << i + 1 << std::endl;
    }

    return 0;
}
