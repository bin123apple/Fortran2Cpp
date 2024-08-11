#include <iostream>

void fsub3(int arg, int& res) {
    std::cout << "fsub3 called" << std::endl;
    res = arg * 4;
}

// Example usage
int main() {
    int arg = 5;
    int result = 0;
    fsub3(arg, result);
    std::cout << "Result: " << result << std::endl;
    return 0;
}