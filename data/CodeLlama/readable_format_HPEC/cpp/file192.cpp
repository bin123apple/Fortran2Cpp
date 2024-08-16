#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a type alias for float or double, and DATA_PRINTF_MODIFIER is a format string
// For simplicity, we'll use float and a simple format string for the output

void print_array(int n, float a[n][n]) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(6);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Print the element in the specified format
            std::cout << a[j][i] << " ";

            // Check if we need to insert a newline after every 20 elements
            if ((i * n + j) % 20 == 0 && i != 0 && j != 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl; // Newline after each row
    }
    std::cout << std::endl; // Newline after the entire array
}

int main() {
    // Example usage
    const int n = 4;
    float a[n][n] = {
        {1.0, 2.0, 3.0, 4.0},
        {5.0, 6.0, 7.0, 8.0},
        {9.0, 10.0, 11.0, 12.0},
        {13.0, 14.0, 15.0, 16.0}
    };

    print_array(n, a);

    return 0;
}
