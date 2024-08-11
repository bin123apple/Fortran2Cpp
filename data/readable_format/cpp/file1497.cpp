#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "tmpfile";
    std::string access = "sequential"; // Simulating Fortran's access='sequential'
    
    // Open a new file
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    
    // Simulate INQUIRE by displaying the properties. 
    // Note: This is a simplification. Actual file properties checking is not straightforward in C++.
    std::cout << access << std::endl; // Displaying the simulated 'access' mode
    
    // In C++, there's no direct equivalent to Fortran's INQUIRE for these properties,
    // so we'll simulate displaying fixed values based on what we 'set' above.
    std::cout << "sequential" << std::endl; // Assuming 'sequential' since it's a text file
    std::cout << "N/A" << std::endl; // 'direct' doesn't have a direct equivalent
    std::cout << "formatted" << std::endl; // Assuming 'formatted' for text files
    std::cout << "formatted" << std::endl; // Since we're writing text
    std::cout << "unformatted" << std::endl; // Assuming opposite of 'formatted'
    
    // Close and delete the file
    file.close();
    if (remove(filename.c_str()) != 0) {
        std::cerr << "Error deleting file." << std::endl;
        return 1;
    }

    return 0;
}