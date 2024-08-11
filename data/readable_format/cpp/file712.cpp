#include <cassert>
#include <iostream>

double square(double x) {
    return x * x;
}

int main() {
    double number = 2.0;
    double result = square(number);

    assert(result == 4.0); // Simple assertion for demonstration
    
    std::cout << "Test passed: The square of " << number << " is " << result << std::endl;

    return 0;
}