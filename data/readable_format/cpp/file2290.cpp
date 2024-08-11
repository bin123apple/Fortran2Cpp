#include <iostream>
#include <array>

// Function declaration
int f();

int main() {
    std::array<int, 3> a;
    int value = f();

    // Assign the value of f to all elements of the array
    a.fill(value);

    // Print the array elements
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

// Function definition
int f() {
    return 42;
}