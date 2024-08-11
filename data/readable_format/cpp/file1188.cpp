#include <iostream>
#include <cassert>

// Function declarations
void int_sub(int x, int &y);
int int_func(int x);

int main() {
    int x = 5;
    int y;

    // Test the subroutine equivalent
    int_sub(x, y);
    std::cout << "Subroutine result for x = 5: " << y << std::endl;
    assert(y == 6);
    if (y == 6) {
        std::cout << "Subroutine test PASSED" << std::endl;
    } else {
        std::cout << "Subroutine test FAILED" << std::endl;
    }

    // Test the function equivalent
    int result = int_func(x);
    std::cout << "Function result for x = 5: " << result << std::endl;
    assert(result == 6);
    if (result == 6) {
        std::cout << "Function test PASSED" << std::endl;
    } else {
        std::cout << "Function test FAILED" << std::endl;
    }

    return 0;
}

// Function implementations
void int_sub(int x, int &y) {
    y = x + 1;
}

int int_func(int x) {
    return x + 1;
}