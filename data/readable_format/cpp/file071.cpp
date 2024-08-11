#include <iostream>

int main() {
    int n, result;

    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    result = 1;
    while (n > 0) {
        result *= n;
        --n;
    }

    std::cout << "Factorial is: " << result << std::endl;

    return 0;
}