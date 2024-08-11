#include <iostream>
#include <string>

void S(const std::string& c) {
    std::cout << c << std::endl;
}

int main() {
    std::string c = "YourTextHere"; // Example string. Adjust length as needed.
    S(c);
    return 0;
}