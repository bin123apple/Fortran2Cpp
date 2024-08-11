#include <iostream>
#include <string>
#include <cmath> // For std::pow

// The function prototype (declaration)
std::string makenumberstring(float x);

int main() {
    float inputNumber = 4.0;
    std::string result = makenumberstring(inputNumber);
    std::cout << "The square of " << inputNumber << " as a string is: " << result << std::endl;
    return 0;
}

// The function definition
std::string makenumberstring(float x) {
    int xx = std::pow(x, 2);
    return std::to_string(xx);
}