#include <iostream>

// Function declaration
int doubleNumber(int inputNumber);

int main() {
    int inputNumber = 4;
    int result = doubleNumber(inputNumber);
    std::cout << "Double of " << inputNumber << " is " << result << std::endl;
    return 0;
}

// Function definition
int doubleNumber(int inputNumber) {
    return 2 * inputNumber;
}