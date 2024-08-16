#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    double getSum = 0.0;

    std::vector<std::vector<double>> u(len, std::vector<double>(len, 0.5));

    #pragma omp parallel for private(double temp, int i, int j)
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            double temp = u[i][j];
            getSum += temp * temp;
        }
    }

    std::cout << "sum = " << getSum << std::endl;

    return 0;
}
