#include <iostream>

// A simple function to print a __int128 integer.
// Note: This is a basic implementation and might not cover all edge cases.
void print_int128(__int128 i) {
    if (i < 0) {
        std::cout << '-';
        i = -i;
    }
    if (i / 10) {
        print_int128(i / 10);
    }
    std::cout << char('0' + i % 10);
}

int main() {
    __int128 int128_var = 42; // Assigning a value directly to a __int128 variable.

    // Basic operation
    int128_var += 10; // Adding 10 to our __int128 variable

    // Since there's no direct std::cout support for __int128, we use a helper function to print it.
    std::cout << "Int128 Var: ";
    print_int128(int128_var);
    std::cout << std::endl;

    return 0;
}