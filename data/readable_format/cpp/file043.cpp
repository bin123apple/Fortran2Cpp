#include <iostream>

// Define the IT_COMPUTE_STRAIN_ATT_BACKWARD function
int IT_COMPUTE_STRAIN_ATT_BACKWARD(int input) {
    return input * input; // Assuming the function squares the input
}

int main() {
    int input = 4;
    int result = IT_COMPUTE_STRAIN_ATT_BACKWARD(input);
    
    std::cout << "Input: " << input << std::endl;
    std::cout << "Squared Result: " << result << std::endl;

    return 0;
}