#include <iostream>

// Forward declaration of func2 to make it accessible in main
void func2();

int main() {
    float x = 1.0f; // 'real' in Fortran is typically equivalent to 'float' in C++
    std::cout << "x in main before func2: " << x << std::endl;
    func2();
    // x remains unchanged in main after func2, as C++ has block scope
    std::cout << "x in main after func2: " << x << std::endl;
    return 0;
}

void func2() {
    char x = 'A'; // Character variable, local to func2
    std::cout << "x in func2: " << x << std::endl;
}