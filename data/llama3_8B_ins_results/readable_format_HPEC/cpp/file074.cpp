#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    int i = 0;
    int j = 0;
    double dp = 1.0;

    std::vector<double> a(len);
    std::vector<double> b(len);
    std::vector<double> c(len);

    for (i = 1; i <= len; i++) {
        a[i-1] = (double(i)/2.0);
        b[i-1] = (double(i)/3.0);
        c[i-1] = (double(i)/7.0);
    }

    #pragma omp parallel for linear(j)
    for (i = 1; i <= len; i++) {
        c[j] += a[i-1] * b[i-1];
        j++;
    }

    //std::cout << "c(50) = " << c[50] << std::endl;

    return 0;
}
