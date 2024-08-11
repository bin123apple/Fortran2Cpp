#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

// Simulates checking the status of a file operation
void ncheck(bool success, const std::string& fname) {
    if (!success) {
        std::cerr << "Error in file operation: " << fname << std::endl;
        exit(EXIT_FAILURE); // Exit the program with an error state
    }
}

int main() {
    std::string fname = "non_existent_file.nc";
    std::ifstream file(fname);

    // Simulate checking the success of opening the file
    ncheck(file.is_open(), fname);

    // If success (which in this case, it won't be), proceed with operations
    std::cout << "File opened successfully." << std::endl;

    // Close the file if it was opened
    if (file.is_open()) {
        file.close();
    }

    return 0;
}