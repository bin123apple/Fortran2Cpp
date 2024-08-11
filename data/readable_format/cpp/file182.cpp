#include <iostream>
#include <cmath>

int main() {
    // Equivalent of ANINT(1.2)
    std::cout << std::round(1.2) << std::endl;

    // Equivalent of AINT(1.2)
    std::cout << std::trunc(1.2) << std::endl;

    // Equivalent of ATAN(ANINT(1.2))
    std::cout << std::atan(std::round(1.2)) << std::endl;

    // Equivalent of ATAN(AINT(1.2))
    std::cout << std::atan(std::trunc(1.2)) << std::endl;

    return 0;
}