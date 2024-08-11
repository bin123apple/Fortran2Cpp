#include <iostream>
#include <cmath>
#include <cstddef>

int IDAMAX(std::size_t N, const double* DX, int INCX);

int main() {
    std::cout << "C++ Tests:" << std::endl;
    double DX[] = {-1.0, 2.0, -3.0, 4.0, -5.0};
    int result;

    result = IDAMAX(5, DX, 1);
    std::cout << "Test case 1: " << result << std::endl;

    result = IDAMAX(1, DX, 1);
    std::cout << "Test case 2: " << result << std::endl;

    result = IDAMAX(5, DX, -1);
    std::cout << "Test case 3: " << result << std::endl;

    result = IDAMAX(0, DX, 1);
    std::cout << "Test case 4: " << result << std::endl;

    result = IDAMAX(3, DX, 2);
    std::cout << "Test case 5: " << result << std::endl;

    return 0;
}

int IDAMAX(std::size_t N, const double* DX, int INCX) {
    if (N < 1 || INCX <= 0) {
        return 0;
    }

    int IDAMAX = 1;
    if (N == 1) {
        return IDAMAX;
    }

    std::size_t IX = 0;
    double DMAX = std::abs(DX[0]);
    for (std::size_t I = 1; I < N; ++I) {
        IX += INCX;
        if (std::abs(DX[IX - 1]) > DMAX) {
            IDAMAX = I + 1;
            DMAX = std::abs(DX[IX - 1]);
        }
    }

    return IDAMAX;
}