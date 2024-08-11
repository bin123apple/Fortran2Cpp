#include <iostream>

double factori(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    } else {
        double result = 1.0;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
}

int main() {
    // Example of using the function
    int number = 5;
    std::cout << "Factorial of " << number << " is " << factori(number) << std::endl;
    return 0;
}