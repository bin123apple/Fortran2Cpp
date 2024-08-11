#include <iostream>

int fact(int n) {
    if (n <= 1) return 1;
    else return n * fact(n - 1);
}

int main() {
    int num, result;

    std::cout << "Enter a number: ";
    std::cin >> num;

    result = fact(num);

    std::cout << "The factorial of " << num << " is " << result << std::endl;

    return 0;
}