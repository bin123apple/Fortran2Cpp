#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>

int main() {
    long double x = 1.0L + std::pow(2.0L, -105); // Using long double, closest to real(kind=16)
    
    // Convert to hexadecimal string. C++ doesn't directly support converting floats to hex strings,
    // so we'll represent the number in hex by first treating its bit pattern as an integer.
    // This requires some care and understanding of the underlying representation.
    
    // Since C++ standard library doesn't directly support printing floating points in hex,
    // the approach to directly convert the number as in Fortran's example is non-trivial and
    // would generally involve bit manipulation and understanding of the floating-point format.
    // For educational purposes, we'll simplify the scenario by focusing on the conversion to string and formatting.
    
    std::stringstream ss;
    ss << std::hexfloat << x; // Convert to hex-based floating point representation
    std::string str1 = ss.str();
    
    // Print with fixed length (assuming 32 characters is the goal, but with hexfloat it's tricky to match exactly)
    std::cout << std::setw(32) << std::setfill('0') << str1 << std::endl;
    
    // Print without leading zeros (directly printing the stringstream's content)
    std::cout << str1 << std::endl;

    return 0;
}