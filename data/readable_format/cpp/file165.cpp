#include <iostream>
#include <cmath> // For M_PI and atan()

using std::cout;

// Function prototype
long double timestwo(long double a);

int main() {
    // Set the precision for floating-point types
    constexpr long double pi = 4.0L * atan(1.0L);

    cout << "2pi: " << timestwo(pi) << '\n';

    return 0;
}

// Function definition
long double timestwo(long double a) {
    return 2 * a;
}