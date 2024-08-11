#include <iostream>
#include <array>

int main() {
    std::array<int, 10> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // Optional: Demonstrating the values in the array
    for(int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}