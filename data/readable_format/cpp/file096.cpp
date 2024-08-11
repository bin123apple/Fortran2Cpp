#include <iostream>
#include <cmath> // For pow()

// Declaration of the square function
double square(double num);

int main() {
    double x = 5.0;
    double result = square(x);

    if (result == 25.0) {
        std::cout << "Test passed: The square of " << x << " is " << result << std::endl;
    } else {
        std::cerr << "Test failed" << std::endl;
    }

    return 0;
}

// Definition of the square function
double square(double num) {
    return std::pow(num, 2);
}