#include <iostream>
#include <iomanip>

void printArray(int n, double* a) {
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(10) << std::setprecision(5) << a[i];
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    int n = 10; // replace with your desired array size
    double a[n]; // replace with your desired array values

    // initialize array values
    for (int i = 0; i < n; i++) {
        a[i] = i * 1.2345; // replace with your desired array values
    }

    printArray(n, a);

    return 0;
}
