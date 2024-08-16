#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is double for this example
using DATA_TYPE = double;

void print_array(int nx, int ny, DATA_TYPE** ex, DATA_TYPE** ey, DATA_TYPE** hz) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(6);

    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            // Print ex, ey, hz in the specified order
            std::cout << ex[j][i] << " ";
            std::cout << ey[j][i] << " ";
            std::cout << hz[j][i] << " ";

            // Check if we need to insert a newline character
            if ((i * nx + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    int nx = 4, ny = 3; // Example dimensions

    // Allocate memory for the arrays
    DATA_TYPE** ex = new DATA_TYPE*[ny];
    DATA_TYPE** ey = new DATA_TYPE*[ny];
    DATA_TYPE** hz = new DATA_TYPE*[ny];

    for (int i = 0; i < ny; ++i) {
        ex[i] = new DATA_TYPE[nx];
        ey[i] = new DATA_TYPE[nx];
        hz[i] = new DATA_TYPE[nx];
    }

    // Initialize arrays with some values for demonstration
    for (int i = 0; i < ny; ++i) {
        for (int j = 0; j < nx; ++j) {
            ex[i][j] = i + j;
            ey[i][j] = i - j;
            hz[i][j] = i * j;
        }
    }

    // Call the function
    print_array(nx, ny, ex, ey, hz);

    // Clean up
    for (int i = 0; i < ny; ++i) {
        delete[] ex[i];
        delete[] ey[i];
        delete[] hz[i];
    }
    delete[] ex;
    delete[] ey;
    delete[] hz;

    return 0;
}
