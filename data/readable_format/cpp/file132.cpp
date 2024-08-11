#include <fstream>
#include <iostream>
#include <string>

int main() {
    // The file to write to
    std::string filename = "output.txt";

    // Open a file stream in binary mode to mimic stream access
    std::ofstream file(filename, std::ios::binary | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    // Write the text to the file
    file << "TEXT";

    // Check if the write was successful
    if (!file) {
        std::cerr << "Write operation failed." << std::endl;
        file.close();
        return 1;
    }

    // Retrieve the current position in the file
    std::streampos position = file.tellp();

    // Close the file
    file.close();

    // Delete the file by removing it
    if (std::remove(filename.c_str()) != 0) {
        std::cerr << "Error deleting the file." << std::endl;
        return 1;
    }

    // Check if the position is not 5 (considering "TEXT" is 4 characters and we expect position 5)
    if (position != 5) {
        std::cerr << "File position is not as expected. Position: " << position << std::endl;
        return 1; // Use return 1 to indicate error, similar to 'stop 1' in Fortran
    }

    return 0; // Success
}