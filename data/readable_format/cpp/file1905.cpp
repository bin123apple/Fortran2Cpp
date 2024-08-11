#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

bool isWhitespace(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isspace);
}

void checkString(const std::string& str) {
    if (str.empty() || isWhitespace(str)) {
        std::cout << "Empty String" << std::endl;
    } else {
        std::cout << "Non-Empty String" << std::endl;
    }
}

int main() {
    std::string c = " ";
    checkString(c);
    return 0;
}