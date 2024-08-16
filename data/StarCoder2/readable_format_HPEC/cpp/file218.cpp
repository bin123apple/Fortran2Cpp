#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is int for this example
void print_array(int n, int** path) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(DATA_PRINTF_MODIFIER) << path[j][i] << " ";

            // Check if we need to insert a newline character
            if ((i * n + j + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    const int n = 4; // Example size
    int** path = new int*[n];

    // Initialize the path array
    for (int i = 0; i < n; ++i) {
        path[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            path[i][j] = i * n + j + 1; // Example values
        }
    }

    // Print the array
    print_array(n, path);

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] path[i];
    }
    delete[] path;

    return 0;
}
