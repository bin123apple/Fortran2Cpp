#include <iostream>
#include <omp.h>

void foo(int &r);

int main() {
    int r = 0;
    foo(r);

    if (r == 11) {
        std::cout << "Test passed, r = " << r << std::endl;
    } else {
        std::cerr << "Test failed, r = " << r << std::endl;
        return 1; // Indicate an error
    }

    return 0; // Indicate success
}

void foo(int &r) {
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp parallel for reduction(+:r)
            for (int i = 1; i <= 10; ++i) {
                r = r + 1;
            }
            r = r + 1;
        }
    }
}