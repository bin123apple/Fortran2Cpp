#include <iostream>
#include <iomanip>

void banner(int ivery, int iverm, int iverd) {
    // Line 101
    std::cout << "********************************************************" << std::endl;

    // Line 102
    std::cout << "******************       GOTIC2       ******************" << std::endl;

    // Line 103
    std::cout << "****************** Version "
              << std::setw(4) << ivery << '.'
              << std::setfill('0') << std::setw(2) << iverm << '.'
              << std::setw(2) << iverd
              << " ******************" << std::endl;

    // Reset fill character to space (default)
    std::cout << std::setfill(' ');

    // Line 101 again
    std::cout << "********************************************************" << std::endl;

    // Line 104
    std::cout << " " << std::endl;
}

int main() {
    // Example call to banner function with version numbers
    banner(2023, 4, 15);

    return 0;
}