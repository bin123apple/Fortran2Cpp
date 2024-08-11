#include <iostream>

int main() {
    const float x = 4.0f;
    const float y = 5.0f;
    const float t = 2.0f;
    float v1, v2;
    
    v1 = x / t;
    v2 = y / t;
    
    // If you want to print the results
    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
    
    return 0;
}