#include <iostream>
#include <iomanip>

void print_array(int n, double* y) {
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(10) << y[i];
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    int n = 10; // replace with your desired value of n
    double y[n] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}; // replace with your desired values of y
    print_array(n, y);
    return 0;
}
