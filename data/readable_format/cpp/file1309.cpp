#include <cmath>
#include <iostream>
#include <cstdlib>

float specific_sin_r4(float parm) {
    return std::sin(parm);
}

int main() {
    const float pi = 3.14159265f;
    float input = pi / 6.0f;
    float expected_output = 0.5f;
    float error_threshold = 1.0E-5f;
    
    float result = specific_sin_r4(input);
    std::cout << "Testing specific_sin_r4 with input: " << input << std::endl;
    
    if (std::abs(result - expected_output) < error_threshold) {
        std::cout << "PASS" << std::endl; // Fix applied here
    } else {
        std::cout << "FAIL" << std::endl; // Fix applied here
    }
    
    return 0;
}