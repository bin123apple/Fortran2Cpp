#include <iostream>
#include <fstream>
#include <cstdio> // For std::remove

int main() {
    const std::string filename = "tmpfile";
    std::fstream file;

    // Attempt to open or create the file with direct access (in binary mode to mimic direct access)
    file.open(filename, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    // Mimicking file write/read by seeking specific positions
    file.seekp(0); // Seek to the beginning for write
    file << 'A'; // Write a character

    file.seekg(0); // Seek to the beginning for read
    char ch;
    file >> ch; // Read the character

    std::cout << "Character written and read: " << ch << std::endl;

    // Closing the file
    file.close();

    // Deleting the file
    if (std::remove(filename.c_str()) != 0) {
        std::cerr << "Error deleting the file." << std::endl;
    } else {
        std::cout << "File deleted successfully." << std::endl;
    }

    return 0;
}