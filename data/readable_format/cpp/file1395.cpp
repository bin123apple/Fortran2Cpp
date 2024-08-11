#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>

float SLAPY3(float x, float y, float z) {
    float xabs = std::abs(x);
    float yabs = std::abs(y);
    float zabs = std::abs(z);
    float w = std::max({xabs, yabs, zabs});
    if (w == 0.0f) {
        return 0.0f;
    } else {
        return w * std::sqrt(std::pow(xabs / w, 2) + std::pow(yabs / w, 2) + std::pow(zabs / w, 2));
    }
}

int main() {
    assert(std::abs(SLAPY3(3.0f, 4.0f, 0.0f) - 5.0f) < 1e-6);
    std::cout << "SLAPY3(3, 4, 0) passed" << std::endl;
    
    assert(std::abs(SLAPY3(1.0f, 1.0f, 1.0f) - std::sqrt(3.0f)) < 1e-6);
    std::cout << "SLAPY3(1, 1, 1) passed" << std::endl;
    
    assert(std::abs(SLAPY3(0.0f, 0.0f, 0.0f)) < 1e-6);
    std::cout << "SLAPY3(0, 0, 0) passed" << std::endl;
    
    assert(std::abs(SLAPY3(-5.0f, -12.0f, -13.0f) - std::sqrt(std::pow(-5.0f, 2) + std::pow(-12.0f, 2) + std::pow(-13.0f, 2))) < 1e-6);
    std::cout << "SLAPY3(-5, -12, -13) passed" << std::endl;
    
    std::cout << "All tests passed successfully." << std::endl;
    
    return 0;
}