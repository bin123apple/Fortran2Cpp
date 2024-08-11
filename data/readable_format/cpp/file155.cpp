#include <iostream>
#include <complex>

int main() {
    // Declare complex numbers
    std::complex<double> zero(0.0, 0.0);
    std::complex<double> one_two(1.0, 2.0);
    
    // Parameters (since const expressions are evaluated at compile time, they are used for parameters)
    const double three = 3.0;
    const double four = three + 1.0;
    std::complex<double> three_four(three, four);
    
    // Write to output
    std::cout << zero << std::endl;
    std::cout << one_two << std::endl;
    std::cout << three_four << std::endl;
    
    return 0;
}