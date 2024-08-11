#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib> // For std::abort()

int main() {
    std::ostringstream oss;
    
    // Equivalent to writing the integer 1 into the 'c' with the specified format
    // Note: setw(4) sets the width for the next outputted item only, so it's applied to the integer '1'.
    oss << ' ' << std::setw(4) << 1 << ' ';
    
    // Getting the formatted string
    std::string c = oss.str();
    
    // Check if 'c' does not match the expected string (with proper amount of leading and trailing spaces)
    if (c != "    1 ") {
        std::abort(); // Aborts the program
    }
    
    return 0;
}