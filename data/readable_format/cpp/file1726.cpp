#include <iostream>

int calculateFactorial(int n) {
    int result = 1;
    for(int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n = 5;
    std::cout << "The factorial of " << n << " is " << calculateFactorial(n) << std::endl;
    return 0;
}