#include <iostream>

int main() {
    int x = 10;
    int& y = x; // y is now an alias for x
    std::cout << "The value of y is: " << y << std::endl;
    return 0;
}