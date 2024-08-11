#include <iostream>
#include <iomanip> // For std::setw

void xersor(const std::string &srname, int info) {
    // Ensure the string 'srname' is not longer than 7 characters for output
    std::string outputSrName = srname.substr(0, 7);

    // Print the formatted message
    std::cout << " ** On entry to " << std::left << std::setw(7) << outputSrName
              << " parameter number " << std::setw(2) << info 
              << " had an illegal value" << std::endl;
}

// Example usage
int main() {
    xersor("ABCDEF", 5);
    return 0;
}