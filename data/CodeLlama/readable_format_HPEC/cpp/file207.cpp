#include <iostream>

// Define the type of the elements in the array
using DATA_TYPE = double;

// Function to initialize the array
void init_array(int n, DATA_TYPE** a) {
    // Loop through rows
    for (int i = 0; i < n; ++i) {
        // Loop through columns
        for (int j = 0; j < n; ++j) {
            // Calculate the value and assign it to the array
            a[i][j] = ((static_cast<DATA_TYPE>(i) - 1) * (static_cast<DATA_TYPE>(j + 1)) + 2.0) / n;
        }
    }
}

int main() {
    // Example usage
    const int n = 3; // Size of the array

    // Allocate memory for the 2D array
    DATA_TYPE** a = new DATA_TYPE*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new DATA_TYPE[n];
    }

    // Initialize the array
    init_array(n, a);

    // Print the array to verify the initialization
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Clean up the allocated memory
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
