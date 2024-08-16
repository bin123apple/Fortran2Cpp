#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a double for this example
void print_array(double* y, int ny) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < ny; ++i) {
        std::cout << y[i] << " ";
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    double array[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    int size = sizeof(array) / sizeof(array[0]);

    print_array(array, size);

    return 0;
}
