#include <iostream>
#include <iomanip> // For std::setprecision if needed

// Assuming DATA_TYPE is a type alias for a floating-point type like double
using DATA_TYPE = double;

void print_array(const DATA_TYPE* d, int ni, int nl) {
    // Assuming the 2D array is stored in row-major order as in Fortran
    // and accessed accordingly in C++

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            // Printing the element
            std::cout << d[j * ni + i] << " ";

            // Adding a newline every 20 elements
            if ((i * ni + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl; // Newline after each row
    }
    std::cout << std::endl; // Final newline
}

int main() {
    // Example usage
    const int ni = 5; // Number of columns
    const int nl = 4; // Number of rows
    DATA_TYPE data[ni * nl] = {1.1, 1.2, 1.3, 1.4, 1.5,
                               2.1, 2.2, 2.3, 2.4, 2.5,
                               3.1, 3.2, 3.3, 3.4, 3.5,
                               4.1, 4.2, 4.3, 4.4, 4.5};

    print_array(data, ni, nl);

    return 0;
}
