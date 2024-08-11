#include <iostream>
#include <sstream>
#include <string>

std::string formatInteger(int n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}

int main() {
    int n = 1;
    std::string formatted_string = formatInteger(n);
    std::cout << "Formatted string: " << formatted_string << std::endl;
    return 0;
}