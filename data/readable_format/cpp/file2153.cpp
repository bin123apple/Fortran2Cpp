#include <iostream>
#include <array>

// Function to print the array
void bar(const std::array<int, 10>& a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int n = 10;
    std::array<int, n> a;
    
    // Initialize the array
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    // Create a reversed copy of the array
    std::array<int, n> a_reversed;
    for (int i = 0; i < n; ++i) {
        a_reversed[i] = a[n - 1 - i];
    }

    // Call the bar function with the reversed array
    bar(a_reversed, n);

    return 0;
}