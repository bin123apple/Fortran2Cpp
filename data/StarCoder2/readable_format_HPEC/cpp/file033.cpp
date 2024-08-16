#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int b = 5;
    int len = 1000;
    int error = 0;

    std::vector<int> a(len);

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjusting for 0-based indexing
    }

    #pragma omp parallel shared(b, error)
    {
        #pragma omp parallel
        {
            #pragma omp for
            for (int i = 0; i < len; ++i) {
                a[i] = b + a[i] * 5;
            }
            #pragma omp single
            {
                error = a[9] + 1; // Adjusting for 0-based indexing and accessing the 10th element as in Fortran
            }
        }
    }

    std::cout << "error = " << error << std::endl;

    return 0;
}
