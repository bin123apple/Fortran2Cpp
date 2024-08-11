#include <iostream>

int square(int n) {
    return n * n;
}

int main() {
    int number = 4;
    int result = square(number);
    std::cout << "The square of " << number << " is " << result << std::endl;
    return 0;
}