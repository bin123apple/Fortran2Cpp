#include <iostream>
#include <cassert>

float square(float x) {
    return x * x;
}

int main() {
    float x = 4.0f;
    float expected = 16.0f;
    float computed = square(x);

    assert(computed == expected); // Simple assertion as a unit test.
    std::cout << "Test passed." << std::endl;

    return 0;
}