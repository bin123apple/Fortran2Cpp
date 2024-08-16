#include <iostream>
#include <iomanip>

void printArray(int n, double** a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(10) << std::setprecision(6) << a[i][j];
            if ((i * n + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int n = 10; // adjust the value of n as needed
    double** a = new double*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
    }

    // initialize the array a with your data

    printArray(n, a);

    // don't forget to delete the dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
