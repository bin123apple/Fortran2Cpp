#include <iostream>
#include <vector>
#include <omp.h>

int main(int argc, char** argv)
{
    int len = 100;
    double getSum = 0.0;
    double temp;

    if (argc == 1) {
        std::cout << "No command line arguments provided.\n";
        return 1;
    }

    len = std::stoi(argv[1]);

    std::vector<std::vector<double>> u(len, std::vector<double>(len, 0.5));

    #pragma omp parallel for private(temp) reduction(+:getSum)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            temp = u[i][j];
            getSum += temp * temp;
        }
    }

    std::cout << "sum = " << getSum << std::endl;

    return 0;
}
