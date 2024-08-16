#include <iostream>
#include <vector>
#include <cstdio> // For printf

// Assuming DATA_TYPE is double and DATA_PRINTF_MODIFIER is a format string
void print_array(const std::vector<double>& output) {
    for (const auto& elem : output) {
        printf(DATA_PRINTF_MODIFIER, elem); // Using printf for formatted output
    }
    std::cout << std::endl; // Newline after printing the array elements
}

int main() {
    // Example usage
    std::vector<double> myArray = {1.2, 3.4, 5.6};
    print_array(myArray);
    return 0;
}
