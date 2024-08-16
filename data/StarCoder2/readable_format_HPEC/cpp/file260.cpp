#include <iostream>

// Assuming DATA_TYPE is double and DATA_PRINTF_MODIFIER is "%g"
void print_array(int nx, int ny, double* s, double* q) {
    for (int i = 0; i < ny; ++i) {
        std::cout << s[i] << " ";
        if ((i + 1) % 80 == 0) {
            std::cout << std::endl;
        }
    }

    for (int i = 0; i < nx; ++i) {
        std::cout << q[i] << " ";
        if ((i + 1) % 80 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    int nx = 5; // Number of elements in q
    int ny = 3; // Number of elements in s
    double s[] = {1.1, 2.2, 3.3}; // Example array s
    double q[] = {4.4, 5.5, 6.6, 7.7, 8.8}; // Example array q

    print_array(nx, ny, s, q);

    return 0;
}
