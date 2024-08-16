#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 2560;
    double sum = 0.0;
    double sum2 = 0.0;

    std::vector<double> a(len);
    std::vector<double> b(len);

    for (int i = 0; i < len; i++) {
        a[i] = i / 2.0;
        b[i] = i / 3.0;
    }

    #pragma omp target teams distribute
    {
        int i2;
        #pragma omp parallel for reduction(+:sum)
        for (i2 = 0; i2 < len; i2 += 256) {
            int i;
            for (i = i2 + 1; i < std::min(i2 + 256, len); i++) {
                sum += a[i] * b[i];
            }
        }
    }

    #pragma omp parallel for reduction(+:sum2)
    for (int i = 0; i < len; i++) {
        sum2 += a[i] * b[i];
    }

    std::cout << "sum = " << int(sum) << "; sum2 = " << int(sum2) << std::endl;

    return 0;
}
