// square.cpp
#include <iostream>
#include <cassert> // For assert

// Function prototype
float square(float x);

int main() {
    float number = 4.0f;
    float result = square(number);
    std::cout << "Square of " << number << " is " << result << std::endl;
    
    // Simple unit test
    assert(square(2.0f) == 4.0f); // This should pass
    assert(square(-3.0f) == 9.0f); // This should also pass
    
    std::cout << "All tests passed." << std::endl;
    return 0;
}

// Function definition
float square(float x) {
    return x * x;
}