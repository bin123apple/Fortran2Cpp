// main.cpp
#include <iostream>
#include <cmath>
#include <cassert>

const float pi32 = 4 * std::atan(1.0f);
const double pi64 = 4 * std::atan(1.0);

template<typename T>
void timestwo(T& a) {
    a = 2 * a;
}

void testTimestwo() {
    float a32 = 1.0f;
    double a64 = 1.0;
    timestwo(a32);
    timestwo(a64);
    assert(std::abs(a32 - 2.0f) < 1e-6);
    assert(std::abs(a64 - 2.0) < 1e-15);
    std::cout << "Test passed for timestwo with both float and double." << std::endl;
}

int main() {
    testTimestwo();
    return 0;
}