#include <iostream>
#include <vector>

// Assuming DATA_TYPE is a placeholder for some data type, e.g., int, float, double.
// Replace it with the actual data type you're using.
using DATA_TYPE = int; // Example data type

void print_array(int maxgrid, std::vector<std::vector<DATA_TYPE>>& path) {
    // Assuming DATA_PRINTF_MODIFIER is a format specifier for output, e.g., "%d" for integers.
    // Replace it with the actual format specifier you're using.
    const char* DATA_PRINTF_MODIFIER = "%d"; // Example format specifier

    for (int i = 0; i < maxgrid; ++i) {
        for (int j = 0; j < maxgrid; ++j) {
            // Printing the element at path[i][j] using the format specifier
            std::cout << path[j][i] << " ";

            // Checking the condition and printing a newline if necessary
            if (((i * maxgrid) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl; // Newline after each row
    }
    std::cout << std::endl; // Final newline
}

int main() {
    // Example usage
    int maxgrid = 5; // Example size
    std::vector<std::vector<DATA_TYPE>> path(maxgrid, std::vector<DATA_TYPE>(maxgrid));

    // Initialize path with some values for demonstration
    for (int i = 0; i < maxgrid; ++i) {
        for (int j = 0; j < maxgrid; ++j) {
            path[i][j] = i * maxgrid + j; // Example initialization
        }
    }

    print_array(maxgrid, path);

    return 0;
}
