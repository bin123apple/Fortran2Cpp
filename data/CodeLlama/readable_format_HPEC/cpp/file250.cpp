#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is float for this example. Adjust if necessary.
void print_array(const float* y, int ny) {
    for (int i = 0; i < ny; ++i) {
        std::cout << y[i];
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int ny = 100; // Example size
    float y[ny] = {0}; // Initialize array with zeros
    
    // Fill the array with example values
    for (int i = 0; i < ny; ++i) {
        y[i] = static_cast<float>(i); // Example: fill with sequential values
    }

    print_array(y, ny);

    return 0;
}
