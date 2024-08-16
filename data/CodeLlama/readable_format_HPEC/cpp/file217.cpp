#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a placeholder for the actual data type (e.g., int, float, double).
// We'll use double for the example, but you should change it according to your needs.
void print_array(int n, double* w) {
    for (int i = 0; i < n; ++i) {
        // Print the element
        std::cout << w[i] << " ";
        // Add a newline every 20 elements
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl; // Newline at the end
}

int main() {
    // Example usage
    const int n = 100; // Example size
    double w[n]; // Example array, fill with values as needed
    
    // Initialize array with some values (example initialization)
    for (int i = 0; i < n; ++i) {
        w[i] = i; // Example initialization, replace with actual values
    }

    // Call the function
    print_array(n, w);

    return 0;
}
