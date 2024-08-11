#include <iostream>
#include <string>

std::string ch() {
    return "hello";
}

int main() {
    if (ch() == "hello") {
        // Continue to next line (no operation needed here)
    }
    return 0;
}