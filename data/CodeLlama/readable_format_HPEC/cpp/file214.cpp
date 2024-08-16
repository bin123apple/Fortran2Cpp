#include <iostream>
#include <iomanip> // For std::setprecision if needed

// Assuming DATA_TYPE is float or double for this example
void print_array(int n, DATA_TYPE* x) {
    // Set precision if needed, for example:
    // std::cout << std::fixed << std::setprecision(6);
    
    for (int i = 0; i < n; ++i) {
        std::cout << x[i];
        if (i % 20 == 19) { // Print a newline every 20 elements
            std::cout << std::endl;
        } else {
            std::cout << " "; // Separate elements with spaces
        }
    }
}

// Example usage
int main() {
    int n = 100; // Example size
    DATA_TYPE x[] = {/* initialize with your data */}; // Example array
    
    print_array(n, x);
    
    return 0;
}
