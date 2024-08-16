#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is int for this example
void print_array(int n, int* outArray) {
    for (int i = 0; i < n; ++i) {
        std::cout << std::setw(DATA_PRINTF_MODIFIER) << outArray[i]; // Adjust width as needed
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
}

// Example usage
int main() {
    const int n = 5;
    int array[n] = {1, 2, 3, 4, 5};
    print_array(n, array);
    return 0;
}
