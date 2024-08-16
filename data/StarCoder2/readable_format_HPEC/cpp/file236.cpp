#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is double and DATA_PRINTF_MODIFIER is "%.6g" for simplicity
void print_array(int n, double* x1, double* x2) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(6);

    for (int i = 0; i < n; ++i) {
        std::cout << x1[i] << " ";
        std::cout << x2[i] << " ";

        // Newline after every 20 elements or at the end of the array
        if ((i + 1) % 20 == 0 || i == n - 1) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    int n = 5;
    double x1[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double x2[] = {5.5, 4.4, 3.3, 2.2, 1.1};

    print_array(n, x1, x2);

    return 0;
}
