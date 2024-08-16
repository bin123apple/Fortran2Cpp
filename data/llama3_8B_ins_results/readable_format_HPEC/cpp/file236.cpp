#include <iostream>
#include <iomanip>

void printArray(int n, double* x1, double* x2) {
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(DATA_PRINTF_MODIFIER) << x1[i];
        std::cout << std::setw(DATA_PRINTF_MODIFIER) << x2[i];
        if ((i - 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    int n = 0; // declare the variable n
    double* x1 = new double[n]; // allocate memory for x1
    double* x2 = new double[n]; // allocate memory for x2

    // initialize x1 and x2

    printArray(n, x1, x2);

    delete[] x1; // deallocate memory for x1
    delete[] x2; // deallocate memory for x2

    return 0;
}
