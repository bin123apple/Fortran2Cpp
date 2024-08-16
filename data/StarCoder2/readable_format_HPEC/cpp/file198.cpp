#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is int for this example
void print_array(int ni, int** c) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            // Print the element with a specified format
            std::cout << std::setw(DATA_PRINTF_MODIFIER); // Assuming DATA_PRINTF_MODIFIER is a width for std::setw
            std::cout << c[j][i] << " "; // Note the change in array indexing

            // Check if a new line should be printed
            if ((i * ni + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl; // Additional new line at the end
}

// Example usage
int main() {
    const int ni = 4; // Example size
    int** c = new int*[ni]; // Dynamically allocate the array

    // Initialize the array with some values
    for (int i = 0; i < ni; ++i) {
        c[i] = new int[ni];
        for (int j = 0; j < ni; ++j) {
            c[i][j] = i * ni + j; // Example values
        }
    }

    print_array(ni, c); // Call the function

    // Clean up the dynamically allocated memory
    for (int i = 0; i < ni; ++i) {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
