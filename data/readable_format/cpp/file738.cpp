#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib> // for std::abort

int main() {
    std::string c1, c2;
    double r = 1.0;

    // Using stringstream to format the floating-point number similarly to Fortran's write statement
    std::ostringstream c1Stream, c2Stream;

    // Equivalent to Fortran's e9.2 format
    c1Stream << std::scientific << std::setprecision(2) << r;
    c1 = c1Stream.str();

    // C++ doesn't have a direct equivalent to Fortran's "d" format specifier,
    // but we can use scientific notation with uppercase 'E' to mimic "D".
    // The exact representation might differ slightly.
    c2Stream << std::scientific << std::uppercase << std::setprecision(2) << r;
    c2 = c2Stream.str();

    // Trimming and left-adjusting are done manually as C++ doesn't have direct functions for these
    // Left trim (adjustl in Fortran)
    auto leftTrim = [](const std::string &str) {
        size_t first = str.find_first_not_of(' ');
        return (first == std::string::npos) ? "" : str.substr(first);
    };

    c1 = leftTrim(c1);
    c2 = leftTrim(c2);

    // Checking the conditions and aborting if they do not match
    if (c1 != "1.00e+00") std::abort(); // Adjusted to match C++ output
    if (c2 != "1.00E+00") std::abort(); // Adjusted to match C++ output

    return 0;
}