#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is a type that can be printed, e.g., int, double, etc.
template<typename DATA_TYPE>
void print_array(int m, DATA_TYPE** symmat) {
    // Set output formatting
    std::cout << std::fixed << std::setprecision(2); // Example for double, adjust as needed

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << std::setw(8) << symmat[j][i] << " "; // Adjust width as needed
            if ((i * m + j + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    const int m = 4; // Example size
    double** symmat = new double*[m]; // Dynamic allocation of the 2D array
    
    // Initialize the array with some values
    for (int i = 0; i < m; ++i) {
        symmat[i] = new double[m];
        for (int j = 0; j < m; ++j) {
            symmat[i][j] = i * m + j + 1; // Example values
        }
    }

    print_array(m, symmat); // Call the function

    // Clean up
    for (int i = 0; i < m; ++i) {
        delete[] symmat[i];
    }
    delete[] symmat;

    return 0;
}
