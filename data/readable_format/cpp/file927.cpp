#include <iostream>
#include <cstdlib> // For exit()

int main() {
    // Declare the 2D arrays. In C++, array indexing starts from 0.
    int x[100][100], y[100][100];

    int result = 0;

    // Initialize x to 0
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            x[i][j] = 0;
        }
    }

    // Set the interior of x to 1
    for (int i = 1; i < 99; ++i) { // Note: i and j start from 1 and go to 98 to match Fortran's 2:99 (Fortran is 1-based)
        for (int j = 1; j < 99; ++j) {
            x[i][j] = 1;
        }
    }

    // Initialize y's columns to 0
    for (int j = 0; j < 100; ++j) { // Entire columns, so no need to adjust for 1-based indexing
        for (int i = 0; i < 100; ++i) {
            y[i][j] = 0;
        }
    }

    // Set the interior of y to 1
    for (int i = 1; i < 99; ++i) {
        for (int j = 1; j < 99; ++j) {
            y[i][j] = 1;
        }
    }

    // Compare x and y
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (x[i][j] != y[i][j]) {
                result = -1;
            }
        }
    }

    // Check result and print message
    if (result != 0) {
        std::cout << "ERROR" << std::endl;
        exit(1); // Exit the program with an error code
    } else {
        std::cout << "PASS" << std::endl;
    }

    return 0;
}