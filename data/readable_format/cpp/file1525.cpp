#include <iostream>

int calculateFactorial(int n) {
    int result = 1;
    while (n > 1) {
        result *= n;
        n -= 1;
    }
    return result;
}

int main() {
    int n = 5; // Example input
    std::cout << "Factorial of " << n << " is " << calculateFactorial(n) << std::endl;
    return 0;
}