#include <iostream>

// Function that matches the Fortran example
int myFunction(int x) {
    return x * 2;
}

int main() {
    int result = myFunction(5);
    std::cout << "The result is: " << result << std::endl;
    return 0;
}