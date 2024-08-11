#include <iostream>
#include <cmath>

namespace complexity {
    float g(float x, float y) {
        return (x*x*x*x*x*x + y*y*y*y);
    }
}

int main() {
    float x = 2.0f, y = 3.0f;
    float result = complexity::g(x, y);
    std::cout << "Result of g(" << x << ", " << y << "): " << result << std::endl;

    if (std::abs(result - 67.0f) < 0.001f) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed." << std::endl;
    }

    return 0;
}