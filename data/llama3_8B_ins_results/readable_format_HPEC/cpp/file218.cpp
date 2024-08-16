#include <iostream>
#include <iomanip>

void printArray(int n, double** path) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(10) << std::setprecision(5) << path[i][j] << " ";
            if ((i * n + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int n = 10; // Change this to your desired size
    double** path = new double*[n];
    for (int i = 0; i < n; i++) {
        path[i] = new double[n];
    }

    // Initialize your array here
    //...

    printArray(n, path);

    // Don't forget to free the memory
    for (int i = 0; i < n; i++) {
        delete[] path[i];
    }
    delete[] path;

    return 0;
}
