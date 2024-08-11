#include <iostream>

class X {
public:
    int i;
    X() : i(1) {} // Constructor to initialize i with 1
};

int main() {
    X y; // Create an instance of class X
    std::cout << y.i << std::endl; // Print the value of i
    return 0;
}