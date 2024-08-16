#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int i, len;
    double dp = 1.0;
    std::vector<double> a;

    len = 100;
    a.resize(len);

    for (i = 1; i <= len; i++) {
        a[i - 1] = (double(i) / 2.0);
    }

    #pragma omp target teams num_teams(2)
    {
        a[49] = a[49] * 2.0;
    }

    std::cout << "a(50) = " << a[49] << std::endl;

    return 0;
}
