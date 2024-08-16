#include <iostream>
#include <iomanip> // For std::setprecision

void print_array(DATA_TYPE*** a, int nr, int nq, int np) {
    // Assuming a is a 3D array dynamically allocated or passed as a pointer to a pointer to a pointer
    std::cout << std::fixed << std::setprecision(2); // Set precision for floating-point output
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nq; ++j) {
            for (int k = 0; k < np; ++k) {
                std::cout << a[k][j][i] << " "; // Print the element
                if ((i + 1) % 20 == 0) {
                    std::cout << std::endl; // New line after every 20 elements
                }
            }
        }
    }
    std::cout << std::endl; // Final new line
}
