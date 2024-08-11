#include <iostream>
#include <iomanip>

int main() {
    // Set format for floating-point numbers to scientific notation
    // with 2 digits after the decimal point
    std::cout << std::scientific << std::setprecision(2);
    // Print the number 3.0 using the specified format
    std::cout << 3.0 << std::endl;

    return 0;
}