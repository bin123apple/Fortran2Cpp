#include <iostream>
#include <cassert>

float square(float x) {
    return x * x;
}

int main() {
    float result = square(2.0f);
    std::cout << "Square of 2 is " << result << std::endl;
    assert(result == 4.0f); // Simple assertion to serve as a "unit test"
    std::cout << "Test passed." << std::endl;
    return 0;
}