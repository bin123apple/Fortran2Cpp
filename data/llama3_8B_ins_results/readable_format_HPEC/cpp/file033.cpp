#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int i, error, len, b;
    std::vector<int> a;

    b = 5;
    len = 1000;

    a.resize(len);

    #pragma omp parallel shared(b, error)
    {
        #pragma omp for
        for (i = 1; i <= len; i++) {
            a[i-1] = b + a[i-1]*5;
        }

        #pragma omp single
        {
            error = a[9] + 1;
        }
    }

    std::cout << "error = " << error << std::endl;

    a.clear();

    return 0;
}
