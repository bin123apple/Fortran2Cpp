#include <iostream>

// Function declaration
int f() {
    return 42;
}

int main() {
    int a;
    a = f(); // Call the function and assign the result to 'a'
    std::cout << a << " " << f() << std::endl; // Print 'a' and the direct call to 'f()'
    return 0;
}