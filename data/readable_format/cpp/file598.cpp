#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

void numtext(float value, std::string& str) {
    std::ostringstream stream;
    float test = std::abs(value);
    
    stream << std::fixed;
    if (test <= 0.000009) {
        stream << std::setprecision(9);
    } else if (test <= 0.00009) {
        stream << std::setprecision(8);
    } else if (test <= 0.0009) {
        stream << std::setprecision(7);
    } else if (test <= 0.009) {
        stream << std::setprecision(6);
    } else if (test <= 0.09) {
        stream << std::setprecision(5);
    } else if (test <= 0.9) {
        stream << std::setprecision(4);
    } else if (test <= 999.0) {
        stream << std::setprecision(3);
    } else if (test <= 999999.0) {
        stream << std::setprecision(2);
    } else if (test == 0.0) {
        stream << std::setprecision(1);
    } else {
        stream << std::setprecision(0);
    }
    
    stream << value;
    str = stream.str();
    // Ensure the output is not longer than 12 characters.
    if (str.length() > 12) {
        str = str.substr(0, 12);
    }
}

int main() {
    std::string result;
    numtext(1234567.0, result);
    std::cout << result << std::endl;
    return 0;
}