#include <iostream>

int factorial(int n) {
    int result = 1;
    for(int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int number;
    std::cout << "Enter a positive integer: ";
    std::cin >> number;

    if(number < 0) {
        std::cout << "Factorial of a negative number doesn't exist." << std::endl;
    } else {
        int result = factorial(number);
        std::cout << "Factorial of " << number << " is " << result << std::endl;
    }

    return 0;
}