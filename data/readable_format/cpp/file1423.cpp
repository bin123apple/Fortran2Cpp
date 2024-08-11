#include <iostream>

// Function prototype declaration
float f(float x);

int main() {
    float a, b;
    a = 2;
    b = f(a);
    // If you need to use the value of b, you can print it or use it as needed.
    std::cout << "b = " << b << std::endl;
    return 0;
}

// Function definition
float f(float x) {
    x = 1; // This line changes the local copy of x to 1.
    return x; // Returns the modified value of x.
}