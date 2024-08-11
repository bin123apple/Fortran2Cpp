#include <iostream>

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num = 5;
    int result = factorial(num);
    std::cout << "Factorial of " << num << " is " << result << std::endl;
    return 0;
}