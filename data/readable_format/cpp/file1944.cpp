#include <iostream>
#include <iomanip>

int main() {
    // Example floating-point number
    double num = 123.456;

    // Set output formatting using iomanip library
    std::cout << std::fixed << std::setprecision(3) << std::setw(10) << num << std::endl;

    return 0;
}