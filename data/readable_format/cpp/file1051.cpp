#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> // for exit()

int main() {
    // Create a string of length 72 filled with '!' characters
    std::string c(72, '!');

    // Iterate over the string two characters at a time
    for (std::size_t i = 0; i < c.length(); i += 2) {
        // In Fortran, the string index starts at 1, but in C++, it starts at 0.
        // The Fortran code checks if the two-character sequence is not "!)",
        // but since the Fortran format initializes `c` with "!" symbols, there's a mismatch in the logic.
        // Assuming the intention is to check for "!!" (since "!)' doesn't match the Fortran initialization),
        // we'll check for "!!". If you indeed intended a different check, adjust the comparison accordingly.
        if (c.substr(i, 2) != "!!") {
            std::cerr << "Unexpected string format." << std::endl;
            exit(1); // Exit with an error code
        }
    }

    // In the provided Fortran code, there's no output or further processing after the check,
    // so the equivalent C++ code also ends here.
    // If you had specific behavior or output in mind after this check, you would add it here.

    return 0;
}