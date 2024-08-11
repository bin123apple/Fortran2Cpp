#include <iostream>

float square(float x) {
    return x * x;
}

int main() {
    float number = 4.0;
    float result = square(number);
    std::cout << "The square of " << number << " is " << result << std::endl;
    return 0;
}