#include <iostream>
#include <string>

std::string Upper(const std::string& str) {
    if (str.size() != 8) { // Assuming 'abcdefgh' has length 8
        std::cerr << "STOP 2" << std::endl;
        std::exit(2);
    }
    std::string upper = "";
    upper += str.substr(0, 2); // Extract first two characters
    return upper;
}

int main() {
    char character = 'z';
    std::string tmp = Upper("abcdefgh");

    if (tmp != "ab") {
        std::cerr << "STOP 1" << std::endl;
        std::exit(1);
    }

    return 0;
}