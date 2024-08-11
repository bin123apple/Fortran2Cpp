#include <iostream>

// Function prototype
void squareNumber(int inputNumber, int &result);

int main() {
    int myNumber = 5;
    int squareResult;

    // Call the function
    squareNumber(myNumber, squareResult);

    // Output the result
    std::cout << "The square of " << myNumber << " is " << squareResult << "." << std::endl;

    return 0;
}

// Function definition
void squareNumber(int inputNumber, int &result) {
    result = inputNumber * inputNumber;
}