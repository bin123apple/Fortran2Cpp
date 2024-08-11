#include <iostream>
#include <string>
#include <cstdlib> // For std::exit

std::string doesntwork_p8(char c, int a1, int a2, int a3, int a4, int a5, int a6) {
    if (a1 != 1 || a2 != 2 || a3 != 3 || a4 != 4 || a5 != 5 || a6 != 6) {
        std::exit(1);
    }
    if (c != 'o') { // Assuming the intent was to check for 'o', not "o " which includes a space
        std::exit(2);
    }
    return "foo";
}

int main() {
    // Example usage
    std::string result = doesntwork_p8('o', 1, 2, 3, 4, 5, 6);
    std::cout << result << std::endl;
    return 0;
}