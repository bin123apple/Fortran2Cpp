#include <iostream>

// Assuming DATA_TYPE is int for this example
// Adjust the type and format as necessary
void print_array(int ni, int nj, int** c) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            // Adjust the format specifier as necessary
            std::cout << c[j][i] << " ";
            if ((i * ni + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    int ni = 3; // Number of columns
    int nj = 2; // Number of rows
    int** c = new int*[nj]; // Dynamically allocate 2D array
    
    // Initialize the array with some values
    for (int i = 0; i < nj; ++i) {
        c[i] = new int[ni];
        for (int j = 0; j < ni; ++j) {
            c[i][j] = i * ni + j; // Example values
        }
    }
    
    // Call the function
    print_array(ni, nj, c);
    
    // Clean up
    for (int i = 0; i < nj; ++i) {
        delete[] c[i];
    }
    delete[] c;
    
    return 0;
}
