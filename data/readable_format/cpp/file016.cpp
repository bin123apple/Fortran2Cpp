#include <iostream>

// Declaration of the function to print Hello, World!
void sayHello() {
    std::cout << "Hello, World!" << std::endl;
}

// Declaration and definition of the function to square a number
int square(int x) {
    return x * x;
}

int main() {
    sayHello();
    std::cout << "The square of 5 is " << square(5) << std::endl;
    return 0;
}