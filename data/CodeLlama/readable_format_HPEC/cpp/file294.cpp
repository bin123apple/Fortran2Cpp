#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is double for this translation
void print_array(int n, double* a) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(6);

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
        if (i % 20 == 19) { // Print a newline every 20 elements
            std::cout << std::endl;
        }
    }
    std::cout << std::endl; // Print a newline at the end
}

int main() {
    // Example usage
    const int size = 100; // Example size
    double array[size] = {0}; // Example array initialization

    // Fill the array with some values (not shown in the original code)
    // For demonstration, let's fill it with sequential values
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }

    print_array(size, array);

    return 0;
}
