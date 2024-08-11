// Compile with: g++ -o square square.cpp
#include <iostream>

int square(int n) {
    return n * n;
}

int main() {
    int x = 4;
    int result = square(x);
    std::cout << "Square of " << x << " is " << result << std::endl;
    return 0;
}