#include <iostream>

int main() {
    int n, result;

    std::cout << "Enter a number:" << std::endl;
    std::cin >> n;

    result = 1;
    while (n > 1) {
        result = result * n;
        --n;
    }

    std::cout << "Factorial is: " << result << std::endl;

    return 0;
}