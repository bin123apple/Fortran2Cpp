#include <iostream>
#include <iomanip>

void print_array(int n, double b[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(10) << std::setprecision(6) << b[j][i];
            if ((i * n + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    int n = 10; // Replace with your desired value of n
    double b[n][n]; // Initialize your array here
    // Fill your array here
    print_array(n, b);
    return 0;
}
