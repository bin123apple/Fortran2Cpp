#include <iostream>
#include <vector>

// Assuming DATA_TYPE is float for this example, but you can change it to any type
// For example, if DATA_TYPE is double, change float to double
template<typename T>
void print_array(int n, const std::vector<T>& y) {
    for (int i = 0; i < n; ++i) {
        std::cout << y[i];
        if (i % 20 == 0 && i != 0) {
            std::cout << std::endl;
        }
    }
}

int main() {
    // Example usage
    int n = 100; // Example size
    std::vector<float> y(n); // Create a vector of size n
    
    // Fill the vector with some values (example)
    for (int i = 0; i < n; ++i) {
        y[i] = static_cast<float>(i); // Example initialization
    }

    print_array(n, y); // Call the function to print the array

    return 0;
}
