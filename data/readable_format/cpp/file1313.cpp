#include <iostream>
#include <iomanip>
#include <array>
#include <string>

int main() {
    std::array<int, 6> i;
    std::array<std::array<std::string, 2>, 4> r = {{{"0123456789AB"}}}; // Initialize with the same string for simplicity
    int ierr = 0; // Variable to simulate I/O operation status

    // Initialize array i with values 1 to 6
    for(int j = 0; j < 6; j++) {
        i[j] = j + 1;
    }

    // Attempt to write i into r in a formatted way
    // Note: This is a simplification since C++ does not directly support formatted writes into strings as Fortran does.
    // Instead, we'll just demonstrate filling 'r' with values from 'i' as a demonstration.
    try {
        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 2; ++col) {
                int index = row * 2 + col;
                if (index < i.size()) {
                    r[row][col] = std::to_string(i[index]);
                } else {
                    throw std::runtime_error("Index out of bounds");
                }
            }
        }
    } catch (const std::exception& e) {
        // Simulating an error in I/O operation
        ierr = -1; // Using -1 to indicate error, as C++ exception handling is different from Fortran I/O status checking
    }

    // Error handling based on simulated I/O status
    if (ierr != -2) {
        std::cerr << "An error occurred" << std::endl;
        return 1; // Return with error code 1
    }

    // Optionally, print the contents of r to demonstrate the result
    for (const auto& row : r) {
        for (const auto& col : row) {
            std::cout << col << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}