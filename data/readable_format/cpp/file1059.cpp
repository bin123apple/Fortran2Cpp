#include <iostream>

int bar(int a, int b) {
    return a + b;
}

int main() {
    // Example usage
    std::cout << "The result of bar(5, 3) is: " << bar(5, 3) << std::endl;
    return 0;
}