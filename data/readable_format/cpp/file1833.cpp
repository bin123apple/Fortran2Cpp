#include <iostream>

int factorial(int n);

int main() {
    int number;
    std::cout << "Enter a number:" << std::endl;
    std::cin >> number;

    int result = factorial(number);

    std::cout << "The factorial of " << number << " is " << result << std::endl;

    return 0;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}