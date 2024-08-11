// chk_alloc_string.cpp
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

std::string formatStrings(const std::vector<std::string>& strings) {
    std::ostringstream buffer;
    for (const auto& str : strings) {
        buffer.width(4); // Ensure each string is output with a width of 4 characters
        buffer << std::left << str.substr(0, 4); // Left-align and truncate/pad as necessary
    }
    return buffer.str();
}

int main() {
    std::vector<std::string> strings = {"A", "C", "ABCD", "V", "zzzz"};
    std::string formattedOutput = formatStrings(strings);

    std::cout << formattedOutput << std::endl;

    return 0;
}