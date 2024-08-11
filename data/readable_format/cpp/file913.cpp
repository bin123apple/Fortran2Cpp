#include <iostream>
#include <iomanip> // For std::setprecision and std::setw

// Assuming the function is part of a program that includes necessary headers
void writemac(double** mac, int nev, int nevcomplex) {
    // Assuming mac is a dynamically allocated 2D array with dimensions nev x nevcomplex

    std::cout << std::endl;
    std::cout << "Modal Assurance Criterion" << std::endl;
    std::cout << std::endl;

    // Set output formatting
    std::cout << std::fixed << std::setprecision(4);

    for (int i = 0; i < nev; i++) {
        for (int j = 0; j < nevcomplex; j++) {
            std::cout << std::setw(12) << mac[i][j];
        }
        std::cout << std::endl;
    }
}

// Note: The definition of the main function and the allocation/population of the 'mac' array are not included.
// The user must allocate and populate the 'mac' array, as well as deallocate it if it's dynamically allocated.