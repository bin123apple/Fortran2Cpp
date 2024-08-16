#include <iostream>
#include <iomanip> // For std::setw

void print_array(int n, DATA_TYPE** a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(DATA_PRINTF_WIDTH) << a[j][i] << " ";
            if ((i * n + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    const int n = 4; // Example size
    DATA_TYPE** a = new DATA_TYPE*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new DATA_TYPE[n];
        for (int j = 0; j < n; ++j) {
            a[i][j] = i * n + j; // Example initialization
        }
    }

    print_array(n, a);

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
