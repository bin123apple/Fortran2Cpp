#include <iostream>

union Equiv {
    int a[3];
    int b;
};

int main() {
    volatile Equiv equiv; // volatile keyword added to the union
    // Access equiv.a[0], equiv.a[1], equiv.a[2] or equiv.b as needed

    // Example usage
    equiv.a[0] = 1;
    equiv.a[1] = 2;
    equiv.a[2] = 3;

    std::cout << "equiv.b: " << equiv.b << std::endl;
    std::cout << "equiv.a[0]: " << equiv.a[0] << std::endl;
    std::cout << "equiv.a[1]: " << equiv.a[1] << std::endl;
    std::cout << "equiv.a[2]: " << equiv.a[2] << std::endl;

    return 0;
}