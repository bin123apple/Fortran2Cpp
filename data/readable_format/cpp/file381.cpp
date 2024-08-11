#include <iostream>

int calculate_factorial(int n) {
    int result = 1;
    for(int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n = 5; // Example number
    std::cout << "Factorial of " << n << " is " << calculate_factorial(n) << std::endl;
    return 0;
}