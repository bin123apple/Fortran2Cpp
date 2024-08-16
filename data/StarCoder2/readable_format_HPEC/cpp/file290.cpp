#include <iostream>

void print_array(int n, int* a) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    int n = 5; // Size of the array
    int a[] = {1, 2, 3, 4, 5}; // Example array

    print_array(n, a);

    return 0;
}
