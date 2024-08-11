#include <iostream>

#define NEW

int main() {
    int x = 1;
#ifdef NEW
    // Program A logic
    std::cout << x << std::endl;
#else
    // Program B logic could go here if needed
    std::cout << x << std::endl; // Assuming we want the same output for simplicity
#endif
    return 0;
}