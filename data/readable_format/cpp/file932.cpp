#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("test.dat", std::ios::out); // Open the file for writing.

    if (!file.is_open()) { // Check if the file was successfully opened.
        std::cerr << "Failed to open test.dat" << std::endl;
        return 1; // Return with error code.
    }

    file << "Hello world!" << std::endl; // Write to the file.

    file.close(); // Close the file.

    return 0; // Return success.
}