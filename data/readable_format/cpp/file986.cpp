#include <iostream>
#include <string>
#include <cstdlib> // For std::abort

struct t {
    std::string x;
    t() : x(2, ' ') {} // Initialize x with 2 spaces, mimicking Fortran character length
};

int main() {
    t a;
    std::string b(3, ' '); // Initialize b with 3 spaces
    std::string line(10, ' '); // Initialize line with 10 spaces
    
    // Mimic Fortran's fixed-length string assignments
    a.x[0] = 'a'; // Assign 'a' to the first position
    // Create formatted string similar to Fortran's write statement
    line = a.x.substr(0, 1) + "X" + std::string(8, ' '); // Trim and format
    if (line != "aX        ") std::abort();
    
    b[0] = 'a'; b[1] = 'b'; // Assign 'ab' to b
    // Again, create formatted string
    line = b.substr(0, 2) + "Y" + std::string(7, ' '); // Trim and format
    if (line != "abY       ") std::abort();
    
    return 0;
}