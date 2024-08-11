// Compile with: g++ -o square square.cpp -std=c++11
#include <iostream>

float square(float x) {
    return x * x;
}

int main() {
    float number = 4.0;
    float result = square(number);
    std::cout << "Square of " << number << " is " << result << std::endl;
    return 0;
}