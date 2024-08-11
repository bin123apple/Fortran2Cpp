#include <iostream>
#include <string>

// Function declarations
std::string f(); // for when i is not present
std::string f(int i); // for when i is present

int main() {
    std::cout << f(1) << std::endl;
    return 0;
}

// Function definitions
std::string f() {
    return "absent";
}

std::string f(int i) {
    return "present";
}