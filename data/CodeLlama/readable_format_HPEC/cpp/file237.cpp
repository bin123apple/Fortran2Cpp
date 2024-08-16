#include <iostream>
#include <iomanip> // For std::setprecision if needed

// Assuming DATA_TYPE is a type alias for a data type like int, float, double, etc.
// You need to define DATA_TYPE and DATA_PRINTF_MODIFIER according to your specific needs.
// For simplicity, let's assume DATA_TYPE is int and we'll just use std::cout for output.

void print_array(int n, DATA_TYPE* outArray) {
    for (int i = 0; i < n; ++i) {
        std::cout << outArray[i];
        if (i % 20 == 0 && i != 0) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl; // Newline after the last element
}

// Example usage
int main() {
    const int n = 100; // Example size
    DATA_TYPE outArray[n]; // Example array
    
    // Initialize array with some values (example initialization)
    for (int i = 0; i < n; ++i) {
        outArray[i] = i; // Example initialization
    }

    print_array(n, outArray);

    return 0;
}
