#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

// Function prototype
std::vector<float> triple(int n, const std::vector<float>& x);

// Definition of a procedure pointer type
using ProcPointerType = std::function<std::vector<float>(int, const std::vector<float>&)>;

int main() {
    // Create a procedure pointer variable and assign the 'triple' function to it
    ProcPointerType f = triple;
    
    // Test the function pointer directly
    std::vector<float> tres = f(2, {2.0f, 4.0f});
    if (std::abs(tres[0] - 6.0f) > 1E-3) return 1;
    if (std::abs(tres[1] - 12.0f) > 1E-3) return 2;
    
    // Use the function through the pointer again with different parameters
    tres = f(2, {3.0f, 5.0f});
    if (std::abs(tres[0] - 9.0f) > 1E-3) return 3;
    if (std::abs(tres[1] - 15.0f) > 1E-3) return 4;
    
    return 0;
}

// Implement the 'triple' function
std::vector<float> triple(int n, const std::vector<float>& x) {
    std::vector<float> tre(2);
    tre[0] = 3.0f * x[0];
    tre[1] = 3.0f * x[1];
    return tre;
}