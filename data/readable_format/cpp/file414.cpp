#include <iostream>
#include <cstdlib> // For abort()
#include <cstdint> // For int64_t type
#include <string> // For std::string
#include <sstream> // For std::stringstream

int main() {
    int64_t i = 1; // Equivalent to integer(kind=8)
    
    // Equivalent to the Fortran do loop for multiplying i by 2, 63 times
    for (int j = 1; j <= 63; ++j) {
        i = i * 2;
    }
    
    // Convert the integer i to a string
    std::stringstream ss;
    ss << i;
    std::string l = ss.str();
    
    // Check if l is not equal to the desired string
    if (l != "-9223372036854775808") {
        abort(); // Calls std::abort() to terminate the program
    }

    return 0;
}