#include <iostream>
#include <cmath>

void print_rescale(double a) {
    const double POWERVAL = 0.25;
    std::cout << a << " gives " << std::pow(a, POWERVAL) << std::endl;
}

int main() {
    for (int i = 1; i <= 9; ++i) {
        double a = i / 10.0;
        print_rescale(a);
    }
    return 0;
}